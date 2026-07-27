#!/bin/bash

# Verifica qual o processo ativo
if pgrep -x "niri" > /dev/null; then
    SESSION="niri"
elif pgrep -x "dwm" > /dev/null; then
    SESSION="dwm"
else
    SESSION="unknown"
fi

case "$SESSION" in
    "dwm")
        wal -n -i "$1" 
        setroot "$1"
        sh "$HOME/.config/zathura/zathura-pywal/dirzathurarc" 
        sh "$HOME/.config/dunst/dunst-pywal/dirdunstrc" 
        pkill dunst
        dwmc reloadxrdb 

        # create wallpaper
        mkdir -p "$HOME/.wallpapers" 
        wallpaper="$HOME/.wallpapers/current_wallpaper"
        blured_wallpaper="$HOME/.wallpapers/blured_wallpaper"

        cp "$1" "$wallpaper"
        magick "$1" -blur 0x8 "$blured_wallpaper"

        notify-send -i "$wallpaper" "Novo tema aplicado!" "Novo tema aplicado no dwm"
        ;;

    "niri")    
        wal -n -i "$1"

        sh "$HOME/.config/zathura/zathura-pywal/dirzathurarc" 
        #sh "$HOME/.config/dunst/dunst-pywal/dirdunstrc"
        sh "$HOME/.config/niri/niri-noctalia/dirniriconfig"
        #sh "$HOME/.config/swaylock/swaylock-pywal/dirconfig"
        #sh "$HOME/.config/waybar/launch.sh"
        #pkill dunst

        # create wallpaper
        mkdir -p "$HOME/.wallpapers" 
        wallpaper="$HOME/.wallpapers/current_wallpaper"
        blured_wallpaper="$HOME/.wallpapers/blured_wallpaper"

        cp "$1" "$wallpaper"
        #magick "$1" -blur 0x8 "$blured_wallpaper"

        #swww img "$wallpaper" --transition-fps 60 --transition-type any

        notify-send -i "$wallpaper" "Novo tema aplicado!" "Novo tema aplicado no niri wm!"	
        ;;

    *)
        notify-send "Aviso!" "Nenhum WM compatível (niri/dwm) detetado em execução."
        ;;
esac
