/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Abr 06, 2020
 * \details         Usar MakeFile para compilar y linkear
 */

#include "../inc/functions.h"

/**
 * \fn      int msr_tot(FILE* fp)
 * \brief   Calcula la cantidad de mediciones de temperatura almacenadas en el archivo apuntado por "fp"
 * \author  Marcos Goyret.
 * \date    Abr 06, 2020
 * \param	fp: puntero al archivo del cual se levantan los datos
 * \return  Cantidad de mediciones contadas en el archivo
 */

int msr_tot(FILE* fp)
{
    int tot = 0;
    char line[LINE];

    while(!feof(fp))
    {
        if(fgets(line, LINE, fp) != NULL)
            tot += 1;
    }
    /* 1. Llevo el fp nuevamente al inicoi del archivo
            No se por que al hacer printf de la posicion del fp antes y despues me marca la misma,
            pero no es la misma ya el el fp fue movido por fgets, ademas si no hago el rewind al volver
            al main, el proceso "while" siguiente no es llevado a cabo porque se encuentra el EOF, osea
            que el fp si que esta al final del archivo... */
    rewind(fp);   
    if (tot > 1024)
    {
        printf("Solo se cargaran las primeras 1024 mediciones de termperatura\n");
        tot = 1024;
    }
     
    return tot;
}

/**
 * \fn      void ln_st(FILE* fp, meassure* msr, int cnt)
 * \brief   Carga los datos del archivo apuntado por fp a un array de estructuras del tipo "meassure"
 * \author  Marcos Goyret.
 * \date    Abr 06, 2020
 * \param	fp:     puntero al archivo contenedor de datos
 * \param   msr:    array de estructuras "meassure" donde se almacenaran los datos
 * \param   cnt:    cantidad de mediciones presentes en el archivo
 */

void ln_st(FILE* fp, meassure* msr, int cnt)
{
    char *token, line[LINE];
    int i = 0;

    for (i = 0; i < cnt; i++)
    {
        fgets(line, LINE, fp);
        token = strtok(line, ",");
        msr[i].id = atoi(token);
        token = strtok(NULL, "\n");
        msr[i].value = atoi(token);
    }
}

/**
 * \fn      void show(meassure* msr, int cnt)
 * \brief   Muestra el contenido del array msr
 * \author  Marcos Goyret.
 * \date    Abr 06, 2020
 * \param	msr: array a imprimir
 * \param   cnt: cantidad de posiciones a imprimir
 */

void show(meassure* msr, int cnt)
{
    int i;

    for (i = 0; i < cnt; i++)
    {
        printf("msr[%d].id = %d\nmsr[%d].value = %d\n", i, msr[i].id, i, msr[i].value);
    }
}

/**
 * \fn      int set_shm(int* pos, int* flag)
 * \brief   Crea un bloque de memoria compartida o se adiere a uno existente
 * \author  Marcos Goyret.
 * \date    Abr 06, 2020
 * \param	pos:  variable que almacena el subindice de la posicion del array de memoria compartida
 *                sobre el cual se debe comenzar a escribir
 * \param   flag: flag para indicar si se creo un nuevo bloque de memoria (flag = 1) o si se adirio a uno ya existente (flag = 0)
 * \return  codigo de identificacion del bloque de memoria compartida creado o encontrado, o [-1] en caso de error
 */

int set_shm(int* pos, int* flag)
{
    key_t key;
    int out = 1, shmid;

    if((key = ftok("../key.txt", 'M')) != -1)
    {
        printf("\nKEY MEMORIA [%d]\n\n", key);
        /* 1. Trato de crear bloque de memoria compartida */
        shmid = shmget(key, (size_t)(sizeof(int)*SHM_SIZE),  0644 | IPC_CREAT| IPC_EXCL);
        if(shmid >= 0)
        {
            printf("Nuevo bloque de memoria compartida creado\n");
            *flag = NEW_MEM;
        }
        /* 2. Si el bloque de memoria compartida ya existe (errno = EEXIST), me acoplo a la existente */
        else if(errno == EEXIST)
        {
            if((shmid = shmget(key, (size_t)(sizeof(int)*SHM_SIZE),  0644 | IPC_CREAT)) >= 0)
            {
                printf("Unido a bloque de memoria compartida existente\n");
                *flag = OLD_MEM;
            }
            else
            {
                printf("ERROR shm_get [4]\n");
                out = -1;
            }
            
        }
        else
        {
            printf("ERROR set_shm() [2] [%d]\n", shmid);
            out = -1;
        }
    }
    else
    {
        printf("ERROR set_shm() [1]\n");
        out = -1;
    }
    if(out>0)
    {
        out = shmid;
    }
    printf("Saliendo de set_shm() shmid es %d\n", shmid);
    return out;
}

/**
 * \fn      int shm_clean(int** data, int tam)
 * \brief   Setea todas las posiciones del array "data" a 0
 * \author  Marcos Goyret.
 * \date    Abr 06, 2020
 * \param	data: array a ser seteado a 0
 * \param   tam:  largo del array
 */

/*
int shm_clean(int** data, int tam)
{
    int tot = 0, i;
    for (i = 0; i < tam; i++)
    {
        printf("vuelta %d. *data[%d] = %d\n", i, i, *data[0]);
        *data[i] = 0;
        tot++;
        printf("data[%d] = %d\n", i, *data[i]);
    }
    / 1. Devuelvo cantidad de posiciones seteadas a 0 /
    return tot;
}
*/

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