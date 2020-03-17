#include <stdio.h> //programa que recibe dos coordenadas (x,y) de un punto, e imprime en pantalla su cuadrante y su distancia del origen
#include <math.h> //header que habilita el uso de la funcion pow
int main (){

	float x, y;  //declaracion de coordenadas variables
	float dist;  //declaracion de distancia variable

	printf("ingrese el valor de x\n");
	scanf("%f", &x);
	printf("ingrese el valor de y\n");
	scanf("%f", &y);
	dist=pow(pow(x,2)+pow(y,2),0.5); //la distancia=elevar a un medio (raiz cuadrada) la suma de los cuadrados de las coordenadas X e Y

	if((x==0)&&(y==0)){ //el punto cartesiano (0,0) corresponde al origen
	printf("punto ubicado en origen de coordenadas\n");
	}
	else{
		if((x>0)&&(y>0)) //if para las condiciones de cada cuadrante
		{printf("punto ubicado en el primer cuadrante\n");}
		else{
			if((x<0)&&(y>0))
			{printf("punto ubicado en el segundo cuadrante\n");}
			else{
				if((x<0)&&(y<0))
				{printf("punto ubicado en el tercer cuadrante\n");}
				else{
					if((x>0)&&(y<0))
					{printf("punto ubicado en el cuarto cuadrante\n");}
				    }
			    }
		    }
	    }
             printf("la distancia del punto al origen de coordenadas es %f\n", dist);
return 0;
}
