#pragma once

#include <Neo.h>

namespace neo{

enum Color{

	Black		= 0x0,
	Blue		= 0x1,
	Green		= 0x2,
	Cyan		= 0x3,
	Red			= 0x4,
	Purple		= 0x5,
	Brown		= 0x6,
	LightGray	= 0x7,
	DarkGray	= 0x8,
	LightBlue	= 0x9,
	LightGreen	= 0xA,
	LightCyan	= 0xB,
	LightRed	= 0xC,
	LightPurple	= 0xD,
	Yellow		= 0xE,
	White		= 0xF

};


enum Modifier{

	endl, 
	clear,
	del,
	
	fgBlack,
	fgBlue,
	fgGreen,
	fgCyan,
	fgRed,
	fgPurple,
	fgBrown,
	fgLightGray,
	fgDarkGray,
	fgLightBlue,
	fgLightGreen,
	fgLightCyan,
	fgLightRed,
	fgLightPurple,
	fgYellow,
	fgWhite,

	bgBlack,
	bgBlue,
	bgGreen,
	bgCyan,
	bgRed,
	bgPurple,
	bgBrown,
	bgLightGray,
	bgDarkGray,
	bgLightBlue,
	bgLightGreen,
	bgLightCyan,
	bgLightRed,
	bgLightPurple,
	bgYellow,
	bgWhite,

	dec,
	hex,
	bin

};

class Logger{

	public:

		Logger();	
		Logger(Color foreground, Color background);

		static const constexpr int WIDTH = 80;
		static const constexpr int HEIGHT = 25;

		void clearscreen();
		void newline();
		void backspace();

		void scroll(int n = 1);

		void putc(char c);
		void print(const char* str);		

		int getCursor();

		void setCursor(int pos);

		Logger& operator << (const char* str);
		Logger& operator << (const uint16_t i);
		Logger& operator << (const uint32_t i);
		Logger& operator << (const uint64_t i);
		Logger& operator << (const int16_t i);
		Logger& operator << (const int32_t i);
		Logger& operator << (const int64_t i);
		Logger& operator << (const float f);
		Logger& operator << (const double d);
		Logger& operator << (const Modifier mod);


	private:

		Color foreground;
		Color background;
		Modifier base;

		uint16_t Cursor;

		char* get_write_pointer();


};

Modifier foreground(Color c);
Modifier background(Color c);

}























