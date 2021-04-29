//Zachary Holmes
//Chapter 1 Assignment 2
//Date: 9-19-18

#include <iostream>
#include "TemperatureDriver.h"
#include "Temperature.h"


//Purpose:: Test Temperature Class
//Preconditions:: None
//Postconditions:: None
void TemperatureDriver::TestTemperature() {
	TestConstructors();
	TestAccessors();
	TestMutators();
}

//Purpose:: Test Constructor
//Preconditons:: None
//Postconditions:: None
void TemperatureDriver::TestConstructors() {
	std::cout << "Testing Constructors" << std::endl;
	Temperature a;
	Temperature b(50);
	std::cout << "Testing Constructors Success" << std::endl << std::endl;
}

//Purpose:: Test Acessor functions
//Preconditions:: None
//Postconditions:: None
void TemperatureDriver::TestAccessors() {
	std::cout << "Testing Accessors" << std::endl;
	Temperature a(50);

	printTemperature(a);

	std::cout << "Testing Accessors Success" << std::endl << std::endl;
}

//Purpose:: Test mutator functions
//Preconditions:: None
//Postconditions:: None
void TemperatureDriver::TestMutators() {
	std::cout << "Testing Mutators" << std::endl;

	Temperature a(50);

	printTemperature(a);
	std::cout << std::endl;

	std::cout << "\tSetting temperature in Fahrenheit to 20" << std::endl;
	a.setTempInFahrenheit(20);
	printTemperature(a);
	std::cout << std::endl;

	std::cout << "\tSetting temperature in Celsius to 20" << std::endl;
	a.setTempInCelsius(20);
	printTemperature(a);
	std::cout << std::endl;

	std::cout << "Testing Mutators Success" << std::endl << std::endl;

}

//Purpose:: Print the temperature of a temperature object in both celsius and fahrenheit
//Preconditions:: Temperature object
//Postconditions:: None
void TemperatureDriver::printTemperature(const Temperature& a) {
	std::cout << "\tTemperature in Fahrenheit is " << a.getTempInFahrenheit() << std::endl;
	std::cout << "\tTemperature in Celsius is " << a.getTempInCelsius() << std::endl;
}
