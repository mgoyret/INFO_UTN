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
void leerArchivo (struct shared_use_st **);
void modificar_sem(int, int, struct sembuf);
void devolverRecursos(void**, int,int);
int getSemaforo(void);


union semun {
  int              val;    /* Value for SETVAL */
  struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
  unsigned short  *array;  /* Array for GETALL, SETALL */
  struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux specific) */
};


struct shared_use_st {
  char texto[500];
};



int main(int argc, char *argv[]) {
  void *shared_mem = (void *) 0;
  struct shared_use_st *shared_stuff;
  int shmid, semid;
  struct sembuf sb = {0, -1, 0};  /* arrancar en lock */


  shared_stuff = adquirirMemoria(&shmid, &shared_mem); //Pido memoria shm si no estaba pedida

  leerArchivo(&shared_stuff); //Cargo en shared memory el archivo indicado por scanf();
  printf("Texto: %s\n", shared_stuff->texto);
  

  semid=getSemaforo(); //Recién con la memoria escrita habilito a los otros programas (SETVAL = 1)

  modificar_sem(LOCK, semid, sb); //Bloqueo esperando que lleguen programas antes de borrar sem y shm (VAL=0)
  devolverRecursos(&shared_mem, shmid,semid); //Borro sem y shm
  printf("Cerró todo correctamente\n");
  exit(EXIT_SUCCESS); 
}






struct shared_use_st * adquirirMemoria(int * shmid, void** shared_mem)
{
  key_t key; 
  if ((key = ftok("Ej3.c", 'a')) == -1) //Pido una clave que debe coincidir con los otros programas
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


void leerArchivo(struct shared_use_st ** shared_stuff)
{

  char buffer[100];
  FILE* fp;
  int i=0;


  printf("Ingrese el nombre del archivo\n");
  scanf("%s", buffer);

  fp = fopen(buffer, "r");
  if(fp==NULL)
  {
    perror("Error al abrir el archivo");
    exit(EXIT_FAILURE);
  }

  while(!feof(fp))
  {
    (*shared_stuff) -> texto[i] = getc(fp);
    i++;
  }

  if(i>0) //Aseguro que se haya leído al menos un caracter
    (*shared_stuff) -> texto[i-1] = '\0';
  else
    (*shared_stuff) -> texto[0] = '\0';
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



void devolverRecursos(void** shared_mem, int shmid,int semid)
{
    union semun arg;

    if (shmdt(*shared_mem) == -1) {
    perror("shmdt in shrmem2_sysV failed");
    exit(EXIT_FAILURE);
  }
  
  if (shmctl(shmid, IPC_RMID, 0) == -1) {
    perror("shmctl in shrmem2_sysV failed");
    exit(EXIT_FAILURE);
  }

  if (semctl(semid, 0, IPC_RMID, arg) == -1) {
      perror("semctl");
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

  //Como es el programa principal es el único que tiene derecho a forzar el semáforo
  //El resto de los programas se quedará esperando a que este lo escriba
  //Si no estaban escuchando el desbloqueo de la memoria, se lo pierden
  arg.val = 1; //Arranca en 2 debido a que hay 2 programas que van a requerir la memoria
  if (semctl(semid, 0, SETVAL, arg) == -1) 
  {
      perror("semctl");
      exit(1);
  }

  return semid;
}