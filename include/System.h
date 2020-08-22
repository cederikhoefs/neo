#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H

#include <Neo.h>
#include <Logger.h>
#include <PIC.h>
#include <PIT.h>

namespace neo{

class System{

	public:

		System();																	//hardware detection... etc

		Logger& getTerminal();

		PIC& getPIC();
		PIT& getPIT();
		
		uint32_t& TotalMemory();
		
	private:

		Logger term;

		PIC pic;
		PIT pit;
		uint32_t totalmemory;
		
		
};

extern System sys;

extern Logger& cout;

}

#endif
