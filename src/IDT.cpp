#include <Neo.h>
#include <Interrupts.h>
#include <Logger.h>
#include <Compatibility.h>

using namespace neo;

namespace neo{

IDTEntry IDT[256];
IDTPointer IDTP = {.limit = 256 * sizeof(IDTEntry) - 1, .pointer = IDT};

void loadIDT(){

	asm volatile("cli");
	asm volatile("lidt %0" : : "m" (IDTP));	//Load IDT Address
	asm volatile("sti");

}

IDTEntry::IDTEntry(){

	this->offset_low = 0;
	this->offset_high = 0;	

	this->selector = 0;             					
	this->zero = 0;									
	this->flags = 0;			

}

IDTEntry::IDTEntry(InterruptHandler handler, uint16_t selector, uint8_t flag){

	this->offset_low = ((unsigned)handler & 0xFFFF); 		//Lower 16 bits von der Adresse der Funktion
	this->offset_high = ((unsigned)handler >> 16) & 0xFFFF; 	//Upper 16 bits von der Adresse der Funktion

	this->selector = selector;             					//Selector, Kernel Code Segment
	this->zero = 0x00;									//Muss 0 sein
	this->flags = flag;							
	
}

Logger& operator << (Logger& c, IDTEntry e){

	c << hex << (uint32_t)e.offset_high << (uint32_t)e.offset_low << "|" << (uint32_t)e.selector << bin << (uint32_t)e.flags << endl;
	return c;

}

}


