/*
 * s5p4418_sysclk.c
 *
 *  Created on: 2016年9月15日
 *      Author: James
 */

#include "../include/s5p4418_sysclk.h"

void udelay(uint32_t us)
{
	uint32_t i;
	for(;us >0;us--)
		for(i=1200;i>0;i--);
}

void mdelay(uint32_t ms)
{
	uint32_t i,j;
	for(;ms >0;ms--)
		for(i=1000;i>0;i--)
			for(j=1200;j>0;j--);

}
