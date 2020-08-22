#pragma once
#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <Neo.h>
#include <Logger.h>

#define FLAG_PRESENT  0b10000000
#define FLAG_INTRGATE 0b00000110
#define FLAG_TRAPGATE 0b00000111
#define FLAG_TASKGATE 0b00000101
#define FLAG_32B_SEG  0b00001000
#define FLAG_RING_3   0b01100000
#define FLAG_RING_0   0b00000000

namespace neo{

struct CPUContext;

using InterruptHandler = void(*)();
using InterruptCallback = void(*)(CPUContext*);

struct IDTEntry{

	unsigned offset_low: 16;
	unsigned selector:    16;
	unsigned zero:    8;
	unsigned flags:   8;
	unsigned offset_high: 16;

	public:

	IDTEntry();
	IDTEntry(InterruptHandler handler, uint16_t selector, uint8_t flag);

}__attribute__((packed));

Logger& operator << (Logger& c, IDTEntry e);

typedef struct {

    uint16_t limit;
    void* pointer;

} __attribute__((packed)) IDTPointer;


extern IDTEntry IDT[];
extern void loadIDT();

struct CPUContext{

	uint32_t eax;
	uint32_t ebx;
	uint32_t ecx;
	uint32_t edx;
	uint32_t edi;
	uint32_t esi;
	uint32_t ebp;

	uint32_t err;
	uint32_t intr;

	uint32_t eip;
	uint32_t cs;
	uint32_t eflags;
	uint32_t esp;
	uint32_t ss;

} __attribute__((packed)) ;


}

#endif
