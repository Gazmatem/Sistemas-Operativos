//Imprtas librerias
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

//creas metodo principal
int main () {

  //Creas cadenas para mensaje padre e hijo.
  char padre[]= "I am your father";
  char hijo[]= " ,NOOOOOO!!!!";
  //variables para id de procesos
  pid_t child_pid;
  //Imprimes informacion de proceso.
  printf("Proceso principal id = %d (Padre PID = %d)\n",
  (int) getpid(), (int)  getppid());
  child_pid = fork();
  if (child_pid != 0)
  printf("Padre: proceso hijo id = %d\n", child_pid);
  else
printf("Hijo:  mi processo id = %d\n", (int) getpid());

//concatenacionMensajes("I am your father" , " ,NOOOOOO!!!!");

printf("I am your father, NOOOOOO %d\n",(int) getpid());
//  printf(mensaje, (int) getpid());

  return 0;
}
