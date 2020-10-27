#include "myreg.h"

void init(void)
{
		Init_gpios();
		Init_PLL();
		Init_systick();
		Init_Timers();
		Init_RTC();
}

void Init_RTC(void)
{
	PCONP |= (1 << 9); //Habilitamos el clock del RTC
	CCR = 0x12; // Ponemos el divisor de clock y el contador en reset. Calibracion deshabilitada.
	RTC_AUXEN &= ~(0x01 << 4); // Deshabilito la interrupcion por fail del clock.
	Fijar_tiempo(2019,9,4,11,0,0); // 11:00:00 4/9/2019
	// Año, mes, dia. Ultimos tres argumentos: horas, minutos, segundos.
	CIIR = 0x01; // Cada un segundo me da una interrupcion.
	CCR = 0x11; // Habilitamos el RTC. A partir de que se ejecuta esta linea es que empieza a contar.
	ISER0 = (1 << 17);
}

void Init_gpios(void)
{

		SetPINSEL(P0,22,0);	//Led Integrado
		SetPINSEL(P2,3,PINSEL_GPIO); //RGB
		SetPINSEL(P2,2,PINSEL_GPIO); //RGB
		SetPINSEL(P2,1,PINSEL_GPIO); //RGB

		/* OTROS PERIFÉRICOS */
		/*// SW13 como CAP0.0
		SetPINSEL(P1,28,3);

		// Reles
		SetPINSEL(P0,21,PINSEL_GPIO);
		SetPINSEL(P0,23,PINSEL_GPIO);
		SetPINSEL(P0,27,PINSEL_GPIO);
		SetPINSEL(P2,0,PINSEL_GPIO);
		// Buzzer
		SetPINSEL(P0,28,PINSEL_GPIO);
		// Modos*/

		SetDIR(PORT2,1,SALIDA); //RGB
		SetDIR(PORT2,2,SALIDA); //RGB
		SetDIR(PORT2,3,SALIDA); //RGB
		SetDIR(PORT0,22,SALIDA); //Led Integrado

		/*	SetDIR(PORT0,21,SALIDA);
		SetDIR(PORT0,23,SALIDA);
		SetDIR(PORT0,27,SALIDA);
		SetDIR(PORT2,0,SALIDA);
		SetDIR(PORT0,28,SALIDA);*/

		// Valores iniciales
		/*SetPIN(PORT0,28,1);
		SetPIN(PORT0,21,0);
		SetPIN(PORT0,23,0);
		SetPIN(PORT0,27,0);
		SetPIN(PORT2,0,0);*/
		//RGB y Led integrados inician apagados
		SetPIN(PORT2,1,0);
		SetPIN(PORT2,2,0);
		SetPIN(PORT2,3,0);
		SetPIN(PORT0,22,0);

}

void Init_systick(void)
{
		STRELOAD = 999999; // 999.999=STCALIB (10ms seg con PLL a 100 MHZ)
		STCTRL |= 0x07;	// Clock sistema, interrupción habilitada, systick habilitado.
}

void Init_Timers(void)
{
		PCONP |= 1 << 1; 			// Habilitar Timer 0
		PCLKSEL0 |= 1 << 2; 		// Clock de timer PCLK = CCLK
		T0PR = 99;			    	// Prescaler para generar pulsos lentos. Divido por 100, de 100 Mhz paso a 1 Mhz para TImer0.
		T0CTCR = 0;					// Timer cuenta pulsos PCLK y captura en falling edge de P1.26

		T0MCR &= ~(0x20);           // Deshabilito las configuraciones de M0 y M1
		T0MCR |= 0x19;				// Habilito gen. de interrupcion al ocurrir M0 y al ocurrir M1.

		T0MR0 = 0 ; 	 	    	// Match 0 arranca interrumpiendo.
		T0MR1 = 500000; 			// Match 1 interrumpe cada medio seg y resetea el TIMER0.

		T0EMR |= 0xC0;				// Match 1 cambia el estado del pin cada vez que interrumpe.

		ISER0 |=(0x01 << 1);     	// Habilito Interrupcion TIMER0
		T0TCR = 0x02;		    	// Apago y reseteo el temporizador
		//T0TCR = 0x01;		    	// Enciendo el temporizador
}

void Init_PLL(void) // Clock de 100 MHz.
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

