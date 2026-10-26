<div align="center">

# suckless-stuff

My daily-driver builds of the [suckless](https://suckless.org) tools: dwm, st, dmenu, slock and slstatus.

![X11](https://img.shields.io/badge/display-X11-555?style=flat-square)
![C](https://img.shields.io/badge/language-C-555?style=flat-square)
![License](https://img.shields.io/badge/license-MIT%2FX-555?style=flat-square)

![Desktop](assets/screenshots/desktop.png)

</div>

---

## Gallery

<!-- Replace these with your own screenshots in assets/screenshots/ -->

| Tiled | Monocle with tabs |
|---|---|
| ![Tiled layout](assets/screenshots/tiled.png) | ![Monocle with tab bar](assets/screenshots/monocle-tabs.png) |
| **dmenu** | **Scratchpads** |
| ![dmenu](assets/screenshots/dmenu.png) | ![Scratchpads](assets/screenshots/scratchpads.png) |
| **st** | **slock** |
| ![st](assets/screenshots/st.png) | ![slock](assets/screenshots/slock.png) |

---

## What's inside

| Tool | Version | Role | Highlights |
|---|---|---|---|
| [**dwm**](dwm/) | 6.2 | Window manager | Vanity gaps, scratchpads, swallow, tab bar, systray, underline tags, 6 layouts, 6 colour schemes |
| [**st**](st/) | 0.8.2 | Terminal | Ligatures, scrollback, boxdraw, transparency, live Xresources reload, URL open/copy through dmenu |
| [**dmenu**](dmenu/) | 5.0 | Launcher | Stock dmenu, coloured by dwm's active scheme |
| [**slock**](slock/) | 1.4 | Screen locker | Translucent lock screen (blurred by picom), custom message, One Dark colours |
| [**slstatus**](slstatus/) | — | Status bar | Minimal date and time: `[Mon 26]  [03:45]` |

---

## Colour schemes

dwm ships with six schemes in [`dwm/scheme/`](dwm/scheme/). dmenu takes its colours from the active one.

| Scheme | Bar | Text | Selected | Border |
|---|---|---|---|---|
| **monochrome** (default) | ![](https://img.shields.io/badge/%20-151314?style=flat-square) `#151314` | ![](https://img.shields.io/badge/%20-7b797a?style=flat-square) `#7b797a` | ![](https://img.shields.io/badge/%20-a7a5a6?style=flat-square) `#a7a5a6` | ![](https://img.shields.io/badge/%20-4b494a?style=flat-square) `#4b494a` |
| everblush | ![](https://img.shields.io/badge/%20-141B1E?style=flat-square) `#141B1E` | ![](https://img.shields.io/badge/%20-B3B9B8?style=flat-square) `#B3B9B8` | ![](https://img.shields.io/badge/%20-E57474?style=flat-square) `#E57474` | ![](https://img.shields.io/badge/%20-E57474?style=flat-square) `#E57474` |
| gruv | ![](https://img.shields.io/badge/%20-282828?style=flat-square) `#282828` | ![](https://img.shields.io/badge/%20-666666?style=flat-square) `#666666` | ![](https://img.shields.io/badge/%20-EBDBB2?style=flat-square) `#EBDBB2` | ![](https://img.shields.io/badge/%20-A89984?style=flat-square) `#A89984` |
| nord | ![](https://img.shields.io/badge/%20-2e3440?style=flat-square) `#2e3440` | ![](https://img.shields.io/badge/%20-666666?style=flat-square) `#666666` | ![](https://img.shields.io/badge/%20-d8dee9?style=flat-square) `#d8dee9` | ![](https://img.shields.io/badge/%20-88C0D0?style=flat-square) `#88C0D0` |
| onedark | ![](https://img.shields.io/badge/%20-282C34?style=flat-square) `#282C34` | ![](https://img.shields.io/badge/%20-666666?style=flat-square) `#666666` | ![](https://img.shields.io/badge/%20-ABB2BF?style=flat-square) `#ABB2BF` | ![](https://img.shields.io/badge/%20-98C379?style=flat-square) `#98C379` |
| serenade | ![](https://img.shields.io/badge/%20-2a2f33?style=flat-square) `#2a2f33` | ![](https://img.shields.io/badge/%20-5d5c50?style=flat-square) `#5d5c50` | ![](https://img.shields.io/badge/%20-c1bf89?style=flat-square) `#c1bf89` | ![](https://img.shields.io/badge/%20-c1bf89?style=flat-square) `#c1bf89` |

To switch, change the include in `dwm/config.h` and rebuild:

```c
#include "scheme/nord.h"
```

---

## Installation

### 1. Dependencies

**Debian / Ubuntu**

```sh
sudo apt install build-essential pkg-config libx11-dev libx11-xcb-dev libxcb-res0-dev \
  libxft-dev libxinerama-dev libxrandr-dev libxext-dev libxrender-dev \
  libfontconfig-dev libharfbuzz-dev
```

**Arch**

```sh
sudo pacman -S base-devel libx11 libxcb libxft libxinerama libxrandr libxext libxrender \
  fontconfig harfbuzz
```

### 2. Fonts

| Font | Used by |
|---|---|
| [Terminus](https://github.com/fa-saikat/dotfiles/tree/main/local/fonts) | dwm bar, dmenu, st |
| [JetBrainsMono Nerd Font](https://www.nerdfonts.com/font-downloads) | dwm bar (icons) |
| [NotoSansMono Nerd Font](https://www.nerdfonts.com/font-downloads) | dwm bar (fallback) |
| [Iosevka Nerd Font](https://www.nerdfonts.com/font-downloads) | st (fallback glyphs) |

### 3. Build and install

```sh
git clone https://github.com/fa-saikat/suckless-stuff ~/.local/share/suckless-stuff
cd ~/.local/share/suckless-stuff

for tool in dwm st dmenu slock slstatus; do
  (cd "$tool" && sudo make clean install)
done
```

Everything installs to `/usr/local`. dwm also installs a session entry in `/usr/share/xsessions/`, so it shows up in display managers like SDDM, LightDM or GDM.

If you use `startx`, add this to `~/.xinitrc`:

```sh
exec dwm
```

### 4. Autostart

On startup dwm runs `autostart.sh` from the first of these directories that exists:

1. `$SUCKLESS_HOME/dwm`
2. `$XDG_DATA_HOME/suckless-stuff/dwm`
3. `~/.local/share/suckless-stuff/dwm`
4. `~/.dwm`

If you cloned somewhere else, point `SUCKLESS_HOME` at the repo in a file your login shell reads (such as `~/.profile`):

```sh
export SUCKLESS_HOME="$HOME/path/to/suckless-stuff"
```

The bundled [`autostart.sh`](dwm/autostart.sh) starts nitrogen, dunst, sxhkd, slstatus, picom, nm-applet, volumeicon, ibus, qBittorrent and a polkit agent. Remove whatever you don't use.

---

## Configuration

Following the suckless way, there are no runtime config files. Each tool is configured by editing its source and recompiling.

- `config.def.h` holds the defaults shipped with this repo.
- `config.h` is your personal copy. `make` creates it from `config.def.h` the first time, and it is never tracked by git.

```sh
cd dwm
$EDITOR config.h
sudo make clean install
```

Restart dwm in place with `Super + Shift + r`; open windows are kept.

---

## Keybindings

`Super` is the modifier for dwm. The full list is in [dwm/README.md](dwm/README.md#keybindings).

| Key | Action |
|---|---|
| `Super + Return` | Terminal (kitty) |
| `Super + p` | dmenu |
| `Super + w` | Firefox (also toggles the tab bar) |
| `Super + e` | File manager (Dolphin) |
| `Super + q` | Close window |
| `Super + j / k` | Focus next / previous window |
| `Super + Shift + j / k` | Move window down / up the stack |
| `Super + h / l` | Shrink / grow master area |
| `Super + \` | Promote window to master |
| `Super + Space` | Toggle floating |
| `Super + t / f / g / m / c` | Tile / float / grid / monocle / centred master |
| `Super + 1–9` | Switch to tag |
| `Super + Shift + 1–9` | Move window to tag |
| `Super + , / .` | Previous / next tag |
| `Super + Shift + Return` | Scratchpad terminal |
| `Super + v` | Scratchpad volume control |
| `Super + Shift + r` | Restart dwm |
| `Super + Shift + q` | Quit dwm |

st keybindings are in [st/README.md](st/README.md#keybindings).

---

## Repository layout

```
suckless-stuff/
├── dwm/        window manager, schemes in dwm/scheme/, autostart.sh
├── st/         terminal, plus the st-urlhandler and st-copyout scripts
├── dmenu/      launcher
├── slock/      screen locker
├── slstatus/   status bar
└── assets/     screenshots used in this README
```

---

## Credits

- [suckless.org](https://suckless.org) for the original tools.
- [siduck76](https://github.com/siduck76/st), whose st build this one started from.
- [Luke Smith](https://github.com/LukeSmithxyz/st) for the ligatures patch and the `st-urlhandler` / `st-copyout` scripts.
- [khuedoan](https://github.com/khuedoan/slock) for the picom blur approach in slock.
- The authors of the dwm patches listed in [dwm/README.md](dwm/README.md#patches).

## License

Each tool keeps its upstream MIT/X license. See the `LICENSE` file in each directory.
