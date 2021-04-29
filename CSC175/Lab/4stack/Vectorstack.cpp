#include <iostream>
using namespace std;

class Stack {
	private:
	int size = 20;
	int length = 0;
	int array[20];
	public:

	Stack();

	void push(int data);
	void pop();
	void display();

	int top();
	int lengthOf();
	bool isEmpty();
	bool isFull();
};

Stack::Stack() {
	length = 0;
}

void Stack::push(int data) {
	if (!isFull()) {
		array[length++] = data;
	} else {
		cerr << "Stack Over Flow!" << endl;
	}
}

void Stack::pop() {
	if (!isEmpty()) {
		length--;
	} else {
		cerr << "Stack Under Flow" << endl;
	}
}

void Stack::display() {
	cout << "stack = (";
	for (int i = 0; i < length; i++) {
		if (i == length-1) {
			cout << array[i];
		} else {
			cout << array[i] << ",";
		}
	}

	cout << ")" << endl;
}

int Stack::top() {
	return array[length - 1];
}

int Stack::lengthOf() {
	return length;
}

bool Stack::isEmpty() {
	if (length == 0) {
		return true;
	}

	return false;
}

bool Stack::isFull() {
	if (length == size) {
		return true;
	}

	return false;
}

int main() {

	Stack a;
	cout << "isEmpty: " << a.isEmpty() << endl;
	a.pop();
	a.push(5);
	a.push(4);
	a.push(3);
	a.push(2);
	cout << "Top: " << a.top() << endl;
	a.push(1);
	cout << "isEmpty: " << a.isEmpty() << endl;
	cout << "length: " << a.lengthOf() << endl;
	a.display();
	a.pop();
	cout << "length: " << a.lengthOf() << endl;
	a.display();

	return 0;
}
