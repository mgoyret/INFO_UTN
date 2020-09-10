#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define NR_LOOP 10000

static void* thread_1_function(void*);

static void* thread_2_function(void*);

static int cnt = 0;
sem_t sem1;

int main()
{
    pthread_t thread_1, thread_2;

    /* El semaforo se crea en un proceso y comunica sus hilos */
    sem_init(&sem1, 0, 1);
    pthread_create(&thread_1, NULL, *thread_1_function, NULL);
    pthread_create(&thread_1, NULL, *thread_2_function, NULL);

    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);

    printf("VALOR = $d\n", cnt);

    return 0;
}

static void* thread_1_function(void* arg)
{
    int i;
    for(i=0; i<NR_LOOP; i++)
    {
        /* sem_wait() congela hasta que el valor de sem1 sea 1.
            luego decrementa la variable sem1 y permite continuar */
        sem_wait(&sem1);
        cnt++;
        /* sem_post() incrementa la variable sem1 y continua */
        sem_post(&sem1);
    }
    return NULL;
}

static void* thread_2_function(void* arg)
{
    int i;
    for(i=0; i<NR_LOOP; i++)
    {
        sem_wait(&sem1);
        cnt -= 1;
        sem_post(&sem1);
    }
    return NULL;
}