/**
 * Marcos Goyret
 * Practica 2do parcial Info1 UTN 29/11/2019
*/

/*
    Realizar un programa en C que permita el ingreso de dos números y generé un proceso hijo.
    El proceso padre realizará la suma de ambos números y lo mostrará por pantalla. El proceso hijo realiza
    la multiplicación de los números y lo muestra por pantalla.
    Tome todas las precauciones necesarias al momento de codificar y explique línea por línea su funcionamiento.
*/


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int pid;
    
    if (argc == 3)
    {
        pid = fork();
        if(pid > 0)
        {
            printf("PADRE (pid %d). Mi hijo es %d\n\n%d + %d = %d\n\n", getpid(), pid, atoi(argv[1]), atoi(argv[2]), atoi(argv[1]) + atoi(argv[2]));
        }
        else if (pid == 0)
        {
            printf("HIJO (pid %d). Mi padre es %d\n\n%d * %d = %d\n\n", getpid(), getppid(), atoi(argv[1]), atoi(argv[2]), atoi(argv[1]) * atoi(argv[2]));
        }
        else
            printf("ERROR\n");
    }
    else
        printf("Error de argumentos.\n./<programa> <operando 1> <operando 2>\n");
    
    return 0;
}