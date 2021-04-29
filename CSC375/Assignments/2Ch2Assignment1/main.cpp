// Zachary Holmes
// Chapter 2 Assignment 1
// 10/1/18

#include <iostream>
#include "Rectangle.h"


int main() {

	float length = 10.2;
	float width = 10;
	float newLength = 12.2;
	float newWidth = 12;

	double dlength = 10.2;
	double dwidth = 10;
	double newDLength = 12.2;
	double newDWidth = 12;

	Rectangle<float> a(width, length);
	Rectangle<double> b(dwidth, dlength);

	std::cout << "Testing Float Rectangle Class" << std::endl;
	std::cout << "\tCreated a rectangle with length of 10.2 and width of 10" << std::endl;
	std::cout << "\tChecking if the length is greater then the width: " << a.isLengthGreaterThanWidth() << std::endl;
	std::cout << "\tThe are of the rectangle is " << a.getArea() << std::endl;
	std::cout << "\tThe perimeter of the rectangle is " << a.getPerimeter() << std::endl;
	std::cout << "\tChanging the length to 12.2 " << std::endl;
	a.setLength(newLength);
	std::cout << "\tChanging the width to 12 " << std::endl;
	a.setWidth(newWidth);
	std::cout << "\tChecking if the length is greater then the width: " << a.isLengthGreaterThanWidth() << std::endl;
	std::cout << "\tThe are of the rectangle is " << a.getArea() << std::endl;
	std::cout << "\tThe perimeter of the rectangle is " << a.getPerimeter() << std::endl << std::endl;

std::cout << "Testing Double Rectangle Class" << std::endl;
	std::cout << "\tCreated a rectangle with length of 10.2 and width of 10" << std::endl;
	std::cout << "\tChecking if the length is greater then the width: " << b.isLengthGreaterThanWidth() << std::endl;
	std::cout << "\tThe are of the rectangle is " << b.getArea() << std::endl;
	std::cout << "\tThe perimeter of the rectangle is " << b.getPerimeter() << std::endl;
	std::cout << "\tChanging the length to 12.2 " << std::endl;
	b.setLength(newDLength);
	std::cout << "\tChanging the width to 12 " << std::endl;
	b.setWidth(newDWidth);
	std::cout << "\tChecking if the length is greater then the width: " << b.isLengthGreaterThanWidth() << std::endl;
	std::cout << "\tThe are of the rectangle is " << b.getArea() << std::endl;
	std::cout << "\tThe perimeter of the rectangle is " << b.getPerimeter() << std::endl << std::endl;

	return 0;

}
