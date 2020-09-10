/**
 * \file            main.c
 * \brief           Archivos Header - Prototipos de funciones definidas por el usuario
 * \author          Marcos Goyret
 * \date            Abr 06, 2020
 * \details         Usar MakeFile para compilar y linkear
 */

/*
    Consigna
    Un segundo programa recibe por argumentos del main la cantidad de muestras
    y debe recorrer las primeras N muestras e informar del promedio de temperatura.
*/

#include "../inc/functions.h"

int main (int argc, char** argv)
{
    int shmid, *data, semid, i, op, cnt, sum = 0;
    float prom;
    struct sembuf sb = {0, -1, 0};  /* arrancar en lock */
    union semun arg;
    
    if(argc == 2)
    {   
        cnt = atoi(argv[1]);
        printf("Se calculara el promedio de las primeras %d mediciones del array\n", cnt);
        /* 5. Creo semaforo o me uno si ya existe */
        if((semid = set_sem(&arg)) != -1)
        {
            printf("\nIDENTIFICACION SEMAFORO [%d]\n\n", semid);
            /* 6. Bloqueo el semaforo para leer la memoria compartida */
            printf("Estoy frente al semaforo\n");
            sb.sem_op = -1; 

            /////////////////////////////////////////////// SEMAFORO ABIERTO ////////////////////////////////////////////////

            if (semop(semid, &sb, 1) != -1)
            {
                printf("Semaforo reservado para esto\n");
                /* 7. Creo la memoria compartira o me uno si ya existe */
                if((shmid = set_shm(NULL)) != -1)
                {
                    printf("\nIDENTIFICACION MEMORIA COMPARTIDA [%d]\n\n", shmid);
                    if((data = (int*)shmat(shmid, NULL, 0)) != (void*)-1)
                    {
                        printf("attache a la memoria realizado");
                        printf("Comenzando lectura\n");
                        for(i=1; i<=cnt; i++)
                        {
                            printf("%d + %d = \n", sum, data[i]);
                            sum += data[i];
                            printf("%d\n", sum);
                        }
                        prom = sum/cnt;
                        printf("promedio = %.3f = %d/%d\n", prom, sum, cnt);
                    }
                    else
                    {
                        printf("ERROR main shmat() [5]\n");
                    }
                }
                else
                {
                    printf("ERROR main set_shm [4]\n");
                }

                shmdt(data);
                printf("Desattacheado de memoria compartida\n");
                printf("presione:\n1 = eliminar bloque de memoria compartida\n2 = continuar sin eliminar\n");
                do
                {
                    printf("opcion:");
                    scanf("%d", &op);
                }while ((op != 1) && (op != 2));
                if(op == 1)
                {
                    shmctl(shmid, IPC_RMID, 0);
                    printf("Bloque de memoria compartida eliminado\n");
                }
                else
                {
                    printf("Continuando sin eliminar\n");
                }
                /* 14. Desbloqueo semaforo */
                sb.sem_op = 1;
                if (semop(semid, &sb, 1) != -1)
                {
                    printf("Semaforo desbloqueado\n");
                    printf("presione:\n1 = eliminar semaforo\n2 = continuar sin eliminar\n");
                    do
                    {
                        printf("opcion:");
                        scanf("%d", &op);
                    }while ((op != 1) && (op != 2));
                    if(op == 1)
                    {
                        if (semctl(semid, 0, IPC_RMID, arg) != -1)
                        {
                            printf("semaforo eliminado\n");
                        }
                        else
                        {
                            printf("ERROR main semctl [6]\n");
                        }
                    }
                    else
                    {
                        printf("Continuando sin eliminar\n");
                    }
                }
                else
                {
                    printf("ERROR main semop() [5]\n");
                }  
            }
            else
            {
                printf("ERROR main semop() [5]\n");
            }       
        }
        else
        {
            printf("ERROR main set_sem()\n");
        }
    }
    else
        printf("ERROR main [1]\n./<programa> <cantidad de mediciones>\n");

    printf("FIN MAIN\n");
    return 0;
}