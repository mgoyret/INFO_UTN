/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jul 05, 2019
 */


//se ingresan valores hasta que su suma supera al 100, o el valor ingresado es 0.

#include <stdio.h> //header que contiene los prototipos de las funciones utilizadas
int main ()
{
    int a;          //declaracion de variables
    int suma = 0;
 
    printf("Ingrese valores enteros\n");   
    
    do
    {
        scanf("%d", &a);   //asignacion del valor ingresado, a la variable a                  
        suma += a;
    }
    while((a!=0) && (suma<100));                        
                                                        
    if(suma >= 100)                                      
    {
        printf("Valor acumulado supero  = %d\n", suma);
    }
        else
        {
            printf("El valor ingresado es 0\n");
            printf("Valor acumulado = %d\n", suma);
        }
    return 0;
}

/*

"gcc -c acumulacion.c -o acumulacion.o -Wall" para compilar
"gcc acumulacion.o -o acumulacion.z -Wall" para linkear
"./acumulacion.z" para ejecutar

*/
