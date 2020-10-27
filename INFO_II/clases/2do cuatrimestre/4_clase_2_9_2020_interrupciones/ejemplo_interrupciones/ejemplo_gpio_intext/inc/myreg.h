#define 	__RW				volatile
typedef 	unsigned int 		uint32_t;
typedef 	__RW uint32_t 		registro;
typedef 	unsigned char 		uint8_t;

#define	    PORT0 		( ( registro  * ) 0x2009C000UL )
#define	    PORT1		PORT0[8]
#define	    PORT2		PORT0[16]
#define	    PORT3		PORT0[24]
#define	    PORT4		PORT0[32]

#define		PINSEL		( ( registro  * ) 0x4002C000UL )
#define		PINSEL0		PINSEL[0]
#define		PINSEL1		PINSEL[1]
#define		PINSEL2		PINSEL[2]
#define		PINSEL3		PINSEL[3]
#define		PINSEL4		PINSEL[4]
#define		PINSEL5		PINSEL[5]
#define		PINSEL6		PINSEL[6]
#define		PINSEL7		PINSEL[7]
#define		PINSEL8		PINSEL[8]
#define		PINSEL9		PINSEL[9]

#define 	P0			0
#define 	P1			1
#define 	P2			2
#define 	P3			3
#define 	P4			4

#define 	SALIDA		1
#define		PINSEL_GPIO 0

#define	    EXTMODE 		*( ( registro  * ) 0x400FC148)
#define	    EXTPOLAR 		*( ( registro  * ) 0x400FC14C)
#define	    ISER0 			*( ( registro  * ) 0xE000E100)
#define	    ICER0 			*( ( registro  * ) 0xE000E180)
#define		EXTINT			*((registro * ) 0x400FC140)

#define		PINSEL_INT_EXT		1

void Init_GPIO(void);
void SetPINSEL (uint8_t puerto, uint8_t pin, uint8_t modo);
void SetDIR(registro* puerto,uint8_t pin,uint8_t direccion);
void SetPIN(registro* puerto,uint8_t pin,uint8_t estado);
uint8_t GetPIN(registro* puerto,uint8_t pin);
void init(void);
void Init_IntExt(void);

