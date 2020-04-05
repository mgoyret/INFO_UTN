/**
 * \file            main.c
 * \brief           Archivos Header - Prototipos de funciones definidas por el usuario
 * \author          Marcos Goyret
 * \date            Mar , 2020
 * \details         Usar MakeFile para compilar y linkear
 */

/*
    Consigna
    Generar un programa que reciba por argumentos del main el nombre de un archivo que contiene
    mediciones de sensores con el siguiente formato: idSensor,valor
    Dichos sensores toman la temperatura de diferentes lugares de un entorno, el tamaño máximo es de 1024 mediciones,
    luego debe empezar a escribirse como si fuese una cola. Se requiere implementar un bloque de memoria dinámica que
    permita cargar los valores de temperatura (la identificación no es importante en este caso).
    Dicho programa puede ser utilizado por diferentes procesos para cargar datos en forma simultánea. 
*/

#include "../inc/functions.h"

int main (int argc, char** argv)
{
    FILE *fp;
    meassure *msr;
    int cnt;

    if(argc == 2)
    {
        if((fp = fopen(argv[1], "r")) != NULL)
        {
            cnt = msr_tot(fp);
            printf("Total de mediciones [%d]\n", cnt);
            if((msr = (meassure*)malloc(sizeof(meassure)*cnt)) != NULL)
            {
                ln_st(fp, msr, cnt);
                show(msr, cnt);
                
            }
            else
                printf("ERROR [3]\n");

            fclose(fp);
        }
        else
            printf("ERROR [2]\n");
    }
    else
        printf("ERROR [1]\n./<programa> <archivo>\n");


    return 0;
}