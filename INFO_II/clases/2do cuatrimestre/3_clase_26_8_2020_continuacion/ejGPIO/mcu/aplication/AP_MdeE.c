/**
*	\file AP_MdeE.c
*	\brief Implementacion switch-case
*	\details Descripcion detallada del archivo
*	\author MarcosGoyret
*	\date 02-09-2020 14:44:57
*/

/*********************************************************************************************************************************
 *** INCLUDES
**********************************************************************************************************************************/
#include "AP_MdeE.h" 
#include "AP_FuncionesMdeE.h" 

/*********************************************************************************************************************************
 *** FUNCIONES GLOBALES AL MODULO
**********************************************************************************************************************************/
/**
*	\fn void maquina_LED()
*	\brief Implementacion switch-case
*	\details 
*	\author MarcosGoyret
*	\date 02-09-2020 14:44:57
*/
void maquina_LED()
{
		static int estado = APAGADO;

		switch(estado)
		{
			case APAGADO:
				if( evPrender() )
				{
					prenderLed();
					estado = PRENDIDO;	
				}
				break;
			
			case PRENDIDO:
				if( evApagar() )
				{
					apagarLed();
					estado = APAGADO;	
				}
				break;
			
			default: estado = APAGADO;
		}
}
