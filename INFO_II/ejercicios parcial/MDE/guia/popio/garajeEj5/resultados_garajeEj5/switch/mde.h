/**
*	\file AP_MdeE.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author marcosGoyret
*	\date 24-07-2020 09:53:19
*/
/*********************************************************************************************************************************
*** MODULO
**********************************************************************************************************************************/
#ifndef INC_MDEE_H_
#define INC_MDEE_H_

/*********************************************************************************************************************************
*** INCLUDES GLOBALES
**********************************************************************************************************************************/
#include "bibliotecaInfo2/bibliotecaInfoII.h"


/*********************************************************************************************************************************
*** DEFINES GLOBALES
**********************************************************************************************************************************/
#define	TRUE			1
#define	FALSE			0

//!< Definicion de Estados control_autos
#define	ESPERANDO		0
#define	ENTRANDO		1
#define	SALIENDO		2
#define	CASIADENTRO		3
#define	CASIAFUERA		4

//!< Definicion de Estados alarma
#define	APAGADO		    5
#define	SONANDO		    6
#define	SECUENCIAOFF	7

/* defines para numero de entradas correspondientes
    al sensor del harware (ENTRADA0, 1, etc) */
#define INTERIOR
#define EXTERIOR

/* Define del numero que devuelve GetTimer(), no se si devuelve TERMINADO/NOTERMINADO 
    o si devuelve el tiempo actual */
#define FIN_10S // podria ser "true" o "10" dependiendo de lo que devuelva GetTimer()


//!< Declaracion de la Maquina de Estados
void maquina_control_autos(void);

void maquina_alarma(void);


void inicializarSW();
void inicializarHW();
uint8_t checkExt();
uint8_t checkInt();

void reset_control_autos();

void prenderAlarma();
void apagarAlarma();
void IniciarTimer0_10S();
uint8_t Timer0_10S();


#endif /* INC_MDEE_H_ */
