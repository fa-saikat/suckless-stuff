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
# run "xrandr --output DisplayPort-0 --mode 1920x1080 --pos 1920x0 --rotate right --set TearFree on --output HDMI-A-0 --mode 1920x1080 --primary --pos 0x0 --rotate normal --set TearFree on --rate 100 --output DisplayPort-1 --off --output DisplayPort-2 --off"
# run "xrandr --output DisplayPort-0 --mode 1920x1080 --pos 1920x0 --rotate right --output HDMI-A-0 --primary --mode 1920x1080 --pos 0x957 --rotate normal --output DisplayPort-1 --off --output DisplayPort-2 --off"

# ░█▀█░█▀█░▀█▀░▀█▀░█▀▀░▀█▀░█▀▀░█▀█░▀█▀░▀█▀░█▀█░█▀█
# ░█░█░█░█░░█░░░█░░█▀▀░░█░░█░░░█▀█░░█░░░█░░█░█░█░█
# ░▀░▀░▀▀▀░░▀░░▀▀▀░▀░░░▀▀▀░▀▀▀░▀░▀░░▀░░▀▀▀░▀▀▀░▀░▀
# run "/usr/lib/xfce4/notifyd/xfce4-notifyd"
run "dunst"

# ░█▀▀░█░█░█▀▀░▀█▀░█▀▄░█▀█░█░█
# ░▀▀█░░█░░▀▀█░░█░░█▀▄░█▀█░░█░
# ░▀▀▀░░▀░░▀▀▀░░▀░░▀░▀░▀░▀░░▀░
run "sxhkd" 
run "slstatus"
run "picom"
run "nm-applet"
run "volumeicon"
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
# run "barrier"

# ░█▀█░█▀█░█░█░█▀▀░█▀▄
# ░█▀▀░█░█░█▄█░█▀▀░█▀▄
# ░▀░░░▀▀▀░▀░▀░▀▀▀░▀░▀
# run "xfce4-power-manager"

# ░█▀█░█▀█░█░░░█░█░▀█▀░▀█▀
# ░█▀▀░█░█░█░░░█▀▄░░█░░░█░
# ░▀░░░▀▀▀░▀▀▀░▀░▀░▀▀▀░░▀░
run "/usr/lib/policykit-1-gnome/polkit-gnome-authentication-agent-1"
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
run "qbittorrent" 
# pkill statusbar.sh
# run "virt-manager"
# run "vncviewer -PasswordFile $HOME/.vnc/sangu sangu:5902"
# run "antimicrox --tray"
