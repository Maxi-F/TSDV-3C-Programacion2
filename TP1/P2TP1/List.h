#pragma once

#include "Node.h"

template<typename T> class List {
private:

	Node<T>* first;
	int count;

	Node<T>* getPenultimate();

	Node<T>* getUltimate();

	Node<T>* nodeAt(int index);

public:
	List();

	~List();

	void pushFront(T data);

	void pushBack(T data);

	T popFront();

	T popBack();

	void clear();

	int getCount();

	T at(int index);

	void insert(T data, int index);
};

#include "List.tpp";
