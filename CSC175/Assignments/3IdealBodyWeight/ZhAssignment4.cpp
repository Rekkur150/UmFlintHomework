// Zachary Holmes
// Ideal Body Weight Estimation
// Assignment 4

#include <iostream>
#include <fstream>
using namespace std;

// Constant Global Declaration
const string PATH = "people.txt";
const int INCHES_IN_FEET = 12;
const int MIN_WEIGHT = 110;
const int MIN_HEIGHT_FEET = 5;
const int POUNDS_PER_ADDITIONAL_HEIGHT = 5;
const int ADDITONAL_HEIGHT = 1;

// Supporting Functions
int feetToInches(int feet) {
	return feet * INCHES_IN_FEET;
}

int main() {

	// Varible Declaration
	string personFirst = "";
	string personLast = "";
	string prefix = "";
	int feet = 0;
	int inches = 0;
	int pounds = 0;

	fstream inputFile;
	inputFile.open(PATH);

	// Output
	cout << "Estimated Ideal Body Weight for people in " << PATH << endl;

	while (inputFile >> personFirst >> personLast >> feet >> inches) {

		pounds = MIN_WEIGHT;

		if (feet < MIN_HEIGHT_FEET) {
			prefix = "<="; // Added for people that less than MIN_HEIGHT
		} else {
			feet -= MIN_HEIGHT_FEET; //Removes feet to calcuate additonal height
			inches += feetToInches(feet); //Convertes the left over feet into inches.
			int temp = inches/ADDITONAL_HEIGHT; //Determines how much additional height was added
			pounds += temp * POUNDS_PER_ADDITIONAL_HEIGHT; // Per additional height add weight
		}

		cout << personFirst << " " << personLast << endl
		     << "Ideal Body Weight: " << prefix << pounds << endl
		     << "------------------------------------" << endl;

	}

	inputFile.close();

	return 0;
}
