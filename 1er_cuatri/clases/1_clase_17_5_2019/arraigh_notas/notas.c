#include <stdio.h>
#define CANT 10  //cant=cantidad de alumnos. de esta manera, cambio el valor de cant y se cambia en todo el programa

int main()
{
	int notas[CANT];
	int min=10;
	int max=0;
	int suma=0;
	float prom;
	int i=0;
	int punt[11]={0};   //todos los valores del arraigh valen 0. hago 11 y no uso la posicion 0

	for(i=0;i<CANT;i++)
	{	
	printf("Carga nota %d\n", i+1);
	scanf("%d", &notas[i]); //la direccion es el numero q tenga i, que va a ir variando
	}

	//calculamos promedio
	for(i=0;i<CANT;i++)
	{
	suma = suma + notas[i]; // suma sera la suma de las notas
	}
	prom = (float)suma/i;
	printf("El promedio de %d notas es %f\n", i, prom);

	//nota maxima y minima
	for(i=0;i<CANT;i++)
	{
		if(max<notas[i])
		{
		max = notas[i];
		}

		if(min>notas[i])
		{
		min = notas[i];
		}
	}


	
	printf("Nota minima = %d y nota maxima = %d\n", min, max);

	//cantidad de notas que fueron cada valor
	for(i=0;i<CANT;i++)
	{
		if(notas[i]>0&&notas[i]<=10)
		{
		punt[notas[i]]++;  //si nota=2, se suma uno a punt=2
		}
	}
			printf("%d nota/s fueron un 1\n", punt[1]);
			printf("%d nota/s fueron un 2\n", punt[2]);
			printf("%d nota/s fueron un 3\n", punt[3]);
			printf("%d nota/s fueron un 4\n", punt[4]);
			printf("%d nota/s fueron un 5\n", punt[5]);
			printf("%d nota/s fueron un 6\n", punt[6]);
			printf("%d nota/s fueron un 7\n", punt[7]);
			printf("%d nota/s fueron un 8\n", punt[8]);
			printf("%d nota/s fueron un 9\n", punt[9]);
			printf("%d nota/s fueron un 10\n", punt[10]);

return 0;
}
