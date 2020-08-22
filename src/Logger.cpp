#include <Neo.h>
#include <Logger.h>
#include <MemoryUtility.h>

#define VRAM (char*)(0xB8000)

using namespace neo;

namespace neo{


Logger::Logger(Color foreground, Color background){

	this->foreground = foreground;
	this->background = background;
	this->base = dec;
	this->Cursor = 0;

}

Logger::Logger(){

	this->foreground = White;
	this->background = Black;
	this->base = dec;
	this->Cursor = 0;
	this->putc('L');


}

void Logger::putc(char c){

	if(Cursor >= 80*24){
		scroll();
		Cursor -= 80;
	}	
	*get_write_pointer() = c;
	*(get_write_pointer() + 1) = this->background << 4 | this->foreground;

	this->Cursor++;

}


void Logger::print(const char* str){

	while(*str != '\0'){

		this->putc(*str);
	
		str++;

	}

}

void Logger::scroll(int n){

	for(int i=0; i < HEIGHT - 1; i++){

		memcopy((uint8_t*)(VRAM + i * WIDTH * 2), (uint8_t*)(VRAM + (i + 1) * WIDTH * 2), WIDTH * 2);

	}

	memset((uint8_t*)(VRAM + WIDTH * (HEIGHT - 1) * 2), 0x00, WIDTH *  2);

}


char* Logger::get_write_pointer(){

	return (char*)(VRAM + this->Cursor*2);

}

void Logger::backspace(){
	
	this->Cursor--;
	
	*get_write_pointer() = '\0';

}

void Logger::newline(){

	this->Cursor += (WIDTH - Cursor % WIDTH);

}


Logger & Logger::operator << (const char* str){

	print(str);
	return *this;

}

char* uitoa(uint64_t i, uint8_t base){

	char const digit[] = "0123456789ABCDEF";
	static char buffer[32];

	char* pointer = buffer;

	uint64_t shifter = i;
	do{ //Move to where representation ends
	    ++pointer;
	    shifter = shifter/base;
	}while(shifter);
	*pointer = '\0';
	do{ //Move back, inserting digits as u go
	    *--pointer = digit[i % base];
	    i = i/base;
	}while(i);

	return buffer;

}


Logger & Logger::operator << (const uint16_t i){

	*this << (uint64_t)i;
	return *this;

}

Logger & Logger::operator << (const int16_t i){
	if(i < 0)
		*this << "-";
	*this << (uint16_t)i;
	return *this;

}


Logger & Logger::operator << (const uint32_t i){

	*this << (uint64_t)i;
	return *this;

}

Logger & Logger::operator << (const int32_t i){
	if(i < 0)
		*this << "-";
	*this << (uint32_t)i;
	return *this;

}

Logger & Logger::operator << (const uint64_t i){

	switch(this->base){
		
	case dec:

		print(uitoa(i, 10));
		return *this;
	
	case bin:

		print(uitoa(i, 2));
		return *this;
		
	case hex:

		print(uitoa(i, 16));
		return *this;

	default:

		break;

	}

	return *this;

}

Logger & Logger::operator << (const int64_t i){
	if(i < 0)
		*this << "-";
	*this << (uint64_t)i;
	return *this;

}

Logger & Logger::operator << (const float f){

	*this << (double)f;
	return *this;

}

Logger & Logger::operator << (const double d){

	print(uitoa((uint64_t)d, 10));
	print(".");
	print(uitoa(((uint64_t)((d - (double)((uint64_t)d)) * 1e5)), 10));

	return *this;

}

Logger& Logger::operator << (const Modifier mod){

	switch(mod){

	case endl:

		this->newline();
		break;

	case clear:

		this->clearscreen();
		break;

	case del:

		this->backspace();
		break;

	case hex:
		
		this->base = hex;
		break;

	case bin:

		this->base = bin;
		break;
	
	case dec:

		this->base = dec;
		break;

	default:
		
		int code = (int)mod;
		if(code > 2 && code <= 18){

			this->foreground = (Color)(code - 3);

		}
		else if(code > 18 && code <= 34){

			this->background = (Color)(code - 19);

		}

		break;

	}
	
	return *this;

}


void Logger::clearscreen(){

	memset((uint8_t*)VRAM, '\0', HEIGHT * WIDTH * 2);
	this->Cursor = 0;

}

int Logger::getCursor(){

	return this->Cursor;

}

Modifier foreground(Color c){

	return (Modifier)((int)c + 3);

}

Modifier background(Color c){

	return (Modifier)((int)c + 19);

}

}


