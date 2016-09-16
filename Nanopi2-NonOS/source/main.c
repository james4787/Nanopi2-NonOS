/*
 * main.c
 *
 *  Created on: 2016年8月3日
 *      Author: James
 */

#include "../include/s5p4418.h"

int main(){
	unsigned char temp[10]={0};
	S5P4418_CLK_Init();
	s5p4418_IRQ_Init(VIC0,VIC0_VEC,VIC1,VIC1_VEC);
	UART_ClockInit(UART0CLK);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_StructInit(&GPIO_InitStruct);
	/*LED INIT*/
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStruct.GPIO_ALTFN = ALT_Function2;
	GPIO_InitStruct.GPIO_Mode = Output_Mode;
	GPIO_InitStruct.GPIO_PuPd = Pull_Up;
	S5P4418_GPIO_Init(GPIOB,&GPIO_InitStruct);
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
	/*UART INIT*/
	UART_InitTypeDef UART_InitStruct;
	UART_StructInit(&UART_InitStruct);
	UART_Init(UART0,&UART_InitStruct);
		while(1)
		{	
			UART_ReceiveData(UART0,temp);
			if(temp){			
				GPIO_SetBits(GPIOB,GPIO_Pin_12);
				UART_SendData(UART0,"LED OFF");
				udelay(1000000);
			}
			else{
				GPIO_ResetBits(GPIOB,GPIO_Pin_12);
				UART_SendData(UART0,"LED ON");
				udelay(1000000);
			}
		}
	return 0;
}

