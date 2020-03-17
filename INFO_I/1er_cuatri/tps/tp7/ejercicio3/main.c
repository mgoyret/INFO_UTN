/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jun 21, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include "functions.h"
int main ()
{
    char* pal = NULL;
    char* aux = NULL;
    unsigned char letra = 0;
    unsigned int cant = 1, i = 0;

    /* 1. Solicito  letras por consola */
    printf("Ingrese una letra\n");
    scanf("%c", &letra);
    __fpurge(stdin);
    pal = (char*)malloc(cant*sizeof(char));
    if((pal != NULL)   &&   ES_LETRA)
    {
        pal[0] = letra;
        while(ES_LETRA   &&   (i < 3))
        {
            printf("Ingrese una letra\n");
            scanf("%c", &letra);
            __fpurge(stdin);
            aux = (char*)realloc(pal, (cant + 1)*sizeof(char));
            if((aux != NULL)   &&   ES_LETRA)
            {
                aux[cant] = letra;
                cant++;
                pal = aux;
                if(letra == 'F')
                {
                    i++;
                }
                else i = 0;
            }
            else
            {
                if(aux == NULL) free(pal);
                    else printf("se ingreso un caracter que no es una letra\n");
            }
            
        }
    }

    /* 2. Invoco a la función "printstr", pasándole "pal" y "cant" como argumentos.
          Esta funcion imprime en pantalla el string pasado como parametro  */
    printstr(pal, cant);

    /* 3. Invoco a la función "orderstr", pasándole "pal" y "cant" como argumentos.
          Esta funcion ordena alfabeticamente un string pasado como parametro  */
    orderstr(pal, cant);

    printstr(pal, cant);

    printf("\n\nFIN\n\n");
    free(aux);
    
    return 0;
}