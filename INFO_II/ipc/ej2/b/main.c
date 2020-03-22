/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Mar , 2020
 * \details         Usar MakeFile para compilar y linkear
 */

/*
    Consigna
    A partir de un archivo separado por comas que contiene los siguientes campos: legajo,area,nombre,apellido	
    Recibir por línea de comandos el códidgo del área del empleado (valor entero) y generar un nuevo archivo solo
    con los empleados que corresponden a esa área, con el siguiente formato: Apellido-Nombre,legajo 
    Nota: es importante que la primera letra del nombre y del apellido se garanticen en mayúscula y el resto en minúscula.
*/

#include "functions.h"

int main (int argc, char** argv)
{
    FILE* fp1, fp2;
    char line[TOTAL];

    if(argc == 3)
    {
        fp = fopen(argv[1], "r");
        if(fp != NULL)
        {
            while(!feof(fp))
            {
               /* 4. La ultima vuelta el fgets toma 0 bytes, cuando encuentra el EOF */
               if(fgets(line, TOTAL, fp) > 0)
            }
        }
        else
            printf("ERROR [2]\n");
    }
    else
        printf("ERROR [1]\n./<programa> <archivo>\n\n");

    return 0;
}