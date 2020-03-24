/*
** shmdemo.c -- read and write to a shared memory segment
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>


#define SHM_SIZE 102  /* make it a 1K shared memory segment */
#define MY_KEY 123456


int get_sema( int key, char *f)
{
int shmid;
	*f=0;
	/* connect to (and possibly create) the segment: */
	if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT| IPC_EXCL)) >=0) 
	{
		*f=1;	// semaro recien creado - hay que inicializar
		return shmid;
	}
	if (errno==EEXIST)
		if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) >=0) 
			return shmid;

return -1;
}



int main(int argc, char *argv[])
{
	int shmid;
	char *data;
	char flag_new;

	/* connect to (and possibly create) the segment: */
	if ((shmid = get_sema(MY_KEY,&flag_new)) == -1) 
	{
		perror("shmget");
		exit(1);
	}


	/* attach to the segment to get a pointer to it: */
	data = shmat(shmid, (void *)0, 0);
	if (data == (char *)(-1)) {
		perror("shmat");
		exit(1);
	}

	printf("\nkey: %d  - shmid: %d  shmat:%p\n",MY_KEY,shmid,data);

	if (flag_new)
		strcpy(data,"Hola ");
				
	
	/* read or modify the segment, based on the command line: */
	if (argc >= 2) 
	{
		if (!strcasecmp (argv[1],"empty"))
			*data=0;
		else if (!strcasecmp (argv[1],"kill"))
		{
			 shmctl(shmid, IPC_RMID, NULL); // falta chequear error
			 printf("\nChau semáforo (los datos no se borran)\n");
		}
		else if (!strcasecmp (argv[1],"epa"))
		{
			memset (data,'Z',SHM_SIZE+512);
			printf("\nsigo vivo?\n");
		}
		else if (strlen(data)+strlen(argv[1])+2>=SHM_SIZE)
			printf("\nSin espacio suficiente en el Buffer\n");
		else
		{

			printf("adding to segment: \"%s\"\n", argv[1]);
			
			strcat(data, " ");
			strcat(data, argv[1]);
		}
	} 
		
	printf("\nsegment contains: \"%s\"\n", data);
	getchar();
	/* detach from the segment: */
	if (shmdt(data) == -1) {
		perror("shmdt");
		exit(1);
	}

	return 0;
}
