#!/bin/bash

sort file.txt

printf "%s\n" "Otra ordenacion"

sort file.txt > output.txt
sort -o output.txt file.txt
cat output.txt
