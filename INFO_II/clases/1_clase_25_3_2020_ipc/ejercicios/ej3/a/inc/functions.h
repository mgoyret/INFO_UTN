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
#define LINE      30
#define SHM_SIZE  1024+1
#define NEW_MEM   1
#define OLD_MEM   0

/* 2. Union para manejar semaforo */
union semun {
  int              val;    // Value for SETVAL
  struct semid_ds *buf;    // Buffer for IPC_STAT, IPC_SET
  unsigned short  *array;  // Array for GETALL, SETALL
  struct seminfo  *__buf;  // Buffer for IPC_INFO (Linux specific)
};

/* 3. Estructura para cargar datos del archivo indicado */
typedef struct meassure
{
    int id;
    int value;
}meassure;

/* 4. Protoripo de la funcion "msr_tot". Calcula la cantidad de medidas presentes en el archivo indicado */
int msr_tot(FILE* fp);

/* 5. Protoripo de la funcion "ln_st". Carga los datos del archivo separado por comas a un array de estructuras del tipo "meassure" */
void ln_st(FILE* fp, meassure* msr, int cnt);

/* 6. Protoripo de la funcion "show". Muestra el contenido del array msr */
void show(meassure* msr, int cnt);

/* 7. Protoripo de la funcion "set_shm". Crea un bloque de memoria compartida o se adiere a uno existente */
int set_shm(int* pos, int* flag);

/* 8. Protoripo de la funcion "shm_clean". Setea todas las posiciones del array de la memoria compartida a 0 */
int shm_clean(int*** data, int tam);

/* 9. Protoripo de la funcion "set_sem". Crea un semaforo o se une a uno existente */
int set_sem(union semun* arg);

/* 10. Protoripo de la funcion "write_shm". Carga datos del array "msr" al array de memoria compartida */
int write_shm(int** data, meassure* msr, int cnt, int* pos, int tam);

#endif /* FUNCTIONS_H_ */