
#ifndef DISPLAY_H_
#define DISPLAY_H_

	#include "KitInfo2_BaseBoard.h"
	#include "RegsLPC1769.h"

	/** -------------------------------------------------------------------------------------
P2[7] A
P1[29] B
P4[28] C
P1{23] D
P1[20] DP
*/
//Entradas del conversor BCD-7Segmentos
#define NUM_A 2,7
#define NUM_B 1,29
#define NUM_C 4,28
#define NUM_D 1,23

//Teclado 4x2
#define FILA0 1,25
#define FILA1 1,22
#define FILA2 1,19
#define FILA3 0,20
#define COLUMNA0 3,25
#define COLUMNA1 1,27

#define		DIGITO_0			0				//!< Numero de Digito
#define		DIGITO_1			1
#define		DIGITO_2			2
#define		DIGITO_3			3
#define		DIGITO_4			4
#define		DIGITO_5			5

#define		DIGITOS				6

#define		DSP0				0				//!< Display rojo
#define		DSP1				1				//!< Display verde


	/** -------------------------------------------------------------------------------------
	 * Prototipos
	 */
	void Display(uint16_t);
	void BarridoDisplay( void );
	void Inicializar_Display7s( void );
	void Inicializar_TecladoMatricial(void);

#endif
