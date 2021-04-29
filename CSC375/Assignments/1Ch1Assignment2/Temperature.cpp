//Zachary Holmes
//Chapter 1 Assignment 2
//Date: 9-19-18

#include "Temperature.h"

//Purpose:: Default Constructor
//Preconditions:: None
//Postconditions:: None
Temperature::Temperature() {};

//Purpose:: Constructor to set temperature
//Preconditions:: Temp in Celcius
//Postconditions:: None
Temperature::Temperature(float temp) : temperature(temp) {}

//Purpose:: Get the temperature in fahrenheit
//Precondition:: None
//Postconditions:: Temperature in fahrenheit
float Temperature::getTempInFahrenheit() const {
	return temperature;
}

//Purpose:: Get the temperature in Celsius
//Preconditions:: None
//Postconditions:: Temperature in Celsius
float Temperature::getTempInCelsius() const {
	return ((5.0/9.0) * (temperature - 32.0));
}

//Purpose:: Set the temperature in fahrenheit
//Preconditions:: Temperater in fahrenheit
//Postconditions:: None
void Temperature::setTempInFahrenheit(float temp) {
	temperature = temp;
}

//Purpose:: Set the temperature in Celsius
//Preconditions:: Temperature in Celcius
//Postconditions:: None
void Temperature::setTempInCelsius(float temp) {
	temperature = (((9.0/5.0) * (temp)) + 32.0);
}
