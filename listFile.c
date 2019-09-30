#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <string.h> 


int main(int argc, char **argv)
  

{   printf("tamaño ar: %d valor: %s\n",argc,argv[1] );
    if (argc ==1){  //si no se pasa argumento se imprime lista de archivos  
        DIR *d;
        struct dirent *dir;
        d = opendir(".");
        if (d)
        {
            while ((dir = readdir(d)) != NULL)
            {
                printf("%s\n", dir->d_name);
            }
            closedir(d);
        }
        return 0;

    }
     
    else if(argc == 2 && strcmp(argv[1],"-l") == 0){ // se imprimen los archivos con informacion segun stat()
           
            DIR *d;
            struct dirent *dir;
            d = opendir(".");
            if (d)
            {
                while ((dir = readdir(d)) != NULL)
                {

                    struct stat fileStat; //creamos estructura de tipi stat
                    if(stat(dir->d_name,&fileStat) < 0)    
                        return 1;
                    printf("---------------------------\n");
                    printf("INFORMACION PARA:  %s\n",dir->d_name);
                    printf("---------------------------\n");
                    printf("ID del Usuario Propietario: \t%d\n",fileStat.st_uid);
                    printf("ID del Grupo Propietario: \t%d\n",fileStat.st_uid);
                    printf("Tamaño archivo: \t\t%ld bytes\n",fileStat.st_size);
                    printf("Numero de Links: \t\t%d\n",fileStat.st_nlink);
                    printf("Numero de Bloques Asig: \t%ld\n",fileStat.st_blocks);
                    printf("Archivo node-i: \t\t%ld\n",fileStat.st_ino);
                 
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
                    printf ("Última modificación del archivo:%s\n\n", ctime (& fileStat.st_mtime)); 
                 
                    
                 


            }//fin -l

            }
            closedir(d);
 
    
    
        return(0);
    }


    else if(argc == 3 && (strcmp(argv[1],"-l") == 0)){ //Se abre el directorio pasado como parametro y se listan archivos con su info
            DIR *d;
            struct dirent *dir;
            d = opendir(argv[2]);
            
            if (d == NULL){
                printf("Error: No se puede abrir el directorio. Verifique!\n");
                return 1;
            }
            if (d)
            {
                while ((dir = readdir(d)) != NULL)
                {   
                    char path[80]="";
                    strcat(path,argv[2]);
                    strcat(path, dir->d_name);
                    printf("Path:  %s\n",path);

                    struct stat fileStat; //creamos estructura de tipi stat
                    if(stat(path,&fileStat) < 0)    
                        return 1;
                    printf("---------------------------\n");
                    printf("INFORMACION PARA:  %s\n",dir->d_name);
                    printf("---------------------------\n");
                    printf("ID del Usuario Propietario: \t%d\n",fileStat.st_uid);
                    printf("ID del Grupo Propietario: \t%d\n",fileStat.st_uid);
                    printf("Tamaño archivo: \t\t%ld bytes\n",fileStat.st_size);
                    printf("Numero de Links: \t\t%d\n",fileStat.st_nlink);
                    printf("Numero de Bloques Asig: \t%ld\n",fileStat.st_blocks);
                    printf("Archivo node-i: \t\t%ld\n",fileStat.st_ino);
                 
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
                    printf ("Última modificación del archivo:%s\n\n", ctime (& fileStat.st_mtime)); 
                 
                    
                 


            }//fin -l

            }
            closedir(d);
 
    
    
        return(0);

    }
    else {
        printf("Verifique que los argumentos fueron ingresados correcta\n" );
    }


return (0);
}