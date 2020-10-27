
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
*	\file AP_FuncionesMde.c
*	\brief Implementacion switch-case
*	\details Descripcion detallada del archivo
*	\author NicoCampos
*	\date 15-08-2020 16:40:27
*/

/*********************************************************************************************************************************
 *** INCLUDES
**********************************************************************************************************************************/
#include <PR_FuncionesMdeE.h>
#include <PR_GPIO.h>

//#include "AP_Depuracion.h"

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
extern int tiempo;
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

//!< Funciones asociadas a los eventos

/**
*	\fn int Timer0_1S(void)
*	\brief Resumen
*	\details Detalles
*	\author NicoCampos
*	\date 15-08-2020 16:40:27
*/
int Timer0_1S( void )
{
	int res = 0 ;

	if(tiempo == 0)
		res = 1;

	return res;
}

/**
*	\fn int Timer0_2S(void)
*	\brief Resumen
*	\details Detalles
*	\author NicoCampos
*	\date 15-08-2020 16:40:27
*/
int Timer0_2S( void )
{
	int res = 0 ;

	if(tiempo == 0)
		res = 1;

	return res;
}


//!< Funciones asociadas a las acciones

/**
*	\fn void IniciarTimer0_1S(void)
*	\brief Resumen
*	\details Detalles
*	\author NicoCampos
*	\date 15-08-2020 16:40:27
*/
void IniciarTimer0_1S( void )
{
	tiempo = UNSEGUNDO;
}

/**
*	\fn void IniciarTimer0_2S(void)
*	\brief Resumen
*	\details Detalles
*	\author NicoCampos
*	\date 15-08-2020 16:40:27
*/
void IniciarTimer0_2S( void )
{
	tiempo = DOSsEGUNDOS;
}

/**
*	\fn void ApagarLed0(void)
*	\brief Resumen
*	\details Detalles
*	\author NicoCampos
*	\date 15-08-2020 16:40:27
*/
void ApagarLed0( void )
{
	SetPIN(LED,OFF);
}

/**
*	\fn void PrenderLed0(void)
*	\brief Resumen
*	\details Detalles
*	\author NicoCampos
*	\date 15-08-2020 16:40:27
*/
void PrenderLed0( void )
{
	SetPIN(LED,ON);
}


