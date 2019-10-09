#include "functions.h"

float calculadora(float a, float b, char op)
{
	float result = 0;
	switch(op)
	{  //lo que establece que casorealizar, sera la operacion que se ingresa

		case '+': result = a + b;	break;
		case '-': result = a - b;	break;
		case '*': result = a * b;	break;
		case '/': if(b==0) {printf("Operación no válida: División por cero\n");}
					else {result = a / b;}	break;
		default: printf("operacion no válida\n");
	}

	return result;
}
