DIR_SRC = ./source
DIR_OBJ = ./object
DIR_BIN = ./bin
DIR_ASM	= ./asm
DIR_STR	= ./startup

TARGET	= main
MAIN_TAR= ${DIR_OBJ}/${TARGET}

BIN	= main.bin
BIN_TAR = ${DIR_BIN}/${BIN}

SRC	:= $(wildcard $(DIR_SRC)/*.c)   
OBJC	:= $(patsubst %.c,%.o,$(addprefix $(DIR_OBJ)/,$(notdir $(SRC))))
OBJ	:= $(patsubst %.c,%.o,$(addprefix $(DIR_OBJ)/,$(notdir $(SRC))))

ASM	:= $(wildcard ${DIR_ASM}/*.S) 
OBJA	:= $(patsubst %.S,%.o,$(addprefix $(DIR_OBJ)/,$(notdir $(ASM))))
OBJ 	+= $(patsubst %.S,%.o,$(addprefix $(DIR_OBJ)/,$(notdir $(ASM))))

STR	:= $(wildcard ${DIR_STR}/*.S)
OBJS	:= $(patsubst %.S,%.o,$(addprefix $(DIR_OBJ)/,$(notdir $(STR))))
OBJ 	+= $(patsubst %.S,%.o,$(addprefix $(DIR_OBJ)/,$(notdir $(STR))))

all:Interface $(OBJS) $(OBJA) $(OBJC)
	arm-linux-ld -Tlink.ld $(OBJ) -o ${MAIN_TAR}
	arm-linux-objcopy -I elf32-littlearm -O binary $(MAIN_TAR) $(BIN_TAR)
	@echo "Compiled!"


$(filter %.o,$(OBJC)):$(DIR_OBJ)/%.o:$(DIR_SRC)/%.c
	arm-linux-gcc -c $< -o $@
$(filter %.o,$(OBJA)):$(DIR_OBJ)/%.o:$(DIR_ASM)/%.S
	arm-linux-gcc -c $< -o $@
$(filter %.o,$(OBJS)):$(DIR_OBJ)/%.o:$(DIR_STR)/%.S
	arm-linux-gcc -c $< -o $@

Interface:
	@echo "************************************************************************************************************** "	
	@echo "        ___    __                       _____        ______                                                    "
	@echo "       /  /   / /                      / ___ \ __   /_____ \                                                   "
	@echo "      / / /  / /                      / /__/ //_/        / /               ___  __           ______   ______   "
	@echo "     / // / / /____    ____   ____   / _____/__    _____/ /  __________   /  / / /          / ____ \ / _____\  "
	@echo "    / / / // // __ \  / _  \ / __ \ / /     / /   / _____/  /_________/  / / // / ___ ___  / /   / // /____    "
	@echo "   / /  / / // /_/ / / / / // /_/ // /     / /   / /_____               / // / / /_ // _ \/ /___/ / \_____ \   "
	@echo "  /_/   /__/ \__/\_\/_/ /_/ \____//_/     /_/    \______/              /_/ /__/ /__//_//_/\______/ /_______/   "
	@echo "                                                                                                               "
	@echo "************************************************************************************************************** "
	@echo "--------------------------------------------------------------------------------"
	@echo "	Makefile by James : Built on Oct 1 2016 17:08:16"
	@echo "--------------------------------------------------------------------------------"	
	@lsb_release -a; pwd	
	@echo ">>>Environment Ready!"
	@echo ">>>gcc version 4.9.3 (ctng-1.21.0-229g-FA)"
	@echo ">>>Loading File Path...."
	@echo "startup:"$(STR)
	@echo "asm:	"$(ASM)
	@echo "source:	"$(SRC)
	@echo ">>>Files Init Done!"
	@echo ">>>Start compiling...."

.PHONY:burning
burning:
	@sudo dd if=./bin/main.bin of=/dev/sdb bs=1c seek=33280	
	@echo "2ndboot.bin Burning Done!"
	@sudo dd if=./bin/2ndboot.bin of=/dev/sdb bs=1c seek=512	
	@echo "main.bin Burning Done!"

.PHONY:clean
clean:	
	@rm ${OBJS} $(OBJA) ${OBJC} ${MAIN_TAR} 
	@echo "Target clear!"	


