/*
 * PWM_Salidas.c
 *
 *  Created on: 2 sep. 2019
 *      Author: NicoCampos
 */
#include "AP_FuncionesMdeE.h"
#include "Register_PWM.h"
#include "PWM.h"

#define MR0	4500000

//!< Funciones asociadas a las acciones

/**
*	\fn void Habilitar_juego1(void)
*	\brief Resumen
*	\details Detalles
*	\author NicoCampos
*	\date 28-08-2019 10:09:12
*/
void Habilitar_juego1( void )
{
	//!< Codigo propio de la funcion
	PWM_MR0 = 4500001;	// 4500000uS = 4,5 Seg

	PWM_MR1 = 1;		// 1uS

	PWM_MR2 = 1500000;	// 1500000uS = 1,5 Seg

	PWM_MR3 = 1500001;	// 15000000uS = 1,5 Seg

	PWM_MR4 = 3000000;	// 3000000uS = 3 Seg

	PWM_MR5 = 3000001;	// 3000000uS = 3 Seg

	PWM_MR6 = 4500000;	// 4500000uS = 4,5 Seg

	// Actualizar valores de MR0-6
	PWM_LER |= (1<<LER_MR6) | (1<<LER_MR5) | (1<<LER_MR4) | (1<<LER_MR3);
	PWM_LER |= (1<<LER_MR2) | (1<<LER_MR1) | (1<<LER_MR0);
}

/**
*	\fn void Habilitar_juego3(void)
*	\brief Resumen
*	\details Detalles
*	\author NicoCampos
*	\date 28-08-2019 10:09:12
*/
void Habilitar_juego2( void )
{
	//!< Codigo propio de la funcion
	PWM_MR0 = 5000001;	// 5000000uS = 5 Seg

	PWM_MR1 = 1;		// 1uS

	PWM_MR2 = MR0;

	PWM_MR3 = 1500001;	// 15000000uS = 1,5 Seg

	PWM_MR4 = MR0;

	PWM_MR5 = 3000001;	// 3000000uS = 3 Seg

	PWM_MR6 = MR0;

	// Actualizar valores de MR0-6
	PWM_LER |= (1<<LER_MR6) | (1<<LER_MR5) | (1<<LER_MR4) | (1<<LER_MR3);
	PWM_LER |= (1<<LER_MR2) | (1<<LER_MR1) | (1<<LER_MR0);

}

/**
*	\fn void Habilitar_juego3(void)
*	\brief Resumen
*	\details Detalles
*	\author NicoCampos
*	\date 28-08-2019 10:09:12
*/
void Habilitar_juego3( void )
{
	//!< Codigo propio de la funcion
	PWM_MR0 = 1500001;	// 1500000uS = 1,5 Seg

	PWM_MR1 = 1;		// 1uS

	PWM_MR2 = 500000;	// 500000uS = 0,5 Seg

	PWM_MR3 = 500001;	// 5000000uS = 0,5 Seg

	PWM_MR4 = 1000000;	// 1000000uS = 1 Seg

	PWM_MR5 = 1000001;	// 1000000uS = 1 Seg

	PWM_MR6 = 1500000;	// 1500000uS = 1,5 Seg

	// Actualizar valores de MR0-6
	PWM_LER |= (1<<LER_MR6) | (1<<LER_MR5) | (1<<LER_MR4) | (1<<LER_MR3);
	PWM_LER |= (1<<LER_MR2) | (1<<LER_MR1) | (1<<LER_MR0);
}
