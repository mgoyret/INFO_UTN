/**
*	\file main.c
*	\brief Resumen del contenido del archivo
*	\details Descripcion detallada del archivo
*	\author marcosGoyret
*	\date 24-07-2020 14:30:31
*/

#include "mde.h"


extern int lector;
extern uint8_t timer10Fin;
extern uint8_t timer5Fin;


void main(void)
{

//declaracion de variables
//inicializacion de perifericos

	inicializar();

	while(1)
	{
		sensorHuella(); // Actualiza los valores de "acceso" y de "lector"
		maquina_puerta();
		maquina_display();
	}
}
