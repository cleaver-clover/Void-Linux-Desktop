#!/bin/sh

rofi_command="rofi -demenu -i -theme $HOME/.config/rofi/powermenu.rasi"

### Options ### 
power_off="Shutdown" 
reboot="Reboot" 
lock="Lock" 
suspend="Sleep" 
log_out="Logout"

# Variable passed to rofi 
options="$power_off\n$reboot\n$lock\n$suspend\n$log_out" 

# Idk but in nixos it needs the "-e" and in void it does not
#case "$(echo -e "$options" | $rofi_command -dmenu -selected-row 2)" in
case "$(echo "$options" | $rofi_command -dmenu -selected-row 2)" in   
	$power_off)
		loginctl poweroff
		;;
	$reboot)
		loginctl reboot
		;;
	$lock)
		slock
		;;
	$suspend)
		slock & loginctl suspend
		;;
	$log_out)
		# pkill dwm 
		pkill dwm
		;;
esac
