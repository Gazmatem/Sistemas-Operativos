# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.
OBJS= MatricesMult.o
BYNARY= Programas
CFLAG= -g -Wall
all: Programas

Programas: $(OBJS)
	gcc -o $(BYNARY) $(OBJS)

MatricesMult.o: MatricesMult.c
	gcc $(CFLAG) -c MatricesMult.c

clean:
	rm -f $(BYNARY) $(OBJS)
