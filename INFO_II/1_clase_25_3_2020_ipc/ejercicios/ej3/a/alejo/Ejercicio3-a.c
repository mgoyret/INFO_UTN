/**
* \file            Ejercicio3-a.c
* \brief           Ejercicios IPC – parte 1 - Ejercicio3-a
* \author          Alejo Fernadez Bados
* \date            April 9, 2019
* \details         Usar Makefile para compilar, linkear y ejecutar
*/

#include "functions.h"

int main()
{
	//DEfinicion de variables
	int shmid,medicion,cant=1,i,tam,terminar=0,*data;
	char archivo[50], linea[150], *aux;
	key_t key;
	tam=(int)(sizeof(int)*SHM_SIZE);
	FILE *fp = NULL;
	int semid;
	union semun arg;
  	struct sembuf sb = {0, -1, 0};  /* arrancar en lock */

	//Creacion de la llave
	if ((key = ftok("key.txt", 'A')) == -1) {
		perror("ftok memoria");
		exit(1);
	}

	//Creo la memoria o me uno si ya existe
	if ((shmid = get_shm(key,&cant,(size_t)tam)) == -1) 
	{
		perror("shmget");
		exit(1);
	}


	//Obtener un puntero que apunte a la zona de memoria
	data = shmat(shmid, (void *)0, 0);
	if (data == (int *)(-1)) {
		perror("shmat");
		exit(1);
	}

	printf("\nkey: %d  - shmid: %d  shmat:%p\n",key,shmid,data);

	//Creacion de la llave para el semaforo
	if ((key = ftok("key.txt", 'J')) == -1) {
     perror("ftok");
     exit(1);
  	}
	printf("La key del semaforo es: %d \n",key);

	//Creo semaforo o me uno si ya existe
  	if ((semid = semget(key,1, IPC_CREAT| IPC_EXCL | 0600)) >=0) 
	{
		// Iniciializo el semaforo
		arg.val = 1;
		if (semctl(semid, 0, SETVAL, arg) == -1) {
			perror("semctl");
			exit(1);
		}
		printf("Cree el semaforo\n");
	}
	else if (errno==EEXIST){
		semid = semget(key, 1, IPC_CREAT | 0600);
  	}

	if (semid == -1) {
		perror("Falló semid");
		exit(1);
	}
	//Bloqueo el semaforo
	sb.sem_op = -1; 
    if (semop(semid, &sb, 1) == -1) {
        perror("semop");
        exit(1);
    }
	/*Tomo el valor de cant que se guarda
	en el primer lugar*/
	if(cant==1)
		cant=data[0];

	printf("Como se llama el archivo?\n");
	fgets(archivo, sizeof(char) * 50, stdin);
	archivo[strlen(archivo)-1]='\0';
	//Abro el archivo
	fp = fopen(archivo, "r");
	if(fp!=NULL){
		//Leo una linea y tomo la medicion
		fgets(linea, sizeof(char)*150,fp);
		while(feof(fp)==0 && cant<SHM_SIZE+1){
		strtok(linea,",");
		aux=strtok(NULL,"\n");
		medicion=atoi(aux);
		for(i=cant;i>0;i--)
			data[i+1]=data[i];
		data[1]=medicion;
		cant++;
		fgets(linea, sizeof(char)*150,fp);
		}
		if(feof(fp)!=0 && cant>SHM_SIZE){
			printf("Memoria LLena:No se pudo cargar mas mediciones\n");
		}
	} 
	data[0]=cant;
	//Muestro en pantalla las mediciones
	printf("Cant es %d las temperaturas: \n",cant);
	for(i=1;i<cant+1;i++){
		if(i!=cant)
			printf("%d,",data[i]);
		else
		{
			printf("%d",data[i]);	
		}
		if(i%15==0)
			printf("\n");
	}
	//Desbloqueo semaforo
	sb.sem_op = 1;
    if (semop(semid, &sb, 1) == -1) {
        perror("semop");
        exit(1);
    }
	//Me desacoplo de la memoria
	if (shmdt(data) == -1) {
		perror("shmdt");
		exit(1);
	}
	printf("\nQueres borrar la memoria compartida ?(0-No1-Si)\n");
	scanf("%d",&terminar);
	if (terminar==1){
		if(shmctl(shmid, IPC_RMID, NULL) == -1) {
			perror("semctl");
			exit(1);
		}
		if (semctl(semid, 0, IPC_RMID, arg) == -1) {
			perror("semctl");
			exit(1);
		}
		exit(EXIT_SUCCESS);
	}
	return 0;
}