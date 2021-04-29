#ifndef NODE_H
#define NODE_H

template <class T>
struct Node {
public:
	Node();
	Node(const T& d);
	Node(const Node<T>&);

	T data;
	Node<T> *next = nullptr;
	Node<T> *prev = nullptr;

	void operator=(const T&);
	void operator=(const Node<T>&);
};

template <class T>
Node<T>::Node() {}

template <class T>
Node<T>::Node(const T& d) : data(d) {}

template <class T>
Node<T>::Node(const Node<T>& n) : data(n.data) {}

template <class T>
void Node<T>::operator = (const T& newData) {
	data = newData;
}

template <class T>
void Node<T>::operator = (const Node<T>& newNode) {
	data = newNode.data;
}

#endif
