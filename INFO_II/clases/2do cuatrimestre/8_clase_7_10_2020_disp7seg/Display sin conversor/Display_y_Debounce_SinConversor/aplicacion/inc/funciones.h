/**
*	\file funciones.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author FedericoBua
*	\date 08-09-2018 22:58:22
*/
#include "RegsLPC1769.h"
//Declaracion de constantes
#define TRUE  1
#define FALSE  0

#define ON 1
#define OFF 0

#define NO_KEY 255
#define KEY0 0
#define KEY1 1
#define KEY2 2
#define KEY3 3
#define KEY4 4

uint8_t Teclado( void );
void agregarTiempoRGB(uint8_t);
