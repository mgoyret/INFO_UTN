#include "funciones.h"
#include <stdio.h>
#include <dirent.h> 
#include <string.h>

int main()
{
    ESPACIO
    printf("Comienza el programa desde el main");
    ESPACIO
    mostrar_directorios("media");
    printf("\nTermina el programa desde el main\n");
    ESPACIO
    return 0;
}