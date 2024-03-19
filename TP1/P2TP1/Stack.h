#pragma once
#include "List.h"

template<typename T> class Stack {
private:
	List<T>* list;

public:
	Stack();

	~Stack();

	void push(T data);

	T pop();

	int getCount();
};

#include "Stack.tpp";