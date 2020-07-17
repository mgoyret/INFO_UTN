#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

// NOTA: compilar con -lpthread


// mutex para sincronizar acceso a datos compartidos entre threads
pthread_mutex_t mutex_suma;
float suma = 0;
pthread_mutex_t mutex_producto;
float producto = 1;


// función thread secundario

void* fun_sumador(void* arg)
{

  FILE* fp = arg;
 
  char *buffer;
  size_t bufsize = 32; //Sobra para float
  size_t characters;

  buffer = (char *)malloc(bufsize * sizeof(char));
  if( buffer == NULL)
  {
      perror("Unable to allocate buffer");
      exit(1);
  }

  while(!feof(fp))
  {  
    characters = getline(&buffer,&bufsize,fp);
    pthread_mutex_lock(&mutex_suma);
    suma = suma + atof(buffer); 
    pthread_mutex_unlock(&mutex_suma);
  }


  free(buffer);


  return NULL;
}


void* fun_multiplicador (void* arg)
{

  FILE* fp = arg;
 
  char *buffer;
  size_t bufsize = 32;
  size_t characters;

  buffer = (char *)malloc(bufsize * sizeof(char));
  if( buffer == NULL)
  {
      perror("Unable to allocate buffer");
      exit(1);
  }

  while(!feof(fp))
  {  
    characters = getline(&buffer,&bufsize,fp);
    pthread_mutex_lock(&mutex_producto);
    producto = producto * atof(buffer); 
    pthread_mutex_unlock(&mutex_producto);
  }


  free(buffer);
  return NULL;
}



// programa principal
int main(int argc, char *argv[])
{
  pthread_t thread_suma;
  pthread_t thread_multiplicacion;
  FILE* fp1 = NULL;
  FILE* fp2 = NULL;
 
  
  fp1=fopen("Archivo1", "r");
  if(fp1 == NULL)
  {
    perror("fopen1");
    exit(1);
  }


  fp2=fopen("Archivo2", "r");
  if(fp2 == NULL)
  {
    perror("fopen2");
    exit(1);
  }

  // creo mutex con atributos por default (NULL)
  if (pthread_mutex_init(&mutex_suma, NULL))
  {
    perror("pthread_mutex_init()");
    exit(1);
  }



  if (pthread_mutex_init(&mutex_producto, NULL))
  {
    perror("pthread_mutex_init()");
    exit(1);
  }

  // creo un nuevo thread con atributos por default (NULL) que va a ejecutar la
  // función thread_function sin recibir argumentos (NULL)
  if (pthread_create(&thread_suma, NULL, &fun_sumador, (void*)fp1))
  {
    perror("pthread_create()");
    exit(1);
  }


  if (pthread_create(&thread_multiplicacion, NULL, &fun_multiplicador, (void*)fp2))
  {
    perror("pthread_create()");
    exit(1);
  }
 
  pthread_join(thread_suma, NULL);
  pthread_join(thread_multiplicacion, NULL);


  pthread_mutex_lock(&mutex_suma);
  pthread_mutex_lock(&mutex_producto);
  printf("Producto = %f\n", producto);
  printf("Suma = %f\n", suma);
  printf("Cociente = %f\n", producto/suma);
  pthread_mutex_unlock(&mutex_producto);
  pthread_mutex_unlock(&mutex_suma);



  // una vez que los dos threads terminaron el procesamiento, podemos
  // destruir el mutex
  pthread_mutex_destroy(&mutex_suma);
  pthread_mutex_destroy(&mutex_producto);
  fclose(fp1);
  fclose(fp2);


  return 0;
}
