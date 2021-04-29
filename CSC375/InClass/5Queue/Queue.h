#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

template <class T>
class Queue {

public:
	Queue();
	Queue(const Queue<T>& toCopy);
	~Queue();

	void enqueue(const T& data);
	T dequeue();
	T& peek();

private:
	Node<T> *head = nullptr;
	Node<T> *tail = nullptr;
}

template <class T>
Queue:Queue() {}

template <class T>
Queue::Queue(const Queue<T>& toCopy) {
	Node<T>* copyCurrent = toCopy.head;
	Node<T>* current;

	while(copyCurrent != nullptr) {

		current = new Node<T>(*copyCurrent);

		if (head == nullptr) {
			head = current;
		}
	}
	

}

template <class T>
Queue::~Queue() {
	Node<T>* current = head;
	Node<T>* temp = nullptr;

	head = nullptr;
	tail = nullptr;

	while(current != nullptr) {
		temp = current;
		current = current->next;
		current->prev = nullptr;

		delete temp;
	}	

}



#endif
