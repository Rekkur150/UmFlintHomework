#include <iostream>
#include <math.h>
using namespace std;

double path(double a, double b) {
	return sqrt(pow(a,2) + pow(b,2));
}

int main() {

	char ret;
	double a,b,c, hours;

	do {
		cout << "Speed of plane 1" << endl;
		cin >> a;
		cout << "Speed of plane 2" << endl;
		cin >> b;

		cout << "How many hours? : ";
		cin >> hours;

		a *= hours;
		b *= hours;

		cout << endl << "Miles apart: " << path(a,b) << endl;

		cout << "exit ? (y/n): ";
		cin >> ret;
	} while (ret != 'y' || ret != 'Y');



	return 0;
}
