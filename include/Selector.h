#pragma once
#ifndef SELECTOR_H
#define SELECTOR_H

#include <Neo.h>
#include <Compatibility.h>

namespace neo{

struct Selector{

	unsigned RPL : 2;        //Request Privilege
	unsigned Table : 1;        //1: Entry in LDT 0: Entry in GDT
	unsigned Index : 13;  //GDT Entry Number counted from zero

	Selector();
	Selector(uint8_t rpl, uint8_t tableindex, uint16_t entry);
	Selector(uint16_t rawselector);

	operator uint16_t() const;

} __attribute__ ((__packed__));

const Selector NullSelector(0, 0, 0);

const Selector KernelCode(0, 0, 1);
const Selector KernelData(0, 0, 2);

const Selector UserCode(0, 0, 3);
const Selector UserData(0, 0, 4);

}

#endif
