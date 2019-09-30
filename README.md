# Files and Directories #

En esta tarea, nos familiarizaremos con el API descrito en el capítulo del libro. Para hacer esto, usted solo debe escribir unos cuantos programas, la mayoría basados en varias utilidades UNIX.

## Questions ##

1. **Stat**: Escriba su propia versión del comando ```stat```, la cual simplemente invoca la llamada del sistema ```stat()``` en un archivo o directorio. Imprima el tamaño del archivo, el número de bloques asignado, contador de referencias (links), etc. ¿Qué significa el contador de referencias (link count) de un directorio?, ¿cómo cambia el número de entradas en el directorio? Interfaces útiles: ```stat()```, naturalmente.

Este contador de referencias es en realidad el recuento de enlaces del archivo, cuando se refiere a un archivo, o el número de entradas de directorio contenidas, cuando se refiere a un directorio. En ambos casos los lugares desde donde se usa el mismo archivo o directorio. El número de entradas no cambia debido a que no se ha copiado ni linkeado el archivo en ningún momento.

![enlace](https://raw.githubusercontent.com/gilbertrendon/files-directories/master/Pantallazos/1.png)

2. **List Files**: Escriba un programa que liste los archivos en un directorio dado. Cuando sea llamado sin argumentos, el programa deberá imprimir solo los nombres del archivo. Cuando se invoque con la flag ```-l```, el programa deberá imprimir la información de cada archivo tal como, owner, group, permissions y otra información obtenida de la llamada de sistema ```stat()```. El programa deberá tomar un argumento adicional el cual es el directorio a leer, por ejemplo, ```myls -l directory```.  Si ningún directorio es dado, el programa deberá usar el directorio de trabajo actual. Interfaces útiles: ```stat()```, ```opendir()```, ```readdir()```, ```getcwd()```.

![enlace](https://raw.githubusercontent.com/gilbertrendon/files-directories/master/Pantallazos/2.png)


3. **Tail**: Escriba un programa que imprima una cuantas líneas al final de un archivo. El programa deberá ser eficiente, de manera que realice un *seek* para desplazarse cerca del final del archivo, realice una lectura de un bloque de datos y luego retroceda hasta encontrar el número de líneas solicitado; hasta este punto, el programa debería imprimir esas lineas desde el principio al final del archivo. Para invocar el programa, uno deberia digitar: ```mytail -n file```, donde ```n``` es el número de lineas al final del archivo a imprimir. Interfaces Útiles: ```stat()```, ```lseek()```, ```open()```, ```read()```, ```close()```.

![enlace](https://raw.githubusercontent.com/gilbertrendon/files-directories/master/Pantallazos/3.png)


4. **Recursive Search**: Escriba un programa que imprima los nombres de cada archivo y directorio del árbol del sistema de archivos (*file system tree*), empezando en un punto dado del sistema de archivos en el árbol. Por ejemplo, cuando ejecute sin argumentos, el programa deberá empezar con el directorio de trabajo actual e imprimir su contenido, así como con los contenidos de cualquier subdirectorio en este, etc., hasta que el árbol entero, root en el CWD sea impreso. Si se da un único argumento (de un nombre de un directorio), use este como root en vez de él del sistema. Refine su busqueda recursiva con más opciones de busqueda divertidas, similar a la poderosa herramienta por línea de comandos ```find```. Interfaces Útiles: Resolverlo.


## Referencias de utilidad ##

1. [Conceptos básicos claves resumidos](https://docs.google.com/document/d/1-336S7oKYwzSSSH-vzks8lGJ0R5VJoZu3PGBsz3vP2w/edit?usp=sharing)
2. [Aspectos básicos de C](https://github.com/repos-SO-UdeA/lab3)
3. [Manejo dinámico de memoria en C](https://github.com/repos-SO-UdeA/lab5)
4. [Manejo de archivos en C](https://github.com/repos-SO-UdeA/lab6)

Notas: Stat - > display file or file system status
https://www.google.com/search?q=stat+en+linux+para+que+sirve&oq=stat+en+linux+para+que+sirve&aqs=chrome..69i57j33l5.6335j0j7&sourceid=chrome&ie=UTF-8

