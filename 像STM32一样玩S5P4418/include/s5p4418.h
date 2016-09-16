/*
 * s5p4418.h
 *
 *  Created on: 2016年8月3日
 *      Author: James
 */

#ifndef _S5P4418_H_
#define _S5P4418_H_

typedef unsigned int	uint32_t;

#include "string.h"
#include "s5p4418_clock.h"
#include "s5p4418_gpio.h"
#include "s5p4418_uart.h"
#include "s5p4418_sysclk.h"
#include "s5p4418_interrupt.h"



#define	GPIOA_BASE		(uint32_t)0xC001A000
#define	GPIOB_BASE		(uint32_t)0xC001B000
#define	GPIOC_BASE		(uint32_t)0xC001C000
#define	GPIOD_BASE		(uint32_t)0xC001D000
#define	GPIOE_BASE		(uint32_t)0xC001E000

#define	CLOCK_BASE		(uint32_t)0xC0010000

#define UART0_BASE		(uint32_t)0xC00A1000
#define UART1_BASE		(uint32_t)0xC00A0000
#define UART2_BASE		(uint32_t)0xC00A2000
#define UART3_BASE		(uint32_t)0xC00A3000
#define UART4_BASE		(uint32_t)0xC006D000

#define UART0CLK_BASE		(uint32_t)0xC00A9000
#define UART1CLK_BASE		(uint32_t)0xC00A8000
#define UART2CLK_BASE		(uint32_t)0xC00AA000
#define UART3CLK_BASE		(uint32_t)0xC00AB000
#define UART4CLK_BASE		(uint32_t)0xC006E000
#define UART5CLK_BASE		(uint32_t)0xC0084000

#define VIC0_BASE		(uint32_t)0xC0002000
#define VIC1_BASE		(uint32_t)0xC0003000






/* S5P4418 ID 
[31:24] Implementer		0x41 ARM Limited.
[23:20] Variant 		0x4 Major revision number.
[19:16] Architecture		0xF Defined by CPUID scheme.
[15:4] Primary part number	0xC09 Cortex-A9.
[3:0] Revision 			0x1 Minor revision number.
*/

#define S5P4418_ID_ECID0		(0xC0067000 + 0x00)
#define S5P4418_ID_ECID1		(0xC0067000 + 0x04)
#define S5P4418_ID_ECID2		(0xC0067000 + 0x08)
#define S5P4418_ID_ECID3		(0xC0067000 + 0x0C)

#define S5P4418_ID_EC0			(0xC0067000 + 0x54)
#define S5P4418_ID_EC1			(0xC0067000 + 0x58)
#define S5P4418_ID_EC2			(0xC0067000 + 0x5C)

#endif /* S5P4418_H_ */
