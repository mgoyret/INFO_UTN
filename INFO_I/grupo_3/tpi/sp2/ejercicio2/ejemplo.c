#include <stdio.h>
#include <stdlib.h>

int Cerrar_Archivo(FILE*);

int main( void )
{
    FILE *archivo;
    archivo = fopen("archivo.txt","w");
    fprintf(archivo,"Hola Mundo");
    Cerrar_Archivo();

    return 0;
}

int Cerrar_Archivo(FILE* archivo)
{
    fclose(archivo);
}