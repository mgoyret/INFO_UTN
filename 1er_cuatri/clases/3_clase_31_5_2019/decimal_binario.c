//si se la cantidad de bits q tendra el numero, por ejemplo 8:

#include <stdio.h>
int main ()
{
    int num, i;
    int res[8];

    printf("digite numero menor a 256, u 8 bits:\n");
    scanf("%d", &num);
    
    for(i=7; i>0; i--)
    {
        res[i] = num%2;
        num /= 2;
    }
        res[i] = num; //este es el numero en binario

        for (i = 0; i < 8; i++)
        {
            printf("%d", res[i]);
        }
        printf("\n");
    return 0;
}