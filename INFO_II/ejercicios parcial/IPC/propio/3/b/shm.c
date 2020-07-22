#include <sys/types.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/sem.h>

#define KEYFILE "key"
#define KEYNUM  0

// Union para semaforo
typedef union semun {
  int              val;    /* Value for SETVAL */
  struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
  unsigned short  *array;  /* Array for GETALL, SETALL */
  struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux specific) */
}semun;

typedef struct shm_st {
  char buf[500];
}shm_st;

int main (int argc, char** argv)
{
    int shmid, semid, key, i;
    FILE* fp = NULL;
    char* shmP = NULL;
    char c;
    semun arg;
    struct sembuf sb = {0, -1, 0};
    shm_st shmSt;
    
    if(argc == 2)
    {
        /* 1. Abro archivo con texto */
        fp = fopen(argv[1], "r");
        if(fp == NULL)
        {
            printf("Error fopen()\n");
            exit(-1);
        }else printf("Archivo: %s\n", argv[1]);

        /* 2. Cargo contenido del archivo en estructura */
        memset(shmSt.buf, '\0', sizeof(shm_st));
        i=0;
        while( (!feof(fp)) && (i<sizeof(shm_st)-1) )
        {
            c = fgetc(fp);
            if(c != EOF)
                shmSt.buf[i++] = c;
        }//luego son todos \0


        /* 3. Clave para semaforo y memoria compartida*/
        key = ftok(KEYFILE, KEYNUM);
        if(key == -1)
        {
            printf("Error ftok()\n");
            exit(-1);
        }
        /* 4. Creo o me uno a semaforo */
        semid = semget(key, 1, IPC_CREAT | 0666);
        if(semid == -1)
        {
            printf("Error semget()\n");
            exit(-1);
        }
        /* 5. Inicializo semaforo en 1 */
        arg.val = 1;
        if(semctl(semid, 0, SETVAL, arg) == -1)
        {
            printf("Error semctl()\n");
            exit(-1);
        }
        ///////////////// Semaforo bloqueado ///////////////////
        sb.sem_op = -1;
        if(semop(semid, &sb, 1) == -1)
        {
            printf("Error semop(-1) [main]\n");
            exit(-1);
        }//en realidad ahora si que esta bloqueado
        printf("Semaforo bloqueado\n");

        /* 4. Creo o me uno a shared memory*/
        shmid = shmget(key, sizeof(shm_st), IPC_CREAT | 0777);
        if(shmid == -1)
        {
            printf("Error shmget()\n");
            exit(-1);
        }
        /* 5. Me acoplo a la memoria */
        shmP = (char*)shmat(shmid, 0, 0);
        if(shmP == (void*)-1)
        {
            printf("Error shmat()\n");
            exit(-1);
        }
        // MEMORIA DISPONIBLE
        /* 6. Escribo en memoria */
        printf("Escribiendo memoria [%ld]\n", sizeof(shm_st));
        for(i=0; i<sizeof(shm_st); i++)
            shmP[i] = shmSt.buf[i];

        /* 7. Leyendo memoria */
        printf("Leyeno memoria para corroborar\n\n");
        i=0;
        while(shmP[i] != '\0')
            printf("%c", shmP[i++]);
            
        printf("\n");
        fflush(stdin);
        printf("Presione una tecla para desbloquear semaforo: ");
        fgetc(stdin);

        sb.sem_op = 1;
        if(semop(semid, &sb, 1) == -1)
        {
            printf("Error semop(1) [main]\n");
            exit(-1);
        }
        printf("Semaforo desbloqueado\n");
        //////////////// Semaforo desbloqueado ////////////////////

        fflush(stdin);
        printf("Presione una tecla para bloquear semaforo y borrar memoria: ");
        fgetc(stdin);
        // Bloqueo semaforo para borrar memoria
        sb.sem_op = -1;
        if(semop(semid, &sb, 1) == -1)
        {
            printf("Error semop(-1) [main]\n");
            exit(-1);
        }
        printf("Semaforo bloqueado\n");
        /* 8. Me desacoplo de la memoria y la borro */
        if(shmdt((char*)shmP) == -1)
        {
            printf("Error shmdt()\n");
            exit(-1);
        }
        if(shmctl(shmid, IPC_RMID, NULL) == -1)
        {
            printf("Error shmctl()\n");
            exit(-1);
        }
        printf("Memoria eliminada\n");
        //desbloqueo semaforo
        sb.sem_op = 1;
        if(semop(semid, &sb, 1) == -1)
        {
            printf("Error semop(1) [main]\n");
            exit(-1);
        }
        printf("Semaforo desbloqueado\n");

        fflush(stdin);
        printf("Presione una tecla para eliminar semaforo: ");
        fgetc(stdin);
        // Destruyo semaforo
        if(semctl(semid, 0, IPC_RMID, arg) == -1)
        {
            printf("Error semctl()\n");
            exit(-1);
        }
        printf("Semaforo borrado\n");

        printf("FIN\n");

    }else
        printf("Error - Cantidad de parametros no soportada\n");
    return 0;
}


/*
B. Realizar 2 programas que lean la shared memory anterior (Señalizados por
semáforos para asegurarse que no se está leyendo la información cuando todavía
no se terminó de cargar). Uno de ellos deberá indicar la cantidad de palabras que
contiene el texto, y el otro indicará la cantidad de letras del mismo.
*/