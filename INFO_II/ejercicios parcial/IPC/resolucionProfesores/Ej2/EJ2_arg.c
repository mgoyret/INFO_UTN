#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

// NOTA: compilar con -lpthread


struct thread_data
{
  FILE* fp;
  float val;
};


/*
===============================================================================================
============================================= THREAD SUMA =====================================
===============================================================================================*/  
void* fun_sumador(void* arg)
{

  struct thread_data* this = (struct thread_data*)arg; //Estructura que viene con la dirección del archivo a leer
  FILE* fp = this->fp;
 
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
    characters = getline(&buffer,&bufsize,fp); //Leo hasta que termine la línea (número) o 32 caracteres que sobrepasa un float
    this->val = this->val + atof(buffer);  //Voy sumando resultados parciales convirtiendo el array leído en float
  }


  free(buffer);


  return this;
}


/*
===============================================================================================
============================================= THREAD PRODUCTO =================================
===============================================================================================*/  

void* fun_multiplicador (void* arg)
{

  struct thread_data* this = (struct thread_data*)arg;
  FILE* fp = this->fp;

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
    this->val = this->val * atof(buffer); 
  }


  free(buffer);
  return this;
}



/*
===============================================================================================
============================================= ARRANCA MAIN=====================================
===============================================================================================*/  
int main(int argc, char *argv[])
{
  pthread_t thread_suma,thread_multiplicacion;
  struct thread_data struct_suma,struct_producto;
  FILE* fp1 = NULL;
  FILE* fp2 = NULL;
 
/*============================================= APERTURA DE ARCHIVOS =====================================*/  
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
/*=============================================== INICIALIZACIÓN DE ESTRUCTURAS ============================*/
  struct_suma.fp = fp1;
  struct_suma.val = 0;
  struct_producto.fp = fp2;
  struct_producto.val = 1;


/*=============================================== CREACIÓN DE THREADS ===========================================*/
  if (pthread_create(&thread_suma, NULL, &fun_sumador, (void*)&struct_suma)) //Argumento de thread estructura con dirección del archivo
  {
    perror("pthread_create()");
    exit(1);
  }

  if (pthread_create(&thread_multiplicacion, NULL, &fun_multiplicador, (void*)&struct_producto)) //Argumento de thread estructura con dirección del archivo
  {
    perror("pthread_create()");
    exit(1);
  }

/*=================================================== ESPERO QUE TERMINEN THREADS DE PROCESAR ======================*/ 
  pthread_join(thread_suma, (void*)&struct_suma); //Recibo misma estructura pero con el valor de la suma cargado
  pthread_join(thread_multiplicacion, (void*)&struct_producto); //Recibo misma estructura pero con el valor del producto cargado

/*=================================================== MUESTRO RESULTADOS ========================================*/ 
  printf("Producto = %f\n", struct_producto.val);
  printf("Suma = %f\n", struct_suma.val);
  printf("Cociente = %f\n", struct_producto.val/struct_suma.val);
 

  fclose(fp1); //Cierro desde acá o desde struct_suma.fp que es el mismo puntero
  fclose(fp2);


  return 0;
}
