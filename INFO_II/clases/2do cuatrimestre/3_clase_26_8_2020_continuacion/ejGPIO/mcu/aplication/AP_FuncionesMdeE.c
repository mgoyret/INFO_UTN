/**
*	\file AP_FuncionesMde.c
*	\brief Implementacion switch-case
*	\details Descripcion detallada del archivo
*	\author MarcosGoyret
*	\date 02-09-2020 14:44:57
*/

/*********************************************************************************************************************************
 *** INCLUDES
**********************************************************************************************************************************/
#include "AP_FuncionesMdeE.h" 
#include <header.h>

//!< Funciones asociadas a los eventos


/**
*	\fn void inicializar(void)
*	\brief Resumen
*	\details Detalles
*	\author MarcosGoyret
*	\date 02-09-2020 14:44:57
*/
void inicializar(void)
{
	///////////ENTRADAS///////////
	//tecla1
	setPinSel(TECLA1, FUNCION_GPIO);
	setDir(TECLA1, ENTRADA);
	setPinMode(TECLA1, PULLUP_INTERNO);
	//tecla2
	setPinSel(TECLA2, FUNCION_GPIO);
	setDir(TECLA2, ENTRADA);
	setPinMode(TECLA2, PULLUP_INTERNO);

	//////////SALIDAS////////////
	setPinSel(LED_STICK, FUNCION_GPIO);
	setDir(LED_STICK, SALIDA);
	setPinModeOD(LED_STICK, NORMAL_EXIT);
	setPin(LED_STICK, OFF);//inicializo apagado

}

/**
*	\fn int evPrender(void)
*	\brief Resumen
*	\details Detalles
*	\author MarcosGoyret
*	\date 02-09-2020 14:44:57
*/
int evPrender( void )
{
	int res = 0 ;
	if( getPin(TECLA1) == DOWN)
		res = 1;
	return res;
}

/**
*	\fn int evApagar(void)
*	\brief Resumen
*	\details Detalles
*	\author MarcosGoyret
*	\date 02-09-2020 14:44:57
*/
int evApagar( void )
{
	int res = 0 ;
	if( getPin(TECLA2) == DOWN)
		res = 1;
	return res;
}

//!< Funciones asociadas a las acciones

/**
*	\fn void prenderLed(void)
*	\brief Resumen
*	\details Detalles
*	\author MarcosGoyret
*	\date 02-09-2020 14:44:57
*/
void prenderLed( void )
{
	setPin(LED_STICK, ON);
}

/**
*	\fn void apagarLed(void)
*	\brief Resumen
*	\details Detalles
*	\author MarcosGoyret
*	\date 02-09-2020 14:44:57
*/
void apagarLed( void )
{
	setPin(LED_STICK, OFF);
}

