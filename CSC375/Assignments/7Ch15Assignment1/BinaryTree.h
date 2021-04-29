#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"

template <class T>
class BinaryTree {
public:
	BinaryTree();
	~BinaryTree();

	//These functions initiate the recursion functions.
	void insertion(const T& data);
	void deleteTree();
	bool retrieval(const T& data);

	void preorder();
	void inorder();
	void postorder();


private:

	//Helper functions do the recursion
	void insertionHelper(const T& data, Node<T>* current);
	void deleteTreeHelper(Node<T>* current);
	Node<T>* retrievalHelper(const T& data, Node<T>* current);

	void preorderHelper(Node<T>* current);
	void inorderHelper(Node<T>* current);
	void postorderHelper(Node<T>* current);

	Node<T>* root = nullptr;
};

//Purpose: Default Constructor
//Precondtions: None
//Postconditions: None
template <class T>
BinaryTree<T>::BinaryTree() {}

//Purpose: Remove memory created by Binary Tree
//Precondtions: None
//Postconditions: None
template <class T>
BinaryTree<T>::~BinaryTree() {
	deleteTree();
}

//Purpose: To insert data into the binary tree
//Preconditions: Data to be inserted
//Postconditions: None
template <class T>
void BinaryTree<T>::insertion(const T& data) {
	if (root == nullptr) {
		root = new Node<T>(data);
	} else {
		insertionHelper(data, root);
	}

	std::cout << data << std::endl;
}

//Purpose: To remove all nodes in the binary tree
//Preconditons: None
//Postconditions: None
template <class T>
void BinaryTree<T>::deleteTree() {
	deleteTreeHelper(root);
	root = nullptr;
}

//Purpose: To get data from the tree
//Preconditions: Data to fine
//Postconditions: True if the data was found, false if it was not found
template <class T>
bool BinaryTree<T>::retrieval(const T& data) {
	Node<T>* ret = retrievalHelper(data, root);
	if (ret != nullptr) {
		return true;
	} else {
		return false;
	}
}

//Purpose: Print the binary tree in preorder
//Preconditons: None
//Postconditions: None
template <class T>
void BinaryTree<T>::preorder() {
	preorderHelper(root);
	std::cout << std::endl;
}

//Purpose: Print the binary tree in order
//Preconditons: None
//Postconditons: None
template <class T>
void BinaryTree<T>::inorder() {
	iPunorderHelper(root);
	std::cout << std::endl;
}

//Purpose: To print the binary tree in post order
//Preconditons: None
//Postconditons: None
template <class T>
void BinaryTree<T>::postorder() {
	postorderHelper(root);
	std::cout << std::endl;	
}

//Purpose: To do the recursion that will print the binary tree in pre order
//Preconditions: The node to start printing the tree at
//Postconditions: None
template <class T>
void BinaryTree<T>::preorderHelper(Node<T>* current) {
	if (current != nullptr) {
		std::cout << current->data << " ";
		preorderHelper(current->left);
		preorderHelper(current->right);
	}
}

//Purpose: To do the recursion that will print the binary tree in order
//Precondtions: The node to start printing the tree at
//Postconditons: None
template <class T>
void BinaryTree<T>::inorderHelper(Node<T>* current) {
	if (current != nullptr) {
		inorderHelper(current->left);
		std::cout << current->data << " ";
		inorderHelper(current->right);
	}
}

//Purpose: To do the recursion that will print the binary tree post order
//Precondtions: The node to start printing the tree at
//Postconditons: None
template <class T>
void BinaryTree<T>::postorderHelper(Node<T>* current) {
	if (current != nullptr) {
		postorderHelper(current->left);
		postorderHelper(current->right);
		std::cout << current->data << " ";
	}
}	

//Purpose: The recursion function that will insert data into the binary tree
//Precondtions: Data to insert and node to start looking for area to put data
//Postconditions: None
template <class T>
void BinaryTree<T>::insertionHelper(const T& data, Node<T>* current) {
	if (data < current->data) {
		if (current->left == nullptr) {
			current->left = new Node<T>(data);
		} else {
			insertionHelper(data, current->left);
		}
	} else {
		if (current->right == nullptr) {
			current->right = new Node<T>(data);
		} else {
			insertionHelper(data,current->right);
		}
	}
}

//Purpose: The recursive function that allows the searching of data
//Precondtions: Data to look for and the node to begin the search.
//Postcondions: The node which the data was found, could be a nullptr if data was not found.
template <class T>
Node<T>* BinaryTree<T>::retrievalHelper(const T& data, Node<T>* current) {
	if (current == nullptr) {
		return current;
	} else if (current->data == data) {
		return current;
	} else {
		if (current->data < data) {
			return retrievalHelper(data, current->left);
		} else {
			return retrievalHelper(data, current->right);
		}
	}
}

//Purpose: The recursive function to delete the tree.
//Preconditions: Starting point to delete tree.
//Postconditons: Destruction
template <class T>
void BinaryTree<T>::deleteTreeHelper(Node<T>* current) {
	if (current != nullptr) {
		deleteTreeHelper(current->left);
		deleteTreeHelper(current->right);
		delete current;
	};
}



#endif

