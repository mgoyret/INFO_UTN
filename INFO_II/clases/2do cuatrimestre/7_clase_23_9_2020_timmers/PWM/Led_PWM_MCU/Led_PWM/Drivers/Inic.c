/*
 * Inic.c
 *
 *  Created on: 28 ago. 2019
 *      Author: NicoCampos
 */

/**
*	\fn void inicializar(void)
*	\brief Resumen
*	\details Detalles
*	\author NicoCampos
*	\date 28-08-2019 10:09:12
*/

#include "Oscilador.h"
#include "Inicializacion.h"
#include "Register_PWM.h"
#include "PWM.h"
void inicializar( void )
{
	InicPLL();
	Init_GPIO_PWM();
	Init_PWM();
	Init_EINT();
	Iniciar_juego1();
}

void Init_EINT(void)
{
	// Inicializo los pines como interrupciones externas
	SetPINSEL(PIN_EINT0);

	// Interrupcion por flanco
	EXTMODE |= (1<<0);

	// Flanco de bajada
	EXTPOLAR &= ~(1<<0);

	// Habilito las interrupciones
	ISER0 |= 1<<18;

//	EXTINT |= 1<<0;

}

void Init_GPIO_PWM(void)
{
	SetPINSEL(PIN_PWM1_2_P2);	 // Configuro en el puerto 2, pin 1 como funcion de PWM --> LED_RGB(Infotronic)Azul
	SetPINSEL(PIN_PWM1_4_P2);	 // Configuro en el puerto 2, pin 3 como funcion de PWM --> LED_RGB(Infotronic)Verde

	//	No lo dejo funcional por no coincidir con algun led para poder ver el juego de luces
	//SetPINSEL(PIN_PWM1_6_P3);	 // Configuro en el puerto 3, pin 26 como funcion de PWM -->
}

void Init_PWM(void)
{
	PCONP |= 1 << 6; //Habilitar PWM1

	// Elijo el clock completo(como tengo inicializado el PLL --> 100 Mhz)
	PCLKSEL0 &= ~(3 << 12);
	PCLKSEL0 |= 1 << 12;

	// Selecciono Double Edge PWM
	PWM_PCR |= (1<<SEL_MR6) | (1<<SEL_MR4) | (1<<SEL_MR2);

	PWM_PR = 100-1;		// para definir este valor hacemos (PCLK * PWM_Resolucion)-1 --> (100Mhz * 1uS)-1 = 100-1

	PWM_MCR = 1 << MR0R;	// Restablecer PWM

	PWM_PCR |= (1<<MENA_MR6) | (1<<MENA_MR4) | (1<<MENA_MR2) ;	// Habilitar salidas PWM

	PWM_TCR = (1<<1);	// Reset PWM TC & PR

	PWM_TCR = (1<<0) | (1<<3);	// Habilitar contador y modo PWM
}
