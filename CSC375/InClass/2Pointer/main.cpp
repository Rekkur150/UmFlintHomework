#include <iostream>

void foo() {
	int *x,y, *z;

	y = 9;

	x = &y;

	*x = 2;
	std::cout << &y << std::endl;
	std::cout << *x << std::endl;
	std::cout << y << std::endl;

	x = new int[500000];

	std::cout << &x << std::endl;

	delete [] x;

	std::cout << &x << std::endl;

}

int main() {

	foo();

	return 0;
}
