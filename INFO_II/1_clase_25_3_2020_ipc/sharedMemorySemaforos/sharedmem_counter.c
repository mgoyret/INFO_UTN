#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

struct shared_use_st {
  int counter;
};

int main(int argc, char *argv[]) {
  void *shared_mem = (void *) 0;
  struct shared_use_st *shared_stuff;
  int shmid;
  int cont;
  int pid;
  key_t key = ftok("memcompartida", 'a');

  shmid = shmget(key, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
  if (shmid == -1) {
    perror("Falló shmget");
    exit(EXIT_FAILURE);
  }
  
  shared_mem = shmat(shmid, (void *)0, 0);
  if (shared_mem == (void *)-1) {
    perror("Falló shmat");
    exit(EXIT_FAILURE);
  }
  shared_stuff = (struct shared_use_st *)shared_mem;
  shared_stuff -> counter = 0;


  pid=fork();
  for (cont=0;cont<10000000;cont++) {
    shared_stuff -> counter = shared_stuff -> counter+1;
  }

  if (pid == 0){
    exit(0);           /* El hijo se muere */
  }
  wait(NULL); /* Esperar a que se muera el hijo */

  printf("Contador: %d\n", shared_stuff -> counter);

  if (shmdt(shared_mem) == -1) {
    perror("Error en shmdt");
    exit(EXIT_FAILURE);
  }
  
  if (shmctl(shmid, IPC_RMID, 0) == -1) {
    perror("Error en shmctl");
    exit(EXIT_FAILURE);
  }
    
  exit(EXIT_SUCCESS);
}
