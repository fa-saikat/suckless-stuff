<div align="center">

# slstatus

[slstatus](https://tools.suckless.org/slstatus) feeding a minimal date and time to the dwm bar.

![slstatus](../assets/screenshots/slstatus.png)

</div>

---

## What it shows

```
[Mon 26]  [03:45]
```

Weekday, day of the month and 12-hour time, updated every second. `autostart.sh` starts it with dwm.

---

## Adding more

Each item is a line in the `args` array in `config.h`:

```c
static const struct arg args[] = {
	/* function   format         argument */
	{ cpu_perc,   "[CPU %s%%]  ", NULL },
	{ ram_perc,   "[RAM %s%%]  ", NULL },
	{ datetime,   "%s",           "[%a %d]  [%I:%M]" },
};
```

Rebuild with `sudo make clean install` and restart slstatus.

### Available components

| Component | Shows | Argument |
|---|---|---|
| `battery_perc` / `battery_state` / `battery_remaining` | Battery percentage, charging state, time left | Battery name (`BAT0`) |
| `cpu_perc` / `cpu_freq` | CPU usage, frequency | `NULL` |
| `datetime` | Date and time | `strftime` format |
| `disk_free` / `disk_perc` / `disk_total` / `disk_used` | Disk space | Mount point (`/`) |
| `ram_free` / `ram_perc` / `ram_total` / `ram_used` | Memory | `NULL` |
| `swap_free` / `swap_perc` / `swap_total` / `swap_used` | Swap | `NULL` |
| `temp` | Temperature in °C | Sensor file (`/sys/class/thermal/...`) |
| `netspeed_rx` / `netspeed_tx` | Network speed | Interface (`wlan0`) |
| `ipv4` / `ipv6` | IP address | Interface (`eth0`) |
| `wifi_perc` / `wifi_essid` | Wi-Fi signal, network name | Interface (`wlan0`) |
| `vol_perc` | Volume (OSS/ALSA) | Mixer file (`/dev/mixer`) |
| `keymap` / `keyboard_indicators` | Keyboard layout, Caps/Num Lock | `NULL` / format (`c?n?`) |
| `load_avg` / `uptime` | Load average, uptime | `NULL` |
| `kernel_release` / `hostname` / `username` | System info | `NULL` |
| `num_files` | Files in a directory | Path |
| `run_command` | Output of a shell command | Command |

The full list with notes is at the top of `config.def.h`.

---

## Usage

```sh
slstatus        # write to the dwm bar
slstatus -s     # write to stdout instead
```

---

## Installation

```sh
sudo make clean install
```

Needs the Xlib headers: `libx11-dev` on Debian/Ubuntu, `libx11` on Arch.
