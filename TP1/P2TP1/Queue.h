#pragma once
#include "List.h"

template<typename T> class Queue {
private:
	List<T>* list;

public:
	Queue();

	~Queue();

	void enqueue(T data);

	T dequeue();

	int getCount();
};

#include "Queue.tpp";
