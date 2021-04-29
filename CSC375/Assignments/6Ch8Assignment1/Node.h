#ifndef NODE_H
#define NODE_H

template <class T>
struct Node {
public:
	//Constructor
	Node();
	Node(const T& d);

	//Data
	T data;
	Node<T> *next = nullptr;

};

//Purpose: Default constructor
//Preconditions: None
//Postconditions: None
template <class T>
Node<T>::Node() {}

//Purpose: Constructor that sets data on initalization
//Preconditions: Data to put into node
//Postconditions: None
template <class T>
Node<T>::Node(const T& d) : data(d) {}

#endif
