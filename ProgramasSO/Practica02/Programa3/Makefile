# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.
OBJS= aver.o monitoreo.sh Procesos.sh
BYNARY= Programas
CFLAG= -g -Wall
all: Programas

Programas: $(OBJS)
	gcc -o $(BYNARY) $(OBJS)

aver.o: aver.sh
	cmd +x $(CFLAG) aver.sh

monitoreo.o: monitoreo.sh
	cmd +x $(CFLAG) monitoreo.sh

Procesos.o: Procesos.sh
	cmd +x $(CFLAG) Procesos.sh

clean:
	rm -f $(BYNARY) $(OBJS)
