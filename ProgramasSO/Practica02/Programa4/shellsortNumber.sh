#!/bin/bash
# ordenas los numeros del archivo fileNumber.txt
sort -n fileNumber.txt

# Pedimos al usuario introducir numeros en terminal, y luego se ordenan dichos valores.
IFS=' ' read -ra arr -p "Introduzca numero: "
# Imprimimos valores en terminal
sort -n <(printf "%s\n" "${arr[@]}")
