
// C programa para implementar sighup(), sigint()
// y sigquit() signal funcion.
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// Declaramos las funciones.
void sighup();
void sigint();
void sigquit();

// Codigo principal
void main()
{
    int pid;

    /* Obtienes proceso hijo */
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) { /* hijo */
        signal(SIGHUP, sighup);
        signal(SIGINT, sigint);
        signal(SIGQUIT, sigquit);
        for (;;)
            ; /* repites un ciclo infinito para que siempre este a la escucha */
    }

    else /* Padre */
    { /* mantienes el id de hijo */
        printf("\nPedre: enviando SIGHUP\n\n");
        sighup();
        sigint();
        kill(pid, SIGHUP);

        sleep(3); /* Duermes por 3 segundos */
        printf("\nPedre: enviando SIGINT\n\n");
        sighup();
        sigint();
        kill(pid, SIGINT);

        sleep(3); /* Duermes por 3 segundos */
        printf("\nPedre: enviando SIGQUIT\n\n");
        sighup();
        sigint();
        sigquit();
        kill(pid, SIGQUIT);
        sleep(3);
    }
}

// sighup() definicion de funcion
void sighup()

{
    signal(SIGHUP, sighup); /* Restauras la senal */
    printf("Hijo ha recivido la senal SIGHUP\n");
}

// sigint() Defines la funcion
void sigint()

{
    signal(SIGINT, sigint); /* Restauras la senal */
    printf("Hijo ha recivido la senal SIGINT\n");
}

// sigquit() definicion de la funcion
void sigquit()
{
    printf("Padre mato proceso hijo\n");
    exit(0);
}
