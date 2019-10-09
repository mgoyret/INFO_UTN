#include <stdio.h>
int main ()
{
	int a;
	int *p;

	a = 5;
	p = &2;  //el puntero vale la direccion de a.   El contenido de lo apuntdo por p es a

	printf("a = %d\n", a);
	printf("direccion de a = %x\n", &a);   //%x para interpretar direccion
	printf("la direccion de a atravez de p = %p\n", p);   //p guarda la direccion de a,%p es como el %x pero para cuando uso punteros
	printf("*p es el contenido de lo apuntado por p, y es %d\n", *p); 
}
