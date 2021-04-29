// Zachary Holmes
// Chapter 3 Assignemnt 2
// Calcuate Wind Chill Factor

#include <iostream>
#include <math.h>
using namespace std;

//Function Prototype
double calcWindChillFactor(double velocity, double temp);

//Global Variable Declaration
double maxTemp = 10;


int main() {

	//Variable Declaration
	double velocity, tempInCels, windChillFactor;

	//Output
	cout << "Fill out information below " << endl
	     << "\tVelocity in meters per second: ";
	cin >> velocity;
	cout << "\tTempature in Celsius: ";
	cin >> tempInCels;

	//Test to see if maxTemp exceeds max temp and outputs
	if (tempInCels > maxTemp) {
		cout << "Error: Above exceeds max temp" << endl;
		return 0;
	} else {
		cout << "The wind chill factor is " << calcWindChillFactor(velocity, tempInCels) << " degrees Celsius" << endl;
	}

	return 0;
}

double calcWindChillFactor(double v, double t) {
	return 33 - (((10 * sqrt(v)) - v + 10.5) * (33 - t))/23.1;
}
