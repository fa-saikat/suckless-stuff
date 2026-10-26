<div align="center">

# dwm

A patched [dwm](https://dwm.suckless.org) 6.2 with gaps, scratchpads, tabs, swallowing and a systray.

![dwm](../assets/screenshots/dwm.png)

</div>

---

## Contents

- [Patches](#patches)
- [Appearance](#appearance)
- [Tags](#tags)
- [Layouts](#layouts)
- [Scratchpads](#scratchpads)
- [Window rules](#window-rules)
- [Keybindings](#keybindings)
- [Mouse](#mouse)
- [Autostart](#autostart)
- [Known quirks](#known-quirks)

---

## Patches

| Patch | What it does |
|---|---|
| [vanitygaps](https://dwm.suckless.org/patches/vanitygaps/) | Inner and outer gaps, plus the bstack, centredmaster and grid layouts (`vanitygaps.c`) |
| [scratchpads](https://dwm.suckless.org/patches/scratchpads/) | Multiple toggleable floating windows |
| [swallow](https://dwm.suckless.org/patches/swallow/) | A terminal is hidden while a GUI program launched from it is open |
| [tab](https://dwm.suckless.org/patches/tab/) | Tab bar in monocle layout |
| [systray](https://dwm.suckless.org/patches/systray/) | System tray in the bar |
| [underline tags](https://dwm.suckless.org/patches/underlinetags/) | Line under the active tag |
| [barpadding](https://dwm.suckless.org/patches/barpadding/) | Floating, padded bar |
| [movestack](https://dwm.suckless.org/patches/movestack/) | Move windows up and down the stack (`movestack.c`) |
| [shiftview](https://lists.suckless.org/dev/1104/7590.html) | Cycle through tags (`shiftview.c`) |
| [cyclelayouts](https://dwm.suckless.org/patches/cyclelayouts/) | Step through layouts |
| [sticky](https://dwm.suckless.org/patches/sticky/) | Keep a window on every tag |
| [switchtotag](https://dwm.suckless.org/patches/switchtotag/) | Jump to a window's tag when it opens |
| [pertag](https://dwm.suckless.org/patches/pertag/) | Default layout per tag |
| [focusmaster](https://dwm.suckless.org/patches/focusmaster/) | Focus the master window |
| [restartsig](https://dwm.suckless.org/patches/restartsig/) | Restart dwm in place |
| [autostart](https://dwm.suckless.org/patches/autostart/) | Run scripts at startup |

---

## Appearance

### Fonts

| Font | Size |
|---|---|
| [Terminus](https://github.com/fa-saikat/dotfiles/tree/main/local/fonts) | 12 (bar), 10 (dmenu) |
| [JetBrainsMono Nerd Font](https://www.nerdfonts.com/font-downloads) | 10 |
| [NotoSansMono Nerd Font](https://www.nerdfonts.com/font-downloads) | 10 |

### Colour scheme

Set by the include in `config.h`. The default is `scheme/monochrome.h`. Also available: everblush, gruv, nord, onedark and serenade. dmenu takes its colours from the same file.

### Settings

| Setting | Value | Meaning |
|---|---|---|
| `borderpx` | `2` | Window border width |
| `snap` | `10` | Snap distance for floating windows |
| `gappih` / `gappiv` | `14` / `14` | Inner gaps (horizontal / vertical) |
| `gappoh` / `gappov` | `14` / `14` | Outer gaps (horizontal / vertical) |
| `smartgaps` | `0` | Keep gaps with a single window |
| `topbar` | `1` | Bar at the top |
| `vertpad` / `sidepad` | `10` / `14` | Space around the bar |
| `horizpadbar` / `vertpadbar` | `86` / `8` | Padding inside the bar |
| `showtab` | `showtab_auto` | Tab bar only in monocle with several windows |
| `toptab` | `True` | Tab bar at the top |
| `showsystray` | `1` | Systray on |
| `systraypinning` | `1` | Systray pinned to monitor 1, falling back to the first |
| `swallowfloating` | `0` | Floating windows are not swallowed |

---

## Tags

Nine tags, drawn as Nerd Font glyphs:

```
󰎤 󰎧 󰎪 󰎭 󰎱 󰎳 󰎶 󰎹 󰎼
```

Three other sets (app icons, dice and plain numbers) are commented out in `config.def.h`.

Default layouts per tag: tag 3 opens in monocle, tag 4 in grid, the rest in tile.

The active tag is underlined: 2px thick, 5px padding.

---

## Layouts

| Symbol | Layout | Key |
|---|---|---|
| `󰇙 󰬛 󰇙` | Tile (default) | `Super + t` |
| `󰇙 󰬍 󰇙` | Floating | `Super + f` |
| `󰇙 󰬉 󰇙` | Bottom stack | `Super + Shift + t` |
| `󰇙 󰬊 󰇙` | Centred master | `Super + c` |
| `󰇙 󰬎 󰇙` | Grid | `Super + g` |
| `󰇙 [M] 󰇙` | Monocle | `Super + m` |

Master area: 60% of the screen, one window.

---

## Scratchpads

Floating windows you can show and hide from any tag.

| Key | Scratchpad |
|---|---|
| `Super + Shift + Return` | Terminal (kitty) |
| `Alt + Return` | Second terminal (kitty) |
| `Alt + Shift + Return` | htop |
| `Super + v` | pavucontrol |

---

## Window rules

| Program | Tag | Behaviour |
|---|---|---|
| Firefox | 3 | |
| opencode | 3 | |
| Zoom | 5 | Floating, switches to tag 5 |
| Dolphin | 6 | |
| qBittorrent | 9 | |
| st, kitty | | Marked as terminals for swallowing |
| xev | | Never swallowed |

---

## Keybindings

`Super` is the modifier.

### Programs

| Key | Action |
|---|---|
| `Super + Return` | Terminal (kitty) |
| `Super + p` | dmenu |
| `Super + w` | Firefox, and toggles the tab bar (see [quirks](#known-quirks)) |
| `Super + e` | Dolphin |

### Windows

| Key | Action |
|---|---|
| `Super + q` | Close window |
| `Super + j / k` | Focus next / previous |
| `Super + Shift + j / k` | Move down / up the stack |
| `Super + \` | Promote to master |
| `Super + Shift + \` | Focus master |
| `Super + Space` | Toggle floating |
| `Super + s` | Toggle sticky |

### Layout

| Key | Action |
|---|---|
| `Super + h / l` | Shrink / grow master |
| `Super + Ctrl + i / d` | More / fewer master windows |
| `Super + Page_Up / Page_Down` | Previous / next layout |
| `Super + t / f / g / m / c` | Tile / float / grid / monocle / centred master |
| `Super + Shift + t` | Bottom stack |
| `Super + Ctrl + b` | Toggle bar |

### Gaps

| Key | Action |
|---|---|
| `Super + 0` | Toggle gaps |
| `Super + Shift + 0` | Reset gaps |
| `Super + = / -` | Bigger / smaller gaps |

### Tags

| Key | Action |
|---|---|
| `Super + 1–9` | View tag |
| `Super + Shift + 1–9` | Move window to tag |
| `Super + Ctrl + 1–9` | Add tag to view |
| `Super + Ctrl + Shift + 1–9` | Add tag to window |
| `Super + , / .` | Previous / next tag |
| `Super + Tab` | Last tag |
| `Super + a` | Show window on all tags |
| `Super + Shift + a` | View all tags |

### Monitors

| Key | Action |
|---|---|
| `Super + [ / ]` | Focus previous / next monitor |
| `Super + Shift + [ / ]` | Send window to previous / next monitor |

### Session

| Key | Action |
|---|---|
| `Super + Shift + r` | Restart dwm |
| `Super + Shift + q` | Quit dwm |

---

## Mouse

| Where | Button | Action |
|---|---|---|
| Layout symbol | Left / middle / right | Next layout / grid / monocle |
| Status text | Middle | Open terminal |
| Tag | Left / right | View tag / add to view |
| Tag + `Super` | Left / right | Move window to tag / add tag to window |
| Window + `Super` | Left / middle / right | Move / toggle floating / resize |
| Tab | Left | Focus window |

---

## Autostart

At startup dwm runs `autostart_blocking.sh` (waits for it to finish) and then `autostart.sh` (in the background), from the first of these directories that exists:

1. `$SUCKLESS_HOME/dwm`
2. `$XDG_DATA_HOME/suckless-stuff/dwm`
3. `~/.local/share/suckless-stuff/dwm`
4. `~/.dwm`

A script that is missing or not executable is skipped.

---

## Known quirks

- **`Super + w` does two things.** It is bound to both `tabmode` and Firefox, and dwm runs every matching binding, so it opens Firefox and toggles the tab bar together.
- **Trimmed layouts.** Only tile, bstack, centredmaster and grid are compiled from `vanitygaps.c`. The others (deck, dwindle, spiral, nrowgrid and more) are commented out there, along with unused keybinding stubs in `config.def.h`.
- **Volume keys.** Bindings for cycling layouts and tags with the volume keys are commented out.
