#include "../inc/functions.h"

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

void ln_st(FILE* fp, meassure* msr, int cnt)
{
    char *token, line[LINE];
    int i = 0;

    for (i = 0; i < cnt; i++)
    {
        fgets(line, LINE, fp);
        //printf("Linea [%s]\n", line);
        token = strtok(line, ",");
        msr[i].id = atoi(token);
        token = strtok(NULL, "\n");
        msr[i].value = atoi(token);
    }

}

void show(meassure* msr, int cnt)
{
    int i;

    for (i = 0; i < cnt; i++)
    {
        printf("msr[%d].id = %d\nmsr[%d].value = %d\n", i, msr[i].id, i, msr[i].value);
    }
}

int set_shm(int cnt, int** data)
{
    key_t key;
    int out = 1, shmid, cant;

    if((key = ftok("key.txt", 'm')) != -1)
    {
        /* 1. Si la memoria compartida ya existe, shmget da errno = EEXIST */
        shmid = shmget(key, (size_t)(sizeof(int)*SHM_SIZE),  0644 | IPC_CREAT| IPC_EXCL);
        if(shmid >= 0)
        {
            out = shmid;
            cant = 0;
        }
        else if(errno == EEXIST)
        {
            shmid = shmget(key, (size_t)(sizeof(int)*SHM_SIZE),  0644 | IPC_CREAT);
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

    if (out >= 0)
    {
        if((*data = (int*)shmat(shmid, NULL, 0)) != (void*)-1)
        {
            printf("MEMORIA COMPARTIDA CREADA Y ATTACHE REALIZADO\n");
        }else
        {
            printf("ERROR set_shm() [3]\n");
            out = -1;
        }
    }
    
    return out;
}

int set_sem(void* a)
{
    int semid, key;
	union semun arg;

	if ((key = ftok("key.txt", 's')) != -1)
    {
    	//Creo semaforo o me uno si ya existe
        semid = semget(key,1, IPC_CREAT| IPC_EXCL | 0600);
      	if(semid >= 0) 
    	{
    		/* 1. Iniciializo el semaforo */
    		arg.val = 1;
    		if(semctl(semid, 0, SETVAL, arg) != -1)
            {
                printf("Semaforo creado\n");
    		}
            else
            {
    			printf("ERROR set_sem [3]\n");
    			semid = -1;                
            }
    	}
        /* 2. Me uno si el semaforo existte */
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

    return semid;
}