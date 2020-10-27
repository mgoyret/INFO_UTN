/**
 	\file FW_SysTick.c
 	\brief Driver del SysTick
 	\details
 	\author
 	\date
*/

#include "FW_SysTick.h"
#include "FW_GPIO.h"

void InitSysTick(uint32_t useg)
{
	uint32_t value;

	// N = t / (1/fclk) = t * fclk
	// si fclk = 100MHz -->  N = t (en us) * 100
	// Para temporizaciones repetitivas se debe cargar N-1
	value = useg * 100 - 1;
	STRELOAD = value;
	//Hago que se dispare la interrupción al habilitar
	STCURR = 0;
	//Habilito el SysTick
	STCTRL = 0x00000007;
}

void SysTick_Handler(void)
{
	static uint32_t ticks_10ms = TICKS_CENTESIMAS;
	static uint32_t	ticks_100ms = TICKS_DECIMAS;
	static uint32_t ticks_1seg = TICKS_SEGUNDOS;

	ticks_10ms--;
	if(!ticks_10ms) {
		// cada 10ms
		ticks_10ms = TICKS_CENTESIMAS;
		ticks_100ms--;
		if(!ticks_100ms) {
			// cada 100ms
			ticks_100ms = TICKS_DECIMAS;
			ticks_1seg--;
			if(!ticks_1seg) {
				// cada 1seg
				ticks_1seg = TICKS_SEGUNDOS;
				// prendo y apago el led del stick
				SetPIN(PORT0, 22, !GetPIN(PORT0, 22));
			}
		}
	}
}

