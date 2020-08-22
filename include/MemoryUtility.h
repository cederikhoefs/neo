#pragma once
#ifndef MEMORY_UTILITY_H
#define MEMORY_UTILITY_H

#include <Neo.h>

namespace neo{

extern void* NULL;

extern void memset(void* dest, uint8_t value, uint32_t n);
extern void memcopy(void* dest, void* src, uint32_t n);
extern void memmove(void* dest, void* src, uint32_t n);

}


#endif
