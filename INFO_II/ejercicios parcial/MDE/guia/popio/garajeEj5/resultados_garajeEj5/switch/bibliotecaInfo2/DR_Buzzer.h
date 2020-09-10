/*******************************************************************************************************************************//**
 *
 * @file		DR_Buzzer.h
 * @brief		Breve descripción del objetivo del Módulo
 * @date		14 de nov. de 2017
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

#ifndef DRIVERS_INFOTRONIC_INC_DR_BUZZER_H_
#define DRIVERS_INFOTRONIC_INC_DR_BUZZER_H_



/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/



/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/
#include "DR_tipos.h"
#include "DR_Infotronic.h"

/***********************************************************************************************************************************
 *** DEFINES GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MACROS GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TIPO DE DATOS GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES
 **********************************************************************************************************************************/
extern volatile uint8_t BufferBuzzer;		//!< Buffer de las salidas de los relays

/***********************************************************************************************************************************
 *** PROTOTIPOS DE FUNCIONES GLOBALES
 **********************************************************************************************************************************/
void RefrescoBuzzer ( void );
void InicializarBuzzer( void );


#endif /* DRIVERS_INFOTRONIC_INC_DR_BUZZER_H_ */