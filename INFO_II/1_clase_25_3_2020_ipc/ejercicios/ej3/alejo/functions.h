/**
* \file            functions.h
* \brief           Ejercicios IPC – parte 1 - Ejercicio3-a
* \author          Alejo Fernadez Bados
* \date            April 2, 2020
* \details         Usar Makefile para compilar, linkear y ejecutar
*/

//Inclucion de los headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#define SHM_SIZE 1025 /* Memoria para 1024 mediciones + 1 para guardar la cantidad de mediciones */

union semun {
  int              val;    /* Value for SETVAL */
  struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
  unsigned short  *array;  /* Array for GETALL, SETALL */
  struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux specific) */
};

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
//Declaración de los prototipos de las funciones
int get_shm( int key,int * cant,size_t tam);
#endif /* FUNCTIONS_H_ */