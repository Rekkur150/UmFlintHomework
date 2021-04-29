#include <iostream>
using namespace std;


class Engine {
private:
	int numberOfCylinders;
	int cubicInches;

public:
	Engine();
	Engine(int numberOfCylindersIn, int cubicInchesIn);

	int getHorsepower();
	void display();
};

Engine::Engine() {
	numberOfCylinders = 0;
	cubicInches = 0;
}
	//:: is the scope resolution operator
Engine::Engine(int numberOfCylindersIn, int cubicInchesIn) {
	numberOfCylinders = numberOfCylindersIn;
	cubicInches = cubicInchesIn;
}

int Engine::getHorsepower() {
	return numberOfCylinders * cubicInches;
}

void Engine::display() {
	cout << "Cylinders = " << numberOfCylinders << endl
	     << "Cubic Inches = " << cubicInches << endl
	     << "Horse Power = " << getHorsepower() << endl;
}

class Car {

private:

	string make;
	string model;
	int year;
	Engine motor;

public:

	Car(string makeIn,string modelIn,int yearIn, Engine &motorIn);
	
	string getMake();
	string getModel();
	int getYear();
	void display();
};

Car::Car(string makeIn, string modelIn, int yearIn, Engine &motorIn) {
	make = makeIn;
	model = modelIn;
	year = yearIn;
	motor = motorIn;
}

string Car::getMake() {
	return make;
}

string Car::getModel() {
	return model;
}

int Car::getYear() {
	return year;
}

void Car::display() {
	cout << "Make = " << make << endl
	     <<"Model = " << model << endl
	     <<"Year = " << year << endl;
	motor.display();
}


int main() {

	Engine motor(8,350);
	Car jack("Chevy","s10",2000, motor);
	jack.display();

	return 0;
}

