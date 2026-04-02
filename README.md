# 🎮 Elden Ring Trainer - Visual Edition

A standalone visual trainer interface for Elden Ring: Shadow of the Erdtree, built with C++20 and Dear ImGui.

> **⚠️ IMPORTANT:** This is a **visual-only demonstration** project. It does NOT interact with game processes, does NOT read/write memory, and does NOT provide actual trainer functionality. All options only change UI states in the application's memory.

> **🛡️ ANTIVIRUS WARNING:** Some antivirus programs may flag this application as suspicious due to overlay window features and lack of digital signature. This is a **false positive**. The source code is fully open and auditable. See [ANTIVIRUS-INFO.md](ANTIVIRUS-INFO.md) for details and solutions.

## 📸 Features

- ✨ **30+ Options** styled like FLiNG trainers
- 🎨 **Dark Theme** with transparent overlay
- ⌨️ **Keyboard Shortcuts** (INSERT to show/hide, ESC/END to exit)
- 🪶 **Lightweight** (~497 KB standalone executable)
- 🚀 **No Dependencies** - works on any Windows 10/11 PC

## 🎯 Available Options

### Character Stats
- God Mode / Ignore Hits
- Infinite HP / FP / Stamina
- Super Run Speed (1.0-12.0x slider)
- Super Jump Height (1.0-20.0x slider)
- Zero Equip Load
- No Fall Damage
- Infinite Items Usage

### Combat
- One Hit Kill
- Damage Multiplier (1-200x slider)
- Defense Multiplier (0.1-10x slider)
- No Damage Taken
- Infinite Poise
- 100% Item Discovery

### Currency & Progression
- Add Runes (button + input field)
- Runes Multiplier on Gain (1-100x slider)
- No Rune Loss on Death

### Advanced
- Infinite Great Rune Effect
- Always Regenerate HP/FP/Stamina
- Freeze All Enemies
- Game Speed (0.1-5.0x slider)
- Easy Craft / No Materials
- Unlimited Arrows & Bolts
- Infinite Spirit Summons
- Instant Respawn

## 🛠️ Building from Source

### Prerequisites

- Windows 10/11 (64-bit)
- Visual Studio 2022 or newer with C++ tools
- PowerShell

### Setup

1. **Clone this repository**
```bash
git clone https://github.com/yourusername/elden-ring-trainer-visual.git
cd elden-ring-trainer-visual
```

2. **Download Dear ImGui**

The build script will automatically download Dear ImGui v1.90.1. Or download manually:
```bash
https://github.com/ocornut/imgui/archive/refs/tags/v1.90.1.zip
```

Extract and copy these files to `imgui/` folder:
- `imgui.h`, `imgui.cpp`, `imgui_draw.cpp`, `imgui_tables.cpp`, `imgui_widgets.cpp`
- `imgui_internal.h`, `imconfig.h`
- `imstb_*.h` files
- From `backends/`: `imgui_impl_dx11.*` and `imgui_impl_win32.*`

3. **Compile**
```powershell
.\CompileNow.ps1
```

The executable will be created at: `bin\ShadowTrainerVisual.exe`

## 🎮 Usage

1. Run `ShadowTrainerVisual.exe`
2. Press **INSERT** to show/hide the menu
3. Click checkboxes and adjust sliders
4. Press **ESC** or **END** to exit

### Controls

| Key | Action |
|-----|--------|
| **INSERT** | Toggle UI visibility |
| **ESC** | Exit application |
| **END** | Exit application |

## 📦 Technical Details

- **Language:** C++20
- **GUI Library:** Dear ImGui 1.90.1
- **Graphics API:** DirectX 11
- **Compiler:** MSVC (Visual Studio 2022+)
- **Runtime:** Static linking (/MT)
- **Size:** ~497 KB
- **Architecture:** x64 only

### Optimization Flags

```
/O2 /Oi /Ot /GL /MT /GS- /LTCG
```

### System Dependencies

Only standard Windows DLLs (present on all Windows 10/11):
- `d3d11.dll` - DirectX 11
- `dxgi.dll` - DirectX Graphics Infrastructure
- `dwmapi.dll` - Desktop Window Manager
- `IMM32.dll` - Input Method Manager
- `D3DCOMPILER_47.dll` - DirectX shader compiler

## 📂 Project Structure

```
elden-ring-trainer-visual/
├── Main.cpp              # WinMain entry point, DirectX 11 setup
├── UIRenderer.cpp        # ImGui interface implementation
├── UIRenderer.h          # UI rendering declarations
├── AppState.h            # Application state structure
├── CompileNow.ps1        # Quick compilation script
├── README.md             # This file
└── imgui/                # Dear ImGui library (download separately)
    ├── imgui.cpp
    ├── imgui_impl_dx11.cpp
    ├── imgui_impl_win32.cpp
    └── ...
```

## ⚠️ Legal Notice

This is an **educational demonstration project only**. It does not:
- ❌ Interact with any game processes
- ❌ Read or write game memory
- ❌ Modify game files or behavior
- ❌ Provide actual cheating functionality

All UI elements are purely visual and only store states in the application's own memory.

**Use responsibly and respect game developers' terms of service.**

## 📜 License

This project is provided as-is for educational purposes only.

Dear ImGui is licensed under the MIT License.

## 🙏 Credits

- **Dear ImGui** by Omar Cornut - https://github.com/ocornut/imgui
- **DirectX 11** by Microsoft

## 🔗 Links

- [Dear ImGui GitHub](https://github.com/ocornut/imgui)
- [ImGui Documentation](https://github.com/ocornut/imgui/wiki)

---

Made with ❤️ for learning purposes only
