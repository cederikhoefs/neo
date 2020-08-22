#include <Neo.h>
#include <Multiboot.h>
#include <GDT.h>

#include <Interrupts.h>
#include <ISR.h>

#include <Compatibility.h>
#include <MemoryUtility.h>
#include <Stack.h>

#include <System.h>
#include <Logger.h>
#include <Syscalls.h>

#include <PIC.h>

#include <PMM.h>

using namespace neo;

char* henlo = "HENLO";

uint64_t ms = 0;

void count(CPUContext* state){

	cout << clear << (1.0 / sys.getPIT().actual_frequency) * (ms++) << endl;

}

uint32_t getTotalMemory(const MultibootHeader* Header){


	MemoryMapEntry * mmap = (MemoryMapEntry*)Header->mmap_addr;
	
	int TotalMemory = 0;

	for(uint16_t i = 0; i < Header->mmap_length / sizeof(MemoryMapEntry); i++){
		
		cout << "#" << dec << i;
		cout << "; range: " << hex << "0x" << mmap[i].base << " - " << hex << "0x" << mmap[i].base + mmap[i].length;
		cout << "; length: " << dec << (mmap[i].length / 1024) << " KiB; ";
		cout << ((mmap[i].type == MemoryMapEntryTypeFree)? "Free" : "Unusuable") << endl;
		
		if(mmap[i].type == MemoryMapEntryTypeFree)
			TotalMemory += mmap[i].length;

	}

	return TotalMemory;

}


cstyle void S1(const MultibootHeader* Header, const uint32_t MagicNumber){

	if(MagicNumber != Multiboot_MagicNumber){


		cout << "Wrong Multiboot magic number / Please " << foreground(Red) << background(White) << "reboot your system...";

		while(1);

	}
	cout << clear;

	sys.TotalMemory() = getTotalMemory(Header);

	cout << "Total (Usable) Memory: " << sys.TotalMemory() / (1024*1024) << " MByte" << endl;
	sys.getPIC().mask(IRQ_PIT);

	while(true);


}
