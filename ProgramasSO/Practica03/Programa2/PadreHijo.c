//Importas librerias necesarias.
#include  <stdio.h>
#include  <sys/types.h>

//defines el maximo numero posible.
#define   MAX_COUNT  200

void  ChildProcess(void);                /* prototipo proceso hijo */
void  ParentProcess(void);               /* prototipo proceso padre */

//funcion principal.
void  main(void)
{
    //Defines el id de nuestro proceso originar
     pid_t  pid;

     //creas proceso hijo
     pid = fork();
     ChildProcess();
     ParentProcess();
}

//Funcion para imprimir los procesos hijos una cantidad MAX_COUNT
void  ChildProcess(void)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf(" Esta linea es para los hijos, valor = %d\n", i);
     printf("   *** Proceso hijo esta terminado ***\n");
}

//metodo para imprimir los procesos padres.
void  ParentProcess(void)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("Esta linea es para el padre, valor = %d\n", i);
     printf("*** Proceso padre terminado ***\n");
}
