#ifndef NODE_H
#define NODE_H

template <class T>
struct Node {
public:
	Node();
	Node(const T& d);

	T data;
	Node<T> *next = nullptr;

	void operator=(const T&);
	void operator=(const Node<T>&);
};

template <class T>
Node<T>::Node() {}

template <class T>
Node<T>::Node(const T& d) : data(d) {}

template <class T>
void Node<T>::operator = (const T& newData) {
	data = newData;
}

template <class T>
void Node<T>::operator = (const Node<T>& newNode) {
	data = newNode.data;
}

#endif
