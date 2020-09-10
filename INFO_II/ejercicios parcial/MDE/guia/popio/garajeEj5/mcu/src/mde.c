/**
*	\file AP_MdeE.c
*	\brief Implementacion switch-case
*	\details Descripcion detallada del archivo
*	\author marcosGoyret
*	\date 24-07-2020 09:53:19
*/


#include "mde.h"


extern uint8_t extSensor;
extern uint8_t intSensor;
extern uint8_t cnt_autos;
extern uint8_t timerFin;

/**
*	\fn void maquina_control_autos()
*	\brief Implementacion switch-case
*	\details
*	\author marcosGoyret
*	\date 24-07-2020 09:53:19
*/
void maquina_control_autos()
{
	static int estado = ESPERANDO;

	switch(estado)
	{
		case ESPERANDO:
			if( (extSensor == TRUE) && (intSensor == FALSE) )
			{
				#ifdef DEPURAR
					Log( 0 , 0 , 0 );
				#endif
				estado = ENTRANDO;
			}
			if( (intSensor == TRUE) && (extSensor == FALSE) )
			{
				#ifdef DEPURAR
					Log( 0 , 0 , 1 );
				#endif
				estado = SALIENDO;
			}
 			break;

		case ENTRANDO:
			if( (extSensor == FALSE) && (intSensor == FALSE) )
			{
				#ifdef DEPURAR
					Log( 0 , 1 , 0 );
				#endif
				estado = ESPERANDO;
			}
			if( (intSensor == TRUE) && (extSensor == TRUE) )
			{
				#ifdef DEPURAR
					Log( 0 , 1 , 1 );
				#endif
				estado = CASIADENTRO;
			}
			break;

		case SALIENDO:
			if( (intSensor == FALSE) && (extSensor == FALSE) )
			{
				#ifdef DEPURAR
					Log( 0 , 2 , 0 );
				#endif
				estado = ESPERANDO;
			}
			if( (extSensor == TRUE) && (intSensor == TRUE) )
			{
				#ifdef DEPURAR
					Log( 0 , 2 , 1 );
				#endif
				estado = CASIAFUERA;
			}
			break;

		case CASIADENTRO:
			if((intSensor == FALSE) && (extSensor == TRUE))
			{
				#ifdef DEPURAR
					Log( 0 , 3 , 0 );
				#endif
				estado = ENTRANDO;
			}
			if((extSensor == FALSE) && (intSensor == FALSE))
			{
				#ifdef DEPURAR
					Log( 0 , 3 , 1 );
				#endif
				cnt_autos += 1;
				estado = ESPERANDO;
			}
			break;

		case CASIAFUERA:
			if((extSensor == FALSE) && (intSensor == TRUE))
			{
				#ifdef DEPURAR
					Log( 0 , 4 , 0 );
				#endif
				estado = SALIENDO;
			}
			if((extSensor == FALSE) && (intSensor == FALSE))
			{
				#ifdef DEPURAR
					Log( 0 , 4 , 1 );
				#endif
				cnt_autos -= 1;
				estado = ESPERANDO;
			}
			break;

		default:
			estado = ESPERANDO;
			reset_control_autos();
	}
}

/**
*	\fn void maquina_alarma()
*	\brief Implementacion switch-case
*	\details 
*	\author marcosGoyret
*	\date 24-07-2020 11:58:15
*/
void maquina_alarma()
{
	static int estado = APAGADO;

	switch(estado)
	{
		case APAGADO:			
			if((extSensor == TRUE) && (intSensor == TRUE))
			{
				#ifdef DEPURAR
					Log( 1 , 0 , 0 );
				#endif
				prenderAlarma();
				estado = SONANDO;	
			}
			break;
			
		case SONANDO:
			if((extSensor == FALSE) && (intSensor == FALSE))
			{
				#ifdef DEPURAR
					Log( 1 , 1 , 0 );
				#endif
				IniciarTimer0_10S();
				estado = SECUENCIAOFF;	
			}
			break;

		case SECUENCIAOFF:
			if( timerFin == TRUE )
			{
				#ifdef DEPURAR
					Log( 1 , 2 , 0 );
				#endif
				apagarAlarma();
				estado = APAGADO;	
			}
			break;
			
		default: estado = APAGADO;
	}


}
