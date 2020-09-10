/**
*	\file mde.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
#ifndef INC_MDE_H_
#define INC_MDE_H_

#include <bibliotecaInfoII.h>

//!< Definiciones Globales  
#define	TRUE			1
#define	FALSE			0

/*********************************************************************************************************************************
*** DEFINICIONES DE ESTADOS
**********************************************************************************************************************************/

//!< Definicion de Estados mde general
#define	ESPERANDO   0
#define	VEICULO		1
#define	SIRENA		2

//!< Definicion de Estados mde led
//#define	VERDE	3 //define ya echo en la biblioteca
#define	ROJA		4

//!< Definicion de Estados mde sirena
#define	STANDBY		5
//#define	ON          6 //define ya echo en la biblioteca
//#define	OFF         7 //define ya echo en la biblioteca

//!< Definiciones de estados mde central_control
//#define ESPERANDO 0 //define ya echo 
//#define SIRENA    1 //define ya echo 

//!< Definiciones de estados mde recepcion_trama
//#define ESPERANDO
#define LEYENDO     6
#define CHECK       7

/*********************************************************************************************************************************
*** DEFINICIONES PARA FUNCIONES DE MAQUINAS
**********************************************************************************************************************************/

//!< Definiciones para funciones de mde general
#define INGRESO 0   //(ENTRADA0)
#define EGRESO  1   //(ENTRADA1)
#define TIMER_INGRESO   0

//!< Definiciones para funciones de mde led

//!< Definiciones para funciones de mde sirena
#define TIMER_SIRENA    1

//!< Definiciones para funciones de mde central_control

//!< Definiciones para funciones de mde recepcion_trama
#define MSGTAM  3
#define INICIO  0xAA
#define M1      'O'
#define M2      'F'
#define M3      'F'
#define FIN     0xEE


//!< Declaracion de Maquinas de Estados
void maquina_general(void);

void maquina_led(void);

void maquina_sirena(void);

void maquina_central_control();

void maquina_recepcion_trama();


void inicializar( void );

//general
uint8_t ingreso( void );
uint8_t egreso( void );
int TECLA0( void );
void iniciarTimer_10s( void );
void timerHandler( void );
void detenerTimer( void );
int recibiTrama( void );
void reset_general( void );

//led
void rojoOn( void );
void verdeOn( void );
void rojoOff( void );
void verdeOff( void );
void reset_led( void );

//sirena
void iniciarTimerSirena( void );
void timerSirenaHandler( void );
void detenerTimerSirena( void );
void sirenaOn( void );
void sirenaOff( void );
void reset_sirena( void );

//central_control
int TECLA0( void );
void enviarTrama( void );

//recepcion_trama
void guardoAux(int16_t, int16_t*, int16_t);
int tramaFinCheck(int16_t*);

#endif /* INC_MDE_H_ */
