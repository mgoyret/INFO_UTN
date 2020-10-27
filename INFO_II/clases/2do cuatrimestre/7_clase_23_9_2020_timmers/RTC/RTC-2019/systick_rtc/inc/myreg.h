#define 	__RW				volatile
typedef 	unsigned int 		uint32_t;
typedef 	__RW uint32_t 		registro;
typedef 	unsigned char 		uint8_t;

#define	    PORT0 		( ( registro  * ) 0x2009C000UL )
#define	    PORT1		PORT0+8
#define	    PORT2		PORT0+16
#define	    PORT3		PORT0+24
#define	    PORT4		PORT0+32

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

#define	 SysTick 		( (__RW uint32_t * )  0xE000E010UL  )
#define  STCTRL			SysTick[0]
#define  STRELOAD		SysTick[1]
#define  STCURR			SysTick[2]
#define  STCALIB		SysTick[3]

#define TMR_TICK		1000
#define CCLK			3000000

#define 	ON		1
#define		OFF		0

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
#define		EXTINT			*( ( registro  * ) 0x400FC140)

#define		INT_EXT		1

// PLL

//////////////Registros del CLOCK y de sistema/////////////////
//0x400FC1A0UL: Registro de control de sistema y registro de status:
#define		DIR_SCS			( (uint32_t *) 0x400FC1A0UL)
//0x400FC104UL: Registro de configuracion del clock:
#define		DIR_CCLKCFG		( (uint32_t *) 0x400FC104UL)
//0x400FC10CUL: Registro de seleccion del clock:
#define		DIR_CLKSRCSEL	( (uint32_t *) 0x400FC10CUL)
//0x400FC1C8UL: Clock Output Config register:
#define		DIR_CLKOUTCFG	( (uint32_t *) 0x400FC1C8UL)
//0x400FC000UL: Flash access configuration:
#define		DIR_FLASHCFG	( (uint32_t *) 0x400FC000UL)

/////////////////Registros de los PLL///////////////////////////
//0x400FC080UL: Registro de control del PLL0:
#define		DIR_PLL0CON		( (uint32_t *) 0x400FC080UL)
//0x400FC084UL: Registro de configuracion del PLL0:
#define		DIR_PLL0CFG		( (uint32_t *) 0x400FC084UL)
//0x400FC088UL: Registro de estado del PLL0:
#define		DIR_PLL0STAT	( (uint32_t *) 0x400FC088UL)
//0x400FC08CUL: Registro de control del PLL0:
#define		DIR_PLL0FEED	( (uint32_t *) 0x400FC08CUL)
//0x400FC0A0UL: Registro de control del PLL1:
#define		DIR_PLL1CON		( (uint32_t *) 0x400FC0A0UL)
//0x400FC0A4UL: Registro de configuracion del PLL1:
#define		DIR_PLL1CFG		( (uint32_t *) 0x400FC0A4UL)
//0x400FC0A8UL: Registro de estado del PLL1:
#define		DIR_PLL1STAT	( (uint32_t *) 0x400FC0A8UL)
//0x400FC0ACUL: Registro de control del PLL1:
#define		DIR_PLL1FEED	( (uint32_t *) 0x400FC0ACUL)

//Registro de status y configuracion del sistema:
#define		SCS			DIR_SCS[0]
#define 	FLASHCFG	DIR_FLASHCFG[0]

//Registros de control del CLOCK:
#define		CCLKCFG		DIR_CCLKCFG[0]
#define		CLKSRCSEL	DIR_CLKSRCSEL[0]
#define		CLKOUTCFG	DIR_CLKOUTCFG[0]

//PLL0:
#define		PLL0CON		DIR_PLL0CON[0]
#define		PLL0CFG		DIR_PLL0CFG[0]
#define		PLL0STAT	DIR_PLL0STAT[0]
#define		PLL0FEED	DIR_PLL0FEED[0]

//PLL1:
#define		PLL1CON		DIR_PLL1CON[0]
#define		PLL1CFG		DIR_PLL1CFG[0]
#define		PLL1STAT	DIR_PLL1STAT[0]
#define		PLL1FEED	DIR_PLL1FEED[0]
// Regs
#define		PCLKSEL		( ( registro  * ) 0x400FC1A8UL )
//!< Registros PCLKSEL
#define		PCLKSEL0	PCLKSEL[0]
#define		PCLKSEL1	PCLKSEL[1]
//Power on peripherials
#define 	PCONP	(* ( ( registro  * ) 0x400FC0C4UL ))

//!< ///////////////////   RTC   /////////////////////////////
//!< 0x40034000UL: Registro de configuracion y estado del RTC y registros de backup:
#define		RTC 			( ( registro  * ) 0x40024000UL )
	//!< Miscellaneous registers
	#define		ILR			RTC[0]
	#define		CCR			RTC[2]
	#define		CIIR		RTC[3]
	#define		AMR			RTC[4]
	#define		RTC_AUX		RTC[23]
	#define		RTC_AUXEN	RTC[22]
	#define		CTIME0		RTC[5]
	#define		CTIME1		RTC[6]
	#define		CTIME2		RTC[7]

	//!< Time counter registers
	#define		SEC			RTC[8]
	#define		MIN			RTC[9]
	#define		HOUR		RTC[10]
	#define		DOM			RTC[11]
	#define		DOW			RTC[12]
	#define		DOY			RTC[13]
	#define		MONTH		RTC[14]
	#define		YEAR		RTC[15]
	#define		CALIBRATION	RTC[16]

	//!< General purpose registers
	#define		GPREG0		RTC[17]
	#define		GPREG1		RTC[18]
	#define		GPREG2		RTC[19]
	#define		GPREG3		RTC[20]
	#define		GPREG4		RTC[21]

	//!< Alarm register group
	#define		ALSEC		RTC[24]
	#define		ALMIN		RTC[25]
	#define		ALHOUR		RTC[26]
	#define		ALDOM		RTC[27]
	#define		ALDOW		RTC[28]
	#define		ALDOY		RTC[29]
	#define		ALMON		RTC[30]
	#define		ALYEAR		RTC[31]

///////////////////   TIMERS   /////////////////////////////
//!< 0x40004000UL : Direccion de inicio de los registros del Timer0
#define		TIMER0		( ( registro  * ) 0x40004000UL )
//!< 0x40008000UL : Direccion de inicio de los registros del Timer1
#define		TIMER1		( ( registro  * ) 0x40008000UL )
//!< 0x40090000UL : Direccion de inicio de los registros del Timer2
#define		TIMER2		( ( registro  * ) 0x40090000UL )
//!< 0x40094000UL : Direccion de inicio de los registros del Timer3
#define		TIMER3		( ( registro  * ) 0x40094000UL )

//Registros de timers:
#define		T0IR		TIMER0[0]
#define		T0TCR		TIMER0[1]
#define		T0TC		TIMER0[2]
#define		T0PR		TIMER0[3]
#define		T0PC		TIMER0[4]
#define		T0MCR		TIMER0[5]
#define		T0MR0		TIMER0[6]
#define		T0MR1		TIMER0[7]
#define		T0MR2		TIMER0[8]
#define		T0MR3		TIMER0[9]
#define		T0CCR		TIMER0[10]
#define		T0CR0		TIMER0[11]
#define		T0CR1		TIMER0[12]
#define		T0EMR		*( ( registro  * ) 0x4000403C)
#define		T0CTCR		*( ( registro  * ) 0x40004070)

#define		T1IR		TIMER1[0]
#define		T1TCR		TIMER1[1]
#define		T1TC		TIMER1[2]
#define		T1PR		TIMER1[3]
#define		T1PC		TIMER1[4]
#define		T1MCR		TIMER1[5]
#define		T1MR0		TIMER1[6]
#define		T1MR1		TIMER1[7]
#define		T1MR2		TIMER1[8]
#define		T1MR3		TIMER1[9]
#define		T1CCR		TIMER1[10]
#define		T1CR0		TIMER1[11]
#define		T1CR1		TIMER1[12]
#define		T1EMR		*( ( registro  * ) 0x4000803C)
#define		T1CTCR		*( ( registro  * ) 0x40008070)


#define		T2IR		TIMER2[0]
#define		T2TCR		TIMER2[1]
#define		T2TC		TIMER2[2]
#define		T2PR		TIMER2[3]
#define		T2PC		TIMER2[4]
#define		T2MCR		TIMER2[5]
#define		T2MR0		TIMER2[6]
#define		T2MR1		TIMER2[7]
#define		T2MR2		TIMER2[8]
#define		T2MR3		TIMER2[9]
#define		T2CCR		TIMER2[10]
#define		T2CR0		TIMER2[11]
#define		T2CR1		TIMER2[12]
#define		T2EMR		*( ( registro  * ) 0x4009003C)
#define		T2CTCR		*( ( registro  * ) 0x40090070)


#define		T3IR		TIMER3[0]
#define		T3TCR		TIMER3[1]
#define		T3TC		TIMER3[2]
#define		T3PR		TIMER3[3]
#define		T3PC		TIMER3[4]
#define		T3MCR		TIMER3[5]
#define		T3MR0		TIMER3[6]
#define		T3MR1		TIMER3[7]
#define		T3MR2		TIMER3[8]
#define		T3MR3		TIMER3[9]
#define		T3CCR		TIMER3[10]
#define		T3CR0		TIMER3[11]
#define		T3CR1		TIMER3[12]
#define		T3EMR		*( ( registro  * ) 0x4009403C)
#define		T3CTCR		*( ( registro  * ) 0x40094070)


// Constantes
#define CLOCK_SETUP_Value 	    1
#define SCS_Value				0x00000020
#define CLKSRCSEL_Value         0x00000001
#define PLL0_SETUP_Value        1
#define PLL0CFG_Value           0x00050063
#define PLL1_SETUP_Value        1
#define PLL1CFG_Value           0x00000023
#define CCLKCFG_Value           0x00000003
#define USBCLKCFG_Value         0x00000000
#define PCLKSEL0_Value          0x00000000
#define PCLKSEL1_Value          0x00000000
#define PCONP_Value             0x042887DE
#define CLKOUTCFG_Value         0x00000000
#define FLASHCFG_Value			0x00004000
//Prototipos
void Fijar_tiempo(uint32_t anio, uint8_t mes, uint8_t dia, uint8_t hora, uint8_t minutos, uint8_t segundos);
void Init_RTC(void);
void Init_systick(void);
void Init_gpios(void);
void SetPINSEL (uint8_t puerto, uint8_t pin, uint8_t modo);
void SetDIR(registro* puerto,uint8_t pin,uint8_t direccion);
void SetPIN(registro* puerto,uint8_t pin,uint8_t estado);
uint8_t GetPIN(registro* puerto,uint8_t pin);
void init(void);
void Init_intext(void);
void Funciones_centesimas(void);
void Funciones_decimas(void);
void Funciones_segundos(void);
void Funciones_minutos(void);
void Funciones_horas(void);
void Funciones_dias(void);
void Init_PLL(void);
void Init_Timers(void);
void Atencion_T0_M0(void);
void Atencion_T0_M1(void);
void Atencion_T0_M2(void);
void Atencion_T0_M3(void);
void Atencion_T0_C0(void);
void Atencion_T0_C1(void);
