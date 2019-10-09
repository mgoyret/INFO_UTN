/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            May 29, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include "functions.h"

/* Definicion de la funcion "generar_numero_aleatorio" */

/**
 * \fn      int generar_numero_aleatorio(int min, int max)
 * \brief   genera un numero aleatorio definido entre dos valores pasados como parametros.
 * \author  Marcos Goyret
 * \date    May 29, 2019
 * \param   min limite inferior del rango
 * \param   max limite superior del rango
 * \return  numero aleatorio dentro del rango
 */
int generar_numero_aleatorio(int min, int max)
    /* Recibo "min" y "max" como parámetros de la función y retorno el contenido de "random" */

{
    int random;
    srand(time(NULL));    
    if(min<max)
    {                                                                           
        random = rand()%(max-min+1);  
        random += min; // (random+=) = (random = random + min)                                                     
    }                     
    else random = 0;

    return random;
}
/* los segundos que genera "time()" no son colocados en ninguna variable debido al NULL,
pero funcionan como semilla de la funcion "srand()", y esta a su vez actua como semilla para "rand()".
De esta manera, el numero aleatorio sera siempre distinto, a menos que el programa se ejecuto en el mismo segundo.
Si la semilla es constante, el numero sera siempre el mismo, porque el algoritmo de la funcion tomaria como punto de partida
siempre el mismo numero, y realizaria las operaciones propias de la funcion siempre sobre el mismo numero, dando el mismo resultado.
No existe algo realmente aleatorio en programacion, por eso es "pseudoaleatorio" */