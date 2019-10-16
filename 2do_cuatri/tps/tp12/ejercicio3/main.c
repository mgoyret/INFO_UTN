
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#define TIEMPO_ALARMA 10

static int i = 0, status = 1;

void handler(int a);
void mi_alarma(int a);

int main()
{
    signal(SIGINT, handler);
    signal(SIGALRM, mi_alarma);

    alarm(TIEMPO_ALARMA);

    while(status);
    printf("Presionaste 'Ctrl + C' %d veces\n", i);
    printf("CHAU!\n");
    return 0;
}

void handler(int a)
{
    signal(SIGINT, SIG_IGN);
    i++;
    signal(SIGINT, handler);
}

void mi_alarma(int a)
{
    printf("ALARMA\n");
    status = 0;
}