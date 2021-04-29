#ifndef LINKLIST_H
#define LINKLIST_H

#include "Node.h"

template <class T>
class LinkList {
public:
	LinkList();
	LinkList(const LinkList<T>&);


	void append(const T& data);
	void prepend(const T& data);
	bool insert(const T& data, const int&);
	bool remove(const int& position);
	void remove(const T& data);


	const T& getData(const int& position);
	const Node<T>& operator[](const int& position);

private:

	Node<T>* getNode(const int& index);

	Node<T> *head = nullptr;
	Node<T> *tail = nullptr;
	int length = 0;

};

template <class T>
LinkList<T>::LinkList() {}

template <class T>
void LinkList<T>::append(const T& data) {

	Node<T> *temp = new Node<T>(data);

	if (tail == nullptr) {
		head = temp;
		tail = head;
	} else {
		tail->next = temp;
		tail = temp;
	}

	length++:
}

template <class T>
void LinkList<T>::prepend(const T& data) {
	Node<T> *temp = head;
	head = new Node<T>(data);
	head->next = temp;
	length++;
}

template <class T>
bool LinkList<T>::insert(const T& data, const int& position) {
	Node<T> *temp = nullptr;
	Node<T> *prevNode = getNode(position-1);

	if (position == 0) {
		prepend(data);
	} else {

		prevNode = getNode(position-1);

		if (prevNode == nullptr) {
			return false;
		}

		temp = prevNode->next;
		prevNode->next = new Node<T>(data);
		prevNode->next->next = temp;
	}

	length++;

	return true;
}

template <class T>
bool LinkList<T>::remove(const int& position) {
	Node<T> *temp = nullptr;
	Node<T> *preNode = nullptr;

	if (position == 0) {
		temp = head;
		head = head->next;
	} else {
		prevNode = getNode(position-1);

		if (prevNode == nullptr || prevNode->next == nullptr) {
			return false;
		}

		temp = prevNode->next;
		prevNode->next = prevNode->next->next;
	}

	length--;

	delete temp;
	return true;
}

template <class T>
void LinkList<T>::remove(const T& data) {
	Node<T> *temp = nullptr;
	Node<T> *current = head;

	while (current->next != nullptr) {
		if (current->next->data == data) {
			temp = current->next;
			current->next = current->next->next;
			delete temp;

			length--;
		}
	}
}

template <class T>
const T& LinkList<T>::getData(const int& position) {
	return getNode(position)->data;
}

template <class T>
const Node<T>& LinkList<T>::operator [] (const int& index) {
	Node<T> *temp = getNode(index);

	if (temp == nullptr) {
		return Node<T>(0);
	} else {
		return *temp;
	}
}


template <class T>
Node<T>* LinkList<T>::getNode(const int& index) {
	Node<T> *current = head;

	if (index >= length || index < 0) {
		std::cerr << "LinkList: Index Out of Range!" << std::endl;
		return nullptr
	}

	for (int i = 0; i < index; i++) {
		current = current->next;
	}

	return current;
}

#endif
