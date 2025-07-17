#!/bin/sh

# Defina o limite de bateria baixa (exemplo: 20%).
threshold=20
charched=95

# Variáveis para armazenar o último estado e porcentagem.
last_status=""
last_percentage=""

while true; do
    # Obter as informações da bateria
    battery_info=$(acpi -b | sed -n '2p') # remover "-n" no hyprland em "sed -n '2p'

    # Extrair o status da bateria (Charging ou Discharging)
    battery_status=$(echo "$battery_info" | awk '{print $3}' | sed 's/,$//') 
    
    # Extrair a porcentagem da bateria
    battery_percentage=$(echo "$battery_info" | grep -oP '\d+(?=%)')

    # Extrair o tempo restante de carga, se aplicável
    #time_remaining=$(echo "$battery_info" | sed 's/.*, \(.*\) remaining/\1/')

    # Verificar se o estado da bateria mudou (de Charging para Discharging ou vice-versa)
    if [ "$battery_status" != "$last_status" ]; then
        #~/.config/waybar/launch.sh
        if [ "$battery_status" = "Charging" ]; then
            dunstify "Aviso de Bateria" "A carregar. \nNível da bateria: ${battery_percentage}%"
        elif [ "$battery_status" = "Discharging" ]; then
            dunstify "Aviso de Bateria" "A descarregar. \nNível da bateria: ${battery_percentage}%"
        fi
    fi

    # Verificar se a bateria está a baixo ou igual a 20%
    if [ "$battery_percentage" -le "$threshold" ] && [ "$battery_percentage" != "$last_percentage" ] && [ "$battery_status" = "Discharging" ]; then
        dunstify "Bateria Baixa" "Nível da bateria: ${battery_percentage}%" 
    fi

    # Alertar quando está carregada
    if [ "$battery_percentage" -gt "$charched" ] && [ "$battery_percentage" != "$last_percentage" ] && [ "$battery_status" = "Charging" ]; then
        dunstify "Bateria Carregada" "Nível da bateria: ${battery_percentage}%" 
    fi

    # Atualizar as variáveis de status e porcentagem
    last_status="$battery_status"
    last_percentage="$battery_percentage"

    # Esperar 1 minuto antes de verificar novamente
    sleep 1s
done &
