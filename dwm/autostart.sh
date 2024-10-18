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
run "nitrogen --restore"

# ░█▀█░█▀█░▀█▀░▀█▀░█▀▀░▀█▀░█▀▀░█▀█░▀█▀░▀█▀░█▀█░█▀█
# ░█░█░█░█░░█░░░█░░█▀▀░░█░░█░░░█▀█░░█░░░█░░█░█░█░█
# ░▀░▀░▀▀▀░░▀░░▀▀▀░▀░░░▀▀▀░▀▀▀░▀░▀░░▀░░▀▀▀░▀▀▀░▀░▀
# run "/usr/lib/xfce4/notifyd/xfce4-notifyd"
run "dunst"

# ░█▀▀░█░█░█▀▀░▀█▀░█▀▄░█▀█░█░█
# ░▀▀█░░█░░▀▀█░░█░░█▀▄░█▀█░░█░
# ░▀▀▀░░▀░░▀▀▀░░▀░░▀░▀░▀░▀░░▀░
run "slstatus"
run "sxhkd -c $XDG_CONFIG_HOME/sxhkd/sxhkdrc" 
run "picom --config $XDG_CONFIG_HOME/picom/picom.conf"
run "nm-applet"
# run "blueberry-tray"
# run "numlockx on"
# run "pa-applet"
# run "mictray"
# run "redshift -c $XDG_CONFIG_HOME/redshift/redshift.conf"
# run "xfce4-clipman"
# run "cbatticon -u 20 -i standard"
# run "klipper"
run "ibus-daemon -drxR"
# run "udiskie -s"

# ░█▀█░█▀█░█░█░█▀▀░█▀▄
# ░█▀▀░█░█░█▄█░█▀▀░█▀▄
# ░▀░░░▀▀▀░▀░▀░▀▀▀░▀░▀
# run "xfce4-power-manager"

# ░█▀█░█▀█░█░░░█░█░▀█▀░▀█▀
# ░█▀▀░█░█░█░░░█▀▄░░█░░░█░
# ░▀░░░▀▀▀░▀▀▀░▀░▀░▀▀▀░░▀░
run "/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1"
# run "/usr/lib/polkit-kde-authentication-agent-1"

# ░█▀▄░█▀▀░░░▄▀░░░░█▀▀░█▀█░█▀█░█░█░█░█
# ░█▀▄░█░█░░░▄█▀░░░█░░░█░█░█░█░█▀▄░░█░
# ░▀▀░░▀▀▀░░░░▀▀░░░▀▀▀░▀▀▀░▀░▀░▀░▀░░▀░
# run "volumeicon"
# run "conky -c $HOME/.config/dwm/conky/qlock_two.conkyrc"
# run "conky -c $HOME/.local/src/dwm/conky/simple.conkyrc"

### X11 ###
# xrdb -load ~/.config/X11/xresources &


# imwheel -b 45 &
# qbittorrent &
# pkill statusbar.sh
