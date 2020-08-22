#pragma once
#ifndef GDT_H
#define GDT_H

#include <Neo.h>
#include <Selector.h>
#include <Compatibility.h>
#include <Logger.h>

using namespace neo;

#define ACC_PRES	0b10000000 //Present?
#define ACC_R_0		0b00000000 //Ring 0
#define ACC_R_1		0b00100000 //Ring 1
#define ACC_R_2		0b01000000 //Ring 2
#define ACC_R_3		0b01100000 //Ring 3
#define ACC_SEGM 	0b00010000 //Segment?
#define ACC_EXEC 	0b00001000 //Code?
#define ACC_DIR  	0b00000100 //Direction... ???
#define ACC_RW   	0b00000010 //Code=Read?, Data=Write?

#define FLA_PAGE 	0b00001000 //Size in Pages(4 KiB)?
#define FLA_SIZE 	0b00000100 //32bit Mode?
#define FLA_LONG 	0b00000010  //Long mode

namespace neo{

struct GDTEntry {

	unsigned limit_low : 16;
	unsigned base_low : 24;
	unsigned access : 8;
	unsigned limit_high : 4;
	unsigned flags : 4;
	unsigned base_high : 8;

	public:

		GDTEntry();
		GDTEntry(uint32_t base, uint32_t limit, uint8_t access, uint8_t flags);

} __attribute__((packed));

Logger& operator << (Logger& c, GDTEntry e);

typedef struct {

    uint16_t limit;
    void* pointer;

} __attribute__((packed)) GDTPointer;

extern GDTEntry GDT[];
extern GDTPointer GP;
extern void loadGDT();

}

#endif
