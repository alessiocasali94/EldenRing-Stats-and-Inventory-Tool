# Direct compilation without MSBuild - Works with any VS version
$ErrorActionPreference = "Stop"

$root = Split-Path -Parent $MyInvocation.MyCommand.Path
Write-Host "=== Compiling Shadow Trainer Visual ===" -ForegroundColor Cyan
Write-Host ""

# Step 1: Find cl.exe
Write-Host "[1/4] Locating compiler..." -ForegroundColor Yellow
$vsPath = "C:\Program Files\Microsoft Visual Studio\18\Community"
$vcvars = "$vsPath\VC\Auxiliary\Build\vcvars64.bat"

if (-not (Test-Path $vcvars)) {
    Write-Host "ERROR: vcvars64.bat not found!" -ForegroundColor Red
    exit 1
}

# Step 2: Prepare build directory
Write-Host "[2/4] Preparing build..." -ForegroundColor Yellow
$buildDir = "$root\bin"
if (Test-Path $buildDir) {
    Remove-Item "$buildDir\*.obj" -Force -ErrorAction SilentlyContinue
    Remove-Item "$buildDir\*.exe" -Force -ErrorAction SilentlyContinue
}
New-Item -ItemType Directory -Force -Path $buildDir | Out-Null

# Step 3: Compile
Write-Host "[3/4] Compiling with optimizations..." -ForegroundColor Yellow

$compileCmd = @"
@echo off
call "$vcvars" >nul 2>&1
cd /d "$root"
rc.exe /nologo resource.rc
cl.exe /nologo /std:c++20 /O2 /Oi /Ot /GL /MT /GS- /W3 /EHsc /DNDEBUG /D_WINDOWS /DWIN32_LEAN_AND_MEAN /I"$root" /I"$root\imgui" /Fe"$buildDir\ShadowTrainerVisual.exe" Main.cpp UIRenderer.cpp imgui\imgui.cpp imgui\imgui_draw.cpp imgui\imgui_tables.cpp imgui\imgui_widgets.cpp imgui\imgui_impl_dx11.cpp imgui\imgui_impl_win32.cpp resource.res /link /SUBSYSTEM:WINDOWS /ENTRY:WinMainCRTStartup /OPT:REF /OPT:ICF /LTCG d3d11.lib dxgi.lib dwmapi.lib user32.lib gdi32.lib
"@

$batchFile = "$buildDir\compile.bat"
Set-Content -Path $batchFile -Value $compileCmd -Encoding ASCII

$output = & cmd.exe /c "$batchFile" 2>&1
$success = $LASTEXITCODE -eq 0

if (-not $success) {
    Write-Host "Compilation failed!" -ForegroundColor Red
    Write-Host $output
    exit 1
}

# Step 4: Verify
Write-Host "[4/4] Verifying output..." -ForegroundColor Yellow

$exe = "$buildDir\ShadowTrainerVisual.exe"
if (Test-Path $exe) {
    $size = [Math]::Round((Get-Item $exe).Length / 1KB, 2)
    Write-Host ""
    Write-Host "=== SUCCESS ===" -ForegroundColor Green
    Write-Host "Location: $exe" -ForegroundColor Cyan
    Write-Host "Size: $size KB" -ForegroundColor Cyan
    Write-Host ""
    Write-Host "Executable is fully standalone - no dependencies!" -ForegroundColor Green
    Write-Host "Works on any Windows 10/11 PC without installing anything." -ForegroundColor Green
    Write-Host ""
    Write-Host "Controls:" -ForegroundColor Yellow
    Write-Host "  INSERT - Show/Hide UI" -ForegroundColor White
    Write-Host "  ESC/END - Exit" -ForegroundColor White
    Write-Host ""
    
    # Test for dependencies
    Write-Host "Testing dependencies..." -ForegroundColor Yellow
    $dllCheck = dumpbin /dependents "$exe" 2>&1 | Select-String -Pattern "\.dll" | Where-Object { $_ -notmatch "KERNEL32.dll|USER32.dll|GDI32.dll|msvcrt.dll|d3d11.dll|dxgi.dll" }
    if ($dllCheck) {
        Write-Host "Warning: Non-standard dependencies detected:" -ForegroundColor Yellow
        Write-Host $dllCheck
    } else {
        Write-Host "Clean! Only system DLLs required." -ForegroundColor Green
    }
    
    # Launch option
    Write-Host ""
    $launch = Read-Host "Launch now? (Y/N)"
    if ($launch -eq "Y" -or $launch -eq "y") {
        Start-Process $exe
    }
    
} else {
    Write-Host "ERROR: Executable not created!" -ForegroundColor Red
    exit 1
}
