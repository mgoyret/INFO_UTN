#include "functions.h"

int main ()
{
    int imagen [FILAS*COLUMNAS], i, valor, j;

    for(i=0;i<FILAS;i++)
    {
        printf("ingrese valor de linea %d\n", i+1);
        scanf("%d", &valor);
        
        pasaloABin(valor, imagen+(COLUMNAS*i));
    }

    mostramelo(imagen);

    for(i=0; i<FILAS; i++)
    {        for(j=0; j<COLUMNAS; j++)
             {       if(imagen[i*j]==1)  printf(PRENDIDO); //las comillas ya estan en el define        
                    else printf(APAGADO);
             }
             printf("\n");
    }
    return 0;
}