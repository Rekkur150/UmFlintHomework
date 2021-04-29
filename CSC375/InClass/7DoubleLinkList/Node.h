#ifndef NODE_H
#define NODE_H

template <class T>
struct Node {

	Node();
	Node(const T& data);

	Node<T>* next = nullptr;
	Node<T>* prev = nullptr;

	T data;
};

template <class T>
Node<T>::Node() {};

template <class T>
Node<T>::Node(const T& newData) {
	data = newData;
}

#endif
