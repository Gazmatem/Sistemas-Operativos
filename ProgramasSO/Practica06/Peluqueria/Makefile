# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.
OBJS= Peluqueria.o
BYNARY= Programas
CFLAG= -g -Wall
all: Programas

Programas: $(OBJS)
	gcc -o $(BYNARY) $(OBJS)

Peluqueria.o: Peluqueria.c
	gcc $(CFLAG) -c Peluqueria.c

clean:
	rm -f $(BYNARY) $(OBJS)
