/*
 * KitInic.c
 *
 *  Created on:
 *  	Author:
 */

#include "FW_Init.h"
#include "FW_GPIO.h"
#include "FW_PINSEL.h"
#include "FW_SysTick.h"
#include "FW_UART.h"

void Init(void)
{
	//Configuro el PLL: seteo el oscilador interno del micro en 100MHz
	InitPLL();
	//Configuro los puertos de entrada/salida de propósito general (GPIOs)
	InitGPIOs();
	//Systick en 2.5ms
	InitSysTick(2500);
	//Inicialización de UART0 en 9600-8-N-1
	InitUART0();
}

/********************************************************************************
	\fn  void InitPLL (void)
	\brief: Este bloque de codigo habilita el oscilador externo como fuente de clk
			del micro, y configura el PLL (Phase Locked Loop) para generar un clock
			interno de 100MHz a partir del oscilador conectado.
	\author & date: CATEDRA INFO2- Nov2012
 	\param 	void
	\return void
*/
void InitPLL(void)
{
	SCS       = SCS_Value;

	if (SCS_Value & (1 << 5))               /* If Main Oscillator is enabled      */
		while ((SCS & (1<<6)) == 0);/* Wait for Oscillator to be ready    */

	CCLKCFG   = CCLKCFG_Value;      /* Setup Clock Divider                */

	PCLKSEL0  = PCLKSEL0_Value;     /* Peripheral Clock Selection         */
	PCLKSEL1  = PCLKSEL1_Value;

	CLKSRCSEL = CLKSRCSEL_Value;    /* Select Clock Source for PLL0       */

	PLL0CFG   = PLL0CFG_Value;      /* configure PLL0                     */
	PLL0FEED  = 0xAA;
	PLL0FEED  = 0x55;

	PLL0CON   = 0x01;             /* PLL0 Enable                        */
	PLL0FEED  = 0xAA;
	PLL0FEED  = 0x55;

	while (!(PLL0STAT & (1<<26)));/* Wait for PLOCK0                    */

	PLL0CON   = 0x03;             /* PLL0 Enable & Connect              */
	PLL0FEED  = 0xAA;
	PLL0FEED  = 0x55;

	while (!(PLL0STAT & ((1<<25) | (1<<24))));/* Wait for PLLC0_STAT & PLLE0_STAT */

	PLL1CFG   = PLL1CFG_Value;
	PLL1FEED  = 0xAA;
	PLL1FEED  = 0x55;

	PLL1CON   = 0x01;             /* PLL1 Enable                        */
	PLL1FEED  = 0xAA;
	PLL1FEED  = 0x55;

	while (!(PLL1STAT & (1<<10)));/* Wait for PLOCK1                    */

	PLL1CON   = 0x03;             /* PLL1 Enable & Connect              */
	PLL1FEED  = 0xAA;
	PLL1FEED  = 0x55;

	while (!(PLL1STAT & ((1<< 9) | (1<< 8))));/* Wait for PLLC1_STAT & PLLE1_STAT */

	PCONP     = PCONP_Value;        /* Power Control for Peripherals      */

	CLKOUTCFG = CLKOUTCFG_Value;    /* Clock Output Configuration         */

	FLASHCFG  = (FLASHCFG & ~0x0000F000) | FLASHCFG_Value;
}

/********************************************************************************
	\fn  void InitGPIOs (void)
	\brief: Para cada PIN de un PUERTO de entrada/salida, tengo que configurar 2 registros:
			PINSEL: Selecciona si el pin se comportará como un GPIO o como el pin de un periférico.
					Para modificar este registro uso la función SetPINSEL().
			FIODIR:	Selecciona si el pin se comportará como una entrada o como una salida digital.
					Para modificar este registro uso la función SetDir().
	\author & date: CATEDRA INFO2 - Feb2012
 	\param 	void
	\return void
*/
void InitGPIOs(void)
{
	//Selecciono FUNCIÓN del pin en PINSELx.
	// LED STICK
	SetPINSEL(P0, 22, PINSEL_GPIO);
	SetDIR(PORT0, 22, SALIDA);
	SetPIN(PORT0, 22, OFF);
}
