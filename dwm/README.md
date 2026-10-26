# `config.h` Documentation

A reference for my **dwm** (dynamic window manager) build. Modifier key is **Mod4 (Super/Windows key)**, referred to below as `MOD`.

---

## 1. Appearance

### Fonts

| Name                                                         | Size |
| ------------------------------------------------------------ | ---- |
| [Terminus](https://github.com/fa-saikat/dotfiles/tree/main/local/fonts) | 12   |
| [JetBrainsMono Nerd Font](https://www.nerdfonts.com/font-downloads) | 10   |
| [NotoSansMono Nerd Font](https://www.nerdfonts.com/font-downloads) | 10   |

### Color Scheme

- Included from `scheme/`, default is `monochrome.h` 

| Setting | Value | Description |
|---|---|---|
| `borderpx` | `2` | Window border thickness (px) |
| `snap` | `10` | Snap distance for window edges (px) |
| `swallowfloating` | `0` | Floating windows are not swallowed by default |
| `gappih` / `gappiv` | `14` / `14` | Inner gap between windows (horizontal / vertical) |
| `gappoh` / `gappov` | `14` / `14` | Outer gap between windows and screen edge (horizontal / vertical) |
| `smartgaps` | `0` | Gaps still shown even with a single window |
| `showbar` | `1` | Status bar is shown |
| `topbar` | `1` | Bar is placed at the top |
| `vertpad` | `10` | Vertical bar padding |
| `sidepad` | `14` | Horizontal bar padding |
| `horizpadbar` | `86` | Horizontal padding for the status text |
| `vertpadbar` | `8` | Vertical padding for the status text |

### Tab Bar
| Setting | Value | Description |
|---|---|---|
| `showtab` | `showtab_auto` | Tab bar shown only in monocle mode with multiple windows |
| `toptab` | `True` | Tab bar placed at the top |

### Systray
| Setting | Value | Description |
|---|---|---|
| `showsystray` | `1` | Systray enabled |
| `systraypinning` | `1` | Systray pinned to monitor 1 |
| `systrayspacing` | `2` | Spacing between systray icons |
| `systraypinningfailfirst` | `1` | Falls back to first monitor if pinning fails |

### Autostart
- Runs `$SUCKLESS_HOME/dwm/autostart.sh` on startup (falls back to `$XDG_DATA_HOME/suckless-stuff/dwm`, then `~/.local/share/suckless-stuff/dwm`, then `~/.dwm`)

---

## 2. Scratchpads

| Name | Functionality | Keybinding |
|---|---|---|
| `spterm1` | A quickly accessible terminal that can be hid | `MOD + Shift + Return` |
| `spterm2` | Another | `Alt + Return` |
| `spterm3` | `kitty --class spterm3 --name Htop --title Htop --override font_size=13 htop` (a floating `htop` terminal) | `Alt + Shift + Return` |
| `pavucontrol` | `pavucontrol` (audio control panel) | `MOD + v` |

**Toggle keybindings:**

| Keybind | Scratchpad |
|---|---|
|  | spterm1 |
|  | spterm2 |
|  | spterm3 (Htop) |
|  | pavucontrol |

---

## 3. Tags (Workspaces)

9 tags, displayed using Nerd Font glyphs (currently: `󰎤 󰎧 󰎪 󰎭 󰎱 󰎳 󰎶 󰎹 󰎼`). Two alternate tag icon sets are commented out in the source.

### Default Layout per Tag
```
defaultlayouts[] = { 0, 0, 0, 5, 4, 0 }
```
- Index `0` = all-tag view default (Tile)
- Tags 1–2: Tile (`0`)
- Tag 3: Monocle (`5`)
- Tag 4: Grid (`4`)
- Remaining tags: unset/default (Tile)

### Underline Tag Indicator
| Setting | Value |
|---|---|
| `ulineall` | `0` (underline only on active tags) |
| `ulinepad` | `5`px |
| `ulinestroke` | `2`px thickness |
| `ulinevoffset` | `0`px offset from bar bottom |

---

## 4. Window Rules

| Class | Instance | Title | Tag | Switch to Tag | Floating | Terminal | No Swallow | Monitor |
|---|---|---|---|---|---|---|---|---|
| — | — | `Event Tester` | — | No | No | No | Yes | any |
| `firefox` | — | — | Tag 3 | No | No | No | No | any |
| `qBittorrent` | — | — | Tag 9 | No | No | No | No | any |
| `st-256color` | — | — | — | No | No | **Yes** | No | any |
| `kitty` | — | — | — | No | No | **Yes** | No | any |
| `zoom` | `zoom` | — | Tag 5 | **Yes** | **Yes** | No | No | any |
| `zoom` | — | `Settings` | Tag 5 | **Yes** | **Yes** | No | No | any |
| — | `spterm1` | — | Scratchpad 0 | No | **Yes** | **Yes** | **Yes** | any |
| — | `spterm2` | — | Scratchpad 1 | No | **Yes** | **Yes** | **Yes** | any |
| `spterm3` | `Htop` | — | Scratchpad 2 | No | **Yes** | **Yes** | **Yes** | any |
| `pavucontrol` | `pavucontrol` | — | Scratchpad 3 | No | **Yes** | **Yes** | **Yes** | any |

Notes:
- `st` and `kitty` are marked as terminals (for swallowing behavior).
- Zoom windows automatically float and switch you to tag 5.
- Firefox always opens on tag 3; qBittorrent always opens on tag 9.

---

## 5. Layouts

| Symbol | Function | Description |
|---|---|---|
| `󰇙 󰬛 󰇙` | `tile` | **Default.** Master/stack tiling |
| `󰇙 󰬍 󰇙` | `NULL` | Floating layout |
| `󰇙 󰬉 󰇙` | `bstack` | Bottom-stack layout |
| `󰇙 󰬊 󰇙` | `centeredmaster` | Centered master area |
| `󰇙 󰬎 󰇙` | `grid` | Grid layout |
| `󰇙 [M] 󰇙` | `monocle` | Fullscreen/monocle stacking |

### Layout Parameters
| Setting | Value | Description |
|---|---|---|
| `mfact` | `0.60` | Default master area size (5%–95% range) |
| `nmaster` | `1` | Number of clients in the master area |
| `resizehints` | `1` | Respects client size hints while tiling |
| `lockfullscreen` | `1` | Forces focus to stay on fullscreen windows |
| `FORCE_VSPLIT` | `1` | In `nrowgrid`, two clients always split vertically |

Extra behavior included from `vanitygaps.c` (gap management) and `shiftview.c` (cyclic tag navigation).

---

## 6. Keybindings

`MOD` = **Super (Mod4)**

### Applications & Core Actions
| Keybind | Action |
|---|---|
| `MOD + Return` | Open terminal (`kitty --single-instance`) |
| `MOD + q` | Kill focused client |
| `MOD + w` | Toggle tab mode *(conflicts — see note below)* |
| `MOD + w` | Launch Firefox *(conflicts with tabmode above)* |
| `MOD + e` | Open file manager (Dolphin) |
| `MOD + p` | Launch dmenu |
| `MOD + Shift + r` | Restart dwm (quit with code `1`) |
| `MOD + Shift + q` | Quit dwm |

> ⚠️ **Note:** `MOD + w` is bound twice in the keys array (`tabmode` and `spawn webcmd`). Only the **last** matching entry (`spawn` → Firefox) will actually trigger, since dwm iterates the array and both match the same chord — effectively shadowing `tabmode`.

### Scratchpads
| Keybind | Action |
|---|---|
| `MOD + Shift + Return` | Toggle scratchpad 1 (spterm1) |
| `Alt + Return` | Toggle scratchpad 2 (spterm2) |
| `Alt + Shift + Return` | Toggle scratchpad 3 (spterm3 / Htop) |
| `MOD + v` | Toggle scratchpad 4 (pavucontrol) |

### Layout / Master Area
| Keybind | Action |
|---|---|
| `MOD + h` | Decrease master area size (`-5%`) |
| `MOD + l` | Increase master area size (`+5%`) |
| `MOD + Ctrl + i` | Increase number of master clients |
| `MOD + Ctrl + d` | Decrease number of master clients |
| `MOD + Page_Up` | Cycle layout backward |
| `MOD + Page_Down` | Cycle layout forward |

### Layout Shortcuts
| Keybind | Layout |
|---|---|
| `MOD + t` | Tile |
| `MOD + f` | Floating |
| `MOD + Shift + t` | Bottom-stack |
| `MOD + c` | Centered master |
| `MOD + g` | Grid |
| `MOD + m` | Monocle |

### Focus & Window Movement
| Keybind | Action |
|---|---|
| `MOD + j` | Focus next window in stack |
| `MOD + k` | Focus previous window in stack |
| `MOD + Shift + j` | Move window down in stack |
| `MOD + Shift + k` | Move window up in stack |
| `MOD + \` (backslash) | Zoom/promote window to master |
| `MOD + Shift + \` | Focus master window |

### Window State
| Keybind | Action |
|---|---|
| `MOD + Ctrl + b` | Toggle bar visibility |
| `MOD + s` | Toggle sticky (window visible on all tags) |
| `MOD + Space` | Toggle floating for focused window |

### Gaps
| Keybind | Action |
|---|---|
| `MOD + 0` | Toggle gaps on/off |
| `MOD + Shift + 0` | Reset gaps to default |
| `MOD + =` | Increase gap size |
| `MOD + -` | Decrease gap size |

### Tags / Workspaces
| Keybind | Action |
|---|---|
| `MOD + a` | Tag focused window on all tags |
| `MOD + Shift + a` | View all tags |
| `MOD + Tab` | View previously selected tag |
| `MOD + [1–9]` | View tag N |
| `MOD + Ctrl + [1–9]` | Toggle view of tag N (add/remove from current view) |
| `MOD + Shift + [1–9]` | Move focused window to tag N |
| `MOD + Ctrl + Shift + [1–9]` | Toggle tag N on focused window |
| `MOD + ,` (comma) | Shift view to previous tag |
| `MOD + .` (period) | Shift view to next tag |

### Monitors (multi-monitor setups)
| Keybind | Action |
|---|---|
| `MOD + [` | Focus previous monitor |
| `MOD + ]` | Focus next monitor |
| `MOD + Shift + [` | Move window to previous monitor |
| `MOD + Shift + ]` | Move window to next monitor |

### Commented Out / Disabled
- `XF86XK_AudioLowerVolume` / `XF86XK_AudioRaiseVolume` bound to `cyclelayout` and `shiftview` — currently disabled in source.
- Several `setlayout` entries for additional layouts (Bottomstack Horizontal, Centeredmaster Floating, Deck, Dwindle, Gapless Grid, Horizontal/Row Grid, Spiral) are stubbed out with no keys assigned.

---

## 7. Mouse Bindings

| Click Location | Modifier | Button | Action |
|---|---|---|---|
| Layout symbol | — | Button1 (left) | Cycle to next layout |
| Layout symbol | — | Button2 (middle) | Set Grid layout |
| Layout symbol | — | Button3 (right) | Set Monocle layout |
| Status text | — | Button2 (middle) | Open terminal |
| Client window | `MOD` | Button1 (left) | Move window with mouse |
| Client window | `MOD` | Button2 (middle) | Toggle floating |
| Client window | `MOD` | Button3 (right) | Resize window with mouse |
| Tag bar | — | Button1 (left) | View clicked tag |
| Tag bar | — | Button3 (right) | Toggle view of clicked tag |
| Tag bar | `MOD` | Button1 (left) | Move window to clicked tag |
| Tag bar | `MOD` | Button3 (right) | Toggle clicked tag on window |
| Tab bar | — | Button1 (left) | Focus clicked window |

---

## 8. Included Patches / Extra Source Files

This config relies on several non-vanilla dwm patches:
- **vanitygaps.c** — gap management (`gappih`, `gappiv`, `gappoh`, `gappov`, `smartgaps`, `togglegaps`, `incrgaps`, etc.)
- **shiftview.c** — cyclic tag shifting (`shiftview`)
- **movestack.c** — moving windows up/down within the stack
- Scratchpad patch (`Sp` struct, `togglescratch`, `SPTAG`)
- Tab bar patch (`showtab`, `toptab`, `ClkTabBar`, `focuswin`, `tabmode`)
- Systray patch
- Swallow patch (`swallowfloating`, `isterminal`, `noswallow`)
- Underline tags patch (`uline*` settings)
- `cyclelayout` patch
- `XF86` multimedia key support (`X11/XF86keysym.h`)

---

## 9. Known Quirks in This Config

1. **Duplicate `MOD + w` binding** — bound to both `tabmode` and `spawn(webcmd)`; only the Firefox spawn will fire in practice.
2. Two alternate tag icon arrays are left commented out for quick swapping.
3. Multiple `setlayout` keybindings are commented out as placeholders for extra layouts not currently bound to a key.
4. Volume-key layout cycling (`XF86XK_AudioLowerVolume/RaiseVolume`) is disabled/commented out.
