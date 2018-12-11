//Importas librerias
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//defines variables para entrada y concatenacion
int mide_entrada(char *input);
char concatenate(char [], char []);

   int
   main(int argc, char * argv[])
   {

       //Variables para id de procesos.
       int pipefd[2];
       pid_t cpid;
       char buf;

       //mandas a llamar a la creacion de la tuberia
       pipe(pipefd);
       printf("Invocacion de fork() para tener un hijo \n");
       cpid = fork();
       //Verificacion para saber si es el hijo o el padre.
       if (cpid == 0)
       {
	 printf("Soy proceso hijo\n");
	 char cadena[50] = "Cadena hijo";

   //Escribes y cierras el pipe
	 write(pipefd[1], cadena, mide_entrada(cadena));
   close(pipefd[1]);
   //Se lee el read hasta estar vacia.
   while (read(pipefd[0], &buf, 1) > 0)
	         write(1, &buf, 1);
           write(1, "\n", 1);
           close(pipefd[0]);
           exit(EXIT_SUCCESS);
       }
       else
       {
	 printf("Soy proceso padre \n");

           //En estas lineas cerramos los pipe y mandamos a concatenar los mensajes para despues ser impresos.
           close(pipefd[0]);
           write(pipefd[1], argv[1], mide_entrada(argv[1]));
           close(pipefd[1]);
           wait(NULL); 
           exit(EXIT_SUCCESS);
       }
       return 0;
   }

int mide_entrada(char *input){

    int length = 0;
    while(input[length]!='\0')  //  remove ;
    {
        length++;
    }

    return length;
}
