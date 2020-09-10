/**
*	\file main.c
*	\brief Resumen del contenido del archivo
*	\details Descripcion detallada del archivo
*	\author marcosGoyret
*	\date 24-07-2020 11:58:15
*/

#include "mde.h"

uint8_t extSensor;
uint8_t intSensor;
uint8_t cnt_autos;


void main(void)
{

//declaracion de variables
//inicializacion de perifericos

	inicializarHW();
	inicializarSW();

	while(1)
	{
		extSensor = checkExt();
		intSensor = checkInt();
		maquina_control_autos();
		maquina_alarma();
	}
}
