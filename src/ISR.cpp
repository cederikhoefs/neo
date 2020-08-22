#include <Neo.h>
#include <ISR.h>
#include <Interrupts.h>
#include <Compatibility.h>
#include <MemoryUtility.h>
#include <Logger.h>

#define CALLBACKS_PER_INTERRUPT 16

#undef VERBOSE

using namespace neo;

uint8_t UsedInterrupts[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 0xCE}; //Later allocate space for the handlers dynamically...

InterruptCallback InterruptCallbacks[sizeof(UsedInterrupts) * CALLBACKS_PER_INTERRUPT]; // 16 handlers per interrupt, later dynamically 
uint8_t InterruptCallbackCount[sizeof(UsedInterrupts)];

bool RegisterCallback(InterruptCallback callback, uint8_t interrupt){

	if(InterruptCallbackCount[interrupt] < CALLBACKS_PER_INTERRUPT){
		
		InterruptCallbacks[interrupt * CALLBACKS_PER_INTERRUPT + InterruptCallbackCount[interrupt]] = callback;
		InterruptCallbackCount[interrupt]++;
		return true;
	
	}
	else
		return false;

}


ISR void HandleInterrupt(CPUContext* state) {

	bool validinterrupt = false;	

	for(int i = 0; i < sizeof(UsedInterrupts) / sizeof(uint8_t); i++)
		if(UsedInterrupts[i] == state->intr)
			validinterrupt = true;

	if(validinterrupt){
#ifdef VERBOSE
		cout << "Valid Interrupt: " << hex << state->intr << ", " << InterruptCallbackCount[state->intr] << " handlers" << endl;
#endif
		for(int i = 0; i < InterruptCallbackCount[state->intr]; i++)
			(*InterruptCallbacks[state->intr * CALLBACKS_PER_INTERRUPT + i])(state);		

	}

	else{
#ifdef VERBOSE
		cout << "Invalid Interrupt: " << hex << state->intr << endl;
#endif
	}

}