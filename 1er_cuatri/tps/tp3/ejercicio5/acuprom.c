/**
 * \file            acuprom.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jul 05, 2019
 */


//se ingresan valores hasta que su suma supera al 100, o el valor ingresado es 0. Se informa el promedio de los valores 

#include <stdio.h>
int main ()
{
    int a;
    int suma = 0;
    int can = 0; //can = cantidad de numeros ingresados
 
    printf("\nIngrese valores enteros\n");
    scanf("%d", &a);
    if(a != 0)
    {
        do
        {
            if(a != 0) can++;
            suma = suma + a;
            scanf("%d", &a);
        }
        while((a!=0) && (suma<100));
    }

    if(can != 0)
    {
        if(suma >= 100)                                         
        {                                                      
            printf("\nValor acumulado = %d\n", suma);
        }            
            else
            {
                printf("El valor ingresado es 0\n");
                printf("\nValor acumulado = %d\n", suma);
            }

        //promedio de valores ingresados
        printf("El promedio de los valores ingresados es %.3f\n", ((float)suma)/can);
    }
    else printf("No se registraron valores.\n");                                       

    return 0;
}

//"gcc -c acumulacion.c -o acumulacion.o -Wall" para compilar
//"gcc acumulacion.o -o acumulacion.z -Wall" para linkear
//"./acumulacion.z" para ejecutar
