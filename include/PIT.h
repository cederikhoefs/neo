#pragma once
#ifndef PIT_H
#define PIT_H

#include <Neo.h>
#include <System.h>

#include <IRQ.h>

#include <IO.h>
#include <IOPorts.h>

namespace neo{

class PIT {

	friend class System;

public:

	uint16_t start(uint16_t frequency);
	uint16_t actual_frequency;	

private:
	
	PIT();        
    PIT( const PIC&); 
    PIT & operator = (const PIC&);
	
};

}

#endif
