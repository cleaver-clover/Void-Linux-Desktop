#
# ~/.bashrc
#

# If not running interactively, don't do anything
# [[ $- != *i* ]] && return

#---------- PROMPT ----------

# PS1='[\u@\h \W]\$ '
PS1='\u @ \w >> '

#--------- AT LAUNCH --------

#clear & 
#neofetch

#------ CUSTOM SCRIPTS ------

#----------- PATH -----------
export PATH="$PATH:$HOME/.local/bin" # needed for appman
