/**
 	\file KitInfo2PR_7Seg.c
 	\brief Primitiva de Display de 7 segmentos
 	\details Valida para Expansion 2 y Expansion 3
 	\author Ing. Marcelo Trujillo
 	\date 2012.04.25
*/

#include "../drivers/inc/FW_Display-Expansion3.h"
#include "funciones.h"
extern volatile uint8_t msgDisplay[DIGITOS];			//!< Buffer de display


void Display(uint16_t Val)
	{
		if(Val>=8)
		{
			SetPIN(2,7,1);
			Val%=8;
		}
		if(Val>=4)
		{
			SetPIN(1,29,1);
			Val%=4;
		}
		if(Val>=2)
		{
			SetPIN(4,28,1);
			Val%=2;
		}
		if(Val>=1)
		{
			SetPIN(1,23,1);
			Val%=1;
		}
	}
