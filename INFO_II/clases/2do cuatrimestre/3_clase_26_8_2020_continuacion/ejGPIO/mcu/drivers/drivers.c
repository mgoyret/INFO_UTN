/*
 * pinsel.c
 *
 *  Created on: Sep 2, 2020
 *      Author: marco
 */


#include <Regs_LPC176x.h>
#include <header.h>

//PINSEL
void setPinSel (uint8_t port, uint8_t pin, uint8_t function)
{
	uint8_t offset = 0;

	if(pin >= 16)
	{
		pin -= 16;
		offset = 1;
	}
	PINSEL[port*2 + offset] &=  ~(3 << 2*pin);
	PINSEL[port*2 + offset] |=   function << 2*pin;
}

//PINMODE
void setPinMode (uint8_t port, uint8_t pin, uint8_t mode)
{
	uint8_t offset = 0;

	if(pin >= 16)
	{
		pin -= 16;
		offset = 1;
	}
	PINMODE[port*2 + offset] &= ~(3 << 2*pin);
	PINMODE[port*2 + offset] |= (mode << 2*pin);
}

//PINMODE_OD
void setPinModeOD (uint8_t port, uint8_t pin, uint8_t mode)
{
	PINMODE_OD[port] &= ~(1 << pin);
	PINMODE_OD[port] |= mode << pin;
}

//FIODIR
void setDir (uint8_t port, uint8_t pin, uint8_t status)
{
	GPIO_BASE[port*8] &= ~(1 << pin);
	GPIO_BASE[port*8] |= status << pin;
}

//FIOPIN
uint8_t getPin (uint8_t port, uint8_t pin)
{
	return (uint8_t)( (GPIO_BASE[port*8 + 5] >> pin) & 1 );
}

//FIOSET
void setPin (uint8_t port, uint8_t pin, uint8_t status)
{
	if(status == ON)
	{
		GPIO_BASE[port*8 + 6] |= 1 << pin;
	}else
	{
		GPIO_BASE[port*8 + 7] |= 1 << pin;
	}
}
