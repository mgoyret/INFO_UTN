/*
 * DR_PINSEL.h
 *
 *  Created on: 15 ago. 2020
 *      Author: nicoc
 */

#ifndef DR_PINSEL_H_
#define DR_PINSEL_H_

#include <DR_tipos.h>
#include <PR_PINSEL.h>

//!< ////////////////Registros PINSEL//////////////////////////////
//!< 0x4002C000UL : Direccion de inicio de los registros PINSEL
#define		PINSEL		( ( __RW uint32_t  * ) 0x4002C000UL )

#define		PINSEL0		PINSEL[0]	//!< PINSEL0--->P0[15:0] (0x4002C000)
#define		PINSEL1		PINSEL[1]	//!< PINSEL1--->P0[31:16](0x4002C004)
#define		PINSEL2		PINSEL[2]	//!< PINSEL2--->P1[15:0] (0x4002C008)
#define		PINSEL3		PINSEL[3]	//!< PINSEL3--->P1[31:16](0x4002C00C)
#define		PINSEL4		PINSEL[4]	//!< PINSEL4--->P2[15:0] (0x4002C010)
#define		PINSEL5		PINSEL[5]	//!< PINSEL5--->P2[31:16] NOT USED
#define		PINSEL6		PINSEL[6]	//!< PINSEL6--->P3[15:0] NOT USED
#define		PINSEL7		PINSEL[7]	//!< PINSEL7--->P3[31:16] 0x4002C01C)
#define		PINSEL8		PINSEL[8]	//!< PINSEL8--->P4[15:0]  NOT USED
#define		PINSEL9		PINSEL[9]	//!< PINSEL9--->P4[31:16](0x4002C024)

//!< ----------- Estados de PINSEL:
#define		PINSEL_GPIO			0
#define		PINSEL_FUNC1		1
#define		PINSEL_FUNC2		2
#define		PINSEL_FUNC3		3

//!< //////////////////Registros PINMODE ///////////////////////////
//!< 0x4002C040UL : Direccion de inicio de los registros de modo de los pines del GPIO
#define	PINMODE		( ( __RW uint32_t  * ) 0x4002C040UL )

#define		PINMODE0	PINMODE[0]		//!< 0x4002C040
#define		PINMODE1	PINMODE[1]		//!< 0x4002C044
#define		PINMODE2	PINMODE[2]		//!< 0x4002C048
#define		PINMODE3	PINMODE[3]		//!< 0x4002C04C
#define		PINMODE4	PINMODE[4]		//!< 0x4002C050
#define		PINMODE5	PINMODE[5]		//!< 0x4002C054
#define		PINMODE6	PINMODE[6]		//!< 0x4002C058
#define		PINMODE7	PINMODE[7]		//!< 0x4002C05C
#define		PINMODE9	PINMODE[9]		//!< 0x4002C064

//!< ----------- Estados de PINMODE
//!< 00	Pull Up resistor enable (reset value)		01	repeated mode enable
//!< 11	Pull Down resistor enable					10	ni Pull Up ni Pull DOwn
#define		PINMODE_PULLUP 		0
#define		PINMODE_REPEAT 		1
#define		PINMODE_NONE 		2
#define		PINMODE_PULLDOWN 	3

//!< ///////////////// REGISTROS PINMODE_OD ///////////////////////////
//!< 0x4002C068UL : Direccion de inicio de los registros de control del modo OPEN DRAIN
#define		PINMODE_OD		( ( __RW uint32_t  * ) 0x4002C068UL )

#define		PINMODE_OD0		PINMODE_OD[0]
#define		PINMODE_OD1		PINMODE_OD[1]
#define		PINMODE_OD2		PINMODE_OD[2]
#define		PINMODE_OD3		PINMODE_OD[3]
#define		PINMODE_OD4		PINMODE_OD[4]

#endif /* DR_PINSEL_H_ */
