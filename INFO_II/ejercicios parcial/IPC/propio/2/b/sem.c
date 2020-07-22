#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

// NOTA: compilar con -lpthread

#define FILE1   "Archivo1"
#define FILE2   "Archivo2"
#define KEYFILE "key"
#define KEYNUM  0

#define LINE_MAX    32

// Estructura para semaforo
union semun {
  int              val;    /* Value for SETVAL */
  struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
  unsigned short  *array;  /* Array for GETALL, SETALL */
  struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux specific) */
};

float suma = 0;
float producto = 1;

int semId = 0;


void* fun_prod(void* arg)
{
    FILE* fp = (FILE*)arg;
    char line[LINE_MAX];
    struct sembuf sb = {0, -1, 0};  /* arrancar en lock */

    while(!feof(fp))
    {
        fgets(line, LINE_MAX, fp);
        // Bloqueo recurso
        sb.sem_op = -1;
        if(semop(semId, &sb, 1) == -1)
        {
            printf("Error semop(-1) [prod]\n");
            exit(-1);
        }
        producto = producto*atof(line);
        // Desbloqueo
        sb.sem_op = 1;
        if(semop(semId, &sb, 1) == -1)
        {
            printf("Error semop(1) [prod]\n");
            exit(-1);
        }
    }

    return fp;
}

void* fun_sum(void* arg)
{
    FILE* fp = (FILE*)arg;
    char line[LINE_MAX];
    struct sembuf sb = {0, -1, 0};  /* arrancar en lock */

    while(!feof(fp))
    {
        fgets(line, LINE_MAX, fp);
        // Bloqueo recurso
        sb.sem_op = -1;
        if(semop(semId, &sb, 1) == -1)
        {
            printf("Error semop(-1) [sum]\n");
            exit(-1);
        }
        suma += atof(line);
        // Desbloqueo
        sb.sem_op = 1;
        if(semop(semId, &sb, 1) == -1)
        {
            printf("Error semop(1) [sum]\n");
            exit(-1);
        }
    }

    return fp;
}

int main()
{
    pthread_t sumId, prodId;   
    FILE* fp1;
    FILE *fp2;
    key_t key;
    union semun arg; // Variables para semaforos
    struct sembuf sb = {0, -1, 0};  /* arrancar en lock */


    // Abro arhcivos
    fp1=fopen(FILE2, "r");
    if(fp1 == NULL)
    {
        printf("Error al abrir %s\n", FILE2);
        exit(-1);
    }
    fp2=fopen(FILE1, "r");
    if(fp2 == NULL)
    {
        printf("Error al abrir %s\n", FILE1);
        exit(-1);
    }

    // Creo clave para semaforo
    key = ftok(KEYFILE, KEYNUM);
    if(key == -1)
    {
        printf("Error ftok()\n");
        exit(-1);
    }

    // Creo semaforo
    semId = semget(key, 1, IPC_CREAT | 0666);
    if(semId == -1)
    {
        printf("Error semget()\n");
        exit(-1);
    }

    // Inicializo semaforo en 1 (cantidad que usaran el recurso en simultaneo)
    arg.val = 1;
    if(semctl(semId, 0, SETVAL, arg) == -1)
    {
        printf("Error semctl()\n");
        exit(-1);
    }

    // Creo threads
    if(pthread_create(&prodId, NULL, &fun_prod, (void*)fp1))
    {
        printf("Error - pthread_create [prod]\n");
        exit(-1);
    }
    if(pthread_create(&sumId, NULL, &fun_sum, (void*)fp2))
    {
        printf("Error - pthread_create [sum]\n");
        exit(-1);
    }

    // Espera a los threads
    pthread_join(prodId, (void*)fp1);
    pthread_join(sumId, (void*)fp2);


    // Bloqueo recursos para imprimirlos
    sb.sem_op = -1;
    if(semop(semId, &sb, 1) == -1)
    {
        printf("Error semop(-1) [main]\n");
        exit(-1);
    }

    printf("Producto = %f\n", producto);
    printf("Suma = %f\n", suma);
    printf("Prod/Sum = %f\n", (producto)/(suma));

    // Desbloqueo recursos
    sb.sem_op = 1;
    if(semop(semId, &sb, 1) == -1)
    {
        printf("Error semop(1) [main]\n");
        exit(-1);
    }

    // Destruyo semaforo
    if(semctl(semId, 0, IPC_RMID, arg) == -1)
    {
        printf("Error semctl()\n");
        exit(-1);
    }

    // Cierro archivos
    fclose(fp1);
    fclose(fp2);


    return 0;
}

/*
B. Ampliar el programa anterior, utilizando semáforos para acceder a las variables globales
que se comparten entre los threads.
*/