/**
* \file            functions.h
* \brief           Ejercicios IPC – parte 1 - Ejercicio3-a
* \author          Alejo Fernadez Bados
* \date            April 2, 2019
* \details         Usar Makefile para compilar, linkear y ejecutar
*/

#include "functions.h"

/**
 * \fn 	int get_sema( int key,int * cant,size_t tam)
 * \brief  Se encarga de ..
 * \author  Alejo Fernadez Bados
 * \date    April 9, 2020
 * \param  int key llave para abrir la shared memory
 * \param  size_t tamaño de la memoria a crear
*/
int get_shm( int key,int * cant,size_t tam)
{
	int shmid;
	//Si existe da errno=EEXIST
	if ((shmid = shmget(key,tam, 0644 | IPC_CREAT| IPC_EXCL)) >=0) 
	{
		*cant=0;	// inicializo la cantidad de temperaturas
		return shmid;
	}
	if (errno==EEXIST)
		if ((shmid = shmget(key,tam, 0644 | IPC_CREAT)) >=0) 
			return shmid;

return -1;
}