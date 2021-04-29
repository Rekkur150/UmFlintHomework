//Zachary Holmes
//Chapter 1 Assignment 2
//Date: 9-19-18

#ifndef TEMPERATUREDRIVER_H
#define TEMPERATUREDRIVER_H

#include "Temperature.h"

class TemperatureDriver {
public:
	void TestTemperature();
	void TestConstructors();
	void TestAccessors();
	void TestMutators();
private:
	void printTemperature(const Temperature&);
};

#endif
