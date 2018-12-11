#!/bin/bash
# Generas paticion al sistema para ver procesos en ejecucion
ps -eo pid,etime,args | awk 'substr($2,1,index($2,"-")-1)>1'
