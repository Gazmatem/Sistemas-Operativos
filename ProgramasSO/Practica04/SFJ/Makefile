# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.
OBJS= SJF.o
BYNARY= Programas
CFLAG= -g -Wall
all: Programas

Programas: $(OBJS)
	gcc -o $(BYNARY) $(OBJS)

2K38Y.o: SJF.c
	gcc $(CFLAG) -c SJF.c

clean:
	rm -f $(BYNARY) $(OBJS)
