#include <stdio.h>   //programa que dice raices de funcion cuadratica
#include <math.h> //header que habilita el uso de la funcion pow
int main (){

	float a, b, c, r1, r2, det, termino1, termino2;    //det=determinante de la formula resolvente. Lo declaro para simplificar
							   //visualmente la formula resolvente y el argumento del "if" escritos mas adelante.
	printf("ingrese a, b, c, separados por comas\n");  //Utilizo el mismo metodo de simplificacion con ambos terminos de la formula r.
	scanf("%f, %f, %f", &a, &b, &c);
	det = pow(b,2)-4*a*c;
	
	if(a==0)  {printf("no es una ecuacion de segundo grado\n");}
	else{
		if(det>=0){
		r1 = ((-b)/(2*a))+((pow(det,0.5))/(2*a)); //formula resolvente
		r2 = ((-b)/(2*a))-((pow(det,0.5))/(2*a));

		printf("raiz 1 = %f\n", r1);
		printf("raiz 2 = %f\n", r2);
		}

		else{
		termino1 = ((-b)/(2*a));
		termino2 = (pow(-(det),0.5))/(2*a);

			if(termino1!=0){ //metodo if-else usado para no imprimir el termino independiente del resultado, si este da cero.
			printf("raiz 1 = %f+j*%f\n", termino1, termino2);
			printf("raiz 2 = %f-j*%f\n", termino1, termino2);
			}
			else{
			printf("raiz 1 = j*%f\n", termino2);
			printf("raiz 2 = -j*%f\n", termino2);
			    }
		    }
	    }
return 0;
}
