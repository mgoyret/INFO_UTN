/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Mar 24, 2020
 * \details         Usar MakeFile para compilar y linkear
 */

/*
    Practica de shared memory.
    El codigo de "main.c" setea un bloque de memoria compartida y escribe el alfabeto.
    El codigo de "main2.c" se adiere a ese mismo bloque y lee lo que fue escrito (el alfabeto).
*/

#include "functions.h"

int main()
{
    key_t key;
    int shm_id, i;
    char* memo = NULL;

    printf("Seteando memoria compartida\nCreando nuevo bloque\n\n");
    key = ftok("/bin/ls", 'A');
    if(key != -1)
    {
        printf("key = [%d]\t|\t", key);
        shm_id = shmget(key, sizeof(char)*MEM_SZ, 0777 | IPC_CREAT);
        if(shm_id != -1)
        {
            printf("shm_id = [%d]\t|\t", shm_id);
            memo = (char*)shmat(shm_id, (const void*)0, 0);
            if(memo != (char*)-1)
            {
                printf("addr. = [%p]\n\n", memo);
                printf("///////////////////////////////////////\n\n");
                printf("Escribiendo memoria\n");
                for(i=0; i<=('Z'-'A'); i++)
                {
                    memo[i] = 'A' + i;
                }
                memo[i] = '\0';
                printf("Memoria escrita\n");
                printf("Me desconecto de la memoria compartida y me retiro\n");
                shmdt((const void*)memo);
            }
            else
                printf("ERROR [3]\n");
        }
        else
            printf("ERROR [2]\n");
    }
    else
        printf("ERROR [1]\n");

    printf("FIN\n");
    return 0;
}