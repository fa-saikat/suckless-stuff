#!/bin/bash

# *-------------------------------------------------*
# | Project Name    - statusbar.sh
# | Created On      - 03/10/22, 05:42:11 PM
# | Author          - MD Fahim Abrar Saikat
# | Author E-Mail   - saikat.cucse.52@gmail.com
# | Author GitHub   - https://github.com/fa-saikat
# *-------------------------------------------------*

# Load colors
# . $HOME/.local/src/dwm/bar/themes/gruv
# . $HOME/.local/src/dwm/bar/themes/nord
# . $HOME/.local/src/dwm/bar/themes/onedark
. $HOME/.local/src/dwm/bar/themes/serenade

interval=0

BATTERY(){
    status="$(cat /sys/class/power_supply/AC/online)"
    capacity="$(cat /sys/class/power_supply/BAT0/capacity)"

    case $status in
		0)
			if [ "$capacity" -lt 20 ]; then
				echo -e "^c$fg^ "
			elif [ "$capacity" -lt 50 ]; then
				echo -e "^c$fg^ "
			elif [ "$capacity" -lt 80 ]; then
				echo -e "^c$fg^ "
			else
				echo -e "^c$fg^ "
			fi
			;;
		1)
			if [ "$capacity" -gt 85 ]; then
				echo -e "^c$fg^ ^c$green^ "
			else
				echo -e "^c$fg^ ^c$yellow^ "
			fi
			;;
	esac
}

MIC(){
	status="$(cat /sys/class/leds/hda::micmute/brightness)"

	case $status in
		0)
			echo -e "^c$fg^"
			;;
		*)
			echo -e "^c$grey^"
			;;
	esac
}

VOLUME(){
	status="$(cat /sys/class/leds/hda::mute/brightness)"
	level="$(amixer sget Master | grep -o '[0-9]\+' | tail -1)"

	case $status in
		0)
			if [[ "$level" -lt 40 ]]; then
				echo -e "^c$fg^奔"
			elif [[ "$level" -lt 70 ]]; then
				echo -e "^c$fg^墳"
			else
				echo -e "^c$fg^ "
			fi
			;;
		*)
			echo -e "^c$grey^ "
			;;
	esac
}

WIFI(){
	# status="$(cat /sys/class/net/wl*/operstate)"
	status="$(nmcli radio wifi)"
	bssid="$(iwgetid | cut -d \" -f2)"

    case $status in
        enabled)
            if [ -n "$bssid" ]; then
                echo -e "^c$fg^ "
            else
                echo -e "^c$red^ "
            fi
            ;;
        *)
            echo -e "^c$grey^ "
            ;;
    esac
}

DATETIME(){
	date="$(date '+%d')"
	time="$(date '+%I:%M')"

	echo -e "^c$fg^$date $time"
}

SCREEN(){
	level="$(cat /sys/class/backlight/*/brightness)"

	if [[ "$level" -le 50 ]]; then
        echo -e "^c$fg^ "
    elif [[ "$level" -le 120 ]]; then
        echo -e "^c$fg^ "
    else
        echo -e "^c$fg^ "
    fi
}

: '
CPU() {
	load=$(grep -o "^[^ ]*" /proc/loadavg)
}

MEMORY(){
	used="$(free -h | awk '/^Mem/ { print $3 }' | sed s/i//g)"
}
'

while true; do
	[ $interval = 0 ] || [ $(($interval % 3600)) = 0 ]
	interval=$((interval + 1))
 # Load Modules
 sleep 1 && xsetroot -name "$(SCREEN)   $(MIC)   $(VOLUME)   $(WIFI)   $(BATTERY)   $(DATETIME)"
done

