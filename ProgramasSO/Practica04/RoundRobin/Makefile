# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.
OBJS= RoundRobin.o
BYNARY= Programas
CFLAG= -g -Wall
all: Programas

Programas: $(OBJS)
	gcc -o $(BYNARY) $(OBJS)

RoundRobin.o: RoundRobin.c
	gcc $(CFLAG) -c RoundRobin.c

clean:
	rm -f $(BYNARY) $(OBJS)
