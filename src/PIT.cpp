#include <Neo.h>
#include <PIC.h>
#include <IO.h>
#include <ISR.h>

#include <Logger.h>

using namespace neo;

namespace neo{

PIT::PIT(){}

uint16_t PIT::start(uint16_t frequency){

	this->actual_frequency = frequency;

	int counter= 1193182/frequency;

	outb(PIT_CONTROL, 0b00110100);
	outb(PIT_COUNTER_0, (counter & 0xFF));
	outb(PIT_COUNTER_0, (counter & 0xFF00)>>8);

	return 1191382/counter;

}

}
