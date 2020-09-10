#include <stdio.h>

typedef struct BITS
{
    unsigned char b0:1;
    unsigned char b1:1;
    unsigned char b2:1;
    unsigned char b3:1;
    unsigned char b4:1;
    unsigned char b5:1;
    unsigned char b6:1;
    unsigned char b7:1;
}BITS;

typedef union PUERTO
{
    unsigned char valor;
    BITS bits;
}PUERTO;

void printPort(PUERTO p);
void printPort(PUERTO p)
{
    fprintf(stdout, "Valor [%d] = [%d %d %d %d %d %d %d %d]\n",
                    p.valor, p.bits.b7, p.bits.b6, p.bits.b5, p.bits.b4, p.bits.b3, p.bits.b2, p.bits.b1, p.bits.b0);
}

int modBit(PUERTO *p, unsigned char bit, unsigned char val);
int modBit(PUERTO *p, unsigned char bit, unsigned char val)
{
    if( (bit > 7) || (val > 1) )
    {
        printf("Error de argumentos en funcion modBit()\n");
        return -1;
    }
    switch (bit)
    {
        case 0: p->bits.b0 = val;
        break;

        case 1: p->bits.b1 = val;
        break;

        case 2: p->bits.b2 = val;
        break;

        case 3: p->bits.b3 = val;
        break;

        case 4: p->bits.b4 = val;
        break;

        case 5: p->bits.b5 = val;
        break;

        case 6: p->bits.b6 = val;
        break;

        case 7: p->bits.b7 = val;
        break;
    }

    return 0;
}

int main()
{
    PUERTO port;

    port.valor = 9;

    printPort(port);

    modBit(&port, 0, 0);

    printPort(port);

    return 0;
}
