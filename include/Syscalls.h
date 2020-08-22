#pragma once
#ifndef SYSCALLS_H
#define SYSCALLS_H

#include <Neo.h>
#include <Interrupts.h>
#include <MemoryUtility.h>

namespace neo{

enum class Syscalls{print};	

extern void SyscallHandler(CPUContext* state);

struct bit{unsigned : 1;} __attribute__((packed));
struct crumb{unsigned : 2;} __attribute__((packed));
struct nibble{unsigned : 4;} __attribute__((packed));

union Packet{

	bit bits[32];
	crumb crumbs[16];
	nibble nibbles[8];
	uint8_t bytes[4];
	uint16_t halfs[2];	
	uint32_t word[1];
	void* pointer[1];

	Packet(uint32_t w){this->word[0] = w;}
	Packet(void* p){this->pointer[0] = p;}
	Packet(){this->word[0] = 0;}

};

typedef Packet Parameter;
typedef Packet Return;

template<int count>
struct SyscallParameter{

	Parameter par[count];

};

template<Syscalls name, int argcount>
Packet Syscall(Packet args[]){

	SyscallParameter<argcount> params;

	memcopy((uint8_t*)params.par, (uint8_t*)args, argcount * sizeof(Parameter));

	asm volatile("mov %0, %%ebx" :: "a"(&params) );
	asm volatile("mov %0, %%ecx" :: "a"(argcount) );
	asm volatile("mov %0, %%eax" :: "a"((uint32_t)name));
	asm volatile("int $0xCE");

	return args[0];
}

}



#endif
