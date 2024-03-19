#ifndef LIST_TPP
#define LIST_TPP

#include "List.h"
	
template<typename T>
Node<T>* List<T>::getPenultimate() {
	Node<T>* penultimate = first;

	if (first && first->getNext()) {
		while (penultimate->getNext()->getNext() != nullptr) {
			penultimate = penultimate->getNext();
		}
	}

	return penultimate;
}

template<typename T>
Node<T>* List<T>::getUltimate() {
	Node<T>* lastNode = first;

	if (first) {
		while (lastNode->getNext() != nullptr) {
			lastNode = lastNode->getNext();
		}
	}

	return lastNode;
}

template<typename T>
List<T>::List() {
	first = nullptr;
	count = 0;
}

template<typename T>
List<T>::~List() {
	clear();
}

template<typename T>
void List<T>::pushFront(T data) {
	Node<T>* nodeToPush = new Node<T>(data);
	nodeToPush->setNext(first);
	first = nodeToPush;

	count++;
};

template<typename T>
void List<T>::pushBack(T data) {
	Node<T>* nodeToPush = new Node<T>(data);
	Node<T>* lastNode = getUltimate();

	if (lastNode) {
		lastNode->setNext(nodeToPush);
	}
	else {
		first = nodeToPush;
	}

	count++;
};

template<typename T>
T List<T>::popFront() {
	T data;

	if (first) {
		Node<T>* nodeToPop = first;

		data = nodeToPop->getData();

		first = nodeToPop->getNext();

		nodeToPop->setNext(nullptr);

		delete nodeToPop;

		count--;
	}

	return data;
};

template<typename T>
T List<T>::popBack() {
	T data;

	if (first) {
		Node<T>* nodeToPop = getUltimate();
		Node<T>* penultimateNode = getPenultimate();

		if (penultimateNode) {
			penultimateNode->setNext(nullptr);
		}

		data = nodeToPop->getData();
		if (penultimateNode == nodeToPop) first = nullptr;

		delete nodeToPop;


		count--;
	}

	return data;
};

template<typename T>
Node<T>* List<T>::nodeAt(int index) {
	if (index < 0) return nullptr;

	Node<T>* node = first;

	for (int i = 0; i < index; i++) {
		node = node->getNext();
	}

	return node;
}

template<typename T>
T List<T>::at(int index) {
	Node<T>* nodeToSearch = nodeAt(index);

	if (nodeToSearch)
		return nodeAt(index)->getData();
}

template<typename T>
void List<T>::insert(T data, int index) {
	Node<T>* previousNode = nodeAt(index - 1);

	if (!previousNode) {
		pushFront(data);
		return;
	}

	Node<T>* nextNode = previousNode->getNext();
	Node<T>* nodeToInsert = new Node<T>(data);
	nodeToInsert->setNext(nextNode);
	previousNode->setNext(nodeToInsert);

	count++;
}

template<typename T>
void List<T>::clear() {
	if (!first) return;

	delete first;
	count = 0;
};

template<typename T>
int List<T>::getCount() {
	return count;
};


#endif
