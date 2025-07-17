set fish_greeting

#---------- PROMPT ----------

function fish_prompt
    echo -n (whoami) " @ " (prompt_pwd) " >> "
end

#--------- AT LAUNCH --------

clear & 
neofetch

#------ CUSTOM SCRIPTS ------

function upgrade-system
    echo "---- Upgrading void ----"
    sudo xbps-install -Su &&
    echo "---- Upgrading nix ----" 
    nix-channel --update &&
    nix-env -u 
    #flatpak missing
end

#----------- PATH -----------
export PATH="$PATH:$HOME/.local/bin"
