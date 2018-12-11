# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.
OBJS= CodigoporProceso.o PadreHijo.o
BYNARY= Programas
CFLAG= -g -Wall
all: Programas

Programas: $(OBJS)
	gcc -o $(BYNARY) $(OBJS)

CodigoporProceso.o: CodigoporProceso.c
	gcc $(CFLAG) -c CodigoporProceso.c

PadreHijo.o: PadreHijo.c
	gcc $(CFLAG) -c PadreHijo.c

clean:
	rm -f $(BYNARY) $(OBJS)
