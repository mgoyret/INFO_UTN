#include <stdio.h>
#include <math.h> //header math.h habilita la libreria que contiene la funcion pow

int main (){

	int mychar=sizeof(char)*8;   //el rango de una variable depende de su cantidad de bits, calculo esta con sizeof()*8
	int myshort=sizeof(short)*8; 
	int myint=sizeof(int)*8;
	long double mylong=sizeof(long)*8;
	
	printf("tipo de dato   | rango de representacion\n\n");		   //en unsigned, rango = 0 a 2^(cantidad de bits)-1
	printf("unsigned char  | 0 a %f\n", pow(2,sizeof(char)*8)-1);      //ya que en el primer bit se eleva a la 0              
	printf("char           | %f a %f\n", pow(2,sizeof(char)*8)/(-2), (pow(2,mychar)/2)-1);   
	printf("unsigned short | 0 a %f\n", pow(2,sizeof(short)*8)-1);
	printf("short          | %f a %f\n", pow(2,sizeof(short)*8)/(-2), (pow(2,myshort)/2)-1);
	printf("unsigned int   | 0 a %f\n", pow(2,sizeof(int)*8)-1);
	printf("int            | %f a %f\n", pow(2,sizeof(int)*8)/(-2), (pow(2,myint)/2)-1);  //en signado, rango = mitad negativa
	printf("unsigned long  | 0 a %f\n", pow(2,sizeof(long)*8)-1);			      //hasta mitad positiva -1
	printf("long           | %f a %f\n", pow(2,sizeof(long)*8)/(-2), (pow(2,mylong)/2)-1);
return 0;
}
