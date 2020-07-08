/**
*	\file funciones.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author Federico Bua
*	\date 31-03-2019 17:38:41
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
#define 	APAGADO	0
#define 	PRENDIDO	1

//Prototipos de los eventos


//Prototipos de las acciones

void LED(uint8_t);
void inicializar(void);
uint8_t consultar (uint8_t,uint8_t);
