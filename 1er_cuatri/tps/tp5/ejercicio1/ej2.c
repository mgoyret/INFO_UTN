#include <stdio.h>
int main (void)
{
    int varIntA, varIntB;
    char varCharA, varCharB;

    printf("varIntA = %08x; %p\r\n", varIntA, &varIntA);
    printf("varIntB = %08x; %p\r\n", varIntB, &varIntB);
    printf("varCharA = %08x; %p\r\n", varCharA, &varCharA);
    printf("varCharB = %08x; %p\r\n", varCharB, &varCharB);
    
    return 0;
}