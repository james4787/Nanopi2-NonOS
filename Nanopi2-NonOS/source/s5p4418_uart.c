/*
 * s5p4418_uart.c
 *
 *  Created on: 2016年8月13日
 *      Author: James
 */
#include "../include/s5p4418_uart.h"

void UART_Init(UART_TypeDef* UARTx, UART_InitTypeDef* UART_InitStruct)
{
	uint32_t IBRD, FBRD;
	uint32_t temp, remainder,uclk = 10*000*000;

	temp = 16 * UART_InitStruct->UART_BaudRate;
	IBRD = (uint32_t)(uclk / temp);
	remainder = (uint32_t)(uclk % temp);
	temp = (8 * remainder) / UART_InitStruct->UART_BaudRate;
	FBRD = (temp >> 1) + (temp & 1);

	UARTx->UARTIBRD = IBRD;
	UARTx->UARTFBRD = FBRD;
	UARTx->UARTLCR_H |= UART_InitStruct->UART_FIFOs << 4;	 	 
	UARTx->UARTLCR_H |= UART_InitStruct->UART_WordLength << 5;
	UARTx->UARTLCR_H |= UART_InitStruct->UART_StopBits << 3;	
	UARTx->UARTLCR_H |= UART_InitStruct->UART_Parity << 1;	
	UARTx->UARTIFLS |= ((2<<3)|(2<<0));
	UARTx->UARTIMSC = 0xFFFFFFFF;
	UARTx->UARTIMSC &= ~0x08;
	UARTx->UARTICR = 0xFFFFFFFF;
}

void UART_StructInit(UART_InitTypeDef* UART_InitStruct)
{
	UART_InitStruct->UART_BaudRate = 115200;
	UART_InitStruct->UART_FIFOs = UART_FIFOs_Enable;
	UART_InitStruct->UART_WordLength = UART_WordLength_8b;
	UART_InitStruct->UART_StopBits = UART_StopBits_1;
	UART_InitStruct->UART_Parity = UART_Parity_No ;
}

void UART_SendData(UART_TypeDef* UARTx, unsigned char * Data)
{
	uint32_t i, buf;
	buf = strlen(Data);
	for(i = 0; i < buf; i++){
		while((UARTx->UARTFR & UARTFR_TXFF)&&(UARTx->UARTFR & UARTFR_BUSY));
		UARTx->UARTDR = Data[i];
	}
	UARTx->UARTDR = 0x0D;
	UARTx->UARTDR = 0x0A;
}

void UART_ReceiveData(UART_TypeDef* UARTx, unsigned char * Data)
{	
	uint32_t i;
	for(i = 0;; i++){
		if(!(UARTx->UARTFR & UARTFR_RXFE))
			Data[i] = (unsigned char)(UARTx->UARTDR & (unsigned char)0xFF);
		else
			break;
	}
}



void UART_ClockInit(UART_ClockTypeDef* UARTxCLK)
{
	UARTxCLK->UARTCLKENB |= 0x04;//Enable to generate a clock.
	UARTxCLK->UARTCLKGEN0L &= ~0xFFFFFFFF;//Specifies the direction of the PADVCLK pad (ENABLE(output))
	UARTxCLK->UARTCLKGEN0L |= 0x6C4;//PLL1(55Mhz) 55 DIVIDER	
}

void UART_IRQHandler(UART_TypeDef* UARTx)
{	
	UARTx->UARTIMSC |= 0x08;
	UART_SendData(UART0,"hahahahhahahahahaha");
	UARTx->UARTICR &= 0x08;
}
