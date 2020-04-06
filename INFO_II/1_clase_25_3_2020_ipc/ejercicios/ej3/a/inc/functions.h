/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Mar , 2020
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

#define LINE      30
#define SHM_SIZE  1024


union semun {
  int              val;    // Value for SETVAL
  struct semid_ds *buf;    // Buffer for IPC_STAT, IPC_SET
  unsigned short  *array;  // Array for GETALL, SETALL
  struct seminfo  *__buf;  // Buffer for IPC_INFO (Linux specific)
};

typedef struct meassure
{
    int id;
    int value;
}meassure;

int msr_tot(FILE* fp);

void ln_st(FILE* fp, meassure* msr, int cnt);

void show(meassure* msr, int cnt);

int set_shm(int cnt, int** data);

int set_sem(void*);

#endif /* FUNCTIONS_H_ */