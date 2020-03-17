#include "functions.h"

float promedio(int *p, int largo)
{
    float res;
    int suma = 0, i = 0;

    for(i=0;i<largo;i++)
    {
        suma = suma + *(p+i); /*i aumenta en funcion del tipo de dato al que esta aumentando (p). porq esta 
                                en el contenido de lo apuntado por el*/
    }
    res = (float)suma/largo;
    return res;
}