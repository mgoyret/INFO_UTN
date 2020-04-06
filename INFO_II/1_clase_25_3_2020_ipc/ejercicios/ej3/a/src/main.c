/**
 * \file            main.c
 * \brief           Archivos Header - Prototipos de funciones definidas por el usuario
 * \author          Marcos Goyret
 * \date            Mar , 2020
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
    int cnt, shmid, *data, i, semid;
    int op;
    struct sembuf sb = {0, -1, 0};  /* arrancar en lock */
    
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
                /* 5. Creo la memoria compartira o me uno si ya existe */
                if((shmid = set_shm(cnt, &data)) != -1)
                {
                    /* 6. Creo semaforo o me uno si ya existe */
                    semid = set_sem(NULL);

                    /* 7. Bloqueo el semaforo para escribir en la memoria compartida */
                    sb.sem_op = -1; 
                    if (semop(semid, &sb, 1) != -1)
                    {
                        printf("Semaforo reservado para esto\n");
                        for(i=0; i<cnt; i++)
                        {
                            data[i] = msr[i].value;
                            printf("[%d]\n", data[i]);
                        }
                        /* 8. Desbloqueo semaforo */
                        sb.sem_op = 1;
                        if (semop(semid, &sb, 1) != -1)
                        {
                            printf("Semaforo desbloqueado\n");
                        }
                        else
                        {
                            printf("ERROR main [5]\n");
                        }        
                    }
                    else
                    {
                        printf("ERROR main [4]\n");
                    }
                    shmdt(data);
                    printf("Desattacheado de memoria compartida\n");
                    printf("presione:\n1 = borrar bloque de memoria compartida\n2 = continuar\n");
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


    return 0;
}