#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// NOTA: compilar con -lpthread

#define FILE1   "Archivo1"
#define FILE2   "Archivo2"

#define LINE_MAX    32

float suma = 0;
float producto = 1;

pthread_mutex_t mutexSum;
pthread_mutex_t mutexProd;


void* fun_prod(void* arg)
{
    FILE* fp = (FILE*)arg;
    char line[LINE_MAX];

    while(!feof(fp))
    {
        fgets(line, LINE_MAX, fp);
        pthread_mutex_lock(&mutexProd);
        producto = producto*atof(line);
        pthread_mutex_unlock(&mutexProd);
    }

    return fp;
}

void* fun_sum(void* arg)
{
    FILE* fp = (FILE*)arg;
    char line[LINE_MAX];

    while(!feof(fp))
    {
        fgets(line, LINE_MAX, fp);
        pthread_mutex_lock(&mutexSum);
        suma += atof(line);
        pthread_mutex_unlock(&mutexSum);
    }

    return fp;
}

int main()
{
    pthread_t sumId, prodId;   
    FILE* fp1;
    FILE *fp2;

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

    // Inicializo mutex
    if(pthread_mutex_init(&mutexProd, NULL))
    {
        printf("Error mutex prod\n");
        exit(-1);
    }
    if(pthread_mutex_init(&mutexSum, NULL))
    {
        printf("Error mutex sum\n");
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
    pthread_mutex_lock(&mutexProd);
    pthread_mutex_lock(&mutexSum);
    printf("Producto = %f\n", producto);
    printf("Suma = %f\n", suma);
    printf("Prod/Sum = %f\n", (producto)/(suma));
    pthread_mutex_unlock(&mutexProd);
    pthread_mutex_unlock(&mutexSum);

    // Destruyo mutex
    pthread_mutexattr_destroy((pthread_mutexattr_t*)&mutexProd);
    pthread_mutexattr_destroy((pthread_mutexattr_t*)&mutexSum);

    // Cierro archivos
    fclose(fp1);
    fclose(fp2);


    return 0;
}

/*
A. Dados 2 archivos de datos numéricos flotantes, hacer un programa que abra dichos
archivos y genere 2 threads, enviándole a cada uno el file descriptor del archivo
correspondiente. El primero deberá hacer el producto de todos los números del
archivo, y el segundo la sumatoria de los mismos, imprimiendo el resultado en dos
variables globales compartidas por todos los threads. El thread principal deberá
tomar el resultado de estas dos operaciones y realizará el cociente de los mismos,
imprimiendo finalmente el resultado por pantalla.
*/