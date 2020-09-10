/**
*	\file mde.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author marcosGoyret
*	\date 24-07-2020 14:30:31
*/
/*********************************************************************************************************************************
*** MODULO
**********************************************************************************************************************************/
#ifndef INC_MDEE_H_
#define INC_MDEE_H_

#include "bibliotecaInfo2/bibliotecaInfoII.h"

#define	TRUE			1
#define	FALSE			0

//!< Definicion de Estados maquina puerta
#define	ESPERANDO		0
#define	ENTRANDO		1
#define	DENTRO          2
#define	SALIENDO		3

//!< Definicion de Estados maquina display
//#define ESPERANDO		4 (ya estaba por la otra maquina)
#define	INVALIDO		5
#define	PERMITIDO		6
//#define DENTRO        7 (ya estaba por la otra maquina)
//#define SALIENDO		8 (ya estaba por la otra maquina)

//!< Definicion de Estados maquina led
#define APAGADO         0
#define PRENDIDO        1

//!< Definicion para primitiva dada
#define NO_HUELLA           0
#define HUELLA_INVALIDA     -1
#define TIENE_HUELLA_VALIDA >0 // para comodidad de indentacion en funcion sensorHuella()


#define KEY_PUERTA_CERRO    SW1
#define KEY_SALIR           SW4

//!< Declaracion de la Maquina de Estados
void maquina_puerta(void);

void maquina_display(void);

void maquina_led( void );



void inicializar();

void reset_maquina_led();
void reset_maquina_puerta();
void reset_maquina_display();

uint8_t accesoPermitido( void );
uint8_t cerroPuerta( void );
uint8_t botonSalir( void );

void prenderLed( void );
void apagarLed(void);

void IniciarTimer_0_10S( void );
void IniciarTimer_0_5S( void );
void Timer_0_10S_Handler( void );
void Timer_0_5S_Handler( void );

void displayNoHabilitado( void );
void displayEsperando( void );
void displayPuertaHabilitada( void );
void displayPersonalDentro( void );

void resetTimer( void );
void sensorHuella( void );
void enviarCodigoHuella( void );
void Display(char*);

#endif /* INC_MDE_H_ */
