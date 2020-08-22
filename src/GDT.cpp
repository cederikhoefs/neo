#include <Neo.h>
#include <GDT.h>
#include <Logger.h>
#include <Compatibility.h>

using namespace neo;

namespace neo{

unsigned const static int GDTEntries = 5;

GDTEntry GDT[GDTEntries];											
GDTPointer GP = {.limit = GDTEntries * sizeof(GDTEntry) - 1, .pointer = GDT};

assembler void updateSegments();

GDTEntry::GDTEntry(){

	this->limit_low = 0;
	this-> base_low = 0;
	this-> access = 0;
	this-> limit_high = 0;
	this-> flags = 0;
	this-> base_high = 0;
}

GDTEntry::GDTEntry(uint32_t base, uint32_t limit, uint8_t access, uint8_t flags){

	this->limit_low	 = (limit & 0x0000FFFF) >> 0;
	this->limit_high = (limit & 0x000F0000) >> 16;

	this->base_low   = (base & 0x00FFFFFF) >> 0;
	this->base_high  = (base & 0xFF000000) >> 24;


	this->access = (access & 0xFF) >> 0;
	this->flags = (flags & 0x0F) >> 0;

}

Logger& operator << (Logger& c, GDTEntry e){

	c << hex << (uint32_t)e.base_high << (uint32_t)e.base_low << "|" << (uint32_t)e.limit_high << (uint32_t)e.limit_low << "|" << bin << (uint32_t)e.access << "|" << (uint32_t)e.flags << endl;
	return c;

}

void loadGDT(){
   
	asm volatile("cli");
	asm volatile("lgdt %0" : : "m" (GP));	//Load GDT Address
	updateSegments();                  		//Reload Segment Registers for update
	asm volatile("sti");

} 

}
