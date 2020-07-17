/*
Este programa no se pide explicitamente en el enunciado pero de alguna
forma tiene que tener el archivo binario con los datos que se mencionan
en el enunciado.

Lo unico que hago es poner valores predefinidos de los tipos de sensores
y de los valores asociados a cada uno. Luego se cargan en el archivo binario
mediante el uso de una estructura y el bucle for.
*/

/*
	VALORES DEL SENSOR 1 - TEMPERATURA
	12
	67
	146
	35
	116
	12
	18

	VALORES DEL SENSOR 2 - PRESION
	345
	156
	128
	16
	36
	116
	67

	VALORES DEL SENSOR 3 - HUMEDAD
	15
	245
	118
	87
	28
	45
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define TAM		20

typedef struct datos
{
	char tipo_sensor;
	long data;
}datos;


int main(void)
{
	FILE *fd;
	datos sensores;
	char tipo[TAM] = {1,2,2,2,1,3,3,1,3,3,2,1,1,3,2,1,3,2,1,2};	// tipo de sensores
	long data[TAM] = {12,345,156,128,67,15,245,146,118,87,16,35,116,28,36,12,45,116,18,67}; // datos de los sensores
	int i = 0;

	// w es para abrirlo en modo escritura y crearlo si no existe
	// b es para que sea del tipo binario, sino es tipo texto
	// es decir, estoy creando un archivo binario y lo abro
	// en modo escritura
	fd = fopen("sensores.dat", "wb");

	if(fd == NULL){
		perror("No se pudo abrir/crear el archivo");
		exit(1);
	}

	// Cargo los datos en la estructura y los voy guardando
	// en el archivo binario
	for(i = 0; i < TAM; i++){
		sensores.tipo_sensor = tipo[i];
		sensores.data = data[i];
		fwrite(&sensores, sizeof(sensores), 1, fd);
	}

	fclose(fd);

	return 0;
}