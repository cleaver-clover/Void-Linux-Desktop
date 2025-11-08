#!/bin/sh

# terminate running instances
pkill waybar

# lauch waybar and disown
waybar & disown -a 
