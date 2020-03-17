/**
 * Marcos Goyret
 * Practica 2do parcial Info1 UTN 29/11/2019
*/

/*
    Como resultado del seguimiento de un objeto por medio de procesamiento de imágenes se obtiene como
    resultado un archivo con el número de frame procesado y la posición x e y del objeto en la imagen.
    A su vez, se dispone de un archivo patrón con el mismo formato con el que se desea comparar los
    resultados obtenidos. El formato de los archivos antes mencionados se encuentra a continuación:

    15,220,143\n
    16,219,143\n
    18,219,144\n
    19,219,144\n
    21,218,145\n
    
    Se pide implementar una función que procese ambos archivos y calcule el promedio del error cometido.
*/



#include "functions.h"

int main()
{
    float error = 0;

    printf("Hola desde el main\n");

    error = calcular("patron", "medida");

    printf("Promedio de error absoluto: '%f'\n", error);

    return 0;
}