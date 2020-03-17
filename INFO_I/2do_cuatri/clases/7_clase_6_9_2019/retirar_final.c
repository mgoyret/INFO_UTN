#include <stdio.h>
#include <stdlib.h>

int retirar_final(int**, int*);

int retirar_final(int** vec, int* tam)
{
    int i = 0, salida = -1, *aux;

    *aux = (int*)realloc(*vec, sizeof(int)*(--(*tam)));
    if (*vec != NULL)
    {
        salida = (*vec)[(*tam)-1];
        *vec = aux;
    }

    return salida;
}

int main ()
{
    int i = 0, tam = 10, *vec;
    
    vec = (int*)malloc(sizeof(int)*tam);
    if (vec != NULL)
    {
        for(i=0; i<10; i++)
            vec[i] = (i+1);


        for (i=0; i<tam; i++)
            printf("%d\n", vec[i]);


        printf("\n\n");

        retirar_final(&vec, &tam);

        printf("vector final\n");
        for(i=0; i<tam; i++)
            printf("%d\n", vec[i]);

    }
    else
    {
        printf("se todo a la mierda\n");
    }
    
    
    return 0;
}