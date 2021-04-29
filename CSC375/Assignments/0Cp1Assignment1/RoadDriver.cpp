// Zachary Holmes
// CSC 375
// Chapter 1, Assignment 1

#include <iostream>
#include "RoadDriver.h"
#include "Road.h"

void RoadDriver::TestRoad() const {
	TestConstructors();
	TestAccessorFunctions();
	TestMutatorFunctions();
	TestAsphalt();
}

void RoadDriver::TestConstructors() const {
	std::cout << "Testing Constructors" << std::endl;
	Road a;
	Road b(10,10);
	std::cout << "Testing Constructors: Success" << std::endl << std::endl;
}


void RoadDriver::TestAccessorFunctions() const {
	std::cout << "Testing AccessorFunctions" << std::endl;
	Road a(8,8);
	std::cout << "\tWidth = " << a.getWidth() << ", Length = " << a.getLength() << std::endl;
	std::cout << "Test AcessorFunctions: Success" << std::endl << std::endl;
}

void RoadDriver::TestMutatorFunctions() const {
	std::cout << "Testing MutatorFunctions" << std::endl;
	Road a(8,8);
	std::cout << "\tBefore: Width = " << a.getWidth() << ", Length = " << a.getLength() << std::endl;
	a.setWidth(16);
	a.setLength(32);
	std::cout << "\tAfter: Width = " << a.getWidth() << ", Length = " << a.getLength() << std::endl;
	std::cout << "Testing MutatorFunctions: Success" << std::endl << std::endl;
}

void RoadDriver::TestAsphalt() const {
	std::cout << "Testing Asphalt" << std::endl;
	float wid = 16;
	float len = 32;
	float thickness = 0.2;

	Road a(wid,len);

	std::cout << "\tThe amount of Cubic Asphalt in a road that is " << a.getWidth() << " feet wide, and " << a.getLength() << " miles long, with a thickness of " << thickness << " is " << a.Asphalt(thickness) << " cubic feet." << std::endl;
}

