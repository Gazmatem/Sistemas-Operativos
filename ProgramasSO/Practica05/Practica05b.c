#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>


int main(int argc, char** argv){

char *filename= argv[1];
struct stat archivo;
if(stat(filename,&archivo) != -1){

//Permisos, id del propietario, fecha de creación, fecha de modificación.
    printf("Permisos de %s: ", filename );
    printf( (S_ISDIR(archivo.st_mode)) ? "d" : "-");
    printf( (archivo.st_mode & S_IRUSR) ? "r" : "-");
    printf( (archivo.st_mode & S_IWUSR) ? "w" : "-");
    printf( (archivo.st_mode & S_IXUSR) ? "x" : "-");
    printf( (archivo.st_mode & S_IRGRP) ? "r" : "-");
    printf( (archivo.st_mode & S_IWGRP) ? "w" : "-");
    printf( (archivo.st_mode & S_IXGRP) ? "x" : "-");
    printf( (archivo.st_mode & S_IROTH) ? "r" : "-");
    printf( (archivo.st_mode & S_IWOTH) ? "w" : "-");
    printf( (archivo.st_mode & S_IXOTH) ? "x" : "-");
    printf("\nEl id del propietario de %s es: %d  \n",filename,archivo.st_uid);
    printf("Fecha de modificación de %s: %s",filename, ctime(&archivo.st_mtime));
    printf("Fecha de creación de %s: %s ",filename, ctime(&archivo.st_ctime));
    printf("\n");
		
}

}

