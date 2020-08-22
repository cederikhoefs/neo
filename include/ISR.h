#pragma once
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <Neo.h>
#include <Interrupts.h>
#include <Compatibility.h>
#include <Selector.h>
#include <Logger.h>

#define ISR cstyle

extern uint8_t UsedInterrupts[];
extern neo::InterruptCallback InterruptCallbacks[];
extern uint8_t InterruptCallbackCount[];

extern bool RegisterCallback(neo::InterruptCallback callback, uint8_t interrupt);

assembler void isr0x00();
assembler void isr0x01();
assembler void isr0x02();
assembler void isr0x03();
assembler void isr0x04();
assembler void isr0x05();
assembler void isr0x06();
assembler void isr0x07();
assembler void isr0x08();
assembler void isr0x09();
assembler void isr0x0A();
assembler void isr0x0B();
assembler void isr0x0C();
assembler void isr0x0D();
assembler void isr0x0E();
assembler void isr0x0F();
assembler void isr0x10();
assembler void isr0x11();
assembler void isr0x12();
assembler void isr0x13();
assembler void isr0x14();
assembler void isr0x15();
assembler void isr0x16();
assembler void isr0x17();
assembler void isr0x18();
assembler void isr0x19();
assembler void isr0x1A();
assembler void isr0x1B();
assembler void isr0x1C();
assembler void isr0x1D();
assembler void isr0x1E();
assembler void isr0x1F();
assembler void isr0x20();
assembler void isr0x21();
assembler void isr0x22();
assembler void isr0x23();
assembler void isr0x24();
assembler void isr0x25();
assembler void isr0x26();
assembler void isr0x27();
assembler void isr0x28();
assembler void isr0x29();
assembler void isr0x2A();
assembler void isr0x2B();
assembler void isr0x2C();
assembler void isr0x2D();
assembler void isr0x2E();
assembler void isr0x2F();
assembler void isr0x30();
assembler void isr0x31();
assembler void isr0x32();
assembler void isr0x33();
assembler void isr0x34();
assembler void isr0x35();
assembler void isr0x36();
assembler void isr0x37();
assembler void isr0x38();
assembler void isr0x39();
assembler void isr0x3A();
assembler void isr0x3B();
assembler void isr0x3C();
assembler void isr0x3D();
assembler void isr0x3E();
assembler void isr0x3F();
assembler void isr0x40();
assembler void isr0x41();
assembler void isr0x42();
assembler void isr0x43();
assembler void isr0x44();
assembler void isr0x45();
assembler void isr0x46();
assembler void isr0x47();
assembler void isr0x48();
assembler void isr0x49();
assembler void isr0x4A();
assembler void isr0x4B();
assembler void isr0x4C();
assembler void isr0x4D();
assembler void isr0x4E();
assembler void isr0x4F();
assembler void isr0x50();
assembler void isr0x51();
assembler void isr0x52();
assembler void isr0x53();
assembler void isr0x54();
assembler void isr0x55();
assembler void isr0x56();
assembler void isr0x57();
assembler void isr0x58();
assembler void isr0x59();
assembler void isr0x5A();
assembler void isr0x5B();
assembler void isr0x5C();
assembler void isr0x5D();
assembler void isr0x5E();
assembler void isr0x5F();
assembler void isr0x60();
assembler void isr0x61();
assembler void isr0x62();
assembler void isr0x63();
assembler void isr0x64();
assembler void isr0x65();
assembler void isr0x66();
assembler void isr0x67();
assembler void isr0x68();
assembler void isr0x69();
assembler void isr0x6A();
assembler void isr0x6B();
assembler void isr0x6C();
assembler void isr0x6D();
assembler void isr0x6E();
assembler void isr0x6F();
assembler void isr0x70();
assembler void isr0x71();
assembler void isr0x72();
assembler void isr0x73();
assembler void isr0x74();
assembler void isr0x75();
assembler void isr0x76();
assembler void isr0x77();
assembler void isr0x78();
assembler void isr0x79();
assembler void isr0x7A();
assembler void isr0x7B();
assembler void isr0x7C();
assembler void isr0x7D();
assembler void isr0x7E();
assembler void isr0x7F();
assembler void isr0x80();
assembler void isr0x81();
assembler void isr0x82();
assembler void isr0x83();
assembler void isr0x84();
assembler void isr0x85();
assembler void isr0x86();
assembler void isr0x87();
assembler void isr0x88();
assembler void isr0x89();
assembler void isr0x8A();
assembler void isr0x8B();
assembler void isr0x8C();
assembler void isr0x8D();
assembler void isr0x8E();
assembler void isr0x8F();
assembler void isr0x90();
assembler void isr0x91();
assembler void isr0x92();
assembler void isr0x93();
assembler void isr0x94();
assembler void isr0x95();
assembler void isr0x96();
assembler void isr0x97();
assembler void isr0x98();
assembler void isr0x99();
assembler void isr0x9A();
assembler void isr0x9B();
assembler void isr0x9C();
assembler void isr0x9D();
assembler void isr0x9E();
assembler void isr0x9F();
assembler void isr0xA0();
assembler void isr0xA1();
assembler void isr0xA2();
assembler void isr0xA3();
assembler void isr0xA4();
assembler void isr0xA5();
assembler void isr0xA6();
assembler void isr0xA7();
assembler void isr0xA8();
assembler void isr0xA9();
assembler void isr0xAA();
assembler void isr0xAB();
assembler void isr0xAC();
assembler void isr0xAD();
assembler void isr0xAE();
assembler void isr0xAF();
assembler void isr0xB0();
assembler void isr0xB1();
assembler void isr0xB2();
assembler void isr0xB3();
assembler void isr0xB4();
assembler void isr0xB5();
assembler void isr0xB6();
assembler void isr0xB7();
assembler void isr0xB8();
assembler void isr0xB9();
assembler void isr0xBA();
assembler void isr0xBB();
assembler void isr0xBC();
assembler void isr0xBD();
assembler void isr0xBE();
assembler void isr0xBF();
assembler void isr0xC0();
assembler void isr0xC1();
assembler void isr0xC2();
assembler void isr0xC3();
assembler void isr0xC4();
assembler void isr0xC5();
assembler void isr0xC6();
assembler void isr0xC7();
assembler void isr0xC8();
assembler void isr0xC9();
assembler void isr0xCA();
assembler void isr0xCB();
assembler void isr0xCC();
assembler void isr0xCD();
assembler void isr0xCE();
assembler void isr0xCF();
assembler void isr0xD0();
assembler void isr0xD1();
assembler void isr0xD2();
assembler void isr0xD3();
assembler void isr0xD4();
assembler void isr0xD5();
assembler void isr0xD6();
assembler void isr0xD7();
assembler void isr0xD8();
assembler void isr0xD9();
assembler void isr0xDA();
assembler void isr0xDB();
assembler void isr0xDC();
assembler void isr0xDD();
assembler void isr0xDE();
assembler void isr0xDF();
assembler void isr0xE0();
assembler void isr0xE1();
assembler void isr0xE2();
assembler void isr0xE3();
assembler void isr0xE4();
assembler void isr0xE5();
assembler void isr0xE6();
assembler void isr0xE7();
assembler void isr0xE8();
assembler void isr0xE9();
assembler void isr0xEA();
assembler void isr0xEB();
assembler void isr0xEC();
assembler void isr0xED();
assembler void isr0xEE();
assembler void isr0xEF();
assembler void isr0xF0();
assembler void isr0xF1();
assembler void isr0xF2();
assembler void isr0xF3();
assembler void isr0xF4();
assembler void isr0xF5();
assembler void isr0xF6();
assembler void isr0xF7();
assembler void isr0xF8();
assembler void isr0xF9();
assembler void isr0xFA();
assembler void isr0xFB();
assembler void isr0xFC();
assembler void isr0xFD();
assembler void isr0xFE();
assembler void isr0xFF();

/*
																							//I wish this would work
template<int T, InterruptHandler H>
__attribute__((interrupt)) __attribute__((naked)) void HardwareException(void* b){

	asm volatile(".intel_syntax noprefix;");
	asm volatile("push 0x00;"); //Errorcode pushen
	//asm volatile("push %[interrupt];" :: [interrupt] "g" (T)); //Interruptnummer pushen
	asm volatile("push ebp;"); //alle Register pushen
    asm volatile("push esi;");
    asm volatile("push edi;");
    asm volatile("push edx;");
    asm volatile("push ecx;");
    asm volatile("push ebx;");
    asm volatile("push eax;");
  
    asm volatile("push ax;");
    asm volatile("mov ax, 0x10;"); //alle Segmente mit KernelData laden
    asm volatile("mov ds, ax;");
    asm volatile("mov es, ax;");
    asm volatile("mov fs, ax;");
    asm volatile("mov gs, ax;");
    asm volatile("pop ax;");

    asm volatile("push esp;");
    //asm volatile("call %[handler];" :: [handler] "" (H)); // Handler aufrufen
    asm volatile("add esp, 4;");
    asm volatile("sti;");

	asm volatile(".att_syntax prefix");
	asm volatile("iret");

} 
*/


#endif
