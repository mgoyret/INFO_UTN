#include "funciones.h"
#include "GPIO.h"
#include "KitInfo2_BaseBoard.h"
#include "FW_Display-Expansion3.h"

void Inicializar_TecladoMatricial( void )
{

	SetPINSEL ( FILA0 , PINSEL_GPIO);
	SetPINSEL ( FILA1 , PINSEL_GPIO);
	SetPINSEL ( FILA2 , PINSEL_GPIO);
	SetPINSEL ( FILA3 , PINSEL_GPIO);

	SetPINSEL ( COLUMNA0 , PINSEL_GPIO);
	SetPINSEL ( COLUMNA1 , PINSEL_GPIO);

	SetDIR ( FILA0 , ENTRADA);
	SetDIR ( FILA1 , ENTRADA);
	SetDIR ( FILA2 , ENTRADA);
	SetDIR ( FILA3 , ENTRADA);

	SetDIR ( COLUMNA0 , SALIDA);
	SetDIR ( COLUMNA1 , SALIDA);

	SetPINMODE (FILA0,0); //Defino Pullup
	SetPINMODE (FILA1,0);
	SetPINMODE (FILA2,0); //Defino Pullup
	SetPINMODE (FILA3,0); //Pullup
}

