#include <Neo.h>
#include <Selector.h>

namespace neo{

Selector::Selector(){

	this->RPL = 0;
	this->Table = 0;
	this->Index = 0;

}

Selector::Selector(uint8_t rpl, uint8_t tableindex, uint16_t entry){

	this->RPL = (rpl & 0b11);
	this->Table = (tableindex & 0b1);
	this->Index = (entry & 0b1111111111111); 

}

Selector::Selector(uint16_t rawselector){

	this->RPL = (rawselector >> 0) & 0b11;
	this->Table = (rawselector >> 2) & 0b1;
	this->Index = (rawselector >> 3) & 0b1111111111111;

}

Selector::operator uint16_t() const {

	return (this->RPL << 0) | (this->Table << 2) | (this->Index << 3);

}

}
