#include <iostream>
#include "Shape.h"
#include "Rectangle.h"

int main() {

	//Shape b();
	Rectangle a(10,10);
	std::cout << a.Shape::getHeight() << std::endl;
	std::cout << a.getHeight() << std::endl;

	std::cout << a.Shape::callArea() << std::endl;
	std::cout << a.getArea() << std::endl;

	return 0;
}
