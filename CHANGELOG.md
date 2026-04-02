# 📋 Changelog

## Version 1.0.1 (2026-03-17)

### 🛡️ Antivirus Compatibility Update

#### Fixed
- 🔧 Replaced `GetAsyncKeyState()` with `WM_KEYDOWN` message handling
  - Reduces false positives from antivirus heuristics
  - More standard Windows message processing
- 📝 Added version metadata resource (company, product info)
- 🎯 Generic naming in file metadata to avoid game-specific flags

#### Technical
- Keyboard handling now via window messages only
- Added `resource.rc` with version information
- Embedded metadata: "UI Framework Demo Application"

## Version 1.0.0 (2026-03-17)

### 🎉 Initial Release

#### Features
- ✨ 30+ trainer-style options with checkboxes and sliders
- 🎨 Dark theme styled after FLiNG trainers
- 🪟 Transparent overlay window (94% opacity)
- ⌨️ Keyboard shortcuts (INSERT, ESC, END)
- 🎯 Draggable window with close button
- 🔧 Collapsible sections (Character Stats, Combat, Currency, Advanced)

#### Options Included
- **Character Stats** (Num 0-9): God Mode, Infinite HP/FP/Stamina, Super Speed/Jump, etc.
- **Combat** (F1-F6): One Hit Kill, Damage/Defense Multipliers, Infinite Poise, etc.
- **Currency** (F7-F9): Add Runes, Runes Multiplier, No Rune Loss
- **Advanced** (F10-F12, INS, DEL, HOME, PGUP, PGDN): Game Speed, Freeze Enemies, etc.

#### Technical
- C++20 standard
- Dear ImGui 1.90.1
- DirectX 11 rendering
- Static runtime linking (/MT)
- Optimized build (~497 KB)
- Standalone executable (no external DLLs required)

#### Known Limitations
- **Visual only** - no actual game interaction
- UI states stored only in application memory
- x64 architecture only

---

**Note:** This is a demonstration project for educational purposes. It does not interact with game processes or memory.
