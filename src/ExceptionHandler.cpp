#include <Neo.h>
#include <Interrupts.h>
#include <Exceptions.h>
#include <Logger.h>

using namespace neo;

void ExceptionHandler(CPUContext* state){

	cout << clear;
	cout << foreground(White) << background(Red);
	cout << "Exception #" << state->intr << endl;
	cout << hex;
	cout << "Error Code: 0x" << state->err << endl;
	cout << ExceptionNames[state->intr] << endl;
	cout << "[eax] = 0x" << state->eax << endl;
	cout << "[ebx] = 0x" << state->ebx << endl;
	cout << "[ecx] = 0x" << state->ecx << endl;
	cout << "[edx] = 0x" << state->edx << endl;

	cout << "[edi] = 0x" << state->edi << endl;
	cout << "[esi] = 0x" << state->esi << endl;
	cout << "[ebp] = 0x" << state->ebp << endl;

	cout << "[eip] = 0x" << state->eip << endl;
	cout << "[cs]  = 0x"  << state->cs << endl;
	cout << "[eflags] = 0x" << state->eflags << endl;
	cout << "[esp] = 0x" << state->esp << endl;
	cout << "[ss]  = 0x"  << state->ss << endl;

	while(true);
}
