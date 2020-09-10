/**
*	\file AP_MdeE.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author MarcosGoyret
*	\date 02-09-2020 14:44:57
*/
/*********************************************************************************************************************************
*** MODULO
**********************************************************************************************************************************/
#ifndef INC_MDEE_H_
#define INC_MDEE_H_


/*********************************************************************************************************************************
*** DEFINES GLOBALES
**********************************************************************************************************************************/
#define	TRUE			1
#define	FALSE			0

//!< Definicion de Estados
#define	APAGADO		0
#define	PRENDIDO		1

//!< Declaracion de la Maquina de Estados
void maquina_LED(void);
void inicializar(void);


#endif /* INC_MDEE_H_ */
