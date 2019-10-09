/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Aug 26, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include <stdio.h>
#include <string.h>
#include "functions.h"

int main(int argc, char** argv)
{
    FILE *fp;
    char line[100], line2[100];

    if(argc == 2)
    {
        fp = fopen(argv[1], "a+");
        if(fp != NULL)
        {
            while (feof(fp) == 0)
            {
                leer_linea(fp, line);
                if(feof(fp)==0)printf("Linea leida:    %s\n", line);
            }
            strcpy(line2, "Prueba TP8. Escritura en linea nueva");
            escribir_linea(fp, line2);
            fclose(fp);
        }
        else
        {
            printf("error al abrir archivo\n");
        }
    }
    else
    {
        printf("Cantidad de argumentos erronea\n");
    }
    return 0;
}