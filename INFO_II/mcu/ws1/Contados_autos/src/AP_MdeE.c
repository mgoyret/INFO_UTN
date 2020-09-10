
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
*	\author Micaela
*	\date 24-07-2020 16:45:22
*/

/*********************************************************************************************************************************
 *** INCLUDES
**********************************************************************************************************************************/
#include "AP_MdeE.h" 
#include "AP_FuncionesMdeE.h" 

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
extern int tiempo_10_segs;
int cant_autos=0;
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
*	\author Micaela
*	\date 24-07-2020 16:45:22
*/
void maquina_MdE1()
{
		static int estado = REPOSO;


		switch(estado)
		{
			case REPOSO:
			
				if( Sensor1( ) )
				{

					estado = ENTRANDO;	
				}
 
				if( Sensor2( ) )
				{

					estado = SALIENDO;	
				}
 

				break;
			
			case ENTRANDO:
			
				if( !Sensor1( ) )
				{

					estado = REPOSO;	
				}
 
				if( Sensor2() && Sensor1( ) )
				{
					
					estado = ENTRO;	
				}
 

				break;
			
			case ENTRO:
			
				if( !Sensor2( ) )
				{
					
					estado = ENTRANDO;	
				}
 
				if( Sensor2() && !Sensor1( ) )
				{


					cant_autos += 1;
					estado = REPOSO;	
				}
 

				break;
			
			case SALIENDO:
			
				if( !Sensor2( ) )
				{
					

					estado = REPOSO;	
				}
 
				if( Sensor1() && Sensor2( ) )
				{
					
					estado = SALIO;	
				}
 

				break;
			
			case SALIO:
			
				if( !Sensor1( ) )
				{

					
					estado = SALIENDO;	
				}
 
				if( Sensor1() && !Sensor2( ) )
				{

					cant_autos -= 1;
					estado = REPOSO;	
				}
 

				break;
			
			default: estado = REPOSO;
		}


}

/**
*	\fn void maquina_MdESirena()
*	\brief Implementacion switch-case
*	\details 
*	\author Micaela
*	\date 24-07-2020 16:45:22
*/
void maquina_MdESirena()
{
		static int estado = APAGADA;

		switch(estado)
		{
			case APAGADA:
			
				if( Sensor1() && Sensor2( ) )
				{


					EnciendoSirena();
					estado = PREPARADA;	
				}


				break;
			
			case PREPARADA:
			
				if( ! Sensor1() && !Sensor2( ) )
				{


					Iniciotimer10();
					estado = ENCENDIDA;	
				}
 

				break;
			
			case ENCENDIDA:
			
				if( tiempo_10_segs)
				{


					ApagoSirena();
					estado = APAGADA;	
				}
 

				break;
			
			default: estado = APAGADA;
		}


}

