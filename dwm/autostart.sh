#!/bin/bash

function run {
 if ! pgrep $1 ;
  then
    $@&
  fi
}

### Resoluiton & Monitor ###
# run "xrandr --output DP2 --right-of eDP1 --auto"


### Statusbar ###
bash ~/.local/src/dwm/bar/statusbar.sh &
# run "slstatus"
# run "numlockx on"
# run "volumeicon"
# run "nm-applet"
# run "blueberry-tray"
# run "klipper"
# ibus-daemon -drxR &


### Notification deamon ###
# run "/usr/lib/xfce4/notifyd/xfce4-notifyd"
run "dunst"


### Power Manager ###
run "xfce4-power-manager"


### Polkit authentication agent ###
# run "/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1"
run "/usr/lib/polkit-kde-authentication-agent-1"


### Wallpapers & Conkies ###
run "nitrogen --restore"
# run "conky -c $HOME/.config/dwm/conky/qlock_two.conkyrc"
# run "conky -c $HOME/.local/src/dwm/conky/simple.conkyrc"


### Compositor ###
picom --experimental-backends --config ~/.config/picom/picom.conf &


### Keybinding ###
sxhkd -c ~/.config/sxhkd/sxhkdrc &


### X11 ###
xrdb -load ~/.config/X11/xresources &


# imwheel -b 45 &
