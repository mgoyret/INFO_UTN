#include "functions.h"
#define CANT 10

int main ()
{
    int notas[CANT];
    int max, min;
    int i=0;

    for(i=0;i<CANT;i++)
	{	
	printf("Carga nota %d\n", i+1);
	scanf("%d", &notas[i]); //la direccion es el numero q tenga i, que va a ir variando
	}

    MaxMin(notas, CANT, &max, &min);
      
    printf("El maximo es %d\n", max);
    printf("El minimo es %d\n", min);

	return 0;
}