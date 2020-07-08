/**
*	\file main.c
*	\brief Resumen del contenido del archivo
*	\details Descripcion detallada del archivo
*	\author nahuel
*	\date 16-06-2020 15:59:10
*/
#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include <BibliotecaInfoII.h>
#include "AP_MdeE.h"

extern int m_abrir;
extern int m_cerrar;


int main(void)
{

//declaracion de variables
//inicializacion de perifericos

	Inicializacion();
	InicializarSalidas();

	while(1)
	{

		maquina_puerta();


	}

	return 0;
}
