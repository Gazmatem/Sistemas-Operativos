#!/usr/bin/python

#IMportamos librerias necdsarias para crear el servidor
import socket
import cPickle
import os
import sys
import signal
PORT = 54321 # Asignamos un puerto aleatorio.
def handle( cs , addr ): # Definimos funcion para creacion de servidor
	print "Conexion desde",addr # Imprimimos si ip
	cs.sendall("HOLA\n")
	try:
		l = cPickle.loads (cs.recv (1024))
		s = sum (l)
		cs.sendall("%d\n" % s)
		#Imprimimos si fue exitosa la conexion.
	except :
		# Imprimimos mensaje de que nos fue correcta la conexion.
		cs.sendall("MAL!!!:(\n")
	cs.sendall("ADIOS\n")
	cs.close()
# abrimos un socket para general la conexion con el puerto definido anteriormente en caso de ser
# exitosa la conexion.
signal.signal(signal.SIGCHLD, signal.SIG_IGN)
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(("0.0.0.0", PORT))
s.listen(100)
while 1:
	(cs,addr) = s.accept()
	pid = os.fork()
	if pid==0:
		s.close ()
		handle(cs,addr)
	sys.exit(0)
cs.close()
