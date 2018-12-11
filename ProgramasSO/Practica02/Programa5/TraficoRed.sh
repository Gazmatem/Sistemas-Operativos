#!/bin/bash

sudo tcpdump -w TraficoRed.txt -s 0 # escribir el trafico de red
sudo grep -e  com tcpdump -v -i any # Toda interfaz de red buscando una palabradada

grep -i com TraficoRed1.txt # Sirve para saver donde esta la palabra buscada en la linea y fecha de creacion

#$ grep -i patron archivo ,ejemplo grep -i web TraficoRed.txt  -i sin importar mayusculas
# encuentras donde mcoincide y lo imprimes

sudo tcpdump -vv -A | grep -e 'malware.com' # si quieres bucar una pagina dada
