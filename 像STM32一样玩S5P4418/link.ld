OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_stext)

STACK_FIQ_SIZE 	= 0x0400;
STACK_IRQ_SIZE 	= 0x0400;
STACK_ABT_SIZE 	= 0x0400;
STACK_UND_SIZE 	= 0x0400;
STACK_SRV_SIZE 	= 0x8000;

SECTIONS
{
	. = 0x42c00000;

	. = ALIGN(4);
	.text :{	
		PROVIDE (__text_start = .);
		./object/start.o (.text)
		*(.text.*)
		PROVIDE (__text_end = .);
	}
	
	. = ALIGN(4);
	.rodata : { *(SORT_BY_ALIGNMENT(SORT_BY_NAME(.rodata*))) }


	. = ALIGN(4);
	.data : {
		PROVIDE (__data_start = .);	
		*(.data*)
  		PROVIDE (__data_end = .);
	}

	. = ALIGN(4);
	.bss (NOLOAD) :
	{
		PROVIDE (__bss_start = .);
		*(.bss)
		*(.bss.*)
		*(.sbss)
		*(COMMON)
		PROVIDE (__bss_end = .);
		
		. = ALIGN(4);
		PROVIDE (__heap_start = .);
		*(.heap)
		. = ALIGN(4);
		PROVIDE (__heap_end = .);
		
		. = ALIGN(4);
		PROVIDE (__stack_start = .);
		PROVIDE (__stack_fiq_start = .);
		. += STACK_FIQ_SIZE;
		PROVIDE (__stack_fiq_end = .);
		. = ALIGN(4);
		PROVIDE (__stack_irq_start = .);
		. += STACK_IRQ_SIZE;
		PROVIDE (__stack_irq_end = .);
		. = ALIGN(4);
		PROVIDE (__stack_abt_start = .);
		. += STACK_ABT_SIZE;
		PROVIDE (__stack_abt_end = .);
		. = ALIGN(4);
		PROVIDE (__stack_und_start = .);
		. += STACK_UND_SIZE;
		PROVIDE (__stack_und_end = .);
		. = ALIGN(4);
		PROVIDE (__stack_srv_start = .);
		. += STACK_SRV_SIZE;
		PROVIDE (__stack_srv_end = .);
		. = ALIGN(4);
		PROVIDE (__stack_end = .);
	}
	
}
