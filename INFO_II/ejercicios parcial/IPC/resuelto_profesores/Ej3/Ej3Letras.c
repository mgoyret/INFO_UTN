#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <linux/errno.h>


#define LOCK -1
#define UNLOCK 1

struct shared_use_st * adquirirMemoria(int *, void**);
void modificar_sem(int, int, struct sembuf);
int getSemaforo(void);
void contarLetras(struct shared_use_st * );


union semun {
  int              val;    /* Value for SETVAL */
  struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
  unsigned short  *array;  /* Array for GETALL, SETALL */
  struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux specific) */
};


struct shared_use_st {
  char texto[500];
};



int main(int argc, char *argv[]) 
{
  void *shared_mem = (void *) 0;
  struct shared_use_st *shared_stuff;
  int shmid, semid;
  struct sembuf sb = {0, -1, 0};  /* arrancar en lock */


  shared_stuff = adquirirMemoria(&shmid, &shared_mem);//Crea la memoria si no lo había hecho alguien ya 


  semid=getSemaforo();//Consigue el semáforo que arranca en 0

  modificar_sem(LOCK, semid, sb); //Bloquea esperando que alguien lo habilite. Si agarra primero cuando principal hace SETVAL=1, pasa. Sino, esperará a que Ej3palabras haga UNLOCK

  contarLetras(shared_stuff); //Accede a memoria

  modificar_sem(UNLOCK, semid, sb); //Si fue el primero, libera para que Ej3Palabras lea y si fue el segundo, libera para que Ej3 borre la shm y el sem

  printf("Cerró todo correctamente\n");
  exit(EXIT_SUCCESS);
}






struct shared_use_st * adquirirMemoria(int * shmid, void** shared_mem)
{
  key_t key;
  if ((key = ftok("Ej3.c", 'a')) == -1) 
  {
    perror("ftok");
    exit(1);
  }

  *shmid = shmget( key, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
  if (*shmid == -1) 
  {
    perror("Falló shmget");
    exit(EXIT_FAILURE);
  }

  *shared_mem = shmat(*shmid, NULL, 0); //shmat() atacheo segmento shared memory del ID conseguido, con NULL especifico que elija una posición de memoria el SO (alineada con las páginas) y 0 para indicar ningún flag
  if(*shared_mem == (void*)-1)
  {
    perror("Falló shmat");
    exit(EXIT_FAILURE);

  }
  return (struct shared_use_st *)*shared_mem;
}

void modificar_sem(int val, int semid, struct sembuf sb)
{
  sb.sem_op = val;
  if (semop(semid, &sb, 1) == -1) 
  {
      perror("semop");
      exit(1);
  }
}


int getSemaforo (void)
{
  key_t key;
  int semid;
  union semun arg;

  if ((key = ftok("Ej3.c", 'Q')) == -1) 
  {
     perror("ftok");
     exit(1);
  }

  if ((semid = semget(key, 1, IPC_CREAT | 0600)) == -1) 
  {
     perror("semget");
     exit(1);
  }

  return semid;
}


void contarLetras(struct shared_use_st * shared_stuff)
{
  int i=0;
  int cant=0;

  unsigned char caracter;

  while(shared_stuff -> texto[i] != '\0')
  {
      caracter = shared_stuff -> texto[i];
      if((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z')) //No tengo en cuenta las letras tildadas porque... :)
         cant++;
      i++;
  }

  printf("La cantidad de letras es %d\n", cant+1); //Cantidad de separadores + 1
}