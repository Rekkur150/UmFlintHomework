// Zachary Holmes
// Csc 175
// In Class Lab

#include <iostream>
using namespace std;

//Global Variable Declaration
const int NUMBER_OF_SECONDS_IN_A_MINUTE = 60;
const int NUMBER_OF_SECONDS_IN_A_HOUR = 3600;
const int NUMBER_OF_SECONDS_IN_A_DAY = 86400;

int main() {

	//Variable Declaration
	int numberOfSeconds = 0;
	int numberOfMinutes = 0;
	int numberOfHours = 0;
	int numberOfDays = 0;

	//Input
	cout << "Please input amount of time in seconds: ";
	cin >> numberOfSeconds;

	//Calculations
	numberOfDays = numberOfSeconds/NUMBER_OF_SECONDS_IN_A_DAY;
	numberOfSeconds = numberOfSeconds - (numberOfDays * NUMBER_OF_SECONDS_IN_A_DAY);

	numberOfHours = numberOfSeconds/NUMBER_OF_SECONDS_IN_A_HOUR;
	numberOfSeconds = numberOfSeconds - (numberOfHours * NUMBER_OF_SECONDS_IN_A_HOUR);
						// ^ Taking advantage of numberOfHours being an int

	numberOfMinutes = numberOfSeconds/NUMBER_OF_SECONDS_IN_A_MINUTE;
	numberOfSeconds = numberOfSeconds - (numberOfMinutes * NUMBER_OF_SECONDS_IN_A_MINUTE);
						// ^ Taking advantage of numberOfMinutes being an int

	//Output
	cout << "-----------------------------------------" << endl
	     << "To put it in more human readable terms" << endl
	     << numberOfDays << " Days, "
	     << numberOfHours << " Hours, " << numberOfMinutes << " Minutes, and " << numberOfSeconds << " Seconds" << endl;

	return 0;
}
