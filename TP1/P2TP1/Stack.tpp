#ifndef STACK_TPP
#define STACK_TPP

#include "Stack.h"

template<typename T>
Stack<T>::Stack() {
	list = new List<T>();
}

template<typename T>
Stack<T>::~Stack() {
	delete list;
}

template<typename T>
void Stack<T>::push(T data) {
	list->pushFront(data);
}

template<typename T>
T Stack<T>::pop() {
	return list->popFront();
}

template<typename T>
int Stack<T>::getCount() {
	return list->getCount();
}


#endif
