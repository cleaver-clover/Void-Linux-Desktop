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
    echo "---- Upgrading flatpak ----" 
    flatpak update
    echo "---- Upgrading appmanager ----" 
    appman -u
end


function clean-system
    echo "---- cleaning void ----"
    sudo xbps-remove -o &&
    echo "---- Upgrading flatpak ----" 
    flatpak uninstall --unused
    echo "---- Upgrading appmanager ----" 
    appman -c
end


#----------- PATH -----------
export PATH="$PATH:$HOME/.local/bin" # needed for appman
