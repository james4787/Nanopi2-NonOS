/*
 * s5p4418_gpio.c
 *
 *  Created on: 2016年8月3日
 *      Author: James
 */

#include"../include/s5p4418_clock.h"

void S5P4418_CLK_Init()
{   
	/*PLL0=550MHz*/
        SysCtrl->PLL_SETREG0 &= ~0xFFF;
	SysCtrl->PLL_SETREG0 |= PLL0_550M_VALUE;
	/*PLL1=1200MHz*/
        SysCtrl->PLL_SETREG1 &= ~0xFFF;
	SysCtrl->PLL_SETREG1 |= PLL0_1200M_VALUE;
	/*PLL2=800MHz*/
        SysCtrl->PLL_SETREG2 &= ~0xFFF;
	SysCtrl->PLL_SETREG2 |= PLL1_800M_VALUE;
	/*PLL3=600MHz*/
        SysCtrl->PLL_SETREG3 &= ~0xFFF;
	SysCtrl->PLL_SETREG3 |= PLL1_600M_VALUE;
	/*FCLK=1.2GHz,HCLK=300MHz*/
        SysCtrl->CLK_DIVREG0 &= ~0x1FFF;
	SysCtrl->CLK_DIVREG0 |= ((3 << 9)|(0 << 3)| 1);        
	/*BCLK=400MHz,PCLK=200MHz*/
	SysCtrl->CLK_DIVREG1 &= ~0x1FFF;
 	SysCtrl->CLK_DIVREG1 |= ((3 << 9)|(1 << 3)| 2);
	/*MDCLK=800MHz,MCLK=800MHz,MBCLK=400MHz,MPCLK=200MHz*/
        SysCtrl->CLK_DIVREG2 &= ~0x7FFFFFF;
        SysCtrl->CLK_DIVREG2 |= ((3 << 21)|(1 << 15)|(0 << 9)|(0 << 3)| 2);
	/*GR3D:BCLK=300MHz,PCLK=150MHz*/
        SysCtrl->CLK_DIVREG3 &= ~0x1FFF;
 	SysCtrl->CLK_DIVREG3 |= ((3 << 9)|(1 << 3)| 3);
	/*MPEG:BCLK=300MHz,FCL K=150MHz*/
        SysCtrl->CLK_DIVREG4 &= ~0x1FFF;
 	SysCtrl->CLK_DIVREG4 |= ((3 << 9)|(1 << 3)| 3);
	/*频率更新*/
        SysCtrl->CLK_MODEREG0 |= 0x0F;
        SysCtrl->CLK_MODEREG0 &= 0x00;
        while(SysCtrl->CLK_MODEREG0 & 0x80000000);
}

