/*
 * s5p4418_gpio.h
 *
 *  Created on: 2016年8月3日
 *      Author: James
 */

#ifndef S5P4418_GPIO_H_
#define S5P4418_GPIO_H_

#include "s5p4418.h"

typedef enum{
	GPIO_Pin_0 = 	 (uint32_t)0x00000001,
	GPIO_Pin_1 =	 (uint32_t)0x00000002,
	GPIO_Pin_2 =	 (uint32_t)0x00000004,
	GPIO_Pin_3 =	 (uint32_t)0x00000008,
	GPIO_Pin_4 =	 (uint32_t)0x00000010,
	GPIO_Pin_5 =	 (uint32_t)0x00000020,
	GPIO_Pin_6 =	 (uint32_t)0x00000040,
	GPIO_Pin_7 =	 (uint32_t)0x00000080,
	GPIO_Pin_8 =	 (uint32_t)0x00000100,
	GPIO_Pin_9 =	 (uint32_t)0x00000200,
	GPIO_Pin_10 = 	 (uint32_t)0x00000400,
	GPIO_Pin_11 = 	 (uint32_t)0x00000800,
	GPIO_Pin_12 = 	 (uint32_t)0x00001000,
	GPIO_Pin_13 = 	 (uint32_t)0x00002000,
	GPIO_Pin_14 = 	 (uint32_t)0x00004000,
	GPIO_Pin_15 = 	 (uint32_t)0x00008000,
	GPIO_Pin_16 = 	 (uint32_t)0x00010000,
	GPIO_Pin_17 = 	 (uint32_t)0x00020000,
	GPIO_Pin_18 = 	 (uint32_t)0x00040000,
	GPIO_Pin_19 = 	 (uint32_t)0x00080000,
	GPIO_Pin_20 = 	 (uint32_t)0x00100000,
	GPIO_Pin_21 = 	 (uint32_t)0x00200000,
	GPIO_Pin_22 = 	 (uint32_t)0x00400000,
	GPIO_Pin_23 = 	 (uint32_t)0x00800000,
	GPIO_Pin_24 = 	 (uint32_t)0x01000000,
	GPIO_Pin_25 = 	 (uint32_t)0x02000000,
	GPIO_Pin_26 = 	 (uint32_t)0x04000000,
	GPIO_Pin_27 = 	 (uint32_t)0x08000000,
	GPIO_Pin_28 = 	 (uint32_t)0x10000000,
	GPIO_Pin_29 = 	 (uint32_t)0x20000000,
	GPIO_Pin_30 = 	 (uint32_t)0x40000000,
	GPIO_Pin_31 = 	 (uint32_t)0x80000000,
	GPIO_Pin_ALL =	 (uint32_t)0xFFFFFFFF
}GPIOPin_TypeDef;

typedef enum{
	DET_Low_Level = 0,
	DET_High_Level,
	DET_Falling_Edge,
	DET_Rising_Edge,
	DET_Both_Edge
}GPIODETMode_TypeDef;

typedef enum{
	Low_Level = 0,
	High_Level
}GPIOOUT_TypeDef;

typedef enum{
	Input_Mode = 0,
	Output_Mode
}GPIOMODE_TypeDef;

typedef enum{
	Disable = 0,
	Enable
}GPIODETENB_TypeDef;

typedef enum{
	ALT_Function0 = 0,
	ALT_Function1,
	ALT_Function2,
	ALT_Function3
}GPIOALTFN_TypeDef;

typedef enum{
	Fast_Slew = 0,
	Normal_Slew
}GPIOSlew_TypeDef;

typedef enum{
	Driver_Strength_to_0 = 0,
	Driver_Strength_to_1,
	Driver_Strength_to_2
}GPIODRV_TypeDef;

typedef enum{
	Pull_Down = 0,
	Pull_Up
}GPIOPUPD_TypeDef;

typedef struct {
	volatile uint32_t	GPIO_OUT; 
	volatile uint32_t	GPIO_OUTENB;
	volatile uint32_t	GPIO_DETMODE0;
	volatile uint32_t	GPIO_DETMODE1; 
	volatile uint32_t	GPIO_INTENB; 									
	volatile uint32_t	GPIO_DET;
	volatile uint32_t	GPIO_PAD;
	volatile uint32_t	RSVD0;
	volatile uint32_t	GPIO_ALTFN0;
	volatile uint32_t	GPIO_ALTFN1;
	volatile uint32_t	GPIO_DETMODEEX;
	volatile uint32_t	RSVD1;
	volatile uint32_t	RSVD2;
	volatile uint32_t	RSVD3;
	volatile uint32_t	RSVD4;
	volatile uint32_t	GPIO_DETENB;
	volatile uint32_t 	GPIO_SLEW;
	volatile uint32_t	GPIO_SLEW_DISABLE_DEFAULT;
	volatile uint32_t	GPIO_DRV1;
	volatile uint32_t	GPIO_DRV1_DISABLE_DEFAULT;
	volatile uint32_t	GPIO_DRV0;
	volatile uint32_t	GPIO_DRV0_DISABLE_DEFAULT;
	volatile uint32_t	GPIO_PULLSEL;
	volatile uint32_t	GPIO_PULLSEL_DISABLE_DEFAULT;
	volatile uint32_t	GPIO_PULLENB;
	volatile uint32_t	GPIO_PULLENB_DISABLE_DEFAULT;
} GPIO_TypeDef;

typedef struct
{
	GPIOPin_TypeDef				GPIO_Pin;
	GPIOMODE_TypeDef			GPIO_Mode;
	GPIODETMode_TypeDef			GPIO_DETMode;
	GPIODETENB_TypeDef			GPIO_DETENB;
	GPIOALTFN_TypeDef			GPIO_ALTFN;
	GPIOSlew_TypeDef			GPIO_Speed;
	GPIODRV_TypeDef				GPIO_DRV;
	GPIOPUPD_TypeDef			GPIO_PuPd;
}GPIO_InitTypeDef;


#define GPIOA              ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB              ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC              ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD              ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE              ((GPIO_TypeDef *) GPIOE_BASE)

void S5P4418_GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
void S5P4418_GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct);
void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin);

#endif /* S5P4418_GPIO_H_ */
