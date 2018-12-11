# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.
OBJS= readKeys.o
BYNARY= Programas
CFLAG= -g -Wall
LDFLAGS=include <linux/input.h>

all: Programas

Programas: $(OBJS)
	gcc -o $(BYNARY) $(OBJS)

readKeys.o: readKeys.c
	gcc $(CFLAG) -c readKeys.c

clean:
	rm -f $(BYNARY) $(OBJS)
