#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

// NOTA: compilar con -lpthread

#define N 20000000

// variable global (compartida por todos los threads)
int var_global;

// mutex para sincronizar acceso a datos compartidos entre threads
pthread_mutex_t mutex;

// función thread secundario
void* thread_function(void* arg)
{
  int cant;

  printf("\nThread secundario corriendo [tid = %lu] [pid %d]\n", pthread_self(), getpid());

  for (cant = 0; cant < N; cant++)
  {
    pthread_mutex_lock(&mutex);
    var_global = var_global + 1;
    pthread_mutex_unlock(&mutex);
  }

  printf("\nThread secundario procesamiento listo [tid %lu] [pid %d]\n", pthread_self(), getpid());

  return NULL;
}

// programa principal
int main(int argc, char *argv[])
{
  pthread_t thread_id;  // variable para almacenar el id del thread creado
  int cant;

  var_global = 0; // inicializo var_global en cero

  // creo mutex con atributos por default (NULL)
  if (pthread_mutex_init(&mutex, NULL))
  {
    perror("pthread_mutex_init()");
    exit(1);
  }

  // creo un nuevo thread con atributos por default (NULL) que va a ejecutar la
  // función thread_function sin recibir argumentos (NULL)
  if (pthread_create(&thread_id, NULL, &thread_function, NULL))
  {
    perror("pthread_create()");
    exit(1);
  }

  printf("Thread principal corriendo [tid %lu] [pid %d]\n", pthread_self(), getpid());

  for (cant = 0; cant < N; cant++)
  {
    pthread_mutex_lock(&mutex);
    var_global = var_global + 1;
    pthread_mutex_unlock(&mutex);
  }
  printf("\nThread principal procesamiento listo [tid %lu] [pid %d]\n", pthread_self(), getpid());

  // espero la finalización del thread secundario, pero no nos interesa el
  // valor devuelto (NULL)
  pthread_join(thread_id, NULL);

  // una vez que los dos threads terminaron el procesamiento, podemos
  // destruir el mutex
  pthread_mutex_destroy(&mutex);

  // imprimo variable global actualizada
  printf("\nValor final de la variable global: %d\n", var_global);

  return 0;
}