#include <Neo.h>
#include <MemoryUtility.h>

using namespace neo;

namespace neo{

void* NULL = reinterpret_cast<void*>(0);

void memcopy(void *dest, void *src, uint32_t n){

	for(int i = 0; i < n; i++){

		reinterpret_cast<uint8_t*>(dest)[i] = reinterpret_cast<uint8_t*>(src)[i];

	}

}

void memmove(void* dest, void* src, uint32_t n){
 
	uint8_t temp;	

	for(int i = 0; i < n; i++){

		temp = reinterpret_cast<uint8_t*>(src)[i];
		reinterpret_cast<uint8_t*>(dest)[i] = temp;

	}

}

void memset(void* dest, uint8_t value, uint32_t n){

	for(int i = 0; i < n; i++){

		reinterpret_cast<uint8_t*>(dest)[i] = value;

	}

}

}