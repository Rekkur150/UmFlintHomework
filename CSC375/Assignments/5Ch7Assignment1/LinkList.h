#ifndef LINKLIST_H
#define LINKLIST_H

#include "Node.h"
#include <ostream>

template <class T>
class LinkList {
public:
	LinkList();

	void append(const T& data);
	void remove(const T& data);
	void print() const;

private:
	Node<T> *head = nullptr;

};

template <class T>
LinkList<T>::LinkList() {}

template <class T>
void LinkList<T>::append(const T& data) {
	Node<T> *temp = new Node<T>(data);
	Node<T> *current = head;

	if (head == nullptr) {
		head = temp;
	} else {
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = temp;
	}
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
		} else {
			current = current->next;
		}
	}

	if (head->data == data) {
		temp = head;
		head = head->next;
		delete temp;
	}

}

template <class T>
void LinkList<T>::print() const {
	Node<T> *current = head;
	int i = 0;

	if (head != nullptr) {
		while (current != nullptr) {
			std::cout << "LinkList[" << i++ << "] = " << current->data << std::endl;
			current = current->next;
		}
	} else {
		std::cout << "LinkList is empty. D=" << std::endl;
	}


}

#endif



