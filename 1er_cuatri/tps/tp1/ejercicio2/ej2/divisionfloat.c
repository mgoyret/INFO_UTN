#include <stdio.h>
int main (){

	float a, b;

	printf("ingrese un dividendo entero\n");
	scanf("%f", &a);
	printf("ingrese un divisor entero\n");
	scanf("%f", &b);
	//con a!=0 y b=0, se da una operacion indefinida, pero el programa toma infinito como resultado
	//con a=0 y b=0, al no ser una operacion valida, no toma al resultado como un numero (devuelve nan)
	//con a/b=1/2, devuelve el resultado sin problemas, ya que el tipo de datos float acepta numeros no enteros

	printf("resultado: %f\n", a/b);
	
return 0;
}
