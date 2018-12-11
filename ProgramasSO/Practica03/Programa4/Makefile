# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.
OBJS= ProcesosKill.o
BYNARY= Programas
CFLAG= -g -Wall
all: Programas

Programas: $(OBJS)
	gcc -o $(BYNARY) $(OBJS)

ProcesosKill.o: ProcesosKill.c
	gcc $(CFLAG) -c ProcesosKill.c

clean:
	rm -f $(BYNARY) $(OBJS)
