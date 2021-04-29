// Zachary Holmes
// Assignment 5
// Miles Per Gallon using functions

#include <iostream>
using namespace std;

//Global Declaration
double GALLONS_PER_LITER = 0.264179;

//Function Declaration
double litersToGallons(double liters);
double milesPerGallon(double miles, double gallons);

int main() {

	//Varible Declaration
	double milesTraveled = 0;
	double litersConsumed = 0;
	char con;

		//The following output is joke satirizing the United States use of a terrible measuring system.

	cout << "If you are not in the US or using the metric system, such that you have no idea how to convert to gallons from liters," << endl
	     << "and for some reason you need to calculate what your miles per gallon is!" << endl
	     << "Then this is the program for you!" << endl
	     << "Simply follow the directions below!"<< endl << endl;

	do {

		//Input
		cout << "Please input your " << endl
		     << "\tLiters of gasoline consumed: ";
		cin >> litersConsumed;

		cout << "\tMiles Traveled: ";
		cin >> milesTraveled;

		//Output
		cout << "Miles per gallon delivered: " << milesPerGallon(milesTraveled, litersToGallons(litersConsumed)) << endl << endl;

		//Repeat calculations
		cout << "Would you like to calculate more miles per gallon? (y/n) ";
		cin >> con;
		cout << "-----------------------------------------------------------------" << endl;

	} while (con == 'y' || con == 'Y');

	// Goodbye message
	cout << "Goodbye!" << endl;
}

double litersToGallons(double liters) {
	return liters * GALLONS_PER_LITER;
}

double milesPerGallon(double miles, double gallons) {
	return miles/gallons;
}
