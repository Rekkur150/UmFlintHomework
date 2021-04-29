//Zachary Holmes
//Chapter 1 Assignment 2
//Date: 9-19-18

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

class Temperature {
public:
	Temperature();
	Temperature(float tempInFahrenheit);

	float getTempInFahrenheit() const;
	float getTempInCelsius() const;

	void setTempInFahrenheit(float temp);
	void setTempInCelsius(float temp);


private:
	float temperature = 0; //Fahrenheit

};

#endif

