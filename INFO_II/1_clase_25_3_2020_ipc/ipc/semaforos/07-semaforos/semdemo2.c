/*
** semdemo.c -- demonstrates semaphore use as a file locking mechanism
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define MAX_RETRIES 10

union semun {
	int val;
	struct semid_ds *buf;
	ushort *array;
};

/*
** initsem() -- more-than-inspired by W. Richard Stevens' UNIX Network
** Programming 2nd edition, volume 2, lockvsem.c, page 295.
*/
int initsem(key_t key, int nsems)  /* key from ftok() */
{
	struct sembuf sb;
	int semid;

	semid = semget(key, nsems, IPC_CREAT | IPC_EXCL | 0666);

	if (semid >= 0) 
	{ /* we got it first */
		sb.sem_op = 1; 
		sb.sem_flg = 0;

		for(sb.sem_num = 0; sb.sem_num < nsems; sb.sem_num++) 
		{ 
			/* do a semop() to "free" the semaphores. */
			/* this sets the sem_otime field, as needed below. */
			if (semop(semid, &sb, 1) == -1) 
			{
				int e = errno;
				semctl(semid, 0, IPC_RMID); /* clean up */
				errno = e;
				return -1; /* error, check errno */
			}
		}
		return semid;
	} 

	if (errno == EEXIST) 
	{ /* someone else got it first */
		semid = semget(key, nsems, 0); /* get the id */
		if (semid >= 0) 
			return semid; 
	}

return -1;
}

int main(int argc, char *argv[])
{
	key_t key;
	int semid;
	struct sembuf sb;


//----------------------------------------------- Argumentos
	if (argc<3)
	{
		printf ("\n ERROR:\n\t *** Ingrese ./app (+/-)sema_val bit_mode(1 NOWAIT/2 UNDO)***\n");
		return 0;
	}
	
	// Nro de semaforo
	sb.sem_num = 0;

	// valor de operacion ==> sem_val
	sb.sem_op =atoi(*(argv+1));
	printf ("--> sem_op:  %d \n-->sem_flg:",sb.sem_op);
	
	// Flags
	sb.sem_flg = 0;
	if (atoi(*(argv+2))&0x01)
	{
		sb.sem_flg |= IPC_NOWAIT;
		puts ("IPC_NOWAIT ");
	}
	if (atoi(*(argv+2))&0x02)
	{
		sb.sem_flg |= SEM_UNDO;
		puts ("SEM_UNDO");
	}
	if (!sb.sem_flg)
		puts ("EMPTY");
		
	
//----------------------------------------------- toma semaforo
	
	if ((key = ftok("semdemo.c", 'J')) == -1) {
		perror("ftok");
		exit(1);
	}
		
	/* grab the semaphore set created by seminit.c: */
	if ((semid = initsem(key, 1)) == -1) {
		perror("initsem");
		exit(1);
	}

//----------------------------------------------- operacion

	printf ("\n ***>> %d \n",semctl(semid, 0, GETVAL, NULL));

	if (semop(semid, &sb, 1) == -1) 
	{
		perror("semop");
		exit(1);
	}
	printf ("\n ***>> %d \n",semctl(semid, 0, GETVAL, NULL));

	return 0;
}