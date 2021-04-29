#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

template <class T>
class Node {

public:
	//Constructors
	Node();
	Node(const T& data, Node<T> *prev, Node<T> *next);

	//Public Accessor Functions
	T getData() const;
	Node<T>* getPrev() const;
	Node<T>* getNext() const;

	//Public Mutator Functions
	void setPrev(Node<T>* newPrev);
	void setNext(Node<T>* newNext);
private:
	T data;
	Node<T> *prev = nullptr;
	Node<T> *next = nullptr;
};

template <class T>
Node<T>::Node() {}

template <class T>
Node<T>::Node(const T& newData, Node<T> *newPrev, Node<T> *newNext): data(newData), prev(newPrev), next(newNext) {}

template <class T>
T Node<T>::getData() const {
	return data;
}

template <class T>
Node<T>* Node<T>::getPrev() const {
	return prev;
}

template <class T>
Node<T>* Node<T>::getNext() const {
	return next;
}

template <class T>
void Node<T>::setPrev(Node<T> *newPrev) {
	prev = newPrev;
}

template <class T>
void Node<T>::setNext(Node<T> *newNext) {
	next = newNext;
}

// DOUBLY LINKED LIST CLASS

template <class T>
class DoublyLinkedList {
public:
	//Constructor
	DoublyLinkedList();
	~DoublyLinkedList();

	//Public Accessor Functions
	bool isEmpty() const;
	void printDataFromHead(std::ostream& outstream = std::cout) const;
	friend std::ostream& operator << (std::ostream& outstream, const DoublyLinkedList<T>& myList) {
		myList.printDataFromHead(outstream);

		return outstream;
	}

	//Public Mutator Functions
	void setHead(Node<T> *newHead);
	bool removeData(const T& data);
	void pushDataToHead(const T& data);
	void reverseList();
	void insertionSort();
	Node<T>* getHead();
	friend std::istream& operator >> (std::istream& instream, DoublyLinkedList<T>& myList) {
		T data;
		instream >> data;
		myList.pushDataToHead(data);

		return instream;
	}

private:
	Node<T> *head;
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(): head(nullptr) {};

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	Node<T> *current = head;
	Node<T> *temp = nullptr;

	while (current != nullptr) {
		temp = current->getNext();
		delete current;
		current = temp;
	}

}

template <class T>
bool DoublyLinkedList<T>::isEmpty() const {
	return (head == nullptr);
}

template <class T>
void DoublyLinkedList<T>::printDataFromHead(std::ostream& outstream) const {
	for (Node<T> *current = head; current != nullptr; current = current->getNext()) {
		outstream << current->getData() << std::endl;
	}
}

template <class T>
void DoublyLinkedList<T>::setHead(Node<T> *newHead) {
	head = newHead;
}

template <class T>
bool DoublyLinkedList<T>::removeData(const T& data) {
	Node<T> temp = nullptr;

	for (Node<T> *current = head; current != nullptr; current = current->getNext()) {
		if (current->getData == data) {
			if (current == head) {
				temp = current->getNext();
				if (temp != nullptr) {
					temp->setPrev(nullptr);
					head = temp;
				} else {
					head = nullptr;
				}

			} else if (current->getNext() == nullptr) {
				current->getPrev()->setNext(nullptr);

			} else {
				current->getNext()->setPrev(current->getPrev());
				current->getPrev()->setNext(current->getNext());

			}

			delete current;
			return true;
		}
	}

	return false;
}

template <class T>
void DoublyLinkedList<T>::pushDataToHead(const T& data) {
	Node<T>* newNode = new Node<T>(data,nullptr,head);

	if (head != nullptr) {
		head->setPrev(newNode);
	}

	head = newNode;
}


template <class T>
void DoublyLinkedList<T>::reverseList() {
	Node<T> *temp = nullptr;

	for (Node<T> *current = head; current != nullptr; current = current->getPrev()) {
		temp = current->getPrev();
		current->setPrev(current->getNext());
		current->setNext(temp);

		if (current->getPrev() == nullptr) {
			head = current;
		}
	}
}

template <class T>
void DoublyLinkedList<T>::insertionSort() {
	
}


#endif

