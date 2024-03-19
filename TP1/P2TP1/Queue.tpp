#ifndef QUEUE_TPP
#define QUEUE_TPP

#include "Queue.h";

template<typename T>
Queue<T>::Queue() {
	list = new List<T>();
};

template<typename T>
Queue<T>::~Queue() {
	delete list;
};

template<typename T>
void Queue<T>::enqueue(T data) {
	list->pushBack(data);
};

template<typename T>
T Queue<T>::dequeue() {
	return list->popFront();
};

template<typename T>
int Queue<T>::getCount() {
	return list->getCount();
};


#endif
