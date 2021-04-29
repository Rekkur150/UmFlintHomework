//Zachary Holmes, Chapter 15 Assignment 1


//Added a student class to put into binary tree. The student class had extra information so I could retrieve extra information by finding a student by their id.
//Can get information of the student by finding the student of the same object or by the student's id.

#include <iostream>

//-----------------------------------------------
// STUDENT
//-----------------------------------------------

class Student {
public:
	Student() {};
	Student(const int& newId, const std::string& newName, const std::string& newMajor): id(newId), name(newName), schoolMajor(newMajor) {};
	int getStudentId() const {return id;};
	std::string getName() const {return name;};
	std::string getMajor() const {return schoolMajor;};

	bool operator==(const Student& b) const;
	bool operator < (const Student& b) const;
	bool operator > (const Student& b) const;

private:
	int id = -1;
	std::string name = "";
	std::string schoolMajor = "";
};

bool Student::operator==(const Student& b) const {
	if (id == b.id) {
		return true;
	} else {
		return false;
	}
}

bool Student::operator < (const Student& b) const {
	if (id < b.id) {
		return true;
	} else {
		return false;
	}
}

bool Student::operator > (const Student& b) const {
	if (id > b.id) {
		return true;
	} else {
		return false;
	}
}


bool operator == (const int& a, const Student& b) {
	if (a == b.getStudentId()) {
		return true;
	} else {
		return false;
	}
}

bool operator == (const Student& b, const int& a) {
	if (a == b.getStudentId()) {
		return true;
	} else {
		return false;
	}
}


bool operator < (const int& a, const Student& b) {
	if (a < b.getStudentId()) {
		return true;
	} else {
		return false;
	}
}

bool operator < (const Student& b, const int& a) {
	if (a < b.getStudentId()) {
		return true;
	} else {
		return false;
	}
}

bool operator > (const int& a, const Student& b) {
	if (a > b.getStudentId()) {
		return true;
	} else {
		return false;
	}
}

bool operator > (const Student& b, const int& a) {
	if (a > b.getStudentId()) {
		return true;
	} else {
		return false;
	}
}

std::ostream& operator << (std::ostream& out, const Student& a) {
	out << "Id = " << a.getStudentId() << ", Name = " << a.getName() << ", Major = " << a.getMajor() << std::endl;
	return out;
}

//-----------------------------------------------
// NODE
//-----------------------------------------------

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

//-----------------------------------------------
// BINARY TREE
//-----------------------------------------------

template <class T>
class BinaryTree {
public:
	BinaryTree();
	~BinaryTree();

	//These functions initiate the recursion functions.
	void insertion(const T& data);
	void deleteTree();
	T retrieval(const T& data);
 	T retrieval(const int& data);
	bool search(const T& data);
	bool search(const int& data);

	void preorder();
	void inorder();
	void postorder();


private:

	//Helper functions do the recursion
	void insertionHelper(const T& data, Node<T>* current);
	void deleteTreeHelper(Node<T>* current);
	Node<T>* retrievalHelper(const T& data, Node<T>* current);
	Node<T>* retrievalHelper(const int& data, Node<T>* current);

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

	std::cout << data;
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
//Preconditions: Data to find
//Postconditions: Returns data
template <class T>
T BinaryTree<T>::retrieval(const T& data) {
	Node<T>* ret = retrievalHelper(data, root);
	return ret->data;
}

//Purpose: To get data from the tree by ID
//Preconditions: Data to find by integer
//Postconditions: Returns data
template <class T>
T BinaryTree<T>::retrieval(const int& data) {
	Node<T>* ret = retrievalHelper(data, root);
	return ret->data;
}

//Purpose: To see if data is in a tree
//Preconditions: Data to find
//Postconditions: True if data was found, false it it was not found.
template <class T>
bool BinaryTree<T>::search(const T& data) {
	Node<T>* ret = retrievalHelper(data, root);
	if (ret != nullptr) {
		return true;
	} else {
		return false;
	}
}

//Purpose: To see if data is in a tree by ID
//Preconditions: Data to find
//Postconditions: True if data was found, false it it was not found.
template <class T>
bool BinaryTree<T>::search(const int& data) {
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
	inorderHelper(root);
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
		if (data < current->data) {
			return retrievalHelper(data, current->left);
		} else {
			return retrievalHelper(data, current->right);
		}
	}
}

//Purpose: The recursive function that allows the searching of data by ID
//Precondtions: Data to look for and the node to begin the search.
//Postcondions: The node which the data was found, could be a nullptr if data was not found.
template <class T>
Node<T>* BinaryTree<T>::retrievalHelper(const int& data, Node<T>* current) {
	if (current == nullptr) {
		return current;
	} else if (current->data == data) {
		return current;
	} else {
		if (data < current->data) {
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

//-----------------------------------------------
// MAIN
//-----------------------------------------------

int main() {
	BinaryTree<Student> a;

	std::cout << "Inputting into tree" << std::endl;

	Student students[8] = {Student(0,"Zachary", "Computer Science"),Student(1,"Billy", "History"),Student(2,"Bob", "Chemistry"),Student(3,"Jimmy", "Organic Chemistry"),Student(4,"Chris", "Black Board Expert"),Student(5,"Barbara", "Chemistry"),Student(6,"Timmy", "Toys"),Student(7,"Jam", "Bread")};

	a.insertion(students[6]);
	a.insertion(students[7]);
	a.insertion(students[3]);
	a.insertion(students[4]);
	a.insertion(students[5]);
	a.insertion(students[2]);
	a.insertion(students[0]);
	a.insertion(students[1]);

	for (int i = 0; i < 10; i++) {
		std::cout << "Getting " << i << ": ";
		if (a.search(i)) {
			std::cout << a.retrieval(i) << std::endl;
		} else {
			std::cout << "Not found!" << std::endl;
		}
	}

	std::cout << "Traversals" << std::endl;
	std::cout << "Pre Order" << std::endl;
	a.preorder();
	std::cout << "Post Order" << std::endl;
	a.postorder();
	std::cout << "In Order" << std::endl;
	a.inorder();

	a.deleteTree();

	return 0;
}
