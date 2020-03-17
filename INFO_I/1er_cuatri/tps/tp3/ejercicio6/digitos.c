/**
 * \file            digitos.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jul 05, 2019
 */


//programa que dice la cantidad de digitos de un numero
#include <stdio.h>
int main ()
{
    int a, b;       //declaracion de variables
    int dig = 1;

    printf("\nIngrese un numero entero\n");
    scanf("%d", &a);
    
    b = a;  //Guardo el valor ingresado, ya que la variable "a" sera modificada
    
    while((a/10)>=1)    //al dividir un numero por 10, disminuye un digito
    {
        dig++;
        a /= 10;
    }                                                      
    
    printf("\n%d tiene %d digitos\n", b, dig);                                                           
                                                           
    return 0;
}

/*
"gcc -c acumulacion.c -o acumulacion.o -Wall" para compilar
"gcc acumulacion.o -o acumulacion.z -Wall" para linkea    
"./acumulacion.z" para ejecutar
*/
