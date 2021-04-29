// Zachary Holmes
// CSC 175
// Pg 42, Project 1

#include <iostream>
using namespace std;

// Global Varibles
const float OUNCES_IN_METRIC_TON = 35273.92;

int main() {

	//Variable Declaration
	float weightOfPackageInOunce = 0;
	float weightOfPackageInTon = 0;
	int unsigned amountOfPackagesInMetricTon = 0; //Made int because you can't have a fraction of a package
						      //Made unsigned because you can't have a negitve amount of packages

	//Input
	cout << "Please input weight of a package of cereal in ounces: ";
	cin >> weightOfPackageInOunce;

	//Calculations
	weightOfPackageInTon = weightOfPackageInOunce/OUNCES_IN_METRIC_TON;
	amountOfPackagesInMetricTon = 1/weightOfPackageInTon;

	//Output
	cout << "Weight of package in metric ton: " << weightOfPackageInTon << endl
	     << "Amount of packages in a metric ton: " << amountOfPackagesInMetricTon << endl;

	return 0;
}

