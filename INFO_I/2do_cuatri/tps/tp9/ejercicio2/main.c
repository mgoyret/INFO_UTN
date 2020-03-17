/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Aug 31, 2019
 * \details         Usar MakeFile para compilar, linkear y ejecutar
 */

#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    /* 1. 'string' es un tipo de dato 'struct' definido en el header 'funciones.h' */
    int i = 0, j = 0;
    string pal[30];
    char aux[TAM];

    SPACE

    HIGHLIGHT
    printf("Puede ingresar hasta 30 palabras de hasta 25 caracteres cada una,\no 'fin' para finalizar la carga\n\n");
    DEFAULT
    printf("Ingrese palabra:\t");
    scanf("%s", aux);

    /* 2. Invoco a la función "fin", pasándole "aux" como argumento.
        Analizo el valor que retorna la función para saber si se ingreso la palabra 'fin' */
    /* 3. Invoco a la función "letra", pasándole "aux" como argumento.
        Analizo el valor que retorna la función para saber si se compone unicamente de letras */
    while (!fin(aux) && (i<=30))
    {
        /* 4. Invoco a la función "stolower", pasándole "aux" como argumento */
        stolower(aux);   
        strcpy(pal[i].spal, aux);
        i++;
        /* 5. Hace falta una ultima vuelta en la que se ejecute el 'strcpy' pero no el 'printf' */
        if(i<30)
            do
            {
                printf("Ingrese palabra:\t");
                scanf("%s", aux);   
                if (!letra(aux))
                    printf("Palabra invalida, solo puede contener letras\n");
            }while (!letra(aux));
    }
    if (i == 30)
        /* 6. Compensa un 'i' que es sumado en la ultima vuelta del while, si el loop finaliza porque 'i' llega a '30' */
        i--;
    if (fin(aux))
        printf("Fin de carga, se ingreso 'fin'\n");
        
    if (i == 29)
        printf("Fin de la carga, se alcanzo el limite de palabras\n");

    HIGHLIGHT
    printf("\n%d Palabras ingresadas", i);
    DEFAULT

    for (j=0; j<i; j++)
        printf("%s\n", pal[j].spal);

    /* 7. Invoco a la función "ordenar", pasándole "pal" y "i" como argumentos */
    ordenar(pal, i);
    
    HIGHLIGHT
    printf("\nPalabras Ordenadas");
    DEFAULT

    for (j=0; j<i; j++)
        printf("%s\n", pal[j].spal);

    SPACE

    return 0;
}