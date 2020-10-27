
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
*	\file AP_FuncionesMdeE.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author NicoCampos
*	\date 15-08-2020 16:40:27
*/
/*********************************************************************************************************************************
*** MODULO
**********************************************************************************************************************************/
#ifndef INC_AP_FUNCIONESMDEE_H_
#define INC_AP_FUNCIONESMDEE_H_

/*********************************************************************************************************************************
*** INCLUDES GLOBALES
**********************************************************************************************************************************/

/*********************************************************************************************************************************
*** DEFINES GLOBALES
**********************************************************************************************************************************/
// Estos valores estan asociados directamente con el clock del systick
// si cambiamos el valor del mismo, deberemos recalcular dichos valores.
// En este caso estan pensados para un tick de 1ms, es decir, 1 segundo = 1000 miliSegundos
#define		UNSEGUNDO		1000
#define		DOSsEGUNDOS		2000

//#define REV_D		// Descomentar esta linea si tiene la revision D del LPC1769

#ifndef	REV_D
	#define OFF		0
	#define ON		1
#else
	#define OFF		1
	#define ON		0
#endif
/*********************************************************************************************************************************
*** MACROS GLOBALES
**********************************************************************************************************************************/
#define LED		0,22
/*********************************************************************************************************************************
*** TIPO DE DATOS GLOBALES
**********************************************************************************************************************************/

/*********************************************************************************************************************************
*** VARIABLES GLOBALES
**********************************************************************************************************************************/

/*********************************************************************************************************************************
*** PROTOTIPOS DE FUNCIONES GLOBALES
**********************************************************************************************************************************/

//!< Prototipos de los Eventos
int Timer0_1S( void );
int Timer0_2S( void );
//!< Prototipos de las Acciones
void IniciarTimer0_1S( void );
void IniciarTimer0_2S( void );
void ApagarLed0( void );
void PrenderLed0( void );

#endif /* INC_AP_FUNCIONESMDEE_H_ */
