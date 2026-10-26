<div align="center">

# dmenu

Stock [dmenu](https://tools.suckless.org/dmenu) 5.0, styled by dwm.

![dmenu](../assets/screenshots/dmenu.png)

</div>

---

## How it's used

dwm opens dmenu with `Super + p` as a vertical list of 10 items. Its font and colours come from dwm, not from dmenu's own config:

| Setting | Source |
|---|---|
| Font | `dmenu_font` in `dwm/config.h` (Terminus 10) |
| Colours | `dmenu_bg`, `dmenu_fg`, `dmenu_sbg`, `dmenu_sfg` in the active `dwm/scheme/*.h` |

Changing the dwm colour scheme recolours dmenu too.

st also uses dmenu to pick URLs (`Alt + l`, `Alt + y`) and command output (`Alt + o`).

---

## Keys

| Key | Action |
|---|---|
| `Enter` | Run the selected item |
| `Shift + Enter` | Run exactly what was typed |
| `Tab` | Complete the selected item |
| `Up / Down` or `Ctrl + p / n` | Previous / next item |
| `Ctrl + u` | Delete to the start of the line |
| `Ctrl + w` | Delete the previous word |
| `Escape` | Close |

---

## Standalone use

dmenu reads choices from stdin and prints the one you pick:

```sh
printf 'shutdown\nreboot\nlogout\n' | dmenu -l 3 -p 'Power:'
```

| Option | Effect |
|---|---|
| `-l <n>` | Vertical list with n lines |
| `-p <text>` | Prompt to the left of the input |
| `-i` | Case-insensitive matching |
| `-b` | Show at the bottom of the screen |
| `-fn <font>` | Font |
| `-nb / -nf / -sb / -sf <colour>` | Normal and selected background / foreground |

`dmenu_run` lists every program in `$PATH`.

---

## Installation

```sh
sudo make clean install
```

**Debian / Ubuntu:** `sudo apt install build-essential libx11-dev libxft-dev libxinerama-dev`

**Arch:** `sudo pacman -S base-devel libx11 libxft libxinerama`
