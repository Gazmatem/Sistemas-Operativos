# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.
OBJS= 2K38Y.o
BYNARY= Programas
CFLAG= -g -Wall
all: Programas

Programas: $(OBJS)
	gcc -o $(BYNARY) $(OBJS)

2K38Y.o: 2K38Y.c
	gcc $(CFLAG) -c 2K38Y.c

clean:
	rm -f $(BYNARY) $(OBJS)
