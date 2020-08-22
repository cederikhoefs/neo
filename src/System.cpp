#include <Neo.h>
#include <System.h>
#include <Logger.h>

namespace neo{

System::System(){

	term = Logger();

}


Logger& System::getTerminal(){

	return this->term;

}

PIC& System::getPIC(){

	return this->pic;	

}

PIT& System::getPIT(){

	return this->pit;	

}

uint32_t& System::TotalMemory(){

	return this->totalmemory;

}

System sys;

Logger& cout = sys.getTerminal();

}
