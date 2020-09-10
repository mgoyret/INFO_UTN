typedef unsigned int uint32_t;
typedef short unsigned int uint16_t;
typedef unsigned char int uint8_t;

//BASE DIRECTION DEFINES FOR "ARRAY" MANIPULATION
#define GPIO		((__RW uint32_t*) 0x2009C000UL)
#define PINSEL		((__RW uint32_t*) 0x4002C000UL)
#define PINMODE		((__RW uint32_t*) 0x4002C040UL)
#define PINMODE_OD	((__RW uint32_t*) 0x4002C068UL)

#define __R volatile const
#define __W volatile 
#define __RW volatile 

//PINSEL
#define function_GPIO0 0
#define function_GPI01 1
#define function_GPI02 2
#define function_GPI03 3

//PINMODE
#define PULLUP 0
#define REPEAT 1
#define NONE 2
#define PULLDOWN 3

//PINMODE_OD
#define NOT_OD 0
#define OD 1


void SetPinSel (uint8_t port,uint8_t pin, uint8_t function);
void SetPinMode (uint8_t port,uint8_t pin, uint8_t mode);
void SetPinModeOD (uint8_t port,uint8_t pin, uint8_t mode);
void SetDir (uint8_t port,uint8_t pin,uint8_t status);
uint8_t GetPin (uint8_t port,uint8_t pin);
void SetPin (uint8_t port,uint8_t pin,uint8_t status);


//PINSEL
void SetPinSel (uint8_t port, uint8_t pin, uint8_t function)
{
	uint8_t offset = 0;

	//PROTECTION
    if( (pin > 31) || (port > 4) || (function > 3) )
        return;

	if(pin >= 16)
	{
		pin -= 16;
		offset = 1;
	}
	/* cada pin usa dos bits, por lo que cada port de 32 pines usa dos reg pinsel completos */
	//primero pongo en 00 los dos bits deseados
	PINSEL[port*2 + offset] &=  ~(3 << 2*pin);
	//luego pongo el valor deseado en esos bits (0 <= function <= 3)
	PINSEL[port*2 + offset] |=   function << 2*pin;
}

//PINMODE
void SetPinMode (uint8_t port, uint8_t pin, uint8_t mode)
{
	uint8_t offset = 0;

	//PROTECTION
    if( (pin > 31) || (port > 4) || (mode > 3) )
        return;

	if(pin >= 16)
	{
		pin -= 16;
		offset = 1;
	}
	PINMODE[port*2 + offset] &= ~(3 << 2*pin);
	PINMODE[port*2 + offset] |= (mode << 2*pin);
}

//PINMODE_OD
void SetPinModeOD (uint8_t port, uint8_t pin, uint8_t mode)
{
	//PROTECTION
    if( (pin > 31) || (port > 4) || (mode > 1) )
        return;

	PINMODE_OD[port] &= ~(1 << pin);
	PINMODE_OD[port] |= mode << pin;
}

//FIODIR
void SetDir (uint8_t port, uint8_t pin, uint8_t status)
{
	//PROTECTION
    if( (pin > 31) || (port > 4) || (status > 1) )
        return;

	GPIO[port*8] &= ~(1 << pin);
	GPIO[port*8] |= status << pin;
}

//FIOPIN
uint8_t GetPin (uint8_t port, uint8_t pin)
{
	//PROTECTION
    if( (pin > 31) || (port > 4) )
        return;

	//la operacion GPIO[port *8 + 5] es de 32 bits, y aunq la desplaze lo sigue siendo, con muchos 0. por lo que lo casteo
	return (uint8_t)( (GPIO[port*8 + 5] >> pin) & 1 );
}

//FIOSET
void SetPin (uint8_t port, uint8_t pin, uint8_t status)
{
	//PROTECTION
    if( (pin > 31) || (port > 4) || (status > 1) )
        return;

	if(status == ON)
	{
		GPIO[port*8 + 6] |= 1 << pin;
	}else
	{
		GPIO[port*8 + 7] |= 1 << pin;
	}
}
