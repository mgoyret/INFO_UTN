#include <sys/types.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/sem.h>

#define KEYFILE "key"
#define KEYNUM  0

typedef struct shm_st {
  char buf[500];
}shm_st;

int main (int argc, char** argv)
{
    int shmid, semid, key, i, palabras=0;
    char* shmP = NULL;
    struct sembuf sb = {0, -1, 0};
    shm_st shmSt;

    memset(shmSt.buf, '\0', sizeof(shmSt));
    
    /* 1. Clave para semaforo y memoria compartida*/
    key = ftok(KEYFILE, KEYNUM);
    if(key == -1)
    {
        printf("Error ftok()\n");
        exit(-1);
    }
    /* 2. Creo o ME UNO a semaforo */
    semid = semget(key, 1, IPC_CREAT | 0666);
    if(semid == -1)
    {
        printf("Error semget()\n");
        exit(-1);
    }
    /* 3. Creo o ME UNO a shared memory */
    shmid = shmget(key, sizeof(shm_st), IPC_CREAT | 0777);
    if(shmid == -1)
    {
        printf("Error shmget()\n");
        exit(-1);
    }
    /* 4. Me acoplo a la memoria */
    shmP = (char*)shmat(shmid, 0, 0);
    if(shmP == (void*)-1)
    {
        printf("Error shmat()\n");
        exit(-1);
    }
    // MEMORIA DISPONIBLE

    fflush(stdin);
    printf("Presione una tecla para bloquear semaforo y leer memoria: ");
    fgetc(stdin);    
    ///////////////// Semaforo bloqueado ///////////////////
    sb.sem_op = -1;
    if(semop(semid, &sb, 1) == -1)
    {
        printf("Error semop(-1) [main]\n");
        exit(-1);
    }//en realidad ahora si que esta bloqueado
    printf("Semaforo bloqueado\n");

    /* 7. Leyendo memoria */
    printf("Cargando memoria en estructura\n");
    i=0;
    while( (shmP[i] != '\0') && (i<sizeof(shmSt)-1) )
    {
        shmSt.buf[i] = shmP[i];
        i++;
    }
    printf("Estructura tiene:\n%s\n", shmSt.buf);

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
    i=0;
    while(shmSt.buf[i] != '\0')
    {
        if(shmSt.buf[i] == ' ' || shmSt.buf[i] == '\n' || shmSt.buf[i] == '\t' || shmSt.buf[i] == '\r')
            palabras++;
        i++;
    }
    printf("Cantidad de palabras: [%d]\n", palabras);

    printf("FIN\n");

    return 0;
}


/*
B. Realizar 2 programas que lean la shared memory anterior (Señalizados por
semáforos para asegurarse que no se está leyendo la información cuando todavía
no se terminó de cargar). Uno de ellos deberá indicar la cantidad de palabras que
contiene el texto, y el otro indicará la cantidad de letras del mismo.
*/