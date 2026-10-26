<div align="center">

# slock

A patched [slock](https://tools.suckless.org/slock) 1.4 with a translucent, blurred lock screen and a custom message.

![slock](../assets/screenshots/slock.png)

</div>

---

## Patches

| Patch | What it does |
|---|---|
| Alpha | Translucent lock screen, so the desktop shows through |
| Blur | Blur comes from picom instead of a screenshot run through ImageMagick, so locking is instant |
| Message | Text shown in the middle of the lock screen |

---

## Appearance

| State | Colour |
|---|---|
| Locked | ![](https://img.shields.io/badge/%20-000000?style=flat-square) `#000000` |
| Typing | ![](https://img.shields.io/badge/%20-282c34?style=flat-square) `#282c34` |
| Wrong password | ![](https://img.shields.io/badge/%20-be5046?style=flat-square) `#be5046` |
| Message text | ![](https://img.shields.io/badge/%20-abb2bf?style=flat-square) `#abb2bf` |

- Opacity: `0.8`
- Message: "Enter password to unlock"
- Clearing the input counts as a wrong password (`failonclear = 1`).

---

## Blur

The blur needs a compositor. With picom, enable a blur method in `picom.conf`:

```
blur-method = "dual_kawase";
blur-strength = 5;
```

Without a compositor, slock still works and shows the colours above at full opacity.

---

## Usage

```sh
slock
```

Type your password and press Enter to unlock.

To lock after a period of inactivity, pair it with `xss-lock` or `xautolock`:

```sh
xss-lock -- slock &
```

---

## Installation

slock runs setuid root, so it must be installed with `sudo`:

```sh
sudo make clean install
```

It drops privileges to `nobody:nogroup` after starting. If your distro has no `nogroup` group (Arch uses `nobody`), change `group` in `config.h`.

### Dependencies

**Debian / Ubuntu**

```sh
sudo apt install build-essential libx11-dev libxext-dev libxrandr-dev
```

**Arch**

```sh
sudo pacman -S base-devel libx11 libxext libxrandr
```

---

## Credits

- [khuedoan](https://github.com/khuedoan/slock): picom blur approach.
- The [suckless](https://tools.suckless.org/slock/patches/) slock patches.
