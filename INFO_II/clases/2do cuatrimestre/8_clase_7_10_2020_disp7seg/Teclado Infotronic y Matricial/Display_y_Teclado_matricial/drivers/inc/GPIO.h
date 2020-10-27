#include "RegsLPC1769.h"
#include "funciones.h"
void SetPINSEL(uint8_t, uint8_t,uint8_t);
void SetPINMODE	(uint8_t, uint8_t,uint8_t);
void SetDIR	(uint8_t, uint8_t, uint8_t);
void SetPIN	(uint8_t, uint8_t, uint8_t);
uint8_t GetPIN (uint8_t, uint8_t, uint8_t);

#define		ACTIVO_BAJO		0
#define		ACTIVO_ALTO		1

#define 	ENTRADA			0
#define 	SALIDA			1

void Inicializar_Teclado( void );
void Inicializar_RGB( void );
void Inicializar_EXP1( void );


#define		Infotronic_KEY0		2,10
#define		Infotronic_KEY1		0,18
#define		Infotronic_KEY2		0,11
#define		Infotronic_KEY3_RC	2,13
#define		Infotronic_KEY4_RC	1,26


#define		RGB_BLUE	2,1
#define		RGB_RED		2,2
#define		RGB_GREEN	2,3


#define PRENDER_ROJO SetPIN(RGB_RED,ON)
#define PRENDER_VERDE SetPIN(RGB_GREEN,ON)
#define PRENDER_AZUL SetPIN(RGB_BLUE,ON)

#define APAGAR_ROJO SetPIN(RGB_RED,OFF)
#define APAGAR_VERDE SetPIN(RGB_GREEN,OFF)
#define APAGAR_AZUL SetPIN(RGB_BLUE,OFF)

void apagarRGB(void);



#define KEY0_ACTIVO_BAJO   GetPIN(Infotronic_KEY0,ACTIVO_BAJO)
#define KEY1_ACTIVO_BAJO   GetPIN(Infotronic_KEY1,ACTIVO_BAJO)
#define KEY2_ACTIVO_BAJO   GetPIN(Infotronic_KEY2,ACTIVO_BAJO)
#define KEY3_ACTIVO_BAJO   GetPIN(Infotronic_KEY3_RC,ACTIVO_BAJO)
#define KEY4_ACTIVO_BAJO   GetPIN(Infotronic_KEY4_RC,ACTIVO_BAJO)
