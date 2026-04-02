# Build Instructions

## Quick Start (Automated)

```powershell
.\CompileNow.ps1
```

The script will:
1. Download Dear ImGui v1.90.1 automatically
2. Configure the compilation environment
3. Compile with full optimizations
4. Output: `bin\ShadowTrainerVisual.exe`

## Manual Build

If you prefer manual setup:

### 1. Download Dear ImGui

Get Dear ImGui v1.90.1 from:
```
https://github.com/ocornut/imgui/archive/refs/tags/v1.90.1.zip
```

### 2. Extract Required Files

Create an `imgui/` folder and copy:

**Core files:**
- `imgui.h`
- `imgui.cpp`
- `imgui_draw.cpp`
- `imgui_tables.cpp`
- `imgui_widgets.cpp`
- `imgui_internal.h`
- `imconfig.h`
- `imstb_rectpack.h`
- `imstb_textedit.h`
- `imstb_truetype.h`

**Backend files** (from `backends/` folder):
- `imgui_impl_dx11.h`
- `imgui_impl_dx11.cpp`
- `imgui_impl_win32.h`
- `imgui_impl_win32.cpp`

### 3. Setup Visual Studio Environment

Open "x64 Native Tools Command Prompt for VS 2022" or run:
```cmd
"C:\Program Files\Microsoft Visual Studio\[version]\Community\VC\Auxiliary\Build\vcvars64.bat"
```

### 4. Compile

```cmd
cl.exe /nologo /std:c++20 /O2 /Oi /Ot /GL /MT /GS- /W3 /EHsc ^
  /DNDEBUG /D_WINDOWS /DWIN32_LEAN_AND_MEAN ^
  /I"." /I"imgui" ^
  /Fe"bin\ShadowTrainerVisual.exe" ^
  Main.cpp UIRenderer.cpp ^
  imgui\imgui.cpp imgui\imgui_draw.cpp imgui\imgui_tables.cpp ^
  imgui\imgui_widgets.cpp imgui\imgui_impl_dx11.cpp imgui\imgui_impl_win32.cpp ^
  /link /SUBSYSTEM:WINDOWS /ENTRY:WinMainCRTStartup ^
  /OPT:REF /OPT:ICF /LTCG ^
  d3d11.lib dxgi.lib dwmapi.lib user32.lib gdi32.lib
```

## Compiler Flags Explained

### Optimization
- `/O2` - Maximum speed optimization
- `/Oi` - Generate intrinsic functions
- `/Ot` - Favor fast code
- `/GL` - Whole program optimization
- `/LTCG` - Link-time code generation

### Runtime
- `/MT` - Static link runtime (no DLL dependencies)

### Security
- `/GS-` - Disable buffer security checks (smaller size)

### Standards
- `/std:c++20` - C++20 language standard
- `/EHsc` - Exception handling model

## Expected Output

- **Size:** ~497 KB
- **Location:** `bin\ShadowTrainerVisual.exe`
- **Dependencies:** Only standard Windows system DLLs

## Troubleshooting

### "cl.exe not found"
Run from Visual Studio Developer Command Prompt or run vcvars64.bat first.

### "Cannot find imgui.h"
Make sure Dear ImGui files are in the `imgui/` subfolder.

### Large executable size (>1 MB)
Ensure `/MT` (not `/MD`) and `/GL` + `/LTCG` flags are set.

### Missing DLL errors
Should not happen - we use `/MT` static linking. All required DLLs are built into Windows 10/11.

## Platform Support

- **Windows 10** (64-bit) ✅
- **Windows 11** (64-bit) ✅
- DirectX 11 required (included in Windows)

---

For issues or questions, please open a GitHub issue.
