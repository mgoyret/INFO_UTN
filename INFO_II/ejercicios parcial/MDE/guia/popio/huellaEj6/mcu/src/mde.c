/**
*	\file mde.c
*	\brief Implementacion switch-case
*	\details Descripcion detallada del archivo
*	\author marcosGoyret
*	\date 24-07-2020 14:30:31
*/

/*********************************************************************************************************************************
 *** INCLUDES
**********************************************************************************************************************************/
#include <mde.h>

int lector; 
uint8_t timer10Fin;
uint8_t timer5Fin;

/**
*	\fn void maquina_puerta()
*	\brief Implementacion switch-case
*	\details 
*	\author marcosGoyret
*	\date 24-07-2020 14:30:31
*/

void maquina_puerta()
{
		static int estado = ESPERANDO;

		switch(estado)
		{
			case ESPERANDO:
				if( lector TIENE_HUELLA_VALIDA )
				{
					#ifdef DEPURAR
						Log( 0 , 0 , 0 );
					#endif
					enviarCodigoHuella( );
					estado = ENTRANDO;	
				}
				break;
			
			case ENTRANDO:
				if( cerroPuerta( ) == TRUE )
				{
					#ifdef DEPURAR
						Log( 0 , 1 , 0 );
					#endif
					estado = DENTRO;	
				}
				break;
			
			case DENTRO:
				if( botonSalir() == TRUE )
				{
					#ifdef DEPURAR
						Log( 0 , 2 , 0 );
					#endif
					IniciarTimer_0_10S( );
					estado = SALIENDO;	
				}
				break;
			
			case SALIENDO:
				if( timer10Fin == TRUE )
				{
					#ifdef DEPURAR
						Log( 0 , 3 , 0 );
					#endif
					timer10Fin = FALSE;
					estado = ESPERANDO;	
				}
				break;
			
			default:
				estado = ESPERANDO;
				reset_maquina_puerta();
		}
}

/**
*	\fn void maquina_display()
*	\brief Implementacion switch-case
*	\details 
*	\author marcosGoyret
*	\date 24-07-2020 14:30:31
*/
void maquina_display()
{
		static int estado = ESPERANDO;

		switch(estado)
		{
			case ESPERANDO:	
				if( lector == HUELLA_INVALIDA )
				{
					#ifdef DEPURAR
						Log( 1 , 0 , 0 );
					#endif
					IniciarTimer_0_5S( );
					displayNoHabilitado( );
					estado = INVALIDO;	
				}
				if( lector TIENE_HUELLA_VALIDA  )
				{
					displayPuertaHabilitada();
					estado = PERMITIDO;
				}
				break;
			
			case INVALIDO:
				if( timer5Fin == TRUE )
				{
					#ifdef DEPURAR
						Log( 1 , 1 , 0 );
					#endif
					displayEsperando( );
					estado = ESPERANDO;	
				}
				break;

			case PERMITIDO:
				if( cerroPuerta( ) == TRUE )
				{
					#ifdef DEPURAR
						Log( 1 , 2 , 0 );
					#endif
					displayPersonalDentro();
					estado = DENTRO;	
				}
				break;

			case DENTRO:
				if( botonSalir() == TRUE )
				{
					#ifdef DEPURAR
						Log( 1 , 3 , 0 );
					#endif
					// En este momento desde la maquina puerta s inicia el timer 10s
					displayPuertaHabilitada();
					estado = SALIENDO;	
				}
				break;

			case SALIENDO:
				if( timer10Fin == TRUE )
				{
					displayEsperando();
					estado = ESPERANDO;
				}
				break;

			default:
				estado = ESPERANDO;
				reset_maquina_display();
				break;
		}
}

void maquina_led()
{
	static int estado = APAGADO;
	switch (estado)
	{
	case APAGADO:
		if( lector == HUELLA_INVALIDA )
		{
			prenderLed();
			estado = PRENDIDO;
		}
		break;

	case PRENDIDO:
		if( timer5Fin == TRUE )
		{
			apagarLed();
			estado = APAGADO;
		}
	
	default:
		estado = APAGADO;
		reset_maquina_led();
		break;
	}
}
