/*------------------------------------------------------------------------------------------------------------- 	
         ___    __                       _____        ______                                                    
        /  /   / /                      / ___ \ __   /_____ \                                                   
       / / /  / /                      / /__/ //_/        / /               ___  __           ______   ______   
      / // / / /____    ____   ____   / _____/__    _____/ /  __________   /  / / /          / ____ \ / _____\  
     / / / // // __ \  / _  \ / __ \ / /     / /   / _____/  /_________/  / / // / ___ ___  / /   / // /____    
    / /  / / // /_/ / / / / // /_/ // /     / /   / /_____               / // / / /_ // _ \/ /___/ / \_____ \   
   /_/   /__/ \__/\_\/_/ /_/ \____//_/     /_/    \______/              /_/ /__/ /__//_//_/\______/ /_______/   
                                                                                                                
 -------------------------------------------------------------------------------------------------------------- 
 	start.s by James : Built on Oct 1 2016 17:08:16                                                        
 --------------------------------------------------------------------------------------------------------------	
*/
.equ	USR_MODE,	0x10	/* normal user mode */
.equ 	FIQ_MODE,	0x11	/* fiq fast interrupts mode */
.equ 	IRQ_MODE,	0x12	/* irq standard interrupts mode */
.equ 	SVC_MODE,	0x13	/* supervisor interrupts mode */
.equ 	ABT_MODE,	0x17	/* abort processing memory faults mode */
.equ 	UDF_MODE,	0x1b	/* undefined instructions mode */
.equ 	MODE_MASK,	0x1f	/* system running in priviledged operating mode */
.equ 	NO_INT,		0xc0
.equ    CPSR_IRQ_EN,	0x80
.equ    CPSR_IRQ_MASK,	0x40	/* disable interrupt mode (irq) */
.equ    CPSR_FIQ_MASK,	0x80	/* disable fast interrupt mode (fiq) */

/*----------------------------
     exception vector table
  ----------------------------*/
.globl	_stext
_stext:
	b 	reset
	ldr	pc, _undefined_instruction
	ldr	pc, _software_interrupt
	ldr	pc, _prefetch_abort
	ldr	pc, _data_abort
	ldr	pc, _not_used
	ldr	pc, _irq
	ldr	pc, _fiq

_undefined_instruction:	.word undefined_instruction
_software_interrupt:	.word software_interrupt
_prefetch_abort:	.word prefetch_abort
_data_abort:		.word data_abort
_not_used:		.word not_used
_irq:			.word irq
_fiq:			.word fiq


	.balignl 16,0xdeadbeef
/*----------------------------
     Reset handling
  ----------------------------*/
reset:
	/* Set the cpu to supervisor mode */	
	mrs	r0, cpsr
	bic	r0, r0, #0x1f
	orr	r0, r0, #0xd3
	msr	cpsr, r0

	/* Invalidate L1 I/D */
	
	mov	r0, #0			@ set up for MCR
	mcr	p15, 0, r0, c8, c7, 0	@ invalidate TLBs
	mcr	p15, 0, r0, c7, c5, 0	@ invalidate icache
	mcr	p15, 0, r0, c7, c5, 6	@ invalidate BP array

	dsb
	isb

	/* disable MMU stuff and I-caches */
	
	mrc	p15, 0, r0, c1, c0, 0
	bic	r0, r0, #0x00002000	@ clear bits 13 (--V-)
	bic	r0, r0, #0x00000007	@ clear bits 2:0 (-CAM)
	orr	r0, r0, #0x00000002	@ set bit 1 (--A-) Align
	orr	r0, r0, #0x00000800	@ set bit 11 (Z---) BTB

	bic	r0, r0, #0x00001000	@ clear bit 12 (I) I-cache

	mcr	p15, 0, r0, c1, c0, 0

/* clear bss section */
clear_bss:
	ldr	r0, _bss_start
	ldr	r1, _bss_end
	mov r2, #0x00000000
	bl	mem_clear

	/* Set Vector Base Address Register */	
	ldr r0, =_stext
	mcr p15, 0, r0, c12, c0, 0
	mrc p15, 0, r0, c1, c0, 0
	bic r0, #(1<<13)
	mcr p15, 0, r0, c1, c0, 0
	
	bl	init_stacks

	ldr	r1, =on_the_ram
	mov	pc, r1

on_the_ram:
	mov r0, #1;
	mov r1, #0;
	bl	main				/* call main function */
	b	on_the_ram
/*
 * initialize stacks
 */
init_stacks:
	mrs	r0, cpsr
	bic	r0, r0, #MODE_MASK | NO_INT
	orr	r1, r0, #UDF_MODE
	msr	cpsr_cxsf, r1
	ldr	sp, _stack_und_end

	bic	r0, r0, #MODE_MASK | NO_INT
	orr	r1, r0, #ABT_MODE
	msr	cpsr_cxsf, r1
	ldr	sp, _stack_abt_end

	bic	r0, r0, #MODE_MASK | NO_INT
	orr	r1, r0, #IRQ_MODE
	msr	cpsr_cxsf, r1
	ldr	sp, _stack_irq_end

	bic	r0, r0, #MODE_MASK | NO_INT
	orr	r1, r0, #FIQ_MODE
	msr	cpsr_cxsf, r1
	ldr	sp, _stack_fiq_end

	bic	r0, r0, #MODE_MASK | NO_INT
	orr	r1, r0, #SVC_MODE
	msr	cpsr_cxsf, r1
	ldr	sp, _stack_srv_end
	mov	pc, lr


mem_clear:
	sub	r1, r1, #32
	cmp	r0, r1
	ble	cp
	mov r3, #0
	mov r4, #0
	mov r5, #0
	mov r6, #0
	mov r7, #0
	mov r8, #0
	mov r9, #0
	mov r10, #0
1:	stmia r0!, {r3-r10}
	cmp	r0, r1
	ble	1b
cp:	add	r1, r1, #32
2:	str	r2, [r0], #4
	cmp	r0, r1
	blt	2b
	mov	pc, lr

/*----------------------------
     Interrupt handling
  ----------------------------*/
undefined_instruction:
	b	.

software_interrupt:
	b	.

prefetch_abort:
	b	.

data_abort:
	b	.

not_used:
	b	.


	.align	4
	.globl irq
irq:
	/* get irq's sp */
	ldr	sp, _stack_irq_end

	/* save user regs */
	sub	sp, sp, #72
	stmia sp, {r0 - r12}			/* calling r0-r12 */
	add r8, sp, #60
	stmdb r8, {sp, lr}^				/* calling sp, lr */
	str lr, [r8, #0]				/* save calling pc */
	mrs r6, spsr
	str r6, [r8, #4]				/* save cpsr */
	str r0, [r8, #8]				/* save old_r0 */
	mov	r0, sp

	/* do irqs routlines */
	bl 	do_irqs

	/* restore user regs */
	ldmia sp, {r0 - lr}^			/* calling r0 - lr */
	mov	r0, r0
	ldr	lr, [sp, #60]				/* get pc */
	add	sp, sp, #72
	subs pc, lr, #4					/* return & move spsr_svc into cpsr */

fiq:
	b	.

/*----------------------------
     the location of stacks
  ----------------------------*/
	.align 4
_stack_fiq_end:
	.long	__stack_fiq_end
_stack_irq_end:
	.long	__stack_irq_end
_stack_abt_end:
	.long	__stack_abt_end
_stack_und_end:
	.long	__stack_und_end
_stack_srv_end:
	.long	__stack_srv_end
/*
 * the location of section
 */
 	.align 4
_text_start:
	.long	__text_start
_text_end:
	.long	__text_end
_data_start:
	.long	__data_start
_data_end:
	.long	__data_end
_bss_start:
	.long	__bss_start
_bss_end:
	.long	__bss_end



.end
