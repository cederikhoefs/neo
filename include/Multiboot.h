#pragma once
#ifndef MULTIBOOT_H
#define MULTIBOOT_H

#include <stdint.h>

namespace neo{


const uint32_t Multiboot_MagicNumber = 0x2BADB002;
const uint32_t MemoryMapEntryTypeFree = 1;

struct MultibootHeader {

	uint32_t flags;
	uint32_t mem_lower;
	uint32_t mem_upper;
	uint32_t bootdevice;
	uint32_t cmdline;
	uint32_t module_count;
	uint32_t module_address;
	uint32_t symbols[4];
	uint32_t mmap_length;
	uint32_t mmap_addr;
	uint32_t drives_length;
	uint32_t drives_addr;
	uint32_t config_table;
	uint32_t bootloader_name;
	uint32_t apm_table;
	uint32_t vbe_control_info;
	uint32_t vbe_mode_info;
	uint16_t vbe_mode;
	uint16_t vbe_interface_seg;
	uint16_t vbe_interface_off;
	uint16_t vbe_interface_length;

} __attribute__((packed)); 

struct MemoryMapEntry {

	uint32_t size;
	uint64_t base;
	uint64_t length;
	uint32_t type;

} __attribute__((packed));



}




















#endif
