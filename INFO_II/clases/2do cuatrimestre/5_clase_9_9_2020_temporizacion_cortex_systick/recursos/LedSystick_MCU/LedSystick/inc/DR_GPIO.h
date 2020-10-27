/*
 * DR_GPIO.h
 *
 *  Created on: 15 ago. 2020
 *      Author: nicoc
 */

#ifndef DR_GPIO_H_
#define DR_GPIO_H_

#include <DR_tipos.h>
#include <PR_GPIO.h>
//!< ////////////////// REGISTROS GPIOs //////////////////////////////
//!< 0x2009C000UL : Dirección de inicio (base) de los registros de GPIO
#define		GPIOs		( ( registro  * ) 0x2009C000UL )

#define 	GPIO0_BASE		(GPIOs + 0x00000)	//!< 0x2009C000
#define 	GPIO1_BASE 		(GPIOs + 0x00020)	//!< 0x2009C020
#define 	GPIO2_BASE 		(GPIOs + 0x00040)	//!< 0x2009C040
#define 	GPIO3_BASE 		(GPIOs + 0x00060)	//!< 0x2009C060
#define 	GPIO4_BASE 		(GPIOs + 0x00080)	//!< 0x2009C080



#endif /* DR_GPIO_H_ */
