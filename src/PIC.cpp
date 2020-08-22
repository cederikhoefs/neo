#include <Neo.h>
#include <PIC.h>
#include <IO.h>
#include <ISR.h>

#include <Logger.h>

using namespace neo;

namespace neo{

PIC::PIC(){}

void PIC::map(int intr){

	outb(PIC_MASTER_ICW1, (ICW1_INIT | ICW1_ICW4));
    outb(PIC_SLAVE_ICW1,  (ICW1_INIT | ICW1_ICW4));

	outb(PIC_MASTER_ICW2, intr);
    outb(PIC_SLAVE_ICW2,  intr + 8);

	outb(PIC_MASTER_ICW3, (1 << IRQ_PIC_SLAVE));
    outb(PIC_SLAVE_ICW3,  IRQ_PIC_SLAVE);

	outb(PIC_MASTER_ICW4, (ICW4_8086 | ICW4_AUTO_EOI));
    outb(PIC_SLAVE_ICW4,  (ICW4_8086 | ICW4_AUTO_EOI)); 

}

void PIC::mask(uint16_t mask){

	outb(PIC_MASTER_INTR_MASK, (mask & 0x00FF));
	outb(PIC_SLAVE_INTR_MASK,  (mask & 0xFF00) >> 8);

}

void PIC::maskall(){

	this->mask(0xFFFF);

}


}
