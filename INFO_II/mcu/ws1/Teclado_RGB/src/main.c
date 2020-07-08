/**
*	\file main.c
*	\brief
*	\details Varía entre 3 estados que cada uno muestra un número distinto en el display.
*	Para acceder a cada estado tiene una tecla asignada y se puede variar entre cualquiera de ellos
*	independientemente (del 1 al 2; del 2 al 3; del 1 al 3, etc.) para reforzar la posibilidad de salto a múltiples estados
*	y no sólo máquinas secuenciales. Adicionalmente tiene un estado inicial que muestra otro número y que no es accesible
*	salvo por reset. Implementado originalmente con distintos colores del RGB y luego con Display_7Segmentos
*
*	\author Federico Bua
*	\date 02-04-2019 16:23:41
*/

#include "funciones.h"

int main()
{
	inicializar();


	while(1)
	{
		maquina_estado();
	}
	return 0;
}
