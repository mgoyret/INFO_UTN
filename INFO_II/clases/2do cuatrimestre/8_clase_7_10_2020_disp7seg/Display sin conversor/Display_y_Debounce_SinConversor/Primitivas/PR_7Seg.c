/**
 	\file KitInfo2PR_7Seg.c
 	\brief Primitiva de Display de 7 segmentos
 	\details Valida para Expansion 2 y Expansion 3
 	\author Ing. Marcelo Trujillo
 	\date 2012.04.25
*/

#include "funciones.h"
#include "FW_Display-Expansion2.h"
extern volatile uint8_t msgDisplay[DIGITOS];			//!< Buffer de display

uint8_t Tabla_Digitos_BCD_7seg[] = { 0x3f, 0x06, 0x5B, 0x4f, 0x66, 0x6D, 0x7C, 0x07, 0x7f, 0x67};

void Display(uint16_t Val)
	{
		uint8_t i ;
		uint8_t auxDisplay[6];
		auxDisplay[0] = auxDisplay[1] = auxDisplay[2]= auxDisplay[3]= auxDisplay[4]= auxDisplay[5]=0;

		//* Convierto a 7 Seg.
		for(i = 0 ; i<DIGITOS ; i++ )
		{
			auxDisplay[i] = Tabla_Digitos_BCD_7seg[Val%10];
			Val /= 10; // Val debe ser entre 0 y 9!!
		}

				msgDisplay[ 5 ] = auxDisplay[ 5 ];
				msgDisplay[ 4 ] = auxDisplay[ 4 ];
				msgDisplay[ 3 ] = auxDisplay[ 3 ];
				msgDisplay[ 2 ] = auxDisplay[ 2 ];
				msgDisplay[ 1 ] = auxDisplay[ 1 ];
				msgDisplay[ 0 ] = auxDisplay[ 0 ];
	}
