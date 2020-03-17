#include "functions.h"

void calcular_vector(int* notas, int* mask, int largo, int* res)
{
    int i = 0;
    int num = (2*largo)/3;
    printf("\nEl ultimo tercio es luego del elemento %d del vector resultado\n", num);

    for(i = 0; i < largo; i++)  //lleno la mascara de '1'
    {
        mask[i] = 1;
    }

    for(i = 0; i < num; i++)    //reemplazo por '0' los primeros dos tercios de la mascara
    {
        mask[i] = 0;
    }


    for(i = 0; i < largo; i++)
    {
        res[i] = (notas[i]) * (mask[i]);
    }
}