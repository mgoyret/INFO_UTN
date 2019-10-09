#include <stdio.h>
int main (){
	
	int a, b;

	printf("ingrese un dividendo entero\n");
	scanf("%d", &a);
	printf("ingrese un divisor entero\n");
	scanf("%d", &b);
	//con b=0, independientemente de a, se da una operacion indefinida, y el programa se cierra por no poder resolver
	//con a/b=1/2, toma solo la parte entera del resultado, ya que el tipo de datos int no lee decimales

	printf("resultado: %d\n", a/b);
	
return 0;
}
