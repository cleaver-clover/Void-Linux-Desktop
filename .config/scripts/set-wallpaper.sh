#!/bin/sh

wal -n -i $1 
setroot $1
sh $HOME/.config/zathura/zathura-pywal/dirzathurarc 
sh $HOME/.config/dunst/dunst-pywal/dirdunstrc 
killall dunst
dwmc reloadxrdb 

# create wallpaper (rofi power menu)
mkdir -p $HOME/.wallpapers 
wallpaper="$HOME/.wallpapers/current_wallpaper"
blured_wallpaper="$HOME/.wallpapers/blured_wallpaper"

cp $1 $wallpaper
magick $1 -blur 0x8 $blured_wallpaper

dunstify "Novo tema aplicado!!"