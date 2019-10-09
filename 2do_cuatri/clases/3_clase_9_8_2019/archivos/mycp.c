/**
 * funcion cp
**/

#include <stdio.h>

int main (int argc, char **argv)
{
    FILE *destino, *origen;
    char aux;

    if(argc == 3)
    {
        origen = fopen("argv[1]", "r");
        destino = fopen("argv[2]", "w");    // "w" si no existe crea el archivo, y si existe lo sobreescribe

        if ((origen != NULL) && (destino != NULL))
        {
            while (feof(origen) == 0)
            {
                aux = fgetc(origen);
                fprintf(destino, "%c", aux);
            }
            fclose(origen);
            fclose(destino);
        }
        else
        {
            printf("Error al abrir archivos\n");
        }
    }
    else
    {
        printf("Cantidad de argumentos invalida\n");
    }

    return 0;
}