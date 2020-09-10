/**
 * \file            main.c
 * \brief           Archivos Header - Prototipos de funciones definidas por el usuario
 * \author          Marcos Goyret
 * \date            Abr 06, 2020
 * \details         Usar MakeFile para compilar y linkear
 */

/*
    Consigna
    Generar un programa que reciba por argumentos del main el nombre de un archivo que contiene
    mediciones de sensores con el siguiente formato: idSensor,valor
    Dichos sensores toman la temperatura de diferentes lugares de un entorno, el tamaño máximo es de 1024 mediciones,
    luego debe empezar a escribirse como si fuese una cola. Se requiere implementar un bloque de memoria dinámica que
    permita cargar los valores de temperatura (la identificación no es importante en este caso).
    Dicho programa puede ser utilizado por diferentes procesos para cargar datos en forma simultánea. 
*/

#include "../inc/functions.h"

int main (int argc, char** argv)
{
    FILE *fp;
    meassure *msr = NULL;
    int cnt, shmid, *data, semid, pos = 1, flag = -1, i, op, tot = 0, first_cnt = 0, scnd_cnt = 0, j = 0;
    struct sembuf sb = {0, -1, 0};  /* arrancar en lock */
    union semun arg;
    
    if(argc == 2)
    {   
        /* 1. Abro archivo contenedor de mediciones */
        if((fp = fopen(argv[1], "r")) != NULL)
        {
            /* 2. Chequeo la cantidad de mediciones contenidas en el archivo */
            cnt = msr_tot(fp);
            printf("Total de mediciones [%d]\n", cnt);
            /* 3. Creo array de estructuras que guardaran cada medicion con el id de su sensor */
            if((msr = (meassure*)malloc(sizeof(meassure)*cnt)) != NULL)
            {
                /* 4. ln_st() copia el contenido del archivo en el array de estructuras */
                ln_st(fp, msr, cnt);
                //show(msr, cnt);

                /* 5. Creo semaforo o me uno si ya existe */
                if((semid = set_sem(&arg)) != -1)
                {
                    printf("\nIDENTIFICACION SEMAFORO [%d]\n\n", semid);
                    /* 6. Bloqueo el semaforo para escribir en la memoria compartida */
                    printf("Estoy frente al semaforo\n");
                    sb.sem_op = -1; 

    /////////////////////////////////////////////// SEMAFORO ABIERTO ///////////////////////////////////////////////////////

                    if (semop(semid, &sb, 1) != -1)
                    {
                        printf("Semaforo verde!\n");
                        /* 7. Creo la memoria compartira o me uno si ya existe */
                        if((shmid = set_shm(&pos, &flag)) != -1)
                        {
                            printf("\nIDENTIFICACION MEMORIA COMPARTIDA [%d]\n\n", shmid);
                            if((data = (int*)shmat(shmid, NULL, 0)) != (void*)-1)
                            {
                                printf("attache a la memoria realizado, flag es %d\n", flag);
                                /* 8. Si es un nuevo bloque de memoria */
                                if (flag == NEW_MEM)
                                {
                                    printf("Se limpiara el nuevo bloque de memoria\n");
                                    for(i=0; i< SHM_SIZE; i++)
                                    {
                                        data[i] = 0;
                                    }
                                    printf("Memoria seteada a 0\n");
                                    /* 9. En 'pos' almaceno la primera posicion sobre la que se puede escribir */
                                    pos = 1;
                                    printf("pos seteado a %d\n", pos);
                                }
                                else if(flag == OLD_MEM)
                                {
                                    pos = data[0];
                                }
                            }
                            printf("pos seteado a %d\n", pos);

                            printf("Comenzando escritura\n");
                            first_cnt = cnt;
                            /* 10. Si quiero escribir mas posiciones de las que quedan disponibles en esta vuelta del array */
                            if ((pos-1+cnt) > (SHM_SIZE-1))
                            {
                                printf("Se escribira la cantidad restante de posiciones del array y se retomara desde el inicio del mismo\n");
                                /* 11. Ahora first_cnt es la cantidad de posiciones disponibles para escribir
                                    antes de comenzar de vuelta */
                                first_cnt = ((SHM_SIZE-1) - pos + 1);
                                scnd_cnt = cnt -((SHM_SIZE-1) - pos + 1);
                            }
                            for(i=pos; i<first_cnt+pos; i++)
                            {
                                data[i] = msr[j].value;
                                usleep(2500); //para chequear semaforo
                                printf("data[%d] = [%d]\n", i, data[i]);
                                tot++;
                                j++;
                            }

                            /* 12. Si se lleno el array se comienza desde el inicio nuevamente */
                            if ((pos-1+cnt) > (SHM_SIZE-1))
                            {
                                printf("Escribiendo desde inicio del array\n");
                                pos = 1;
                                for(i=pos; i<=scnd_cnt; i++)
                                {
                                    data[i] = msr[j].value;
                                    usleep(2500); //para chequear semaforo
                                    printf("data[%d] = [%d]\n", i, data[i]);
                                    tot++;
                                    j++;
                                }
                                pos = i;
                                printf("Se escribieron %d posiciones\n", tot);
                                printf("pos seteado en [%d]\n", pos); 
                            }
                            else
                            {
                                printf("Se escribieron %d posiciones\n", tot);
                                pos = pos + tot;
                                printf("pos seteado en [%d]\n", pos);
                            } 
                        }
                        else
                        {
                            printf("ERROR main set_shm [4]\n");
                        }
                        /* 13. Actualizo el valor del subindice sobre el cual debe continuar llenandose el array */
                        data[0] = pos;
                        printf("data[0] quedo en %d\n", data[0]);
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
                }
                else
                {
                    printf("ERROR main set_sem\n");
                }
            }
            else
                printf("ERROR main [3]\n");

            fclose(fp);
        }
        else
            printf("ERROR main [2]\n");
    }
    else
        printf("ERROR main [1]\n./<programa> <archivo>\n");

    printf("FIN MAIN\n");
    return 0;
}