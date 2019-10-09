#include <stdio.h>
#define COLUMNAS 8
#define FILAS 8
#define PRENDIDO "#"
#define APAGADO " "


int main ()
{
    int imagen [FILAS] [COLUMNAS], i, valor, j;
    
    //charge
    for(i=0;i<FILAS;i++)
    {
        printf("ingrese valor de linea %d\n", i+1);
        scanf("%d", &valor);
        for(j=COLUMNAS-1; j>0; j--)
        {
            imagen [i] [j] = valor%2;
            valor = valor/2;
        }
        imagen [i] [j] = valor;
    }

    //print
    for(i=0; i<FILAS; i++)
    {        
        for(j=0; j<COLUMNAS; j++)
        {       
            if(imagen[i][j]==1)  printf(PRENDIDO);  
                else printf(APAGADO);
        }
        printf("\n");
    }
    return 0;
}