#!/usr/bin/fish

# -- lauch zed on wayland --
# execute this file on the ' ~/.local/share/applications/zed-AM.desktop': 
# Exec=fish /home/<user>/.config/scripts/launch-zed.sh 

set -e WAYLAND_DISPLAY & zed 
