#include <iostream>

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

template <class T>
class DoubleLinkList {
public:

	DoubleLinkList();
	DoubleLinkList(const int& size);

	~DoubleLinkList();

	//Mutator
	void push(const T& data);
	void makeEmpty();
	void pop();

	//Accessor
	T& getAtIndex(const int& i) const;
	T& peek() const;
	int getSize() const;
	bool isEmpty() const;
	bool isFull() const;
	void displayForward() const;
	void displayBackward() const;

	int find(const T&) const;



private:

	void findHelper(Node<T>* node, const T& data, int& amount) const;

	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;

	int maxSize = -1;
	int size = 0;

};

template <class T>
int DoubleLinkList<T>::find(const T& data) const {
	int amount = 0;
	findHelper(head, data, amount);
	return amount;
}

template <class T>
void DoubleLinkList<T>::findHelper(Node<T>* node, const T& data, int& amount) const {
	if (node == nullptr) {
		amount = -1;
	} else if (node->data != data) {
		amount++;
		findHelper(node->next,data,amount);
	}
}

template <class T>
DoubleLinkList<T>::DoubleLinkList() {}

template <class T>
DoubleLinkList<T>::DoubleLinkList(const int& sizeIn) {
	maxSize = sizeIn;
}

template <class T>
DoubleLinkList<T>::~DoubleLinkList() {
	makeEmpty();
}

template <class T>
void DoubleLinkList<T>::push(const T& data) {
	Node<T>* temp = head;

	if (isEmpty()) {
		head = new Node<T>(data);
		tail = head;
		size++;
	} else if (!isFull()) {
		head = new Node<T>(data);
		head->next = temp;
		temp->prev = head;
		size++;
	}
}

template <class T>
void DoubleLinkList<T>::makeEmpty() {
	Node<T>* temp = nullptr;
	Node<T>* current = head;

	while (current != nullptr) {
		temp = current;
		current = current->next;

		delete temp;

	}

	size = 0;
	head = nullptr;
	tail = nullptr;

}

template <class T>
void DoubleLinkList<T>::pop() {
	Node<T>* temp = head;

	if (!isEmpty()) {
		head = head->next;

		if (head != nullptr) {
			head->prev = nullptr;
		} else {
			tail = nullptr;
		}

		size--;
		delete temp;
	}
}

template <class T>
T& DoubleLinkList<T>::getAtIndex(const int& index) const {
	Node<T>* current = head;

	for (int i = 0; i < index; i++) {
		current = current->next;
	}

	return current->data;
}

template <class T>
T& DoubleLinkList<T>::peek() const {
	return head->data;
}

template <class T>
int DoubleLinkList<T>::getSize() const {
	return size;
}

template <class T>
bool DoubleLinkList<T>::isEmpty() const {
	if (size == 0) {
		return true;
	} else {
		return false;
	}
}

template <class T>
bool DoubleLinkList<T>::isFull() const {
	if (size == maxSize) {
		return true;
	} else {
		return false;
	}
}

template <class T>
void DoubleLinkList<T>::displayForward() const {
	Node<T>* current = head;
	int index = 0;

	if (isEmpty()) {
		std::cout << "Stack is empty" << std::endl;
	} else {
		while (current != nullptr) {
			std::cout << "stack[" << index++ << "] = " << current->data << std::endl;
			current = current->next;
		}
	}
}

template <class T>
void DoubleLinkList<T>::displayBackward() const {
	Node<T>* current = tail;
	int index = size - 1;

	if (isEmpty()) {
		std::cout << "Stack is empty" << std::endl;
	} else {
		while (current != nullptr) {
			std::cout << "stack[" << index-- << "] = " << current->data << std::endl;
			 current = current->prev;
		}
	}
}

template <class T>
std::ostream& operator << (std::ostream& out, const DoubleLinkList<T>& doubleLinkList) {
	int size = doubleLinkList.getSize();

	if (doubleLinkList.isEmpty()) {
		out << "stack(" << size << ") is empty";
	} else {
		for (int i = 0; i < size; i++) {
			out << "stack(" << i << ") = " << doubleLinkList.getAtIndex(i) << std::endl;
		}
	}

	return out;
}

int main() {

	DoubleLinkList<int> a(10);

	for (int i = 0; i < 10; i++) {
		a.push(i);
	}


	std::cout << "Display Forward" << std::endl;
	a.displayForward();
	std::cout << std::endl << "Display Backward" << std::endl;
	a.displayBackward();
	std::cout << std::endl;


	std::cout << "Finding: " << a.find(12) << std::endl;

	std::cout << a << std::endl;
	std::cout << a.getSize() << std::endl;

	for (int i = 0; i < 10; i++) {
		a.pop();
	}

	std::cout << a.getSize() << std::endl;

	for (int i = 0; i < 10; i++) {
		a.push(i);
	}

	std::cout << a.getSize() << std::endl;

	a.makeEmpty();

	std::cout << a.getSize() << std::endl;

	return 0;
}
