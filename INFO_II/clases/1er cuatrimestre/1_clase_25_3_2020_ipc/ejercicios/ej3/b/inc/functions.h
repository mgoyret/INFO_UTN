/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Abr 07, 2020
 * \details         Usar MakeFile para compilar y linkear
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <errno.h>

/* 1. Defines para comodidad de indentacion */
#define SHM_SIZE  1024+1

/* 2. Union para manejar semaforo */
union semun {
  int              val;    // Value for SETVAL
  struct semid_ds *buf;    // Buffer for IPC_STAT, IPC_SET
  unsigned short  *array;  // Array for GETALL, SETALL
  struct seminfo  *__buf;  // Buffer for IPC_INFO (Linux specific)
};

/* 3. Protoripo de la funcion "set_shm". Crea un bloque de memoria compartida o se adiere a uno existente */
int set_shm(void* a);

/* 4. Protoripo de la funcion "set_sem". Crea un semaforo o se une a uno existente */
int set_sem(union semun* arg);


#endif /* FUNCTIONS_H_ */