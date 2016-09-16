/*
 * s5p4418_sysclk.h
 *
 *  Created on: 2016年9月2日
 *      Author: James
 */
#ifndef _S5P4418_SYSCLK_H_
#define _S5P4418_SYSCLK_H_

#include"s5p4418.h"



/*Clock Generator Level 1
 *	CODA960
 *	Crypto
 *	I2C
 *	3D GPU
 *	MPEGTSI
 *	PDM
 *	SCALLER
 *	DEINTERLACE
 *	MLC
 */
#define CODA960CLKENB				(*(volatile unsigned *)(0xC00C0000 + 0x7000))
#define CRYPTOCLKENB				(*(volatile unsigned *)(0xC00C0000 + 0x6000))
#define I2C0CLKENB				(*(volatile unsigned *)(0xC00A0000 + 0xE000))
#define I2C1CLKENB				(*(volatile unsigned *)(0xC00A0000 + 0xF000))
#define I2C2CLKENB				(*(volatile unsigned *)(0xC00B0000 + 0x0000))
#define GPUCLKENB				(*(volatile unsigned *)(0xC00C0000 + 0x3000))
#define MPEGTSICLKENB				(*(volatile unsigned *)(0xC00C0000 + 0xB700))
#define PDMCLKENB				(*(volatile unsigned *)(0xC00C0000 + 0xB000))
#define SCALERCLKENB				(*(volatile unsigned *)(0xC00B0000 + 0x6000))
#define DEINTERLACECLKENB			(*(volatile unsigned *)(0xC00B0000 + 0x5000))
#define MLC0CLKENB				(*(volatile unsigned *)(0xC0100000 + 0x23C0))
#define MLC1CLKENB				(*(volatile unsigned *)(0xC0100000 + 0x27C0))
/* Clock Generator Level 1
 *	MIPICSI
 *	PPM
 *	PWMTIMER
 *	SDMMC
 *	SPDIFTX
 *	SSP
 *	UART
 *	VIP
 */
#define MIPICSICLKENB				(*(volatile unsigned *)(0xC00C0000 + 0xA000))
#define MIPICSICLKGEN0L				(*(volatile unsigned *)(0xC00C0000 + 0xA004))
#define PPMCLKENB				(*(volatile unsigned *)(0xC00C0000 + 0x4000))
#define PPMCLKGEN0L				(*(volatile unsigned *)(0xC00C0000 + 0x4004))
#define PWM0CLKENB				(*(volatile unsigned *)(0xC00B0000 + 0xA000))
#define PWM1CLKENB				(*(volatile unsigned *)(0xC00B0000 + 0xE000))
#define PWM2CLKENB				(*(volatile unsigned *)(0xC00B0000 + 0xF000))
#define PWM3CLKENB				(*(volatile unsigned *)(0xC00C0000 + 0x0000))
#define TIMER0CLKENB				(*(volatile unsigned *)(0xC00B0000 + 0x9000))
#define TIMER1CLKENB				(*(volatile unsigned *)(0xC00B0000 + 0xB000))
#define TIMER2CLKENB				(*(volatile unsigned *)(0xC00B0000 + 0xC000))
#define TIMER3CLKENB				(*(volatile unsigned *)(0xC00B0000 + 0xD000))
#define PWM0CLKGEN0L				(*(volatile unsigned *)(0xC00B0000 + 0xA004))
#define PWM1CLKGEN0L				(*(volatile unsigned *)(0xC00B0000 + 0xE004))
#define PWM2CLKGEN0L				(*(volatile unsigned *)(0xC00B0000 + 0xF004))
#define PWM3CLKGEN0L				(*(volatile unsigned *)(0xC00C0000 + 0x0004))
#define TIMER0CLKGEN0L				(*(volatile unsigned *)(0xC00B0000 + 0x9004))
#define TIMER1CLKGEN0L				(*(volatile unsigned *)(0xC00B0000 + 0xB004))
#define TIMER2CLKGEN0L				(*(volatile unsigned *)(0xC00B0000 + 0xC004))
#define TIMER3CLKGEN0L				(*(volatile unsigned *)(0xC00B0000 + 0xD004))
#define SDMMC0CLKENB				(*(volatile unsigned *)(0xC00C0000 + 0x5000))
#define SDMMC1CLKENB				(*(volatile unsigned *)(0xC00C0000 + 0xC000))
#define SDMMC2CLKENB				(*(volatile unsigned *)(0xC00C0000 + 0xD000))
#define SDMMC0CLKGEN0L				(*(volatile unsigned *)(0xC00C0000 + 0x5004))
#define SDMMC1CLKGEN0L			   	(*(volatile unsigned *)(0xC00C0000 + 0xC004))
#define SDMMC2CLKGEN0L			    	(*(volatile unsigned *)(0xC00C0000 + 0xD004))
#define SPDIFTXCLKENB				(*(volatile unsigned *)(0xC00B0000 + 0x8000))
#define SPDIFTXCLKGEN0L				(*(volatile unsigned *)(0xC00B0000 + 0x8004))
#define SSP0CLKENB				(*(volatile unsigned *)(0xC00A0000 + 0xC000))
#define SSP1CLKENB				(*(volatile unsigned *)(0xC00A0000 + 0xD000))
#define SSP2CLKENB				(*(volatile unsigned *)(0xC00A0000 + 0x7000))
#define SSP0CLKGEN0L				(*(volatile unsigned *)(0xC00A0000 + 0xC004))
#define VIP0CLKENB				(*(volatile unsigned *)(0xC00C0000 + 0x1000))
#define VIP1CLKENB				(*(volatile unsigned *)(0xC00C0000 + 0x2000))
#define VIP0CLKGEN0L				(*(volatile unsigned *)(0xC00C0000 + 0x1004))
#define VIP1CLKGEN0L				(*(volatile unsigned *)(0xC00C0000 + 0x2004))
/*Clock Generator Level 2
 *	GMAC
 *	I2S
 *	USBHOSTOTG
 *	DPC
 *	LVDS
 *	HDMI
 *	MIPIDSI
 */
#define GMACCLKENB				(*(volatile unsigned *)(0xC00C0000 + 0x8000))
#define GMACCLKGEN0L				(*(volatile unsigned *)(0xC00C0000 + 0x8004))
#define GMACCLKGEN1L				(*(volatile unsigned *)(0xC00C0000 + 0x800C))
#define I2S0CLKENB				(*(volatile unsigned *)(0xC00B0000 + 0x2000))
#define I2S1CLKENB				(*(volatile unsigned *)(0xC00B0000 + 0x3000))
#define I2S2CLKENB				(*(volatile unsigned *)(0xC00B0000 + 0x4000))
#define I2S0CLKGEN0L				(*(volatile unsigned *)(0xC00B0000 + 0x2004))
#define I2S1CLKGEN0L				(*(volatile unsigned *)(0xC00B0000 + 0x3004))
#define I2S2CLKGEN0L				(*(volatile unsigned *)(0xC00B0000 + 0x4004))
#define I2S0CLKGEN1L				(*(volatile unsigned *)(0xC00B0000 + 0x200C))
#define I2S1CLKGEN1L				(*(volatile unsigned *)(0xC00B0000 + 0x300C))
#define I2S2CLKGEN1L				(*(volatile unsigned *)(0xC00B0000 + 0x400C))
#define USBHOSTOTGCLKENB			(*(volatile unsigned *)(0xC0060000 + 0xB000))
#define USBHOSTOTGCLKGEN0L			(*(volatile unsigned *)(0xC0060000 + 0xB004))
#define USBHOSTOTGCLKGEN1L			(*(volatile unsigned *)(0xC0060000 + 0xB00C))
#define DPC0CLKENB				(*(volatile unsigned *)(0xC0100000 + 0x2BC0))
#define DPC1CLKENB				(*(volatile unsigned *)(0xC0100000 + 0x2FC0))
#define DPC0CLKGEN0L				(*(volatile unsigned *)(0xC0100000 + 0x2BC4))
#define DPC1CLKGEN0L				(*(volatile unsigned *)(0xC0100000 + 0x2FC4))
#define DPC0CLKGEN1L				(*(volatile unsigned *)(0xC0100000 + 0x2BCC))
#define DPC1CLKGEN1L				(*(volatile unsigned *)(0xC0100000 + 0x2FCC))
#define LVDSCLKENB				(*(volatile unsigned *)(0xC0100000 + 0x8000))
#define LVDSCLKGEN0L				(*(volatile unsigned *)(0xC0100000 + 0x8004))
#define LVDSCLKGEN1L				(*(volatile unsigned *)(0xC0100000 + 0x800C))
#define HDMICLKENB				(*(volatile unsigned *)(0xC0100000 + 0x9000))
#define HDMICLKGEN0L				(*(volatile unsigned *)(0xC0100000 + 0x9004))
#define HDMICLKGEN1L				(*(volatile unsigned *)(0xC0100000 + 0x900C))
#define MIPIDSICLKENB				(*(volatile unsigned *)(0xC0100000 + 0x5000))
#define MIPIDSICLKGEN0L				(*(volatile unsigned *)(0xC0100000 + 0x5004))
#define MIPIDSICLKGEN1L				(*(volatile unsigned *)(0xC0100000 + 0x500C))

#endif 
