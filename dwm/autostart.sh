#!/bin/bash

function run {
 if ! pgrep $1 ;
  then
    $@&
  fi
}

# ░█▀▄░▀█▀░█▀▀░█▀█░█░░░█▀█░█░█
# ░█░█░░█░░▀▀█░█▀▀░█░░░█▀█░░█░
# ░▀▀░░▀▀▀░▀▀▀░▀░░░▀▀▀░▀░▀░░▀░
# run "xrandr --output DP2 --right-of eDP1 --auto"

# ░█▀▀░█░█░█▀▀░▀█▀░█▀▄░█▀█░█░█
# ░▀▀█░░█░░▀▀█░░█░░█▀▄░█▀█░░█░
# ░▀▀▀░░▀░░▀▀▀░░▀░░▀░▀░▀░▀░░▀░
bash ~/.local/src/dwm/bar/statusbar.sh &
# run "slstatus"
# run "numlockx on"
# run "volumeicon"
run "pa-applet"
run "mictray"
run "nm-applet"
run "blueberry-tray"
run "xfce4-clipman"
# run "cbatticon -u 20 -i standard"
# run "klipper"
ibus-daemon -drxR &

# ░█▀█░█▀█░▀█▀░▀█▀░█▀▀░▀█▀░█▀▀░█▀█░▀█▀░▀█▀░█▀█░█▀█
# ░█░█░█░█░░█░░░█░░█▀▀░░█░░█░░░█▀█░░█░░░█░░█░█░█░█
# ░▀░▀░▀▀▀░░▀░░▀▀▀░▀░░░▀▀▀░▀▀▀░▀░▀░░▀░░▀▀▀░▀▀▀░▀░▀
# run "/usr/lib/xfce4/notifyd/xfce4-notifyd"
run "dunst"

# ░█▀█░█▀█░█░█░█▀▀░█▀▄
# ░█▀▀░█░█░█▄█░█▀▀░█▀▄
# ░▀░░░▀▀▀░▀░▀░▀▀▀░▀░▀
run "xfce4-power-manager"

# ░█▀█░█▀█░█░░░█░█░▀█▀░▀█▀
# ░█▀▀░█░█░█░░░█▀▄░░█░░░█░
# ░▀░░░▀▀▀░▀▀▀░▀░▀░▀▀▀░░▀░
# run "/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1"
run "/usr/lib/polkit-kde-authentication-agent-1"

# ░█▀▄░█▀▀░░░▄▀░░░░█▀▀░█▀█░█▀█░█░█░█░█
# ░█▀▄░█░█░░░▄█▀░░░█░░░█░█░█░█░█▀▄░░█░
# ░▀▀░░▀▀▀░░░░▀▀░░░▀▀▀░▀▀▀░▀░▀░▀░▀░░▀░
run "nitrogen --restore"
# run "conky -c $HOME/.config/dwm/conky/qlock_two.conkyrc"
# run "conky -c $HOME/.local/src/dwm/conky/simple.conkyrc"

# ░█▀▀░█▀█░█▄█░█▀█░█▀█░█▀▀░▀█▀░▀█▀░█▀█░█▀▄
# ░█░░░█░█░█░█░█▀▀░█░█░▀▀█░░█░░░█░░█░█░█▀▄
# ░▀▀▀░▀▀▀░▀░▀░▀░░░▀▀▀░▀▀▀░▀▀▀░░▀░░▀▀▀░▀░▀
picom --experimental-backends --config ~/.config/picom/picom.conf &
#
# ░█░█░█▀▀░█░█░█▀▄░▀█▀░█▀█░█▀▄░▀█▀░█▀█░█▀▀
# ░█▀▄░█▀▀░░█░░█▀▄░░█░░█░█░█░█░░█░░█░█░█░█
# ░▀░▀░▀▀▀░░▀░░▀▀░░▀▀▀░▀░▀░▀▀░░▀▀▀░▀░▀░▀▀▀
sxhkd -c ~/.config/sxhkd/sxhkdrc &


### X11 ###
# xrdb -load ~/.config/X11/xresources &


# imwheel -b 45 &
# qbittorrent &
