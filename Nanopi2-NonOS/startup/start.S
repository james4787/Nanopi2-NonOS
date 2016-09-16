.text
	.arm
	.global	_start
_start:

/* 0x00: reset */
	b	reset

/* 0x04: undefined instruction exception */
	ldr	pc, _undefined_instruction

/* 0x08: software interrupt exception */
	ldr	pc, _software_interrupt

/* 0x0c: prefetch abort */
	ldr	pc, _prefetch_abort

/* 0x10: data access memory abort */
	ldr	pc, _data_abort

/* 0x14: not used */
	ldr	pc, _not_used

/* 0x18: interrupt request exception */
	ldr	pc, _irq

/* 0x1c: fast interrupt request exception */
	ldr	pc, _fiq



_undefined_instruction:
	.long undefined_instruction
_software_interrupt:
	.long software_interrupt
_prefetch_abort:
	.long prefetch_abort
_data_abort:
	.long data_abort
_not_used:
	.long not_used
_irq:
	.long irq
_fiq:
	.long fiq


reset:
	/* Set the cpu to supervisor mode */	
	mrs	r0, cpsr
	bic	r0, r0, #0x1f
	orr	r0, r0, #0xd3
	msr	cpsr, r0

	/* Enable NEON & VFP unit */
	mrc p15, #0, r1, c1, c0, #2
	orr r1, r1, #(0xf << 20)
	mcr p15, #0, r1, c1, c0, #2
	mov r1, #0
	mcr p15, #0, r1, c7, c5, #4
	mov r0, #0x40000000
	fmxr fpexc, r0

	/* Cache init */
	mrc	p15, 0, r0, c0, c0, 0		/* read main ID register */
	and	r1, r0, #0x00f00000		/* variant */
	and	r2, r0, #0x0000000f		/* revision */
	orr	r2, r2, r1, lsr #20-4		/* combine variant and revision */
	cmp	r2, #0x30
	mrceq	p15, 0, r0, c1, c0, 1		/* read ACTLR */
	orreq	r0, r0, #0x6			/* Enable DP1(2), DP2(1) */
	mcreq	p15, 0, r0, c1, c0, 1		/* write ACTLR */

	/* Invalidate L1 I/D */	
	mov	r0, #0				/* set up for MCR */
	mcr	p15, 0, r0, c8, c7, 0		/* invalidate TLBs */
	mcr	p15, 0, r0, c7, c5, 0		/* invalidate icache */

	/* Disable mmu stuff and caches */
	mrc	p15, 0, r0, c1, c0, 0
	bic	r0, r0, #0x00002000		/* clear bits 13 (--v-) */
	bic	r0, r0, #0x00000007		/* clear bits 2:0 (-cam) */
	orr	r0, r0, #0x00000002		/* set bit 1 (--a-) align */
	orr	r0, r0, #0x00000800		/* set bit 12 (z---) btb */
	mcr	p15, 0, r0, c1, c0, 0

	/* Set Vector Base Address Register */	
	ldr r0, =_start
	mcr p15, 0, r0, c12, c0, 0
	mrc p15, 0, r0, c1, c0, 0
	bic r0, #(1<<13)
	mcr p15, 0, r0, c1, c0, 0
	
	bl	init_stacks

	
	/* Enable vector interrupt controller */
	mrc p15, 0, r0, c1, c0, 0
	orr r0, #(1 << 24)
	mcr p15, 0, r0, c1, c0, 0
	
	
	/* Enable irq and fiq */
	mrs	r0, cpsr
	bic	r0, r0, #0xc0
	msr	cpsr_cxsf, r0
	

	ldr	r1, =on_the_ram
	mov	pc, r1
on_the_ram:

	mov r0, #1;
	mov r1, #0;
	bl	main				/* call main function */
	b	on_the_ram


/*
 * initialize stacks   Leave 100M space for main.bin
 * Stack start address is 0x44500000
 */
init_stacks:
	mrs	r0, cpsr
	bic	r0, r0, #0xdf
	orr	r1, r0, #0x1b
	msr	cpsr_cxsf, r1
	ldr	sp, _stack_und_end

	bic	r0, r0, #0xdf
	orr	r1, r0, #0x17
	msr	cpsr_cxsf, r1
	ldr	sp, _stack_abt_end

	bic	r0, r0, #0xdf
	orr	r1, r0, #0x12
	msr	cpsr_cxsf, r1
	ldr	sp, _stack_irq_end

	bic	r0, r0, #0xdf
	orr	r1, r0, #0x11
	msr	cpsr_cxsf, r1
	ldr	sp, _stack_fiq_end

	bic	r0, r0, #0xdf
	orr	r1, r0, #0x13
	msr	cpsr_cxsf, r1
	ldr	sp, _stack_srv_end
	mov	pc, lr

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

	.global	irq
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

 	.align 4
_stack_fiq_end:
	.long	0x44500400
_stack_irq_end:
	.long	0x44500800
_stack_abt_end:
	.long	0x44500c00
_stack_und_end:
	.long	0x44501000
_stack_srv_end:
	.long	0x44509000

.end
