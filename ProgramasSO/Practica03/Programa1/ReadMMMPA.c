//Importas librerias necesarias.
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h> /* mmap() se obtiene de esta libreria. */
#include <fcntl.h>


//Funcion para determinar si se pudo leer archivo.
void err_quit(char *msg)
{
    printf(msg);
    return err_quit ("usar: a.out <fromfile> <tofile>");
}

//Creas metodo main principal.
int main (int argc, char *argv[])
{

 //Definies variables para lectura, salida de archivos.
 int fdin, fdout;
 char *src, *dst;
 struct stat statbuf;
 int mode = 0x0777;

 if (argc != 3)
   err_quit ("usar: a.out <fromfile> <tofile>");

 /* Abres archivo de entrada. */
 if ((fdin = open (argv[1], O_RDONLY)) < 0)
   {printf("no se puede crear %s para lectura", argv[1]);
    return 0;
   }

 /* abres y creas archivo de salida. */
 if ((fdout = open (argv[2], O_RDWR | O_CREAT | O_TRUNC, mode )) < 0)
   {printf ("no se puede crear %s para escritura", argv[2]);
   fwrite( argv[2], sizeof(char), sizeof(argv[2]), fdout );
    return 0;
   }

 /* encuentras tamano de archivo de entrada. */
 if (fstat (fdin,&statbuf) < 0)
   {printf ("fstat error");
    return 0;
   }

 /* vas a la localizacion correcta del ultimo byte */
 if (lseek (fdout, statbuf.st_size - 1, SEEK_SET) == -1)
   {printf ("lseek error");
    return 0;
   }

 /* escribes un byte en la ultima localidad */
 if (write (fdout, "", 1) != 1)
   {printf ("escritura error");
     return 0;
   }

 /* mmap el archivo de entrada */
 if ((src = mmap (0, statbuf.st_size, PROT_READ, MAP_SHARED, fdin, 0))
   == (caddr_t) -1)
   {printf ("mmap error para salida");
    return 0;
   }

 /* mmap el archivo de entrada */
 if ((dst = mmap (0, statbuf.st_size, PROT_READ | PROT_WRITE,
   MAP_SHARED, fdout, 0)) == (caddr_t) -1)
   {printf ("mmap error para salida");
    return 0;
   }

 /* copia de archivo de entrada y salida*/
 memcpy (dst, src, statbuf.st_size);
 return 0;

} /* main */
