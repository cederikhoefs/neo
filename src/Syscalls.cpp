#include <Neo.h>
#include <Interrupts.h>
#include <Syscalls.h>
#include <Logger.h>
#include <MemoryUtility.h>

using namespace neo;

namespace neo{

void SyscallHandler(CPUContext* state){

	switch((Syscalls)state->eax){

	case Syscalls::print:

		if(state->ecx == 2){

			SyscallParameter<2> args = *(SyscallParameter<2>*)(state->ebx);

			cout << (Modifier)(args.par[1].word[0]) << (char*)(args.par[0].word[0])<< endl;

		}
		break;

	default:
		break;

	}
}

}
