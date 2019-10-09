#include <stdio.h>
int main (){

	char c;  //declaro una variable de cada tipo, para poder calcular su tama
	short s;
	int i;
	long l;
	float f;
	double d;
	printf("tipo de dato | bytes | bits\n");                               //al ejecutar el programa, los "|" quedaron desalineados,	
	printf("    char     |   %lu   |  %ld \n", sizeof(c), (sizeof(c))*8);  //por lo que lo compense en el codigo fuente
	printf("    short    |   %lu   |  %ld \n", sizeof(s), (sizeof(s))*8);
	printf("    int      |   %lu   |  %ld \n", sizeof(i), (sizeof(i))*8);
	printf("    long     |   %lu   |  %ld \n", sizeof(l), (sizeof(l))*8);
	printf("    float    |   %lu   |  %ld \n", sizeof(f), (sizeof(f))*8);
	printf("    double   |   %lu   |  %ld \n", sizeof(d), (sizeof(d))*8);  //sizeof da los bytes, y cada bite tiene 8 bits, por eso
return 0;								       //la multiplicacion del sizeof()*8
}
