#include <stdio.h>
int main ()
{
    char pal[20];
    printf("\033[00minicio\n\n");//nada
    printf("\033[04msubraya\n");//subraya
    printf("\033[00m\n");//limpio

    printf("\033[06m titila\n");//titila
    scanf("%s", pal);
    printf("\033[00m\n");//limpio

    printf("\033[07mresalta\n");//resalta
    scanf("%s", pal);
    printf("\033[00m\n");//limpio

    printf("\033[08minvisible\n");//invisible
    scanf("%s", pal);
    printf("\033[00m");//limpio




    
    return 0;
}