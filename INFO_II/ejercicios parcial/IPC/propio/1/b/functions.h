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

#define TEMPERATURA 1
#define PRESION     2
#define HUMEDAD     3


typedef struct msg
{
    long type;
    long data;
}msg;

struct datos {
    char tipo_sensor;
    long data;
};