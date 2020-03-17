/**
 * \file            pares.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jul 05, 2019
 */


//imprimir numeros pares entre 0 y 100
#include <stdio.h>  //header con prototipos de funciones utilizadas
int main ()
{
    int a=0; //declaracion de variable=0 para que pueda incrementarce en el for()
    printf("Los numeros pares entre 0 y 100 son:\n\n");
    for(a=0;a<=100;a++)
    {
        if((a%2)==0) //si el modulo entre un numero, y 2, es 0, ese numero es par
            printf("%d\n", a);
    }                           
    return 0;
}


//"gcc -c pares.c -o pares.o -Wall" para compilar
//"gcc pares.o -o pares.z -Wall" para linkear
//"./pares.z" para ejecutar
