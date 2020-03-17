#include <stdio.h>
int main (){

	float a, b;	//declaracion de variables numericas y de la operacion
	char op;
	printf("Digite el primer operador, la operación, y el segundo operador:	");
	scanf("%f %c %f", &a, &op, &b);

	switch(op)
	{  //lo que establece que casorealizar, sera la operacion que se ingresa

		case '+': printf("%f %c %f = %f\n", a, op, b, a+b); break;
		case '-': printf("%f %c %f = %f\n", a, op, b, a-b); break;
		case '*': printf("%f %c %f = %f\n", a, op, b, a*b); break;
		case '/': if(b==0) {printf("Operación no válida: División por cero\n");}
			else printf("%f %c %f = %f\n", a, op, b, a/b);  ; break;
		default: printf("operacion no válida\n");
	}
return 0;
}
