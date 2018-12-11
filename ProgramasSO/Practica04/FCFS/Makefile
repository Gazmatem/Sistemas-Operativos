# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.
OBJS= FCFS.o
BYNARY= Programas
CFLAG= -g -Wall
all: Programas

Programas: $(OBJS)
	gcc -o $(BYNARY) $(OBJS)

FCFS.o: FCFS.c
	gcc $(CFLAG) -c FCFS.c

clean:
	rm -f $(BYNARY) $(OBJS)
