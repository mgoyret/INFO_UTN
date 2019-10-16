
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static int i = 0;

void handler(int a);

int main()
{
    signal(SIGINT, handler);
    while(i < 5);
    printf("CHAU!\n");
    return 0;
}

void handler(int a)
{
    signal(SIGINT, SIG_IGN);
    printf("Presionaste!\n");
    i++;
    signal(SIGINT, handler);
}