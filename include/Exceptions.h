#pragma once
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <Neo.h>
#include <Interrupts.h>
#include <MemoryUtility.h>

namespace neo{

const char* ExceptionNames[] = {"Divide by Zero",
								"Debug",
								"Non-maskable Interrupt",
								"Breakpoint", 
								"Overflow", 
								"Bound Range Exceeded", 
								"Invalid Opcode", 
								"Device Not Available",
								"Double Fault",
								"Coprocessor Segment Overrun",
								"Invalid TSS",
								"Segment Not Present",
								"Stack-Segment Fault",
								"General Protection Fault",
								"Page Fault",
								"Reserved",
								"FPU Exception",
								"Aligment Check",
								"Machine Check",
								"SIMD Floating-Point Exception",
								"Virtualization Exception",
								"Reserved",
								"Reserved",
								"Reserved",
								"Reserved",
								"Reserved",
								"Reserved",
								"Reserved",
								"Reserved",
								"Reserved",
								"Security Exception",
								"Reserved" };

extern void ExceptionHandler(CPUContext* state);

}

#endif