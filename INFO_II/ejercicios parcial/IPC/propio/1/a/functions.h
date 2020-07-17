#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define KEYPATH "keyfile"
#define KEYNUM  0

#define MSGTAM  100

typedef struct msg
{
    long type;
    char msg[MSGTAM];
}msg;
