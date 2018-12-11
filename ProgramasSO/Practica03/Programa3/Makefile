# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.
OBJS= Tuberias.o Pipe.o
BYNARY= Programas
CFLAG= -g -Wall
all: Programas

Programas: $(OBJS)
	gcc -o $(BYNARY) $(OBJS)

Tuberias.o: Tuberias.c
	gcc $(CFLAG) -c Tuberias.c

Pipe.o: Pipe.c
	gcc $(CFLAG) -c Pipe.c

clean:
	rm -f $(BYNARY) $(OBJS)
