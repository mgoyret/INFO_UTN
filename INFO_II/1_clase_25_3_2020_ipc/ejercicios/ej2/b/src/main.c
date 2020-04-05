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

#include "../inc/functions.h"

int main (int argc, char** argv)
{
    FILE *fp1, *fp2;
    char line[TOTAL];
    int exit = 0, cnt = 0;

    if(argc == 4)
    {
        fp1 = fopen(argv[1], "r");
        if(fp1 != NULL)
        {
            fp2 = fopen(argv[3], "w");
            if(fp2 != NULL)
            {
                while(!feof(fp1))
                {
                    /* 1. Leo el archivo funete linea a linea.
                        La ultima vuelta fgets encuentra el EOF, su longitud sera 0 */
                    if(fgets(line, TOTAL, fp1) > 0)
                    {
                        /* 2. Invoco a la funcion area_check() para verificar si la linea actual coincide con el area deseada.
                            argv[3] es el area deseada */
                        if(area_check(line, argv[2]))
                        {
                            /* 3. Escribo nueva linea en el nuevo archivo e incremento contador del total de coincidencias encontradas */
                            set_line(line, fp2);
                            cnt++;
                        }
                    }

                }
                printf("Se encontraron [%d] personas pertenecientes al area [%s]\n", cnt, argv[2]);
                if(cnt == 0)
                    remove(argv[2]);
            }
            else
            {
                printf("ERROR [3]\n");
                exit = 3;
            }
        }
        else
        {
            printf("ERROR [2]\n");
            exit = 2;
        }
    }
    else
    {
        printf("ERROR [1]\n./<programa> <archivo fuente> <area> <nuevo archivo>\n\n");
        exit = 1;
    }

    if(exit > 1)
        fclose(fp1);
    if(exit > 2)
        fclose(fp2);

    return exit;
}