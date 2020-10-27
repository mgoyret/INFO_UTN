/**
*	\file funciones.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author NicoCampos
*	\date 14-03-2019 20:31:03
*/

#include "Regs_LPC176x.h"
#include "RegsLPC1769.h"
#include "Oscilador.h"
#include "Register_PWM.h"

//Declaracion de constantes
#define 	TRUE  				1
#define 	FALSE  				0
#define 	SALIDA				1
#define		ENTRADA				0

//declaracion de la maquina
void inicializar(void);

//declaracion de la inicializacion
void Init_PWM(void);
void Init_GPIO_PWM(void);
void SetDIR( uint8_t puerto , uint8_t pin , uint8_t dir );
void SetPIN( uint8_t puerto , uint8_t pin , uint8_t estado );
uint8_t GetPIN( uint8_t puerto , uint8_t pin , uint8_t actividad );
void SetPINSEL( uint8_t puerto , uint8_t pin ,uint8_t funcion );
void SetPINMODE( uint8_t port , uint8_t pin ,uint8_t modo);


//Declaracion de estados
#define 	BAJANDO			0
#define 	SUBIENDO		1
#define 	ESPERANDO		0
#define 	HORARIO			1
#define 	ANTIHORARIO		2

//defines utiles
#define		APAGADO			0
#define		ENCENDIDO		1


//Prototipos de los eventos

//Prototipos de las acciones


