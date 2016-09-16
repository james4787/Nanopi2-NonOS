#ifndef __S5P4418_REG_VIC_H__
#define __S5P4418_REG_VIC_H__

#include"s5p4418.h"

typedef struct {
	volatile uint32_t	VIC_IRQSTATUS; 
	volatile uint32_t	VIC_FIQSTATUS;
	volatile uint32_t	VIC_RAWINTR;
	volatile uint32_t	VIC_INTSELECT; 
	volatile uint32_t	VIC_INTENABLE; 									
	volatile uint32_t	VIC_INTENCLEAR;
	volatile uint32_t	VIC_SOFTINT;
	volatile uint32_t	VIC_SOFTINTCLEAR;
	volatile uint32_t	VIC_PROTECTION;
	volatile uint32_t	VIC_SWPRIORITYMASK;
	volatile uint32_t	VIC_PRIORITYDAISY;
} VIC_TypeDef;

typedef struct {
	volatile uint32_t	VIC_VECTADDR0; 
	volatile uint32_t	VIC_VECTADDR1;
	volatile uint32_t	VIC_VECTADDR2;
	volatile uint32_t	VIC_VECTADDR3; 
	volatile uint32_t	VIC_VECTADDR4; 									
	volatile uint32_t	VIC_VECTADDR5;
	volatile uint32_t	VIC_VECTADDR6;
	volatile uint32_t	VIC_VECTADDR7;
	volatile uint32_t	VIC_VECTADDR8;
	volatile uint32_t	VIC_VECTADDR9;
	volatile uint32_t	VIC_VECTADDR10;
	volatile uint32_t	VIC_VECTADDR11; 
	volatile uint32_t	VIC_VECTADDR12;
	volatile uint32_t	VIC_VECTADDR13;
	volatile uint32_t	VIC_VECTADDR14; 
	volatile uint32_t	VIC_VECTADDR15; 									
	volatile uint32_t	VIC_VECTADDR16;
	volatile uint32_t	VIC_VECTADDR17;
	volatile uint32_t	VIC_VECTADDR18;
	volatile uint32_t	VIC_VECTADDR19;
	volatile uint32_t	VIC_VECTADDR20;
	volatile uint32_t	VIC_VECTADDR21;
	volatile uint32_t	VIC_VECTADDR22; 
	volatile uint32_t	VIC_VECTADDR23;
	volatile uint32_t	VIC_VECTADDR24;
	volatile uint32_t	VIC_VECTADDR25; 
	volatile uint32_t	VIC_VECTADDR26; 									
	volatile uint32_t	VIC_VECTADDR27;
	volatile uint32_t	VIC_VECTADDR28;
	volatile uint32_t	VIC_VECTADDR29;
	volatile uint32_t	VIC_VECTADDR30;
	volatile uint32_t	VIC_VECTADDR31;
	volatile uint32_t	RSVD0;
	volatile uint32_t	RSVD1;
	volatile uint32_t	RSVD2;
	volatile uint32_t	RSVD3;
	volatile uint32_t	RSVD4;
	volatile uint32_t	RSVD5;
	volatile uint32_t	RSVD6;
	volatile uint32_t	RSVD7;
	volatile uint32_t	VIC_VECPRIORITY0; 
	volatile uint32_t	VIC_VECPRIORITY1;
	volatile uint32_t	VIC_VECPRIORITY2;
	volatile uint32_t	VIC_VECPRIORITY3; 
	volatile uint32_t	VIC_VECPRIORITY4; 									
	volatile uint32_t	VIC_VECPRIORITY5;
	volatile uint32_t	VIC_VECPRIORITY6;
	volatile uint32_t	VIC_VECPRIORITY7;
	volatile uint32_t	VIC_VECPRIORITY8;
	volatile uint32_t	VIC_VECPRIORITY9;
	volatile uint32_t	VIC_VECPRIORITY10;
	volatile uint32_t	VIC_VECPRIORITY11; 
	volatile uint32_t	VIC_VECPRIORITY12;
	volatile uint32_t	VIC_VECPRIORITY13;
	volatile uint32_t	VIC_VECPRIORITY14; 
	volatile uint32_t	VIC_VECPRIORITY15; 									
	volatile uint32_t	VIC_VECPRIORITY16;
	volatile uint32_t	VIC_VECPRIORITY17;
	volatile uint32_t	VIC_VECPRIORITY18;
	volatile uint32_t	VIC_VECPRIORITY19;
	volatile uint32_t	VIC_VECPRIORITY20;
	volatile uint32_t	VIC_VECPRIORITY21;
	volatile uint32_t	VIC_VECPRIORITY22; 
	volatile uint32_t	VIC_VECPRIORITY23;
	volatile uint32_t	VIC_VECPRIORITY24;
	volatile uint32_t	VIC_VECPRIORITY25; 
	volatile uint32_t	VIC_VECPRIORITY26; 									
	volatile uint32_t	VIC_VECPRIORITY27;
	volatile uint32_t	VIC_VECPRIORITY28;
	volatile uint32_t	VIC_VECPRIORITY29;
	volatile uint32_t	VIC_VECPRIORITY30;
	volatile uint32_t	VIC_VECPRIORITY31;
} VICVEC_TypeDef;

typedef struct {
	volatile uint32_t	VIC_PERID0; 
	volatile uint32_t	VIC_PERID1;
	volatile uint32_t	VIC_PERID2;
	volatile uint32_t	VIC_PERID3; 
	volatile uint32_t	VIC_PCELLID0;	
	volatile uint32_t	VIC_PCELLID1;
	volatile uint32_t	VIC_PCELLID2;
	volatile uint32_t	VIC_PCELLID3;
} VICPIR_TypeDef;


#define GICC_CTLR		(*(volatile unsigned *)0xF0000100)
#define VIC0_ADDRESS		(*(volatile unsigned *)0xC0002F00)
#define VIC1_ADDRESS		(*(volatile unsigned *)0xC0003F00)

#define VIC0			((VIC_TypeDef *) VIC0_BASE)
#define VIC1			((VIC_TypeDef *) VIC1_BASE)

#define VIC0_VEC		((VICVEC_TypeDef *) (VIC0_BASE + 0x100))
#define VIC1_VEC		((VICVEC_TypeDef *) (VIC1_BASE + 0x100))

#define VIC0_PIR		((VICPIR_TypeDef *) (VIC0_BASE + 0xfe0))
#define VIC1_PIR		((VICPIR_TypeDef *) (VIC1_BASE + 0xfe0))

void s5p4418_IRQ_Init(VIC_TypeDef* VICx,VICVEC_TypeDef* VICx_VEC,VIC_TypeDef* VICy,VICVEC_TypeDef* VICy_VEC);
void do_irqs(void);

#endif /* __S5P4418_INTERRUPT_H__ */
