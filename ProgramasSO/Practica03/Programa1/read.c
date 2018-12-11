/*
Ejemplo de lectura con Read()
 */

 //Importamos librerias necesarias.
#define _POSIX_SOURCE
#include <fcntl.h>
#include <unistd.h>
#undef _POSIX_SOURCE
#include <stdio.h>

// Definimos metodo main
main() {

  //definimos las variables donde leeremos, y guardaremos archivo.
  int ret, fd;
  char buf[1024];

  //llamada al sistema para leer archivo mediante "ls"
  system("ls -l / >| ls.output");

  //Verificacion de que se pudo abrir el archivo con el manejador de archivos fd.
  if ((fd = open("ls.output", O_RDONLY)) < 0)
    perror("open() error");
  else {
    while ((ret = read(fd, buf, sizeof(buf)-1)) > 0) {
      buf[ret] = 0x00;
      printf("block read: \n<%s>\n", buf);
    }
    close(fd); //cierras el manejador de archivos.
  }

  //mandas a imprimir archivos.
  printf("El descriptor de Archivos es: %d\n", fd);
  unlink("ls.output");
}
