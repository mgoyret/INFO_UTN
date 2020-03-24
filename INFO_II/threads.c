#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void* mostrarX(void *);

int main()
{
    pthread_t thread_id; //crea la variable thread de tipo pid thread
    //imprime el id del proceso padre por la salida estandar.
    fprintf (stdout, "El pid del thread principal es %d\n", (int) getpid ());
    /* realiza la llamada para crear elthread, el cual comenzara su ejecución
    con la función
    thread_function */
    pthread_create(&thread_id,NULL,&mostrarX,NULL);
    while(1)
    fputc('o', stdout);
    return 0;
}

void* mostrarX(void *sinUso)
{
    while(1)
    fputc('x',stdout);
    return NULL;
}