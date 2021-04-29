#ifndef CAR_H
#define CAR_H

#include <string.h>
#include <iostream>
struct Car {

	Car(const std::string& carModel);
	Car(const std::string& carModel, const std::string& carMake);

	std::string make;
	std::string model;

	bool operator==(const Car& testCar) const;
};

Car::Car(const std::string& carModel) : model(carModel) {}

Car::Car(const std::string& carModel, const std::string& carMake) : model(carModel), make(carMake) {}

bool Car::operator==(const Car& testCar) const {
	if (model == testCar.model) {
		return true;
	} else {
		return false;
	}
}

std::ostream& operator << (std::ostream& out, const Car& car) {
	out << "Make: " << car.make << ", Model: " << car.model;

	return out;
}


#endif
