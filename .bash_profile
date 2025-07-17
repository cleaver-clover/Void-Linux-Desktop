# .bash_profile

# Get the aliases and functions
[ -f $HOME/.bashrc ] && . $HOME/.bashrc

# Autologin into WM
if [[ $(tty) == /dev/tty1 ]]; then
	startx
fi
