#!/bin/bash

case "$XDG_CURRENT_DESKTOP" in
    "dwm")

	wal -n -i $1 
	setroot $1
	sh $HOME/.config/zathura/zathura-pywal/dirzathurarc 
	sh $HOME/.config/dunst/dunst-pywal/dirdunstrc 
	pkill dunst
	dwmc reloadxrdb 

	# create wallpaper (rofi power menu)
	mkdir -p $HOME/.wallpapers 
	wallpaper="$HOME/.wallpapers/current_wallpaper"
	blured_wallpaper="$HOME/.wallpapers/blured_wallpaper"

	cp $1 $wallpaper
	magick $1 -blur 0x8 $blured_wallpaper

	notify-send -i ~/.wallpapers/current_wallpaper "Novo tema aplicado!" "Novo tema aplicado no dwm"
	;;
    "niri")    
	
	wal -n -i $1

	sh $HOME/.config/zathura/zathura-pywal/dirzathurarc 
	sh $HOME/.config/dunst/dunst-pywal/dirdunstrc
	sh $HOME/.config/niri/niri-pywal/dirniriconfig
	sh $HOME/.config/swaylock/swaylock-pywal/dirconfig
	pkill dunst

	# create wallpaper (rofi power menu)
	mkdir -p $HOME/.wallpapers 
	wallpaper="$HOME/.wallpapers/current_wallpaper"
	blured_wallpaper="$HOME/.wallpapers/blured_wallpaper"

	cp $1 $wallpaper
	magick $1 -blur 0x8 $blured_wallpaper

	swww img ~/.wallpapers/current_wallpaper --transition-fps 60 --transition-type any
	sh $HOME/.config/waybar/launch.sh

	notify-send -i ~/.wallpapers/current_wallpaper "Novo tema aplicado!" "Novo tema aplicado no niri wm!"
	;;
    *)
	notify-send "Aviso!" "Este WM não está configurado."
	;;
esac
    
