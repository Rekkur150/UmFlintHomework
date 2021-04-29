#include <iostream>
#include "Stack.h"

struct CarType {
	std::string maker;
	int year;
	float price;
};

int main() {

	srand(time(NULL));
	
	Stack<int> a;
	Stack<int> bests;

	a.operator=(bests);

	for (int i = 0; i < 9; i++) {
		a.push(rand() % 100);
	}

	std::cout << "Peek() = " << a.peek() << std::endl;
	for (int i = 0; i < 9; i++) {
		std::cout << "Pop() = " << a.pop() << std::endl;
	}

	Stack<float> d;
	Stack<float> b;

	for (int i = 0; i < 9; i++) {
		b.push(rand());
	}

	Stack<float> c(b); //Tesing Copy Constructor
	d = c; //Testing Assignment Operator

	std::cout << "Peek() = " << b.peek() << std::endl;
	for (int i = 0; i < 9; i++) {
		std::cout << "b.Peek() = " << b.peek() << std::endl;
		std::cout << "b.Pop() = " << b.pop() << std::endl;
		std::cout << "c.Peek() = " << c.peek() << std::endl;
		std::cout << "c.Pop() = " << c.pop() << std::endl;
		std::cout << "d.Peek() = " << d.peek() << std::endl;
		std::cout << "d.Pop() = " << d.pop() << std::endl;
	}


	return 0;
}
