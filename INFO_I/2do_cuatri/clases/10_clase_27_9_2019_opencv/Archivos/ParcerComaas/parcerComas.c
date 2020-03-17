/**	
	\file parcerComas.c
	\brief Ejemplo de como parcear un archivo con comas
	\author Jer�nimo F. Atencio (jerome5416@gmail.com)
	\date : 2013.02.14
*/
#include <stdio.h>
#include <errno.h>

#define EXITO 0
#define ERROR -1

/**
	\fn int main (void) 
	\brief Ejemplo de como parcear un archivo con comas
	\author : Jer�nimo F. Atencio (jerome5416@gmail.com)	
	\date : 2013.02.14
	\return -1 si hay un error al abrir el archivo, 0 en caso contrario
*/
int main (void) 
{
FILE *p;
char legajo[16], nombre[16], apellido[16];
int edad;


	p = fopen ("values.csv", "r");
	if (p != NULL)
	{
		while (!feof(p))
		{
			fscanf (p, "%[^,],%[^,],%[^,],%d\r\n", legajo, apellido, nombre, &edad);
			printf ("%10s | %10s | %10s | %2d\r\n", legajo, apellido, nombre, edad);
		}
		fclose (p);
	}
	else
	{
		perror ("Error al abrir el archivo");		
		return (ERROR);
	}
	
	return (EXITO);
}