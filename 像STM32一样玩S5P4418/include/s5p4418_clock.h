/*
 * s5p4418_clock.h
 *
 *  Created on: 2016年9月3日
 *      Author: James
 */

#ifndef _S5P4418_CLOCK_H_
#define _S5P4418_CLOCK_H_


/*	
 * [CORE CLK]   24MHz --> PLLXTI
 * PLLXTI --> PLL0 | PLL1 | PLL2 | PLL3 --> MUX-FCLKCPU0 --> DIV-FCLKCPU0 --> DIV-HCLKCPU0
 * PLLXTI --> PLL0 | PLL1 | PLL2 | PLL3 --> MUX-BCLK --> DIV-BCLK --> DIV-PCLK
 * PLLXTI --> PLL0 | PLL1 | PLL2 | PLL3 --> MUX-MDCLK --> DIV-MDCLK --> DIV-MCLK --> DIV-MBCLK --> DIV-MPCLK
 * PLLXTI --> PLL0 | PLL1 | PLL2 | PLL3 --> MUX-GR3DBCLK --> DIV-GR3DBCLK --> DIV-GR3DPCLK
 * PLLXTI --> PLL0 | PLL1 | PLL2 | PLL3 --> MUX-MPEGBCLK --> DIV-MPEGBCLK --> DIV-MPEGPCLK
 *
 * [TIMER / PWM CLK]
 * DIV-PCLK --> DIV-TIMER-PRESCALER0
 * DIV-PCLK --> DIV-TIMER-PRESCALER1
 * DIV-PCLK --> DIV-PWM-PRESCALER0
 * DIV-PCLK --> DIV-PWM-PRESCALER1
 *
 * [UART CLK]	24MHz --> PLLXTI
 * PLLXTI --> PLL0 | PLL1 | PLL2 --> MUX->UART0 --> DIV-UART0 --> GATE-UART0
 * PLLXTI --> PLL0 | PLL1 | PLL2 --> MUX->UART1 --> DIV-UART1 --> GATE-UART1
 * PLLXTI --> PLL0 | PLL1 | PLL2 --> MUX->UART2 --> DIV-UART2 --> GATE-UART2
 * PLLXTI --> PLL0 | PLL1 | PLL2 --> MUX->UART3 --> DIV-UART3 --> GATE-UART3
 * PLLXTI --> PLL0 | PLL1 | PLL2 --> MUX->UART4 --> DIV-UART4 --> GATE-UART4
 * PLLXTI --> PLL0 | PLL1 | PLL2 --> MUX->UART5 --> DIV-UART5 --> GATE-UART5
 *
 */

#include "s5p4418.h"

#define PLL0_2000M_VALUE       	((6 << 18) | (500 << 8) | 0)
#define PLL0_1900M_VALUE      	((6 << 18) | (475 << 8) | 0)
#define PLL0_1800M_VALUE       	((4 << 18) | (300 << 8) | 0)
#define PLL0_1700M_VALUE       	((6 << 18) | (426 << 8) | 0)
#define PLL0_1600M_VALUE       	((6 << 18) | (400 << 8) | 0)
#define PLL0_1500M_VALUE       	((4 << 18) | (250 << 8) | 0)
#define PLL0_1400M_VALUE       	((6 << 18) | (350 << 8) | 0)
#define PLL0_1300M_VALUE       	((6 << 18) | (325 << 8) | 0)
#define PLL0_1200M_VALUE       	((4 << 18) | (400 << 8) | 1)
#define PLL0_1100M_VALUE       	((6 << 18) | (550 << 8) | 1)
#define PLL0_1000M_VALUE      	((6 << 18) | (500 << 8) | 1)
#define PLL0_900M_VALUE       	((4 << 18) | (300 << 8) | 1)
#define PLL0_800M_VALUE       	((6 << 18) | (400 << 8) | 1)
#define PLL0_780M_VALUE       	((4 << 18) | (260 << 8) | 1)
#define PLL0_760M_VALUE       	((6 << 18) | (380 << 8) | 1)
#define PLL0_740M_VALUE       	((6 << 18) | (370 << 8) | 1)
#define PLL0_720M_VALUE       	((4 << 18) | (240 << 8) | 1)
#define PLL0_600M_VALUE       	((6 << 18) | (600 << 8) | 2)
#define PLL0_562M_VALUE       	((6 << 18) | (562 << 8) | 2)
#define PLL0_550M_VALUE       	((6 << 18) | (550 << 8) | 2)
#define PLL0_533M_VALUE       	((6 << 18) | (533 << 8) | 2)
#define PLL0_490M_VALUE       	((6 << 18) | (490 << 8) | 2)
#define PLL0_470M_VALUE       	((6 << 18) | (470 << 8) | 2)
#define PLL0_460M_VALUE       	((6 << 18) | (460 << 8) | 2)
#define PLL0_450M_VALUE       	((4 << 18) | (300 << 8) | 2)
#define PLL0_440M_VALUE       	((6 << 18) | (440 << 8) | 2)
#define PLL0_430M_VALUE       	((6 << 18) | (430 << 8) | 2)
#define PLL0_420M_VALUE       	((4 << 18) | (280 << 8) | 2)
#define PLL0_410M_VALUE       	((6 << 18) | (410 << 8) | 2)
#define PLL0_400M_VALUE       	((6 << 18) | (400 << 8) | 2)
#define PLL0_399M_VALUE       	((4 << 18) | (266 << 8) | 2)
#define PLL0_390M_VALUE       	((4 << 18) | (260 << 8) | 2)
#define PLL0_384M_VALUE       	((4 << 18) | (256 << 8) | 2)
#define PLL0_350M_VALUE       	((6 << 18) | (350 << 8) | 2)
#define PLL0_330M_VALUE       	((4 << 18) | (220 << 8) | 2)
#define PLL0_300M_VALUE       	((4 << 18) | (400 << 8) | 3)
#define PLL0_266M_VALUE       	((6 << 18) | (532 << 8) | 3)
#define PLL0_250M_VALUE       	((6 << 18) | (500 << 8) | 3)
#define PLL0_220M_VALUE       	((6 << 18) | (440 << 8) | 3)
#define PLL0_200M_VALUE       	((6 << 18) | (400 << 8) | 3)
#define PLL0_166M_VALUE       	((6 << 18) | (332 << 8) | 3)
#define PLL0_133M_VALUE      	((6 << 18) | (532 << 8) | 4)
#define PLL0_125M_VALUE       	((6 << 18) | (500 << 8) | 4)
#define PLL0_100M_VALUE		((6 << 18) | (400 << 8) | 4)
#define PLL0_96M_VALUE		((4 << 18) | (256 << 8) | 4)
#define PLL0_48M_VALUE       	((3 << 18) | (96  << 8) | 4)

#define PLL1_2000M_VALUE       	((3 << 18) | (250 << 8) | 0)
#define PLL1_1900M_VALUE      	((3 << 18) | (238 << 8) | 0)
#define PLL1_1800M_VALUE       	((3 << 18) | (225 << 8) | 0)
#define PLL1_1700M_VALUE       	((3 << 18) | (213 << 8) | 0)
#define PLL1_1600M_VALUE       	((3 << 18) | (200 << 8) | 0)
#define PLL1_1500M_VALUE       	((4 << 18) | (250 << 8) | 0)
#define PLL1_1400M_VALUE       	((3 << 18) | (170 << 8) | 0)
#define PLL1_1300M_VALUE       	((3 << 18) | (163 << 8) | 0)
#define PLL1_1200M_VALUE       	((3 << 18) | (150 << 8) | 0)
#define PLL1_1100M_VALUE       	((3 << 18) | (275 << 8) | 1)
#define PLL1_1000M_VALUE      	((3 << 18) | (250 << 8) | 1)
#define PLL1_900M_VALUE       	((3 << 18) | (225 << 8) | 1)
#define PLL1_800M_VALUE       	((3 << 18) | (200 << 8) | 1)
#define PLL1_780M_VALUE       	((3 << 18) | (195 << 8) | 1)
#define PLL1_760M_VALUE       	((3 << 18) | (190 << 8) | 1)
#define PLL1_740M_VALUE       	((3 << 18) | (185 << 8) | 1)
#define PLL1_720M_VALUE       	((3 << 18) | (180 << 8) | 1)
#define PLL1_600M_VALUE       	((3 << 18) | (150 << 8) | 1)
#define PLL1_562M_VALUE       	((3 << 18) | (141 << 8) | 1)
#define PLL1_550M_VALUE       	((3 << 18) | (275 << 8) | 2)
#define PLL1_533M_VALUE       	((3 << 18) | (267 << 8) | 2)
#define PLL1_490M_VALUE       	((3 << 18) | (245 << 8) | 2)
#define PLL1_470M_VALUE       	((3 << 18) | (235 << 8) | 2)
#define PLL1_460M_VALUE       	((3 << 18) | (230 << 8) | 2)
#define PLL1_450M_VALUE       	((3 << 18) | (225 << 8) | 2)
#define PLL1_440M_VALUE       	((3 << 18) | (220 << 8) | 2)
#define PLL1_430M_VALUE       	((3 << 18) | (215 << 8) | 2)
#define PLL1_420M_VALUE       	((3 << 18) | (210 << 8) | 2)
#define PLL1_410M_VALUE       	((3 << 18) | (205 << 8) | 2)
#define PLL1_400M_VALUE       	((3 << 18) | (200 << 8) | 2)
#define PLL1_399M_VALUE       	((4 << 18) | (266 << 8) | 2)
#define PLL1_390M_VALUE       	((3 << 18) | (195 << 8) | 2)
#define PLL1_384M_VALUE       	((3 << 18) | (192 << 8) | 2)
#define PLL1_350M_VALUE       	((3 << 18) | (175 << 8) | 2)
#define PLL1_330M_VALUE       	((3 << 18) | (165 << 8) | 2)
#define PLL1_300M_VALUE       	((3 << 18) | (150 << 8) | 2)
#define PLL1_266M_VALUE       	((3 << 18) | (266 << 8) | 3)
#define PLL1_250M_VALUE       	((3 << 18) | (250 << 8) | 3)
#define PLL1_220M_VALUE       	((3 << 18) | (220 << 8) | 3)
#define PLL1_200M_VALUE       	((3 << 18) | (200 << 8) | 3)
#define PLL1_166M_VALUE       	((3 << 18) | (166 << 8) | 3)
#define PLL1_133M_VALUE      	((3 << 18) | (266 << 8) | 4)
#define PLL1_125M_VALUE       	((3 << 18) | (250 << 8) | 4)
#define PLL1_100M_VALUE		((3 << 18) | (200 << 8) | 4)
#define PLL1_96M_VALUE		((3 << 18) | (192 << 8) | 4)
#define PLL1_48M_VALUE       	((3 << 18) | (96  << 8) | 4)

typedef struct{
	volatile uint32_t	CLK_MODEREG0; 
	volatile uint32_t	CLK_MODEREG1;
	volatile uint32_t	PLL_SETREG0;
	volatile uint32_t	PLL_SETREG1; 
	volatile uint32_t	PLL_SETREG2; 									
	volatile uint32_t	PLL_SETREG3;
	volatile uint32_t	RSVD0;
	volatile uint32_t	RSVD1;
	volatile uint32_t	CLK_DIVREG0;
	volatile uint32_t	CLK_DIVREG1;
	volatile uint32_t	CLK_DIVREG2;
	volatile uint32_t	CLK_DIVREG3;
	volatile uint32_t	CLK_DIVREG4;
	volatile uint32_t	RSVD2;
	volatile uint32_t	RSVD3;
	volatile uint32_t	RSVD4;
	volatile uint32_t 	RSVD5;
	volatile uint32_t 	RSVD6;
	volatile uint32_t	PLL_SETREG0_SSCG;
	volatile uint32_t	PLL_SETREG1_SSCG;
	volatile uint32_t	PLL_SETREG2_SSCG;
	volatile uint32_t	PLL_SETREG3_SSCG;
}SysCtrl_TypeDef;

#define SysCtrl			((SysCtrl_TypeDef *) CLOCK_BASE)

void S5P4418_CLK_Init(void);

#endif
