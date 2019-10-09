/**
 * \file            multiplos.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jul 05, 2019
 */


/*enteros de 1 a 100, palabra "Fizz" en multiplos de 3; "Buzz" en multiplos de 5, y ambas
en multiplos de ambos*/

#include <stdio.h> //header con prototipos de funciones utilizadas
int main ()
{
    int a = 1; //declaracion de variable
    
    for(a=1;a<=100;a++)
    {
        if ((a%3)!=0 && (a%5)!=0) //valores no multiplos de 3 ni de 5
        {
            printf("%d\n", a);
        }
        else
        {
            if (((a%5)==0)&&((a%3)==0)) //multiplos de ambos
            {
                printf("FizzBuzz\n");
            }
            else
            {
                if (((a%5)==0)&&((a%3)==0)) //multiplos de ambos
                {
                    printf("FizzBuzz\n");
                }
                else
                {
                    if ((a%3)==0) //multiplos de 3 y no de 5
                    {
                        printf("Fizz\n");
                    }
                    else //multiplos de 5 y no de 3
                    {
                        printf("Buzz\n");
                    }  
                }
            }   
        }                     //"gcc -c multiplos.c -o multiplos.o -Wall" para compilar
    }                         //"gcc multiplos.o -o multiplos.z -Wall" para linkear
    return 0;                 //"./multiplos.z" para ejecutar
}
