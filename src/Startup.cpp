#include <Neo.h>

#include <GDT.h>
#include <Selector.h>

#include <Interrupts.h>
#include <ISR.h>

#include <Compatibility.h>

#include <System.h>
#include <Syscalls.h>
#include <Exceptions.h>

/*
extern uint32_t start_ctors, end_ctors;

typedef void (*constructor)(); 

cstyle void initialiseConstructors(){

	for (constructor* i = (constructor*)(& start_ctors); i != (constructor*)(& end_ctors); i++){

		(*i)();

	}


}
*/
cstyle void initialiseGDT(){

	GDT[0] = GDTEntry(0, 0, 0, 0); 																	//Nulldescriptor
	GDT[1] = GDTEntry(0, 0xFFFFFFFF, ACC_PRES|ACC_R_0|ACC_SEGM|ACC_EXEC|ACC_RW, FLA_PAGE|FLA_SIZE); //Kernel Code, 0-4GiB, Readable, 32bit, Ring 0;
	GDT[2] = GDTEntry(0, 0xFFFFFFFF, ACC_PRES|ACC_R_0|ACC_SEGM|ACC_RW, FLA_PAGE|FLA_SIZE);          //Kernel Data, 0-4GiB, Writable, 32bit, Ring 0;
	GDT[3] = GDTEntry(0, 0xFFFFFFFF, ACC_PRES|ACC_R_3|ACC_SEGM|ACC_EXEC|ACC_RW, FLA_PAGE|FLA_SIZE); //User Code,   0-4GiB, Readable, 32bit, Ring 3;
	GDT[4] = GDTEntry(0, 0xFFFFFFFF, ACC_PRES|ACC_R_3|ACC_SEGM|ACC_RW, FLA_PAGE|FLA_SIZE);          //User Data,   0-4GiB, Writable, 32bit, Ring 3;
	
	loadGDT();

}

cstyle void initialiseIDT(){

	// Syscalls

	IDT[0xCE] = IDTEntry(&isr0xCE, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0xDE] = IDTEntry(&isr0xDE, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));

	// Exceptions

	IDT[0x00] = IDTEntry(&isr0x00, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x01] = IDTEntry(&isr0x01, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x02] = IDTEntry(&isr0x02, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x03] = IDTEntry(&isr0x03, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x04] = IDTEntry(&isr0x04, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x05] = IDTEntry(&isr0x05, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x06] = IDTEntry(&isr0x06, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x07] = IDTEntry(&isr0x07, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x08] = IDTEntry(&isr0x08, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x09] = IDTEntry(&isr0x09, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x0A] = IDTEntry(&isr0x0A, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x0B] = IDTEntry(&isr0x0B, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x0C] = IDTEntry(&isr0x0C, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x0D] = IDTEntry(&isr0x0D, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x0E] = IDTEntry(&isr0x0E, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x0F] = IDTEntry(&isr0x0F, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x10] = IDTEntry(&isr0x10, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x11] = IDTEntry(&isr0x11, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x12] = IDTEntry(&isr0x12, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x13] = IDTEntry(&isr0x13, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x14] = IDTEntry(&isr0x14, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x15] = IDTEntry(&isr0x15, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x16] = IDTEntry(&isr0x16, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x17] = IDTEntry(&isr0x17, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x18] = IDTEntry(&isr0x18, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x19] = IDTEntry(&isr0x19, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x1A] = IDTEntry(&isr0x1A, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x1B] = IDTEntry(&isr0x1B, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x1C] = IDTEntry(&isr0x1C, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x1D] = IDTEntry(&isr0x1D, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x1E] = IDTEntry(&isr0x1E, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x1F] = IDTEntry(&isr0x1F, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));

	// Später remappede IRQs

	// Master

	IDT[0x20] = IDTEntry(&isr0x20, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x21] = IDTEntry(&isr0x21, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x22] = IDTEntry(&isr0x22, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x23] = IDTEntry(&isr0x23, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x24] = IDTEntry(&isr0x24, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x25] = IDTEntry(&isr0x25, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x26] = IDTEntry(&isr0x26, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x27] = IDTEntry(&isr0x27, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));

	// Slave

	IDT[0x28] = IDTEntry(&isr0x28, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x29] = IDTEntry(&isr0x29, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x2A] = IDTEntry(&isr0x2A, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x2B] = IDTEntry(&isr0x2B, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x2C] = IDTEntry(&isr0x2C, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x2D] = IDTEntry(&isr0x2D, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x2E] = IDTEntry(&isr0x2E, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	IDT[0x2F] = IDTEntry(&isr0x2F, (uint16_t)KernelCode, (FLAG_PRESENT|FLAG_INTRGATE|FLAG_32B_SEG|FLAG_RING_3));
	
	loadIDT();

}

extern void ExceptionHandler(CPUContext* state);

cstyle void initialiseExceptionHandlers(){

	RegisterCallback(&ExceptionHandler, 0x00);
	RegisterCallback(&ExceptionHandler, 0x01);
	RegisterCallback(&ExceptionHandler, 0x02);
	RegisterCallback(&ExceptionHandler, 0x03);
	RegisterCallback(&ExceptionHandler, 0x04);
	RegisterCallback(&ExceptionHandler, 0x05);
	RegisterCallback(&ExceptionHandler, 0x06);
	RegisterCallback(&ExceptionHandler, 0x07);
	RegisterCallback(&ExceptionHandler, 0x08);
	RegisterCallback(&ExceptionHandler, 0x09);
	RegisterCallback(&ExceptionHandler, 0x0A);
	RegisterCallback(&ExceptionHandler, 0x0B);
	RegisterCallback(&ExceptionHandler, 0x0C);
	RegisterCallback(&ExceptionHandler, 0x0D);
	RegisterCallback(&ExceptionHandler, 0x0E);
	RegisterCallback(&ExceptionHandler, 0x0F);
	RegisterCallback(&ExceptionHandler, 0x10);
	RegisterCallback(&ExceptionHandler, 0x11);
	RegisterCallback(&ExceptionHandler, 0x12);
	RegisterCallback(&ExceptionHandler, 0x13);
	RegisterCallback(&ExceptionHandler, 0x14);
	RegisterCallback(&ExceptionHandler, 0x15);
	RegisterCallback(&ExceptionHandler, 0x16);
	RegisterCallback(&ExceptionHandler, 0x17);
	RegisterCallback(&ExceptionHandler, 0x18);
	RegisterCallback(&ExceptionHandler, 0x19);
	RegisterCallback(&ExceptionHandler, 0x1A);
	RegisterCallback(&ExceptionHandler, 0x1B);
	RegisterCallback(&ExceptionHandler, 0x1C);
	RegisterCallback(&ExceptionHandler, 0x1D);
	RegisterCallback(&ExceptionHandler, 0x1E);
	RegisterCallback(&ExceptionHandler, 0x1F);

}

cstyle void initialiseSyscalls(){

	RegisterCallback(&SyscallHandler, 0xCE);

}

cstyle void initialisePIC(){

	sys.getPIC().map(0x20);
	sys.getPIC().maskall();

}

cstyle void initialisePIT(){


}













