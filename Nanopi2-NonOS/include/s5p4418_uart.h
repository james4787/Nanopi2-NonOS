#ifndef _S5P4418_UART_H_
#define _S5P4418_UART_H_

#include "s5p4418.h"

#define UARTRSR_OE				(0x08)
#define UARTRSR_BE				(0x04)
#define UARTRSR_PE				(0x02)
#define UARTRSR_FE				(0x01)

#define UARTFR_RI				(0x100)
#define UARTFR_TXFE				(0x80)
#define UARTFR_RXFF				(0x40)
#define UARTFR_TXFF				(0x20)
#define UARTFR_RXFE				(0x10)
#define UARTFR_BUSY				(0x08)

#define IS_UART_BAUDRATE(BAUDRATE) (((BAUDRATE) >= 50) && ((BAUDRATE) <= 921600))                                    

typedef enum{
	UART_WordLength_5b,
	UART_WordLength_6b,
	UART_WordLength_7b,
	UART_WordLength_8b
}WordLength_TypeDef;

#define IS_UART_WORD_LENGTH(LENGTH) (((LENGTH) == UART_WordLength_5b) || \
				     ((LENGTH) == UART_WordLength_6b) || \
                                     ((LENGTH) == UART_WordLength_7b) || \
                                     ((LENGTH) == UART_WordLength_8b))

typedef enum{
	UART_FIFOs_Disable,
	UART_FIFOs_Enable
}FIFOs_TypeDef;

#define IS_UART_FIFOS(FIFOS) (((FIFOS) == UART_FIFOs_Disable) || \
			      ((FIFOS) == UART_FIFOs_Enable))

typedef enum{
	UART_Parity_No,
	UART_Parity_Even,
	UART_Parity_Odd
}Parity_TypeDef;

#define IS_UART_PARITY(PARITY) (((PARITY) == UART_Parity_No) || \
                                ((PARITY) == UART_Parity_Even) || \
                                ((PARITY) == UART_Parity_Odd))

typedef enum{
	UART_StopBits_1,
	UART_StopBits_2
}StopBits_TypeDef;

#define IS_UART_STOPBITS(STOPBITS) (((STOPBITS) == UART_StopBits_1) || \
                                    ((STOPBITS) == UART_StopBits_2))

typedef struct {
	volatile uint32_t	UARTDR;/*Data register*/
	volatile uint32_t	UARTRSR_UARTECR;/*Receive status register/error clear register*/
	volatile uint32_t	RSVD0;
	volatile uint32_t	RSVD1;
	volatile uint32_t	RSVD2;
	volatile uint32_t	RSVD3;
	volatile uint32_t	UARTFR;/*Flag register*/
	volatile uint32_t	RSVD4;
	volatile uint32_t	UARTILPR;/*IrDA Low-power counter register*/
	volatile uint32_t	UARTIBRD;/*Integer baud rate register*/									
	volatile uint32_t	UARTFBRD;/*Fractional baud rate register*/
	volatile uint32_t	UARTLCR_H;/*Line control register*/
	volatile uint32_t	UARTCR;/*Control register*/
	volatile uint32_t	UARTIFLS;/*interrupt FIFO level select register*/
	volatile uint32_t	UARTIMSC;/*Interrupt mask set/clear register*/
	volatile uint32_t	UARTRIS;/*Interrupt status register*/
	volatile uint32_t 	UARTMIS;/*Interrupt status register*/
	volatile uint32_t	UARTICR;/*Interrupt clear register*/
	volatile uint32_t	UARTDMACR;/*DMA control register*/
}UART_TypeDef;


#define UART0              ((UART_TypeDef *) UART0_BASE)
#define UART1              ((UART_TypeDef *) UART1_BASE)
#define UART2              ((UART_TypeDef *) UART2_BASE)
#define UART3              ((UART_TypeDef *) UART3_BASE)
#define UART4              ((UART_TypeDef *) UART4_BASE)

#define IS_UART_PERIPH(PERIPH) (((PERIPH) == UART0) || \
                                ((PERIPH) == UART1) || \
                                ((PERIPH) == UART2) || \
                                ((PERIPH) == UART3) || \
                                ((PERIPH) == UART4))

typedef struct
{
	uint32_t		UART_BaudRate;
	WordLength_TypeDef	UART_WordLength;
	FIFOs_TypeDef		UART_FIFOs;
	StopBits_TypeDef	UART_StopBits;
	Parity_TypeDef		UART_Parity;
}UART_InitTypeDef;


typedef struct
{
	volatile uint32_t UARTCLKENB;
	volatile uint32_t UARTCLKGEN0L;
}UART_ClockTypeDef;

#define UART0CLK		((UART_ClockTypeDef *) UART0CLK_BASE)
#define UART1CLK		((UART_ClockTypeDef *) UART1CLK_BASE)
#define UART2CLK		((UART_ClockTypeDef *) UART2CLK_BASE)
#define UART3CLK		((UART_ClockTypeDef *) UART3CLK_BASE)
#define UART4CLK		((UART_ClockTypeDef *) UART4CLK_BASE)
#define UART5CLK		((UART_ClockTypeDef *) UART5CLK_BASE)


void UART_Init(UART_TypeDef* UARTx, UART_InitTypeDef* UART_InitStruct);
void UART_StructInit(UART_InitTypeDef* UART_InitStruct);
void UART_SendData(UART_TypeDef* UARTx, unsigned char * Data);
void UART_ReceiveData(UART_TypeDef* UARTx, unsigned char * Data);
void UART_ClockInit(UART_ClockTypeDef* UARTxCLK);
void UART_IRQHandler(UART_TypeDef* UARTx);

#endif
