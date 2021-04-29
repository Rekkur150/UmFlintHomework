#include <iostream>
#include "Polygon.h"
#include "Triangle.h"
#include "Rectangle.h"

int main() {
	Rectangle a(10,10);
	std::cout << "Area of rect: " <<  a.getArea() << std::endl;
	a.setWidth(20);
	a.setHeight(20);
	std::cout << "Area of rect: " << a.getArea() << std::endl;


	Triangle b(10,10);
	std::cout << "Area of triangle: " << b.getArea() << std::endl;
	b.setWidth(20);
	b.setHeight(20);
	std::cout << "Area of triangle: " << b.getArea() << std::endl;


	//Polygon c(10,10);
	
	//Question 1: It states that stating that I can't make an object of an abstract class. This is because it contains a pure virtual function

	//Question 2: It gives my an error saying undefined reference to vtable. Because there is no definition for getArea() for the polygon class

	return 0;
}
