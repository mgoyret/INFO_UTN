/**
*	\file main.c
*	\brief Resumen del contenido del archivo
*	\details Descripcion detallada del archivo
*	\author MarcosGoyret
*	\date 08-07-2020 14:11:36
*/

#include "funciones.h"
#include "AP_MdeE.h"

int primerSalto;
int llegaron;
int contador;
int tiempoFin[TOTAL_N];
//int i;


void main(void)
{

//declaracion de variables
//inicializacion de perifericos

	inicializar();


	while(1)
	{

		maquina_principal();

		maquina_estado_de_carrera();

	}
}
