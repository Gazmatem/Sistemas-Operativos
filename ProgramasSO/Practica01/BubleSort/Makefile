# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.
OBJS= BubleSort.o
BYNARY= Programas
CFLAG= -g -Wall
all: Programas

Programas: $(OBJS)
	gcc -o $(BYNARY) $(OBJS)

BubleSort.o: BubleSort.c
	gcc $(CFLAG) -c BubleSort.c

clean:
	rm -f $(BYNARY) $(OBJS)
