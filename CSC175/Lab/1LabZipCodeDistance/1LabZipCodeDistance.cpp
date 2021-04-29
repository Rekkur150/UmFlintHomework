// Zachary Holmes
// Lab 2
// Distance between Two Zipcodes

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Global Variable Declaration
const string PATH = "zips.txt";
const double RADIOUS_OF_EARTH = 3959;
const double PI = 3.14159265359;
const char UNIT = 'M';

double toRadians(double a) {
	return a * PI/180;
}

int main() {

	//Varible Declaration
	string tempZipCode;
	string zipCode0;
	string zipCode1;

	//Condition Variables
	bool zip0 = false;
	bool zip1 = false;

	//Data Variables
	double templng, templat;
	double lng0, lat0, lng1, lat1, deltalng, deltalat;

	//Temp Varibles For Calculations
	double a = 0;
	double b = 0;
	double distance = 0;

	//Input
	cout << "Please input two zipcodes" << endl
	     << "Zip Code From: ";
	cin >> zipCode0;
	cout << "Zip Code To: ";
	cin >> zipCode1;


	//Retreive Data from file.
	fstream inputFile;

	inputFile.open(PATH);

	while (inputFile >> tempZipCode >> templng >> templat) {

		if (tempZipCode == zipCode0) {
			lng0 = templng;
			lat0 = templat;
			zip0 = true;
		}

		if (tempZipCode == zipCode1) {
			lng1 = templng;
			lat1 = templat;
			zip1 = true;
		}

		if (zip0 && zip1) {
			break;
		}

		if (zipCode0 == zipCode1) {
			cout << "The distance between the two zip codes is: 0" << UNIT << endl;
			return 0;
		}

	}

	inputFile.close();

	if (!zip0 || !zip1) {
		cout << "One of the zip codes couldn't be found, ending program" << endl;
		return 0;
	}

	//Calculations
	lng0 = toRadians(lng0);
	lat0 = toRadians(lat0);
	lng1 = toRadians(lng1);
	lat1 = toRadians(lat1);

	deltalng = (lng0-lng1);
	deltalat = (lat0-lat1);

	a = (sin(deltalat/2) * sin(deltalat/2)) +
	    (cos(lat0) * cos(lat1) *
	    sin(deltalng/2) * sin(deltalng/2));

	b = 2 * (atan2(sqrt(a), sqrt(1-a)));

	distance = (RADIOUS_OF_EARTH * b);

	string prefix = " Miles";

	//Output
	switch(UNIT) {
		case 'K':
			distance = distance * 1/0.6213712;
			prefix = "Km";
			break;
		case 'E':
			distance = distance * 1/0.0006213712;
			prefix = " M";
			break;
		case 'M':
			prefix = " Miles";
			distance = distance;
			break;
		default:
			distance = distance;
	}

	cout << "The Distance between the two zip codes is: " << distance << prefix << endl;

	return 0;
}
