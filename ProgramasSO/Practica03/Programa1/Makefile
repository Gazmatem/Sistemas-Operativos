# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.
OBJS= read.o readMMMPA.o
BYNARY= Programas
CFLAG= -g -Wall
all: Programas

Programas: $(OBJS)
	gcc -o $(BYNARY) $(OBJS)

read.o: read.c
	gcc $(CFLAG) -c read.c

readMMMPA.o: readMMMPA.c
	gcc $(CFLAG) -c readMMMPA.c

clean:
	rm -f $(BYNARY) $(OBJS)
