
/************************************************************************************************************************************
 * La Redistribuci�n y uso en formas de fuente y objeto con o sin modificaci�n, est�n permitidos siempre que se cumplan las 
 * siguientes condiciones:
 *
 * 1. Las redistribuciones del c�digo fuente deben conservar el aviso de copyright anterior, esta lista de condiciones y el siguiente
 * descargo de responsabilidad.
 *
 * 2. Las redistribuciones en formato objeto deben reproducir el aviso de copyright anterior, esta lista de condiciones y la siguiente
 * exenci�n de responsabilidad en la documentaci�n y / u otros materiales proporcionados con la distribuci�n.
 *
 * 3. Ni el nombre del titular de los derechos de autor ni los nombres de sus los contribuyentes pueden ser utilizados para respaldar 
 * o promocionar productos derivados de este software sin permiso escrito previo espec�fico.
 *
 * ESTE SOFTWARE ES PROPORCIONADO POR LOS TITULARES DE LOS DERECHOS DE AUTOR Y SUS COLABORADORES de uModelFactor y Y SE RENUNCIA 
 * A CUALQUIER GARANT�A EXPRESA O IMPL�CITA, INCLUIDAS, ENTRE OTRAS, LAS GARANT�AS IMPL�CITAS DE COMERCIABILIDAD E IDONEIDAD PARA 
 * UN PROP�SITO DETERMINADO. EN NING�N CASO EL TITULAR DE LOS DERECHOS DE AUTOR O LOS COMERCIANTES SER�N RESPONSABLES DE DA�OS DIRECTOS,
 * INDIRECTOS, INCIDENTALES, ESPECIALES, EJEMPLARES O CONSECUENCIALES (INCLUIDOS, ENTRE OTROS, LA ADQUISICI�N DE BIENES O SERVICIOS 
 * SUSTITUTIVOS, LA P�RDIDA DE USO, LOS DATOS O LAS GANANCIAS; O INTERRUPCI�N DEL NEGOCIO) SIN EMBARGO Y EN CUALQUIER TEOR�A DE 
 * RESPONSABILIDAD, YA SEA POR CONTRATO, RESPONSABILIDAD ESTRICTA O AGRAVIO (INCLUIDA LA NEGLIGENCIA O CUALQUIER OTRO) QUE SURJA DE
 * CUALQUIER MODO DEL USO DE ESTE SOFTWARE, AUN CUANDO SE ESTEVIENDO LA POSIBILIDAD DE DICHO DA�o
 *	
 * El contenido de este archivo es generado en forma automatica a partir del modelo planteado. Cualquier cambio realizado sobre el modelo
 * generara un nuevo codigo que eliminara todos los cambios realizados por el desarrollador en el fuente previamente generado
**************************************************************************************************************************************/

/**
*	\file AP_MdeE.c
*	\brief Implementacion switch-case
*	\details Descripcion detallada del archivo
*	\author MarcosGoyret
*	\date 08-07-2020 14:11:36
*/

/*********************************************************************************************************************************
 *** INCLUDES
**********************************************************************************************************************************/
#include "AP_MdeE.h" 
#include "AP_FuncionesMdeE.h" 
#include "AP_Depuracion.h" 

/*********************************************************************************************************************************
 *** DEFINES PRIVADOS AL MODULO
**********************************************************************************************************************************/

/*********************************************************************************************************************************
 *** MACROS PRIVADAS AL MODULO
**********************************************************************************************************************************/

/*********************************************************************************************************************************
 *** TIPOS DE DATOS PRIVADOS AL MODULO
**********************************************************************************************************************************/

/*********************************************************************************************************************************
 *** TABLAS PRIVADAS AL MODULO
**********************************************************************************************************************************/

/*********************************************************************************************************************************
 *** VARIABLES GLOBALES PUBLICAS
**********************************************************************************************************************************/
/*********************************************************************************************************************************
 *** VARIABLES GLOBALES PRIVADAS AL MODULO
**********************************************************************************************************************************/

/*********************************************************************************************************************************
 *** PROTOTIPO DE FUNCIONES PRIVADAS AL MODULO
**********************************************************************************************************************************/

/*********************************************************************************************************************************
 *** FUNCIONES PRIVADAS AL MODULO
**********************************************************************************************************************************/

/*********************************************************************************************************************************
 *** FUNCIONES GLOBALES AL MODULO
**********************************************************************************************************************************/
/**
*	\fn void maquina_principal()
*	\brief Implementacion switch-case
*	\details 
*	\author MarcosGoyret
*	\date 08-07-2020 14:11:36
*/

extern int primerSalto;
extern int llegaron;
extern int contador;
extern int tiempoFin[TOTAL_N];
//extern int = i;


void maquina_principal()
{
		static int estado = APAGADO;

		switch(estado)
		{
			case APAGADO:
			
				if( Tecla0 )
				{
					#ifdef DEPURAR
						Log( 0 , 0 , 0 );
					#endif

					estado = PRENDIDO;	
				}
 
				break;
			
			case PRENDIDO:
			
				maquina_control_nadadores(); // PRENDIDO es un estado compuesto

				if( Tecla1( ) )
				{
					#ifdef DEPURAR
						Log( 0 , 1 , 0 );
					#endif

					IniciarTimer_5000();
					estado = SALIDA_FALSA;	
				}

				break;
			
			case SALIDA_FALSA:

				if ( Timer_5000() )
				{
					#ifdef DEPURAR
						Log( 0 , 2 , 0 );
					#endif

					inicializar();
				}

				break;

			default: estado = APAGADO;
		}


}

/**
*	\fn void maquina_control_nadadores()
*	\brief Implementacion switch-case
*	\details 
*	\author MarcosGoyret
*	\date 08-07-2020 14:11:36
*/
void maquina_control_nadadores()
{
	static int estado = REPOSO;
	uint8_t i;

	switch(estado)
	{
		case REPOSO:
			
			if(contactoSalio() && (primerSalto == TRUE))
			{
				#ifdef DEPURAR
					Log( 1 , 0 , 0 );
				#endif

				IniciarContador( );
				primerSalto = FALSE; //ya hubo un primero, por lo que el siguiente no lo sera

				estado = SALIO;	
			}
			else if (contactoSalio() && (primerSalto == FALSE))
			{
				estado = SALIO;
			}			

			break;
			
		case SALIO:
			
			/* contactoLlego ademas de devolver true\false, si llego un nadador, setea el valoe i de acuerdo a la identificacion del nadador */
			if( contactoLlego(&i) )
			{
				#ifdef DEPURAR
					Log( 1 , 1 , 0 );
				#endif

				GuardarTiempo(i);
				EnviarInfo( );
				llegaron += 1;

				estado = REPOSO;	
			}

			break;

		case LLEGO:

			break;

		default: estado = REPOSO;
	}
}

/**
*	\fn void maquina_estado_de_carrera()
*	\brief Implementacion switch-case
*	\details 
*	\author MarcosGoyret
*	\date 08-07-2020 14:11:36
*/
void maquina_estado_de_carrera()
{
		static int estado = NO_FINALIZADA;
		int i = 0;

		switch(estado)
		{
			case NO_FINALIZADA:
			
				if( llegaron == TOTAL_N )
				{
					#ifdef DEPURAR
						Log( 2 , 0 , 0 );
					#endif

					IniciarTimer_2000();
					estado = FINALIZADA;	
				}
 

				break;
			
			case FINALIZADA:
			
				if( Timer_2000( ) && (i<TOTAL_N))
				{
					#ifdef DEPURAR
						Log( 2 , 1 , 0 );
					#endif

					mostar(i); // muestra tiempo de nadador en lcd
					if(i<TOTAL_N)
					{
						IniciarTimer_2000( );
						i++;
					}			
				}
 
				break;
			
			default: estado = NO_FINALIZADA;
		}

}

