C_SRCS   = $(shell find src/ -name '*.c')
CPP_SRCS = $(shell find src/ -name '*.cpp')
ASM_SRCS = $(shell find src/ -name '*.asm')

C_OBJS   = $(addprefix bin/, $(addsuffix .o, $(basename $(notdir $(C_SRCS)))))
CPP_OBJS = $(addprefix bin/, $(addsuffix .o, $(basename $(notdir $(CPP_SRCS)))))
ASM_OBJS = $(addprefix bin/, $(addsuffix .o, $(basename $(notdir $(ASM_SRCS)))))

DATE = $(shell date +"%H:%M-%d-%m-%y")

KERNEL = bin/neo.bin
LINK_FILE   = link.ld
MAP_FILE 	= kernel.map

INCLUDE = include/

CC = i686-elf-gcc
CXX = i686-elf-g++ -std=c++11
LD = i686-elf-ld
NA = nasm
OBJDUMP = i686-elf-objdump

WARNINGS = -Wall -Wunused-variable -Wwrite-strings -Wsign-compare -Woverflow -Wmultichar -Wpointer-arith
CFLAGS = -I $(INCLUDE) -g -ffreestanding -fno-stack-protector -fno-builtin -nostdinc $(WARNINGS) -c 
CXXFLAGS = -I $(INCLUDE) -g -ffreestanding -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-leading-underscore -fno-threadsafe-statics -fno-use-cxa-atexit $(WARNINGS) -c
NAFLAGS = -f elf -F dwarf -i src/
LINK_FLAGS = -T $(LINK_FILE) -nostdlib
VQEMU_FLAGS = -D QEMU.log -d cpu_reset

CRTI_OBJ = bin/crti.o
CRTBEGIN_OBJ = $(shell $(CC) $(CFLAGS) -print-file-name=crtbegin.o)
CRTEND_OBJ = $(shell $(CC) $(CFLAGS) -print-file-name=crtend.o)
CRTN_OBJ = bin/crtn.o

OBJ_LIST = $(CRTI_OBJ) $(CRTBEGIN_OBJ) $(C_OBJS) $(CPP_OBJS) $(ASM_OBJS) $(CRTEND_OBJ) $(CRTN_OBJ) 

$(KERNEL): $(OBJ_LIST)
	$(CXX) $(LINK_FLAGS) -o $@ $^ -lgcc
	
bin/%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ $^

bin/%.o: src/%.asm
	$(NA) $(NAFLAGS) -o $@ $^

bin/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

bin/%.o: src/%.s
	$(CC) -c -o $@ $^

bin/%.o: src/%.S
	$(CC) -c -o $@ $^

run: $(KERNEL)
	@echo "Starting Neo in Virtual Machine(QEMU)"
	@qemu-system-i386 -kernel $(KERNEL) &

debug: $(KERNEL) 
	qemu-system-i386 -s -S -kernel $(KERNEL) &
	gdb --command=gdb.cmd $(KERNEL)

disasm: $(KERNEL)
	@$(OBJDUMP) -D $(KERNEL) > verbose/listing.asm

#ahci:
#	@echo "Starting Neo in Virtual Machine(QEMU)"
#	@qemu-system-i386 -kernel $(KERNEL) -drive file=$(DISK_FILE),if=none,id=Disk1 -device ich9-ahci,id=ahci -device ide-drive,drive=Disk1,bus=ahci.0 &

info:
	readelf -all $(KERNEL)

remake: clean $(KERNEL)

neo: kernel
it: kernel
	
clean:
	@echo Cleaning Binaries...
	@rm -f bin/*

