#include "functions.h"

int main (){

	float a = 0, b = 0, result = 0;	//declaracion de variables numericas y de la operacion
	char op;
	printf("Digite el primer operador, la operación, y el segundo operador:	");
	scanf("%f %c %f", &a, &op, &b);

    result = calculadora(a, b, op);

	printf("El resultado es %.3f\n", result);

    return 0;
}
