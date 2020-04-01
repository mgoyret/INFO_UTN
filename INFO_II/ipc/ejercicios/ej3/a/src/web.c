/*
La prisas........... Esta versión es ocrrecta me olvide de ciertos detalles
Si te fijas verás que se puede realizar cualquier tipo de prueba sin necesidad
de shmget  sobre buffer, una vez sea satisfactorio, buffer = shmat(id_zone, (char *)0, 0);
se ahorra el tener que cambiar int key  en cada prueba.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>

typedef struct Parking{
	int semid;
	int coches;
	int pidDesapar;
	int size;
	int nplazas;
	int plazas[1];
}Parking;
 
#define BUFER 200
 
int main(void){
	char *buffer;
	int i;
 
	buffer = malloc(BUFER);
 
	Parking *parking;
	parking = (Parking*)buffer;
 
	parking->size = BUFER - sizeof(Parking);
 
	parking->nplazas =0;
 
	for(i =0; i < 100; i++){
		parking->semid = i;
		parking->coches = i +1;
		parking->pidDesapar = 0;
 
		if( (parking->size - sizeof(int)) <= 0){
			printf("\n----Bloque de memoria sin espacio  %lu\n", (parking->size - sizeof(int)));
			break;
		}
 
		parking->size -= sizeof(int);
		parking->plazas[parking->nplazas] = i+1;
		parking->nplazas++;
	}
 
	for(i =0; i < parking->nplazas; i++){
		printf("%d\n",parking->plazas[i]);
	}
 
	free(buffer);
	return 0;
 
}