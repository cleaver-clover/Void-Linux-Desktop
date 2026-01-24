set fish_greeting

#---------- PROMPT ----------

function fish_prompt
    echo -n (whoami) " @ " (prompt_pwd) " >> "
end

#--------- AT LAUNCH --------

clear & 
fastfetch

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

function gcode-alias
    # Check if at least the filename is provided
    if test (count $argv) -lt 1
        echo "Usage: svg2gcode_alias <my-svg.svg> <dimension>"
        echo "Example: gcode-alias drawing.svg 500mm"
        return 1
    end

    set input_file $argv[1]
    
    # Set dimension to second argument, or default to '360mm' if not provided
    set dimension "360mm"
    if test (count $argv) -ge 2
        set dimension $argv[2]
    end

    # Ensure the dimension ends with a comma
    if not string match -q "*," "$dimension"
        set dimension "$dimension,"
    end

    # Generate output filename by stripping .svg and adding .gcode
    set output_file (string replace -r '\.svg$' '' "$input_file").gcode

    echo "Converting $input_file to $output_file"
    
    svg2gcode "$input_file" \
        --off 'G01 Z4 F5000' \
        --on 'G01 Z0 F5000' \
        --feedrate 2500 \
        --dimensions "$dimension" \
		--end "G0 X0 Y0" \
        -o "$output_file"
end

#----------- PATH -----------
export PATH="$PATH:$HOME/.local/bin" # needed for appman
export PATH="$PATH:$HOME/.cago/bin" # needed for cargo (rust) 
