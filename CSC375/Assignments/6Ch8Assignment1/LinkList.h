#ifndef LINKLIST_H
#define LINKLIST_H

#include "Node.h"

using namespace std;

template <class T>
class LinkList {
public:
	//Constructors
	LinkList();
	LinkList(const LinkList<T>&);
	//Deconstructor
	~LinkList();

	//Mutators
	void push(const T& data);
	bool pop(T& data);
	void makeEmpty();
	void deepCopy(const LinkList<T>&);

	//Accessors
	bool peek(T& data);
	bool isEmpty() const;

	//Operator Overload
	LinkList<T>& operator = (const LinkList<T>&);

private:
	Node<T> *top = nullptr;
};

//Purpose: Default Constructor
//Preconditions: None
//Postconditions: None
template <class T>
LinkList<T>::LinkList() {}

//Purpose: Copy Constructor
//Preconditions: LinkList object of the same data type
//Postconditions: None
template <class T>
LinkList<T>::LinkList(const LinkList<T>& copy) {
	deepCopy(copy);
}

//Purpose: Deconstructor, free memory
//Preconditions: None
//Postconditions: None
template <class T>
LinkList<T>::~LinkList() {
	makeEmpty();
}

//Purpose: To push data on top of the stack
//Preconditions: Object of data type to store
//Postconditions: None
template <class T>
void LinkList<T>::push(const T& data) {
	Node<T> *current = new Node<T>(data);
	current->next = top;
	top = current;
}

//Purpose: To pop data off the top of the stack
//Preconditions: Object of data type to store information
//Postconditions: True if could pop data, false if it could not.
template <class T>
bool LinkList<T>::pop(T& data) {
	Node<T> *current = top;

	if (current == nullptr) {
		return false;
	} else {
		data = current->data;
		top = current->next;

		delete current;
		return true;
	}
	
}

//Purpose: Peek at the data on the top of the stack
//Preconditions: Object of data type to store information
//Postconditons: True if there was data to peek, false if there was not
template <class T>
bool LinkList<T>::peek(T& data) {
	if (top == nullptr) {
		return false;
	} else {
		data = top->data;
		return true;
	}
}

//Purpose: To check if the stack is empty
//Preconditions: None
//Postconditions: True if it is empty, false it is not empty
template <class T>
bool LinkList<T>::isEmpty() const {
	if (top == nullptr) {
		return true;
	} else {
		return false;
	}
}

//Purpose: To make the stack empty
//Precondtions: None
//Postconditions: None
template <class T>
void LinkList<T>::makeEmpty() {
	Node<T> *current = top;
	Node<T> *temp = nullptr;

	top = nullptr;

	while (current != nullptr) {
		temp = current;
		current = current->next;

		delete temp;
	}
}

//Purpose: To make this object a deep copy of another LinkList object
//Preconditions: A linklist of the same datatype to copy
//Postconditons: None
template <class T>
void LinkList<T>::deepCopy(const LinkList<T>& copy) {
	makeEmpty();

	Node<T>* current = copy.top;
	Node<T>* index = nullptr;
	top = new Node<T>(copy.top->data);

	index = top;

	while (current->next != nullptr) {
		index->next = new Node<T>(current->next->data);
		index = index->next;
		current = current->next;
	}
}

//Purpose: Assignemnt Operator
//Preconditions: Linklist to copy
//Postconditions: The object that was on the left side of the assignment operator
template <class T>
LinkList<T>& LinkList<T>::operator=(const LinkList<T>& copy) {
	deepCopy(copy);

	return *this;
}

#endif



