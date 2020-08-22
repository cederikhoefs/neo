#pragma once
#ifndef IO_H
#define IO_H

#include <Neo.h>

namespace neo{

static inline uint16_t inw(uint16_t port){

	uint16_t result;
	asm volatile("inw %1, %0" : "=a" (result) : "Nd" (port));
	return result;

}


static inline uint8_t inb(uint16_t port){

	uint8_t result;
	asm volatile("inb %1, %0" : "=a" (result) : "Nd" (port));
	return result;

}

static inline uint32_t inl(uint16_t port){

	uint32_t result;
	asm volatile("inl %1, %0" : "=a" (result) : "Nd" (port));
	return result;
}

static inline void outw(uint16_t port, uint16_t data){

	asm volatile("outw %0, %1" : : "a" (data), "Nd" (port));

}

static inline void outb(uint16_t port, uint8_t data){

   asm volatile("outb %0, %1" : : "a" (data), "Nd" (port));

}

static inline void outl(uint16_t port, uint32_t data){

    asm volatile("outl %0, %1" : : "a"(data), "Nd" (port));

}

}

#endif







