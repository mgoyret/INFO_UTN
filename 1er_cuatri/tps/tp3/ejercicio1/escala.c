/**
 * \file            escala.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jul 05, 2019
 */


//imprimir numeros de 0 al 9 y viceversa
#include <stdio.h> //header que contiene los prototipos de las funciones utilizadas
int main ()
{
    int num = 0;        //declaracion de variables
    int a = 1;
    for(num=0;num<=9;num++)
    {
        printf("%d\n", num);
    }
    
    for(num=9;num>=0;num--)
    {
        printf("%d\n", num);
    }
    return 0;         
}

//"gcc -c escala.c -o escala.o -Wall" para compilar
//"gcc escala.o -o escala.z -Wall" para linkear
//"./escala.z" para ejecutar