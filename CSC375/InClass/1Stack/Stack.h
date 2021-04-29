#ifndef STACK_H
#define STACK_H

template <class T>
class Stack {
public:
	//Constructor
	Stack();
	Stack(const Stack<T>& copy);

	//Deconstructor
	~Stack();

	//Accessor Functions
	const bool isEmpty() const;
	const bool isFull() const;
	const T& peek();

	int getSize() {return size;};
	int getLength() {return length;};

	//Mutator Functions
	const bool push(const T& data);
	T pop();

	//Operator Overload
	Stack<T>& operator = (const Stack<T>& assign);

private:

	//Helper Function
	void changeArraySize(const int& newSize);

	//Private Data
	const int defaultSize = 8;
	int size = 0;
	int length = 0;
	T *array;
};

//Purpose: Initalize the Stack
//Precondtions: None
//Postconditions: None
template <class T>
Stack<T>::Stack() {
	size = defaultSize;
	array = new T[defaultSize];
}

//Purpose: Create a copy constructor
//Preconditions: Object to Copy
//Preconditions: None
template <class T>
Stack<T>::Stack(const Stack<T>& copyStack) {
	size = copyStack.size;
	length = copyStack.length;
	array = new T[size];

	for (int i = 0; i < length; i++) {
		array[i] = copyStack.array[i];
	}
}

//Purpose: Deconstructor, to deal with dynamic memory
//Preconditons: None
//Postconditions: None
template <class T>
Stack<T>::~Stack() {
	delete [] array;
}

//Purpose: To see if the stack is empty
//Preconditions: None
//Postcondition: Boolean true if empty false if not
template <class T>
const bool Stack<T>::isEmpty() const {
	return (length == 0);
}

//Purpose: To see if the stack is full
//Preconditions: None
//Postconditons: True if the stack is full, false if not
template <class T>
const bool Stack<T>::isFull() const {
	return (size == length);
}

//Purpose: Push information on to the stack
//Preconditions: Data that you wish to push onto the stack
//Postconditions: True if sucessful, false not successful
template <class T>
const bool Stack<T>::push(const T& data) {
	if (!isFull()) {
		array[length++] = data;
		return true;
	} else {
		changeArraySize(size*2);
		array[length++] = data;
		return true;
	}
}

//Purpose: Remove data on top of the stack
//Preconditions: None
//Postconditons: Data that was on the stack
template <class T>
T Stack<T>::pop() {
	if (!isEmpty()) {

		if (length < size/2 && size > defaultSize) {
			changeArraySize(size/2);
		}

		return array[--length];
	} else {
		std::cerr << "Can not pop a empty stack" << std::endl;
	}
}

//Purpose: Look at top object
//Preconditons: None
//Postconditions: Returns the object by reference.
template <class T>
const T& Stack<T>::peek() {
	if (!isEmpty()) {
		return array[length-1];
	}
}

//Purpose: To change the size of the stack's array, to allow for any size of stack
//Preconditons: New array size
//Postconditions: None
template <class T>
void Stack<T>::changeArraySize(const int& newSize) {
	try {
		T *newArray = new T[newSize];

		for (int i = 0; i < length; i++) {
			newArray[i] = array[i];
		}

		delete [] array;
		array = newArray;
		size = newSize;

	} catch (std::bad_alloc e) {
		std::cerr << "Not enough memory" << std::endl;
	}
}

//Purpose: Allow the assignment of the same object
//Preconditons: Another stack of the same data type
//Postconditons: A reference to the original stack to allow multiple operators
template <class T>
Stack<T>& Stack<T>::operator = (const Stack<T>& assign) {
	size = assign.size;
	length = assign.length;
	changeArraySize(size);
	for (int i=0; i < length; i++) {
		array[i] = assign.array[i];
	}
}


#endif
