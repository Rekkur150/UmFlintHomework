#ifndef NODE_H
#define NODE_H

template <class T>
struct Node {
	Node();
	Node(const T&);

	Node<T>* left = nullptr;
	Node<T>* right = nullptr;
	T data;
};

template <class T>
Node<T>::Node() {}

template <class T>
Node<T>::Node(const T& d) {
	data = d;
}

#endif
