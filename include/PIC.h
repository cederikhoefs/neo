#pragma once
#ifndef PIC_H
#define PIC_H

#include <Neo.h>
#include <System.h>

#include <IRQ.h>

#include <IO.h>
#include <IOPorts.h>

#define ICW1_ICW4		0b00000001
#define ICW1_SINGLE		0b00000010
#define ICW1_INIT		0b00010000

#define ICW4_8086		0b00000001
#define ICW4_AUTO_EOI	0b00000010

#define EOI				0b00100000

namespace neo{

class PIC {

	friend class System;

public:

	void map(int intr);
	void mask(uint16_t mask);
	void maskall();

private:

	PIC();        
    PIC( const PIC&); 
    PIC & operator = (const PIC&);
	
};

}

#endif
