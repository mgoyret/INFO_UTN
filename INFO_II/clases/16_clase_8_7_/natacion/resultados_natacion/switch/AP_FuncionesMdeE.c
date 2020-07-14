
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
*	\author MarcosGoyret
*	\date 08-07-2020 14:11:36
*/

/*********************************************************************************************************************************
 *** INCLUDES
**********************************************************************************************************************************/
#include "AP_FuncionesMdeE.h" 
#include "AP_Depuracion.h" 
#include "AP_MdeE.h"

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

//!< Funciones asociadas a los eventos

extern int primerSalto;
extern int llegaron;
extern int contador;
extern int tiempoFin[TOTAL_N];
//extern int i;


void inicializar()
{
	DetenerTimers();
	primerSalto = TRUE;
	llegaron = 0;
	contador = 0;
	i = 0;
}

/**
*	\fn int Tecla1(void)
*	\brief Resumen
*	\details Detalles
*	\author MarcosGoyret
*	\date 08-07-2020 14:11:36
*/
int Tecla1( void )
{
	int res = 0 ;

	//!< Codigo propio de la funcion

	return res;
}

/**
*	\fn int Tecla0(void)
*	\brief Resumen
*	\details Detalles
*	\author MarcosGoyret
*	\date 08-07-2020 14:11:36
*/
int Tecla0( void )
{
	int res = 0 ;

	//!< Codigo propio de la funcion

	return res;
}

/**
*	\fn int Timer_5000(void)
*	\brief Resumen
*	\details Detalles
*	\author MarcosGoyret
*	\date 08-07-2020 14:11:36
*/
int Timer_5000( void )
{
	int res = 0 ;

	//!< Codigo propio de la funcion

	return res;
}

/**
*	\fn int contactoSalio(void)
*	\brief Resumen
*	\details Detalles
*	\author MarcosGoyret
*	\date 08-07-2020 14:11:36
*/
int contactoSalio( void )
{
	int res = FALSE, nadador = -1;

	//!< Codigo propio de la funcion
	/* getPin() es una primitiva que obtiene senales de las plataformas de salida y llegada */
	nadador = getPin();
	if((nadador == LANZA1) || (nadador == LANZA2) || (nadador == LANZA2) || (nadador == LANZA3) || (nadador == LANZA4) || (nadador == LANZA5))
	{
		res = TRUE;
	}

	return res;
}

/**
*	\fn int contactoLlego(void)
*	\brief Resumen
*	\details Detalles
*	\author MarcosGoyret
*	\date 08-07-2020 14:11:36
*/
int contactoLlego( uint8_t i )
{
	int res = FALSE, nadador = -1;

	//!< Codigo propio de la funcion
	/* getPin() es una primitiva que obtiene senales de las plataformas de salida y llegada */
	nadador = getPin();
	switch (nadador)
	{
		case LLEGADA1:
			res = TRUE;
			*i = NADADOR1;
			break;

		case LLEGADA2:
			res = TRUE;
			*i = NADADOR2;
			break;

		case LLEGADA3:
			res = TRUE;
			*i = NADADOR3;
			break;

		case LLEGADA4:
			res = TRUE;
			*i = NADADOR4;
			break;

		case LLEGADA5:
			res = TRUE;
			*i = NADADOR5;
			break;

		default: nadador = -1;
			break;
	}

	return res;
}

/**
*	\fn int Timer_2000(void)
*	\brief Resumen
*	\details Detalles
*	\author MarcosGoyret
*	\date 08-07-2020 14:11:36
*/
int Timer_2000( void )
{
	int res = 0 ;

	//!< Codigo propio de la funcion

	return res;
}

//!< Funciones asociadas a las acciones

/**
*	\fn void IniciarTimer_5000(void)
*	\brief Resumen
*	\details Detalles
*	\author MarcosGoyret
*	\date 08-07-2020 14:11:36
*/
void IniciarTimer_5000( void )
{
	//!< Codigo propio de la funcion

	return ;
}

/**
*	\fn void DetenerTimers(void)
*	\brief Resumen
*	\details Detalles
*	\author MarcosGoyret
*	\date 08-07-2020 14:11:36
*/
void DetenerTimers( void )
{
	//!< Codigo propio de la funcion

	return ;
}

/**
*	\fn void IniciarContador(void)
*	\brief Resumen
*	\details Detalles
*	\author MarcosGoyret
*	\date 08-07-2020 14:11:36
*/
void IniciarContador( void )
{
	//!< Codigo propio de la funcion

	return ;
}

/**
*	\fn void GuardarTiempo(void)
*	\brief Resumen
*	\details Detalles
*	\author MarcosGoyret
*	\date 08-07-2020 14:11:36
*/
void GuardarTiempo( uint8_t i )
{
	//!< Codigo propio de la funcion
	tiempoFin[i] = contador;
	return ;
}

/**
*	\fn void EnviarInfo(void)
*	\brief Resumen
*	\details Detalles
*	\author MarcosGoyret
*	\date 08-07-2020 14:11:36
*/
void EnviarInfo( uint8_t i )
{
	//!< Codigo propio de la funcion
	/* PSV = define con puerto serie virtual deseado */
	Transmitir(PSV, '$', 1);
	Transmitir(PSV, i, 1);
	Transmitir(PSV, (tiempoFin[i]), 4);
	Transmitir(PSV, '#', 1);

	return ;
}

/**
*	\fn void IniciarTimer_2000(void)
*	\brief Resumen
*	\details Detalles
*	\author MarcosGoyret
*	\date 08-07-2020 14:11:36
*/
void IniciarTimer_2000( void )
{
	//!< Codigo propio de la funcion

	return ;
}

/**
*	\fn void mostar(void)
*	\brief Resumen
*	\details Detalles
*	\author MarcosGoyret
*	\date 08-07-2020 14:11:36
*/
void mostar( i )
{

	//!< Codigo propio de la funcion

	/* En las sig. funciones que estan dentro de la primitiva LCD_D(), se toma el tiempo expresado en decimas de segundo presente en tiempoFin[i]
		y se devuelve el primer digito de los minutos equivalentes, el segundo digito, lo mismo con los segundos, y luego un digito equivalente a
		las decimas de segundo restantes para un segundo
		itoa convertiria el int "i" en un char* 
		Si la cantidad de min/seg es menor a 10, el primer digito sera un '0' */
	LCD_Display(itoa(i), 0, 0);
	LCD_Display(mnt1(tiempoFin[i]), 0, 1);
	LCD_Display(mnt2(tiempoFin[i]), 0, 2);
	LCD_Display(seg1(tiempoFin[i]), 0, 3);
	LCD_Display(seg2(tiempoFin[i]), 0, 4);
	LCD_Display(dseg(tiempoFin[i]), 0, 5);

	return ;
}
