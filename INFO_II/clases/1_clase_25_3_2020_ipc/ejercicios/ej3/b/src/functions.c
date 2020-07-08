/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Abr 06, 2020
 * \details         Usar MakeFile para compilar y linkear
 */

#include "../inc/functions.h"

/**
 * \fn      int set_shm(void* a)
 * \brief   Se adiere al bloque de memoria asociado a la clave generada
 * \author  Marcos Goyret.
 * \date    Abr 06, 2020
 * \return  codigo de identificacion del bloque de memoria compartida encontrado, o [-1] en caso de error
 */

int set_shm(void* a)
{
    key_t key;
    int shmid = -1;

    if((key = ftok("../key.txt", 'M')) != -1)
    {
        printf("\nKEY MEMORIA [%d]\n\n", key);
        /* 1. Si el bloque de memoria compartido asociado a la clave "key" no existe, dara error */
        if((shmid = shmget(key, (size_t)(sizeof(int)*SHM_SIZE),  0644 | IPC_CREAT)) >= 0)
        {
            printf("Unido al bloque de memoria compartida existente\n");
        }
        else
        {
            printf("ERROR shm_get [4]\nprobablemente no exista el bloque de memoria compartida que se desea analizar\n");
            shmid = -1;
        }
    }
    else
    {
        printf("ERROR set_shm() [1]\n");
        shmid = -1;
    }

    printf("Saliendo de set_shm()\n");
    return shmid;
}

/**
 * \fn      int set_sem(union semun* arg)
 * \brief   Crea un semaforo o se une a uno existente.
 * \author  Marcos Goyret.
 * \date    Abr 06, 2020
 * \param	arg: union para controlar semaforo. Nesecito que este en el main para poder eliminar el semaforo sin volver a esta funcion
 */

int set_sem(union semun* arg)
{
    int semid = -1, key;

	if ((key = ftok("../key.txt", 'S')) != -1)
    {
        printf("\nKEY SEMAFORO [%d]\n\n", key);
        /* 1. Intento de crear un nuevo semaforo */
        semid = semget(key,1, IPC_CREAT| IPC_EXCL | 0600);
      	if(semid >= 0) 
    	{
    		/* 2. Iniciializo el semaforo creado */
    		arg->val = 1;
    		if(semctl(semid, 0, SETVAL, *arg) != -1)
            {
                printf("Semaforo creado, arg.val vale %d\n", (*arg).val);
    		}
            else
            {
    			printf("ERROR set_sem [3]\n");
    			semid = -1;                
            }
    	}
        /* 2. Si el semaforo ya exsiste (errno == EEXIST), me uno */
    	else if(errno==EEXIST)
        {
    		if((semid = semget(key, 1, IPC_CREAT | 0600)) >= 0)
            {
                printf("Unido a semaforo existente\n");
            }
            else
            {
                printf("ERROR set_sem [4]\n");
                semid = -1;
            }
      	}
        else
        {
            printf("ERROR set_sem [2]\n");
            semid = -1;
        }
  	}
    else
    {
        printf("ERROR set_sem [1] [%d] [%d]\n", key, errno);
        semid = -1;
    }
    printf("saliendo de set_sem\n");
    return semid;
}