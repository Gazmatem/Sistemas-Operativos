#!/bin/bash
#Buscas la informacion sobre archios en uso de la direccion  modify /var/log y los imprimes en pantalla.
inotifywait -r -m -e modify /var/log |
   while read path _ file; do
       echo $path$file modified
   done
