#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

/* -lpthread para linkear */

void* mostrarX(void *);

int main ()
{
    pthread_t thread_id; //crea la variable thread_id de tipo pthread_t
    //imprime el id del proceso padre por la salida estandar.
    fprintf (stdout, "El pid del thread principales %d\n", (int) getpid ());

    /* realiza la llamada para crear el thread */
    pthread_create(&thread_id,NULL,&mostrarX,NULL);
    while(1)
        fputc('o',stdout);
    return 0;
}

void* mostrarX(void *sinUso)
{
    while(1)
    fputc('x',stdout);
    return NULL;
}