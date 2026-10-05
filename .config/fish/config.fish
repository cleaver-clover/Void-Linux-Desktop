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

function start-ai-workspace
	# Setup: Install odysseus (without docker) and ollama
	# Search ollama models at https://ollama.com/library

    # Define the absolute path to your local Odysseus repository
    set -l ODYSSEUS_DIR "$HOME/Documentos/odysseus/"

	echo "Starting local AI stack infrastructure..."

    # Check if the Ollama daemon is already running; if not, initialize it in the background
    if not pgrep -x "ollama" > /dev/null
        echo "Initializing Ollama server process..."
        ollama serve &
    else
        echo "Ollama server process detected. Skipping initialization."
    end

    # Block execution until the Ollama API gateway becomes responsive
    echo "Verifying Ollama API service availability..."
    while not curl -s http://localhost:11434 > /dev/null
        sleep 1
    end
    echo "Ollama API service is operational."

    # Validate the existence of the specified Odysseus directory
    if not test -d $ODYSSEUS_DIR
        echo "Error: Directory $ODYSSEUS_DIR does not exist. Please update the path in the script."
        return 1
    end

    # Navigate to the target directory
    cd $ODYSSEUS_DIR

    # Verify the presence of the virtual environment executable
    if not test -f venv/bin/python
        echo "Error: Python executable not found at venv/bin/python."
        echo "Please ensure your virtual environment is named 'venv' and correctly configured."
        return 1
    end

    # Execute the application server using the virtual environment's specific binary
    echo "Launching Odysseus application server via virtual environment..."
    ./venv/bin/python -m uvicorn app:app --host 127.0.0.1 --port 7000
end


#----------- PATH -----------
export PATH="$PATH:$HOME/.local/bin" # needed for appman
export PATH="$PATH:$HOME/.cago/bin" # needed for cargo (rust)
export PATH="$PATH:/opt/texlive/2026/bin/x86_64-linux" # needed for texlive tlmgr 
