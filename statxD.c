#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
 
/*IMPLEMENTACION DEL COMANDO STAT() 
    POR: GILBERTO RENDÓN */

int main(int argc, char **argv)
{
    if(argc != 2) // se debe pasar como argumento path del archivo o directorio 
        return 1;
 
    struct stat fileStat; //creamos estructura de tipi stat
    if(stat(argv[1],&fileStat) < 0)    
        return 1;
 
    printf("Informacion para %s\n",argv[1]);
    printf("---------------------------\n");
    //printf("Tipo y modo de archivo: \t%s\n",fileStat.st_mode);
    printf("Tamaño archivo: \t\t%li bytes\n",fileStat.st_size);
    printf("Numero de Links: \t\t%i\n",fileStat.st_nlink);
    printf("Numero de Bloques Asig: \t%li\n",fileStat.st_blocks);
    printf("Archivo node-i: \t\t%li\n",fileStat.st_ino);
 
    printf("Permisos del Archivo: \t\t");
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");

    printf ("Último cambio de estado:%s", ctime (& fileStat.st_ctime)); 
    printf ("Último acceso al archivo:%s", ctime (& fileStat.st_atime)); 
    printf ("Última modificación del archivo:%s", ctime (& fileStat.st_mtime)); 
 
    printf("\nEl archivo %s un  link simbolico\n", (S_ISLNK(fileStat.st_mode)) ? "es" : "No es");
 
    return 0;
}