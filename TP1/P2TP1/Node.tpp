#ifndef NODE_TPP
#define NODE_TPP

#include "Node.h"

template<typename T>
Node<T>::Node(T data) {
	this->data = data;
	next = nullptr;
};

template<typename T>
Node<T>::~Node() {
	if (next) {
		delete next;
	}
};

template<typename T>
Node<T>* Node<T>::getNext() {
	return next;
};

template<typename T>
void Node<T>::setNext(Node<T>* nextNode) {
	next = nextNode;
};

template<typename T>
T Node<T>::getData() {
	return this->data;
};

#endif
