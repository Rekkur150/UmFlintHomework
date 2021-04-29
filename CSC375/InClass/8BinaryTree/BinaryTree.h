#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"

template <class T>
struct BinaryTree {
public:
	BinaryTree();
	~BinaryTree();

	void push(const T& data);
	void deleteTree();
	void printTree();

private:
	void printTreeHelper(Node<T>* current);
	void pushHelper(const T& data, Node<T>* current);
	void deleteTreeHelper(Node<T>* current);

	Node<T>* root = nullptr;
};

template <class T>
BinaryTree<T>::BinaryTree() {}

template <class T>
BinaryTree<T>::~BinaryTree() {
	deleteTree();
}

template <class T>
void BinaryTree<T>::push(const T& data) {
	if (root == nullptr) {
		root = new Node<T>(data);
	} else {
		pushHelper(data, root);
	}
}

template <class T>
void BinaryTree<T>::pushHelper(const T& data, Node<T>* current) {
	if (data < current->data) {
		if (current->left == nullptr) {
			current->left = new Node<T>(data);
		} else {
			pushHelper(data, current->left);
		}
	} else {
		if (current->right == nullptr) {
			current->right = new Node<T>(data);
		} else {
			pushHelper(data,current->right);
		}
	}
}

template <class T>
void BinaryTree<T>::printTree() {
	if (root != nullptr) {
		printTreeHelper(root);
	} else {
		std::cout << "Empty Binary Tree" << std::endl;
	}
}

template <class T>
void BinaryTree<T>::deleteTree() {
	deleteTreeHelper(root);
	root = nullptr;
}

template <class T>
void BinaryTree<T>::deleteTreeHelper(Node<T>* current) {
	if (current != nullptr) {
		deleteTreeHelper(current->left);
		deleteTreeHelper(current->right);
		delete current;
	};
}

template <class T>
void BinaryTree<T>::printTreeHelper(Node<T>* current) {
	if (current != nullptr) {
		if (current->left != nullptr && current->right != nullptr) {
			std::cout << "Current = " << current->data << ", Left = " << current->left->data << ", Right = " << current->right->data << "." << std::endl;
		} else if (current->left == nullptr && current->right == nullptr) {
			std::cout << "Current = " << current->data << ", Left = nullptr, Right = nullptr." << std::endl;
		} else if (current->left == nullptr) {
			std::cout << "Current = " << current->data << ", Left = nullptr" << ", Right = " << current->right->data << "." << std::endl;
		} else if (current->right == nullptr) {
			std::cout << "Current = " << current->data << ", Left = " << current->left->data << ", Right = nullptr" << "." << std::endl;
		}

		printTreeHelper(current->left);
		printTreeHelper(current->right);

	}
}


#endif

