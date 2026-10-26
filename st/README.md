<div align="center">

# st

A patched [st](https://st.suckless.org) 0.8.2 with ligatures, scrollback and live Xresources reload.

![st](../assets/screenshots/st.png)

</div>

---

## Patches

| Patch | What it does |
|---|---|
| Ligatures | Font ligatures through HarfBuzz (`hb.c`) |
| Scrollback | Scroll with the keyboard and mouse wheel |
| Alpha | Background transparency, adjustable while running |
| Boxdraw | Pixel-perfect box and line-drawing characters (`boxdraw.c`) |
| font2 | Fallback font for glyphs missing from the main font |
| Xresources | Read fonts and colours from Xresources |
| Live reload | Reload Xresources with `SIGUSR1`, no restart needed |
| Sync | Synchronised drawing to reduce flicker |
| newterm | Open a new terminal in the current directory |
| Right-click paste | Paste the selection with a right click |
| externalpipe | Open or copy URLs, or copy a command's output, through dmenu |
| Zoom | Change font size on the fly |

---

## Appearance

| Setting | Value |
|---|---|
| Font | Terminus 20px |
| Fallback font | Iosevka Nerd Font 17px |
| Colours | Gruvbox dark |
| Border | 15px |
| Cursor | Underline |
| Opacity | 1.0 (adjustable) |

---

## Keybindings

`Alt` is the modifier.

### Clipboard

| Key | Action |
|---|---|
| `Ctrl + Shift + c` | Copy |
| `Ctrl + Shift + v` | Paste |
| `Shift + Insert` | Paste |
| Right click | Paste selection |

### Scrolling

| Key | Action |
|---|---|
| `Alt + k / j` | Scroll up / down one line |
| `Alt + Up / Down` | Scroll up / down one line |
| `Alt + u / d` | Scroll up / down a page |
| `Shift + Page_Up / Page_Down` | Scroll up / down a page |
| Mouse wheel | Scroll |

### Font size

| Key | Action |
|---|---|
| `Alt + , / .` | Bigger / smaller |
| `Alt + g` | Reset |
| `Super + Shift + k / j` | Bigger / smaller |
| `Super + Shift + u / d` | Much bigger / smaller |
| `Super + mouse wheel` | Bigger / smaller |

### Transparency

| Key | Action |
|---|---|
| `Alt + s` | More transparent |
| `Alt + a` | Less transparent |
| `Alt + m` | Opaque |

### Other

| Key | Action |
|---|---|
| `Alt + l` | Pick a URL on screen with dmenu and open it |
| `Alt + y` | Pick a URL on screen with dmenu and copy it |
| `Alt + o` | Pick a recent command with dmenu and copy its output |
| `Super + Shift + Return` | New terminal in the same directory |

The URL and output pickers need `dmenu` and `xclip`. `make install` installs the `st-urlhandler` and `st-copyout` helper scripts.

---

## Live reload with Xresources

Fonts, colours, border and opacity can be set in an Xresources file and reloaded without restarting st:

```sh
xrdb merge ~/.Xresources && pkill -USR1 -x st
```

A sample file is in [`xresources`](xresources). Supported keys include `st.font`, `st.color0`–`st.color15`, `st.background`, `st.foreground`, `st.borderpx` and `st.alpha`.

---

## Dependencies

**Debian / Ubuntu**

```sh
sudo apt install build-essential pkg-config libx11-dev libxft-dev libharfbuzz-dev
```

**Arch**

```sh
sudo pacman -S base-devel libx11 libxft harfbuzz
```

Runtime: `dmenu` and `xclip` for the URL and output pickers.

---

## Credits

- [siduck76](https://github.com/siduck76/st): the build this one started from.
- [Luke Smith](https://github.com/LukeSmithxyz/st): ligatures patch, `st-urlhandler` and `st-copyout`.
- [nimaipatel](https://github.com/nimaipatel/st): live reload.
