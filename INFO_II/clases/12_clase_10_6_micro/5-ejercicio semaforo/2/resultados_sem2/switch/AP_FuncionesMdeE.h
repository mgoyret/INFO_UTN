
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
*	\file AP_FuncionesMdeE.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author marcosGoyret
*	\date 14-06-2020 15:54:04
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

//!< Prototipos de los Eventos
int Tecla0( void );
int Tecla1( void );
int Tecla2( void );
int Tecla3( void );
int Tecla4( void );
int HayPresencia( void );
int NoHayPresencia( void );
int eRele1_abierto( void );
int eRele2_abierto( void );
int eRele3_abierto( void );
int eRele4_abierto( void );
int eRele1_cerrado( void );
int eRele2_cerrado( void );
int eRele3_cerrado( void );
int eRele4_cerrado( void );
int Timer0_1S( void );
int Timer0_2S( void );
int Timer0_5S( void );
int Timer0_10S( void );
int Timer1_1S( void );
int Timer1_2S( void );
int Timer1_5S( void );
int Timer1_10S( void );

//!< Prototipos de las Acciones
void IniciarTimer0_1S( void );
void IniciarTimer0_2S( void );
void IniciarTimer0_5S( void );
void IniciarTimer0_10S( void );
void IniciarTimer1_1S( void );
void IniciarTimer1_2S( void );
void IniciarTimer1_5S( void );
void IniciarTimer1_10S( void );
void PrenderMotor( void );
void ApagarMotor( void );
void PrenderVentilador( void );
void ApagarVentilador( void );
void PrenderEstufa( void );
void ApagarEstufa( void );
void PrenderRele( void );
void ApagarRele( void );
void PrenderRele1( void );
void ApagarRele1( void );
void PrenderRele2( void );
void ApagarRele2( void );
void PrenderRele3( void );
void ApagarRele3( void );
void PrenderRele4( void );
void ApagarRele4( void );
void MedirTemperatura( void );
void MedirHumedad( void );
void MostrarTemperatura( void );
void MostrarHumedad( void );
void PrenderLedRed( void );
void PrenderLedGreen( void );
void PrenderLedBlue( void );
void ApagarLedRed( void );
void ApagarLedGreen( void );
void ApagarLedBlue( void );
void PrenderBuzzer( void );
void ApagarBuzzer( void );
void EncenderDisplay( void );
void ApagarDisplay( void );
void ReiniciarDispay( void );
void MostrarMensaje( void );
void ApagarLed0( void );
void PrenderLed0( void );
void ApagarLed1( void );
void PrenderLed1( void );
void ApagarLed2( void );
void PrenderLed2( void );
void ApagarLed3( void );
void PrenderLed3( void );

#endif /* INC_AP_FUNCIONESMDEE_H_ */
