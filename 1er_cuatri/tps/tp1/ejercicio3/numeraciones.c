#include <stdio.h>
int main (){

	int a;
	
	printf("ingrese un numero entero\n");
	scanf("%d", &a);
	
	printf("el numero %d vale:\n", a);	
	printf("en decimal: %d\n", a);        //%d lee en decimal
	printf("en hexadecimal: %x\n", a);    //%x lee en hexadecimal
	printf("en octal: %o\n", a);          //%o lee en octal
return 0;
}
