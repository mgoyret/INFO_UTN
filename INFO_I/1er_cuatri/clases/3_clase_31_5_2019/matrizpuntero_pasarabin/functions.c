#include "functions.h"

void pasaloABin(int valor, int * bin)  //bin = direccion de comienzo de la fila
{
 int j;
 
for(j=COLUMNAS-1; j>0; j--)
        {
            *(bin+j) = valor%2;
            valor = valor/2;
        }

        *(bin+j) = valor;
}


void mostramelo(int *imagen)
{
    int i, j;
    for(i=0; i<FILAS; i++)
    {        for(j=0; j<COLUMNAS; j++)
             {       if( *(imagen + (i*COLUMNAS + j) ) ==1)  printf(PRENDIDO); //las comillas ya estan en el define        
                    else printf(APAGADO);
             }
             printf("\n");
    }
}