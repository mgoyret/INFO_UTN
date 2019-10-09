#include "functions.h"
int division(int num1, int num2, float *res)
{
    int aux = ERROR;
    if(num2!=0)
    {
        aux = BIEN;

        *res = ((float)num1)/num2;//res es puntero, para cambiar el contenido de res,
    }                             //y no la copia de su contenido, que moriria en la funcion
    return aux;
}