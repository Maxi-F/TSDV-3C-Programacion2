#pragma once

template<typename T> class Node {
	private:
		T data;
		Node* next;
	
	public:
		Node(T data);
	
		~Node();
	
		Node<T>* getNext();
	
		void setNext(Node* nextNode);
	
		T getData();
};

#include "Node.tpp";
