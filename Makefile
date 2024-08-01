CC = gcc
AS = nasm
CFLAGS = -Wall -Wextra -O2 `pkg-config --cflags gtk+-3.0`
LDFLAGS = `pkg-config --libs gtk+-3.0`

SRC_DIR = src
ASM_DIR = assembly
BUILD_DIR = build

ASM_SRC = $(ASM_DIR)/syscalls.asm
ASM_OBJ = $(BUILD_DIR)/syscalls.o

C_SRC = $(SRC_DIR)/main.c $(SRC_DIR)/file_reader.c $(SRC_DIR)/logger.c $(SRC_DIR)/gui.c
C_OBJ = $(BUILD_DIR)/main.o $(BUILD_DIR)/file_reader.o $(BUILD_DIR)/logger.o $(BUILD_DIR)/gui.o

all: $(BUILD_DIR)/monitor

$(BUILD_DIR)/monitor: $(C_OBJ) $(ASM_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(ASM_OBJ): $(ASM_SRC)
	mkdir -p $(BUILD_DIR)
	$(AS) -f elf64 $(ASM_SRC) -o $(ASM_OBJ)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(ASM_OBJ) $(C_OBJ)

.PHONY: all clean