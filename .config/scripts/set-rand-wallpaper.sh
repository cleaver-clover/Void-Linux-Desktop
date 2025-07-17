#!/bin/sh

file=$(find "$HOME/Imagens/Wallpaper_Shuffle/" -type f | shuf -n 1)

wal -n -i $file
setroot $file
sh $HOME/.config/zathura/zathura-pywal/dirzathurarc 
sh $HOME/.config/dunst/dunst-pywal/dirdunstrc 
dwmc reloadxrdb 
pkill dunst

# create wallpaper (rofi power menu)
mkdir -p $HOME/.wallpapers 
wallpaper="$HOME/.wallpapers/current_wallpaper"
blured_wallpaper="$HOME/.wallpapers/blured_wallpaper"

cp $file $wallpaper
magick $file -blur 0x8 $blured_wallpaper

dunstify Sucesso!!