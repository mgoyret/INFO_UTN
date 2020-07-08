/**
*	\file funciones.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author FedericoBua
*	\date 02-04-2019 16:23:41
*/

#include <bibliotecaInfoII.h>
//Declaracion de constantes
#define TRUE  1
#define FALSE  0

#define APRETADO 1
#define SOLTADO 0

#define ON 1
#define OFF 0
//declaracion de la maquina
void maquina_estado(void);


//Declaracion de estados
#define	APAGADO		0
#define	eROJO		1
#define	eVERDE		2
#define	eAZUL		3
#define	eVIOLETA	4

//Prototipos de los eventos

//Prototipos de las acciones
void PrenderLedRed( void );
void PrenderLedGreen( void );
void PrenderLedBlue( void );
void ApagarLedRed( void );
void ApagarLedGreen( void );
void ApagarLedBlue( void );
uint8_t consultar(uint8_t, uint8_t);
void inicializar(void);


