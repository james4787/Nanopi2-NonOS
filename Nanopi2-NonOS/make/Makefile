vpath %.S ../startup
vpath %.c ../source
objects = start.o main.o s5p4418_gpio.o s5p4418_clock.o s5p4418_uart.o s5p4418_interrupt.o s5p4418_sysclk.o div0.o _divsi3.o _udivsi3.o strlen.o
main.bin:$(objects)
	arm-linux-ld -Ttext=0x42c00000 $(objects) -o main
	arm-linux-objcopy -I elf32-littlearm -O binary main main.bin
%.o:%.c
	arm-linux-gcc -c $< -o $@

%.o:%.S
	arm-linux-gcc -c $< -o $@ 


.PHONY:clean
clean:	
	rm *.o main
