#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream> //ostream

template <class T>
class Node {

public:
	// Constructors
	Node();
	Node(const T& data, Node<T>* newLeft, Node<T>* newRight);

	// Functions
	T getData();
	void printData(std::ostream& outstream = std::cout);
	Node<T>* getLeft();
	Node<T>* getRight();

	void setLeft(Node<T> *newLeft);
	void setRight(Node<T> *newRight);
private:
	T data; //Stores data of class T
	Node<T> *left = nullptr; //Stores pointer to left node
	Node<T> *right = nullptr; //Stores pointer to right node
};

//Purpose: Creates default constructor
//Preconditions: None
//Postconditions: None
template <class T>
Node<T>::Node() {}

//Purpose: Creates a construction with data, left, and right pointers
//Preconditions: Data, left node, and right node
//Postconditions: None
template <class T>
Node<T>::Node(const T& newData, Node<T>* newLeft, Node<T>* newRight) : data(newData), left(newLeft), right(newRight) {}

//Purpose: Gets the data
//Preconditions: None
//Postconditions: Returns the data
template <class T>
T Node<T>::getData() {
	return data;
}

//Purpose: Print the data to a out stream
//Preconditions: Can input outstream, default cout
//Postconditions: None
template <class T>
void Node<T>::printData(std::ostream& outstream) {
	outstream << data << std::endl;
}

//Purpose: Gets the left node
//Preconditions: None
//Postconditions: Returns a pointer to the left node
template <class T>
Node<T>* Node<T>::getLeft() {
	return left;
}

//Purpose: Get the right node
//Preconditions: None
//Postconditions: Returns a pointer to the right node
template <class T>
Node<T>* Node<T>::getRight() {
	return right;
}

//Purpose: Set the left node
//Preconditions: Pointer to the left node
//Postconditions: None
template <class T>
void Node<T>::setLeft(Node<T> *newLeft) {
	left = newLeft;
}

//Purpose: Set the right node
//Preconditions: Pointer to the right node
//Postconditions: None
template <class T>
void Node<T>::setRight(Node<T> *newRight) {
	right = newRight;
}

template <class T>
class BinaryTree {
public:
	//Constructor
	BinaryTree();

	//Deconstructor
	~BinaryTree();

	//Functions
	void delete_tree();
	bool search(T key);
	void insert(T key);
	void printTree();
	bool tdelete(T key);

private:
	//Data
	Node<T>* root;

	//Fuctions
	void delete_tree_aux(Node<T> *leaf);
	void insert_aux(T key, Node<T> *leaf);
	bool search_aux(T key, Node<T> *leaf);
	void printTreeAux(Node<T> *leaf);
	bool delete_aux(T key, Node<T> *leaf, Node<T> *prev);
	Node<T>* delete_helper_aux(Node<T> *leaf);


};


//Purpose: To create the default BinaryTree
//Preconditions: None
//Postconditions: Makes the root null
template <class T>
BinaryTree<T>::BinaryTree() {
	root = nullptr;
}

//Purpose: To delete the tree
//Preconditions: None
//Postconditions: Missing Node...
template <class T>
BinaryTree<T>::~BinaryTree() {
	delete_tree();
}

//Purpose: Public function to call the private recursive delete function
//Preconditions: None
//Postconditions: None
template <class T>
void BinaryTree<T>::delete_tree() {
	delete_tree_aux(root);
	root = nullptr;
}

//Purpose: Public function to call the private recursive search function
//Preconditions: Data of type T
//Postconditions: True if the data was found, false if it was not found
template <class T>
bool BinaryTree<T>::search(T key) {
	return search_aux(key, root);
}

//Purpose: Public function to call the private recursive insertion function
//Preconditions: The data you wish to add to the binary tree.
//Postconditions: None
template <class T>
void BinaryTree<T>::insert(T key) {
	if (root == nullptr) {
		root = new Node<T>(key, nullptr, nullptr);
	} else {
		insert_aux(key, root);
	}
}

//Purpose: Public function to call the private recursive print function
//Precondition: None
//Postcondition: None
template <class T>
void BinaryTree<T>::printTree() {
	if (root != nullptr) {
		printTreeAux(root);
	}
}

//Purpose: To recursivaly remove the tree
//Preconditions: None
//Postconditions: None
template <class T>
void BinaryTree<T>::delete_tree_aux(Node<T> *leaf) {
	if (leaf != nullptr) {
		delete_tree_aux(leaf->getLeft());
		delete_tree_aux(leaf->getRight());

		delete leaf;
	}
}

//Purpose: A recursive function to insert a node
//Preconditions: The data T that you want to add to the tree.
//Postconditions: None
template <class T>
void BinaryTree<T>::insert_aux(T key, Node<T> *leaf) {
	Node<T> *temp = leaf->getRight();

	if (key > leaf->getData()) {
		if (temp == nullptr) {
			leaf->setRight(new Node<T>(key, nullptr, nullptr));
		} else {
			insert_aux(key,temp);
		}
	} else {
		temp = leaf->getLeft();
		if (temp == nullptr) {
			leaf->setLeft(new Node<T>(key, nullptr,nullptr));
		} else {
			insert_aux(key,temp);
		}
	}
}

//Purpose: To recursively search for a node in the tree with a certain data
//Preconditions: The data you wish to look for
//Postconditions: True if it found the data in the tree, false it if did not find the data.
template <class T>
bool BinaryTree<T>::search_aux(T key, Node<T> *leaf) {
 	if (leaf == nullptr) {
		return false;
	} else if (key == leaf->getData()) {
		return true;
	} else if (key > leaf->getData()) {
		return search_aux(key, leaf->getRight());
	} else {
		return search_aux(key, leaf->getLeft());
	}
}



template <class T>
bool BinaryTree<T>::delete(T key) {
	return delete_aux(key, root, root);
}
template <class T>
bool BinaryTree<T>::delete_aux(T key, Node<T> *leaf, Node<T> *prev) {
 	if (leaf == nullptr) {
		return false;
	} else if (key == leaf->getData()) {

		if (prev->getRight() == leaf) {
			if (leaf->getRight() == nullptr) {
				prev->setRight(leaf->getLeft());
			} else {
				prev->setRight(leaf->getRight());
			}
		} else if (prev->getLeft() == leaf) {
			if (leaf->getRight() == nullptr) {
				prev->setLeft(leaf->getLeft());
			} else {
				prev->setLeft(leaf->getRight());
			}
		} else {
			if (leaf->getRight() == nullptr) {
				root = leaf->getLeft();
			} else {
				root = leaf->getRight();
			}
		}

		if (leaf->getRight() != nullptr) {
			delete_helper_aux(leaf->getRight())->setLeft(leaf->getLeft());
		}

		delete leaf;

		return true;
	} else if (key > leaf->getData()) {
		return delete_aux(key, leaf->getRight(), leaf);

	} else {
		return delete_aux(key, leaf->getLeft(), leaf);
	}
}

template <class T>
Node<T>* BinaryTree<T>::delete_helper_aux(Node<T> *leaf) {
	if (leaf->getLeft() != nullptr) {
		delete_helper_aux(leaf->getLeft());
	} else {
		return leaf;
	}
}

//Purpose: To recursively print the nodes data and the left and right node's data.
//Preconditions: The starting node.
//Postconditions: None
template <class T>
void BinaryTree<T>::printTreeAux(Node<T> *leaf) {
	if (leaf != nullptr) {
		Node<T> *temp = leaf->getLeft();

		std::cout << "This leaf is " << leaf->getData();
		if (temp != nullptr) {
			std::cout << " and its left node is " << temp->getData();
		} else {
			std::cout << " and its left node is nullptr";
		}

		temp = leaf->getRight();
		if (temp != nullptr) {
			std::cout << " and its right node is " << temp->getData();
		} else {
			std::cout << " and it right node is nullptr";
		}

		std::cout << std::endl;
		printTreeAux(leaf->getLeft());
		printTreeAux(leaf->getRight());
	}
}

#endif
