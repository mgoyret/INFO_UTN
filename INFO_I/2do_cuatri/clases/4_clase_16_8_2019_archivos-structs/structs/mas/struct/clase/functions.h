#include <stdio.h>
#include <stdlib.h>

typedef struct user
{
    char name[20];
    int key;
}user;

int add(user **q, char *name, int key, int tam);

void show(user **q, int tam);