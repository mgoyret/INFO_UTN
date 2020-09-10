
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
*	\file AP_MdeE.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author MarcosGoyret
*	\date 02-09-2020 14:44:57
*/
/*********************************************************************************************************************************
*** MODULO
**********************************************************************************************************************************/
#ifndef INC_MDEE_H_
#define INC_MDEE_H_

/*********************************************************************************************************************************
*** INCLUDES GLOBALES
**********************************************************************************************************************************/

/*********************************************************************************************************************************
*** DEFINES GLOBALES
**********************************************************************************************************************************/
#define	TRUE			1
#define	FALSE			0

//!< Definicion de Estados
#define	APAGADO		0
#define	PRENDIDO		1

/*********************************************************************************************************************************
*** MACROS GLOBALES
**********************************************************************************************************************************/

/*********************************************************************************************************************************
*** TIPO DE DATOS GLOBALES
**********************************************************************************************************************************/

/*********************************************************************************************************************************
*** VARIABLES GLOBALES
**********************************************************************************************************************************/

/*********************************************************************************************************************************
*** PROTOTIPOS DE FUNCIONES GLOBALES
**********************************************************************************************************************************/
//!< Declaracion de la Maquina de Estados
void maquina_LED(void);


#endif /* INC_MDEE_H_ */
