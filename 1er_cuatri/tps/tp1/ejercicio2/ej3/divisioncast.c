#include <stdio.h>
int main (){

	int a, b;

	printf("ingrese un dividendo entero\n");
	scanf("%d", &a);
	printf("ingrese un divisor entero\n");
	scanf("%d", &b);
	//con b=0, se da una operacion indefinida, y el programa se cierra por no poder resolver

	printf("resultado: %f\n", ((float)a)/b); //casteo 'a' para que actue como float y pueda dividice en un no entero
	
return 0;
}
