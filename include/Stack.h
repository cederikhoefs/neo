#pragma once
#ifndef STACK_H
#define STACK_H

namespace neo{

template<typename T, uint32_t N>
class Stack{

private:
	T data[N];
	uint32_t next = 0;

public:
	Stack<T, N>() : next(0) {}

	T pop(){

		if(next > 0)
			return data[--next];
		else
			return (T)NULL;

	}
	void push(T x){

		if(next < N)
			data[next++] = x;
	}

};

}

#endif