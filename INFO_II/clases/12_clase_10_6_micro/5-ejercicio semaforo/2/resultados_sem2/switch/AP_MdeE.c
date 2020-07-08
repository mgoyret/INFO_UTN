
/************************************************************************************************************************************
 * La Redistribución y uso en formas de fuente y objeto con o sin modificación, están permitidos siempre que se cumplan las 
 * siguientes condiciones:
 *
 * 1. Las redistribuciones del código fuente deben conservar el aviso de copyright anterior, esta lista de condiciones y el siguiente
 * descargo de responsabilidad.
 *
 * 2. Las redistribuciones en formato objeto deben reproducir el aviso de copyright anterior, esta lista de condiciones y la siguiente
 * exención de responsabilidad en la documentación y / u otros materiales proporcionados con la distribución.
 *
 * 3. Ni el nombre del titular de los derechos de autor ni los nombres de sus los contribuyentes pueden ser utilizados para respaldar 
 * o promocionar productos derivados de este software sin permiso escrito previo específico.
 *
 * ESTE SOFTWARE ES PROPORCIONADO POR LOS TITULARES DE LOS DERECHOS DE AUTOR Y SUS COLABORADORES de uModelFactor y Y SE RENUNCIA 
 * A CUALQUIER GARANTÍA EXPRESA O IMPLÍCITA, INCLUIDAS, ENTRE OTRAS, LAS GARANTÍAS IMPLÍCITAS DE COMERCIABILIDAD E IDONEIDAD PARA 
 * UN PROPÓSITO DETERMINADO. EN NINGÚN CASO EL TITULAR DE LOS DERECHOS DE AUTOR O LOS COMERCIANTES SERÁN RESPONSABLES DE DAÑOS DIRECTOS,
 * INDIRECTOS, INCIDENTALES, ESPECIALES, EJEMPLARES O CONSECUENCIALES (INCLUIDOS, ENTRE OTROS, LA ADQUISICIÓN DE BIENES O SERVICIOS 
 * SUSTITUTIVOS, LA PÉRDIDA DE USO, LOS DATOS O LAS GANANCIAS; O INTERRUPCIÓN DEL NEGOCIO) SIN EMBARGO Y EN CUALQUIER TEORÍA DE 
 * RESPONSABILIDAD, YA SEA POR CONTRATO, RESPONSABILIDAD ESTRICTA O AGRAVIO (INCLUIDA LA NEGLIGENCIA O CUALQUIER OTRO) QUE SURJA DE
 * CUALQUIER MODO DEL USO DE ESTE SOFTWARE, AUN CUANDO SE ESTEVIENDO LA POSIBILIDAD DE DICHO DAÑo
 *	
 * El contenido de este archivo es generado en forma automatica a partir del modelo planteado. Cualquier cambio realizado sobre el modelo
 * generara un nuevo codigo que eliminara todos los cambios realizados por el desarrollador en el fuente previamente generado
**************************************************************************************************************************************/

/**
*	\file AP_MdeE.c
*	\brief Implementacion switch-case
*	\details Descripcion detallada del archivo
*	\author marcosGoyret
*	\date 14-06-2020 15:54:04
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
*	\fn void maquina_MdE1()
*	\brief Implementacion switch-case
*	\details 
*	\author marcosGoyret
*	\date 14-06-2020 15:54:04
*/
void maquina_MdE1()
{
		static int estado = APAGADO;

		switch(estado)
		{
			case APAGADO:
			
				if( Tecla0( ) )
				{
					#ifdef DEPURAR
						Log( 0 , 0 , 0 );
					#endif

					PrenderLedRed( );
					IniciarTimer0_10S( );
					
					estado = ROJO;	
				}
 

				break;
			
			case ROJO:
			
				if( Tecla0( ) )
				{
					#ifdef DEPURAR
						Log( 0 , 1 , 0 );
					#endif

					ApagarLedRed();
					estado = APAGADO;	
				}
 
				if( Timer0_10S( ) )
				{
					#ifdef DEPURAR
						Log( 0 , 1 , 1 );
					#endif

					IniciarTimer0_2S( );
					PrenderLedGreen( );
					
					estado = AMARILLO;	
				}
 

				break;
			
			case AMARILLO:
			
				if( Tecla0( ) )
				{
					#ifdef DEPURAR
						Log( 0 , 2 , 0 );
					#endif

					ApagarLedRed( );
					ApagarLedGreen( );
					
					estado = APAGADO;	
				}
 
				if( Timer0_2S( ) )
				{
					#ifdef DEPURAR
						Log( 0 , 2 , 1 );
					#endif

					IniciarTimer0_5S( );
					ApagarLedRed( );
					
					estado = VERDE;	
				}
 
				if( Timer1_2S( ) )
				{
					#ifdef DEPURAR
						Log( 0 , 2 , 2 );
					#endif

					ApagarLedGreen( );
					IniciarTimer0_10S( );
					
					estado = ROJO;	
				}
 

				break;
			
			case VERDE:
			
				if( Tecla0( ) )
				{
					#ifdef DEPURAR
						Log( 0 , 3 , 0 );
					#endif

					ApagarLedGreen();
					estado = APAGADO;	
				}
 
				if( Timer0_5S( ) )
				{
					#ifdef DEPURAR
						Log( 0 , 3 , 1 );
					#endif

					IniciarTimer1_2S( );
					PrenderLedRed( );
					
					estado = AMARILLO;	
				}
 

				break;
			
			default: estado = APAGADO;
		}


}

