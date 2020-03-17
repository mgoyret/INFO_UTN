#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>

#define ALARM_TIME 15

void miFuncion(int);
void miAlarma(int);
void seCorto(int);

int condicion = 1;
int cant = 0;

int main(void) {

    signal(SIGUSR1, miFuncion);
    signal(SIGINT, seCorto); // ctrl+C
    signal(SIGALRM, miAlarma); // alarma

    alarm(ALARM_TIME);

    while(condicion);

    printf("Sali del while\n");
    kill(getpid(), SIGUSR1); // Envio una señal a mi mismo
    signal(SIGINT, SIG_IGN);

    return 0;
}

void seCorto(int a) {
    signal(SIGINT, SIG_IGN); // Ignoro la señal por defecto
    printf("\nIntentaste cerrar. Sobrevivi al ctrl+c!\n");
    cant++;
    printf("Van %d veces\n", cant);
    signal(SIGINT, seCorto); // Reinstalo la señal
}

void miAlarma(int a) {
    printf("------- ¡¡Alarma!! -------\n");
    printf("Mi PID es: %d\n", getpid());
    condicion = 0; 
}

void miFuncion(int a) {
    printf("Estoy en SIGUSR1\n");
}