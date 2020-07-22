#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define FILE1   "Archivo1"
#define FILE2   "Archivo2"

#define LINE_MAX    32
typedef struct thread
{
    FILE* fp;
    float res;
}thr_st;

void* fun_prod(void* arg)
{
    thr_st* str = (thr_st*)arg;
    char line[LINE_MAX];

    while(!feof(str->fp))
    {
        fgets(line, LINE_MAX, str->fp);
        str->res = (str->res)*atof(line);
    }

    return str;
}

void* fun_sum(void* arg)
{
    thr_st* str = (thr_st*)arg;
    char line[LINE_MAX];

    while(!feof(str->fp))
    {
        fgets(line, LINE_MAX, str->fp);
        str->res += atof(line);
    }

    return str;
}

int main()
{
    pthread_t sumId, prodId;   
    thr_st sum_st, prod_st;
    FILE* fp1;
    FILE *fp2;

    sum_st.res = 0; 
    prod_st.res = 1;

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

    prod_st.fp = fp1;
    sum_st.fp = fp2;

    if(pthread_create(&prodId, NULL, &fun_prod, (void*)&prod_st))
    {
        printf("Error - pthread_create [prod]\n");
        exit(-1);
    }
    if(pthread_create(&sumId, NULL, &fun_sum, (void*)&sum_st))
    {
        printf("Error - pthread_create [sum]\n");
        exit(-1);
    }

    pthread_join(prodId, (void*)&prod_st);
    pthread_join(sumId, (void*)&sum_st);


    printf("Producto = %f\n", prod_st.res);
    printf("Suma = %f\n", sum_st.res);
    printf("Prod/Sum = %f\n", (prod_st.res)/(sum_st.res));


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