#include "myreg.h"

void SetPINSEL (uint8_t puerto, uint8_t pin, uint8_t modo)
{
	switch (puerto) {
		case P0:
			if (pin >= 16){
				pin -=16;
				PINSEL1 &= ~(0x03 << (pin * 2));
				PINSEL1 |= (modo << (pin * 2));
			}
			else {
				PINSEL0 &= ~(0x03 << (pin * 2));
				PINSEL0 |= (modo << (pin * 2));
			}
			break;

		case P1:
			if (pin >= 16){
				pin -=16;
				PINSEL3 &= ~(0x03 << (pin * 2));
				PINSEL3 |= (modo << (pin * 2));
			}
			else{
				PINSEL2 &= ~(0x03 << (pin * 2));
				PINSEL2 |= (modo << (pin * 2));
			}
			break;

		case P2:
			if (pin >= 16){
				pin -=16;
				PINSEL5 &= ~(0x03 << (pin * 2));
				PINSEL5 |= (modo << (pin * 2));
			}
			else{
				PINSEL4 &= ~(0x03 << (pin * 2));
				PINSEL4 |= (modo << (pin * 2));
			}
			break;

		case P3:
			if (pin >= 16){
				pin -=16;
				PINSEL7 &= ~(0x03 << (pin * 2));
				PINSEL7 |= (modo << (pin * 2));
			}
			else{
				PINSEL6 &= ~(0x03 << (pin * 2));
				PINSEL6 |= (modo << (pin * 2));
			}
			break;

		case P4:
			if (pin >= 16){
				pin -=16;
				PINSEL9 &= ~(0x03 << (pin * 2));
				PINSEL9 |= (modo << (pin * 2));
			}
			else{
				PINSEL8 &= ~(0x03 << (pin * 2));
				PINSEL8 |= (modo << (pin * 2));
			}
			break;
	} //fin switch
}

void SetDIR(registro* puerto,uint8_t pin,uint8_t direccion)
{
	( direccion == 1 ) ? ( puerto[0] |= ( 0x01 << pin ) ):( puerto[0] &= ~( 0x01 << pin ) );
}

void SetPIN(registro* puerto,uint8_t pin,uint8_t estado)
{
	( estado == 1 ) ? ( puerto[6] |= ( 0x01 << pin ) ):( puerto[7] |= ( 0x01 << pin ) );
}

uint8_t GetPIN(registro* puerto,uint8_t pin)
{
	return (puerto[5]>>pin)& 0x01;	//puerto[5] == FIOPIN
}
