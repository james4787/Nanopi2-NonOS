/*
 * s5p4418_gpio.c
 *
 *  Created on: 2016年8月3日
 *      Author: James
 */

#include"../include/s5p4418_gpio.h"

void S5P4418_GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
{
	uint32_t pinpos = 0x00, pos = 0x00 , currentpin = 0x00;
	/* ------------------------- Configure the port pins ---------------- */
	/*-- GPIO Mode Configuration --*/
	for (pinpos = 0x00; pinpos < 0x20; pinpos++){
		pos = ((uint32_t)0x01) << pinpos;
		/* Get the port pins position */
		currentpin = (GPIO_InitStruct->GPIO_Pin) & pos;
		if (currentpin == pos){
			if(currentpin >	GPIO_Pin_15){
				if(GPIO_InitStruct->GPIO_Mode == Input_Mode){
					/* GPIOxOUTENB*/
					GPIOx->GPIO_OUTENB &= ~((uint32_t)0x01 << pinpos);
					GPIOx->GPIO_OUTENB |= (((uint32_t)GPIO_InitStruct->GPIO_Mode) << pinpos);
					/* GPIOxALTFN1*/
					GPIOx->GPIO_ALTFN1 &= ~(((uint32_t)0x03) << ((pinpos - GPIO_Pin_16) * 2));
					GPIOx->GPIO_ALTFN1 |= (uint32_t)GPIO_InitStruct->GPIO_ALTFN << ((pinpos - GPIO_Pin_16) * 2);
					if(GPIO_InitStruct->GPIO_DETENB == Enable){
						/* GPIO_DETMode*/
						GPIOx->GPIO_DETMODEEX &= ~((uint32_t)0x01 << pinpos);
						GPIOx->GPIO_DETMODEEX |= (GPIO_InitStruct->GPIO_DETMode & (uint32_t)0x01) << pinpos;
						GPIOx->GPIO_DETMODE1 &= ~(((uint32_t)0x03) << ((pinpos - GPIO_Pin_16) * 2));
						GPIOx->GPIO_DETMODE1 |= ((GPIO_InitStruct->GPIO_DETMode & (uint32_t)0x06) >> 1) << ((pinpos - GPIO_Pin_16) * 2);
						GPIOx->GPIO_DETENB &= ~((uint32_t)0x01 << pinpos);
						GPIOx->GPIO_DETENB |= (GPIO_InitStruct->GPIO_DETENB << pinpos);
					}
				}
				else if(GPIO_InitStruct->GPIO_Mode == Output_Mode){
					/* GPIOxOUTENB*/
					GPIOx->GPIO_OUTENB &= ~((uint32_t)0x01 << pinpos);
					GPIOx->GPIO_OUTENB |= (((uint32_t)GPIO_InitStruct->GPIO_Mode) << pinpos);
					/* GPIOxALTFN1*/
					GPIOx->GPIO_ALTFN1 &= ~(((uint32_t)0x03) << ((pinpos - GPIO_Pin_16) * 2));
					GPIOx->GPIO_ALTFN1 |= (uint32_t)GPIO_InitStruct->GPIO_ALTFN << ((pinpos - GPIO_Pin_16) * 2);
				}
			}
			else if(currentpin <= GPIO_Pin_15){
				if(GPIO_InitStruct->GPIO_Mode == Input_Mode){
					if((GPIOx == GPIOB)&&(currentpin > GPIO_Pin_3)&&(currentpin < GPIO_Pin_8)){
						GPIOx->GPIO_OUT &= ~((uint32_t)0x01 << pinpos);
						GPIOx->GPIO_OUT |= (((uint32_t)GPIO_InitStruct->GPIO_Mode) << pinpos);
					}
					else if((GPIOx == GPIOC)&&(currentpin == GPIO_Pin_8)){
						GPIOx->GPIO_OUT &= ~((uint32_t)0x01 << pinpos);
						GPIOx->GPIO_OUT |= (((uint32_t)GPIO_InitStruct->GPIO_Mode) << pinpos);
					}
					/* GPIOxOUTENB*/
					GPIOx->GPIO_OUTENB &= ~((uint32_t)0x01 << pinpos);
					GPIOx->GPIO_OUTENB |= (((uint32_t)GPIO_InitStruct->GPIO_Mode) << pinpos);
					/* GPIOxALTFN0*/
					GPIOx->GPIO_ALTFN0 &= ~(((uint32_t)0x03) << (pinpos * 2));
					GPIOx->GPIO_ALTFN0 |= (uint32_t)GPIO_InitStruct->GPIO_ALTFN << (pinpos * 2);
					if(GPIO_InitStruct->GPIO_DETENB == Enable){
						/* GPIO_DETMode*/
						GPIOx->GPIO_DETMODEEX &= ~((uint32_t)0x01 << pinpos);
						GPIOx->GPIO_DETMODEEX |= (GPIO_InitStruct->GPIO_DETMode & (uint32_t)0x01) << pinpos;
						GPIOx->GPIO_DETMODE0 &= ~(((uint32_t)0x03) << (pinpos * 2));
						GPIOx->GPIO_DETMODE0 |= ((GPIO_InitStruct->GPIO_DETMode & (uint32_t)0x06) >> 1) << (pinpos * 2);
						GPIOx->GPIO_DETENB &= ~((uint32_t)0x01 << pinpos);
						GPIOx->GPIO_DETENB |= (GPIO_InitStruct->GPIO_DETENB << pinpos);
					}
				}
				else if(GPIO_InitStruct->GPIO_Mode == Output_Mode){
					/* GPIOxOUTENB*/
					GPIOx->GPIO_OUTENB &= ~((uint32_t)0x01 << pinpos);
					GPIOx->GPIO_OUTENB |= (((uint32_t)GPIO_InitStruct->GPIO_Mode) << pinpos);
					/* GPIOxALTFN0*/
					GPIOx->GPIO_ALTFN0 &= ~(((uint32_t)0x03) << (pinpos * 2));
					GPIOx->GPIO_ALTFN0 |= (uint32_t)GPIO_InitStruct->GPIO_ALTFN << (pinpos * 2);
				}
			}
			/* Speed mode configuration */
			GPIOx->GPIO_SLEW_DISABLE_DEFAULT |= (uint32_t)0x01 << pinpos;
			GPIOx->GPIO_SLEW &= ~((uint32_t)0x01 << pinpos);
			GPIOx->GPIO_SLEW |= (uint32_t)GPIO_InitStruct->GPIO_Speed << pinpos;
			/* Pull-up Pull down resistor */
			if(GPIO_InitStruct->GPIO_PuPd == Pull_Up){
				/* GPIOx_PULLSEL*/
				GPIOx->GPIO_PULLSEL_DISABLE_DEFAULT |= (uint32_t)0x01 << pinpos;
				GPIOx->GPIO_PULLSEL |= (uint32_t)0x01 << pinpos;
				/* GPIO_PULLENB*/
				GPIOx->GPIO_PULLENB_DISABLE_DEFAULT |= (uint32_t)0x01 << pinpos;
				GPIOx->GPIO_PULLENB |= (uint32_t)0x01 << pinpos;
			}
			GPIOx->GPIO_DRV0_DISABLE_DEFAULT |= (uint32_t)0x01 << pinpos;
			GPIOx->GPIO_DRV1_DISABLE_DEFAULT |= (uint32_t)0x01 << pinpos;
			/* GPIOx_DRV */
			switch(GPIO_InitStruct->GPIO_DRV){
				case Driver_Strength_to_0:
					GPIOx->GPIO_DRV0 &= ~((uint32_t)0x01 << pinpos);
					GPIOx->GPIO_DRV1 &= ~((uint32_t)0x01 << pinpos);
					break;
				case Driver_Strength_to_1:
					GPIOx->GPIO_DRV0 &= ~((uint32_t)0x01 << pinpos);
					GPIOx->GPIO_DRV1 |= (uint32_t)0x01 << pinpos;
					break;
				case Driver_Strength_to_2:
					GPIOx->GPIO_DRV0 |= (uint32_t)0x01 << pinpos;
					GPIOx->GPIO_DRV1 |= (uint32_t)0x01 << pinpos;
					break;
				default: ;
			}
		}
	}
}

void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct)
{
  GPIO_InitStruct->GPIO_Pin  = GPIO_Pin_ALL;
  GPIO_InitStruct->GPIO_Mode = Input_Mode;
  GPIO_InitStruct->GPIO_DETMode = DET_Rising_Edge;
  GPIO_InitStruct->GPIO_Speed = Normal_Slew;
  GPIO_InitStruct->GPIO_DRV = Driver_Strength_to_0;
  GPIO_InitStruct->GPIO_PuPd = Pull_Up;
}

void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin)
{
  GPIOx->GPIO_OUT |= GPIO_Pin;
}

void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin)
{
  GPIOx->GPIO_OUT &= ~GPIO_Pin;
}


