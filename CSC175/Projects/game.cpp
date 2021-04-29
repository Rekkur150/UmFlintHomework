#include <iostream>
#include <cstdlib>
using namespace std;

int const MAX = 100;
int const MIN = 1;

string validateGuess(int guess,int ran);
bool checkInputValues(int guess);

int main() {

	srand(time(NULL));

	int tries = 0;
	int userNum = 0;
	int ranNum = rand() % MAX + MIN;

	while (ranNum != 1) {
		ranNum = rand() % MAX + MIN;
	}
	cout << ranNum << endl;

	cout << "Enter Number between " << MIN-1 << "-"<< MAX + MIN << endl;
	do {

		cin >> userNum;

		if (checkInputValues(userNum)) {

		cout << validateGuess(userNum, ranNum);

		tries++;

		} else {
			cout << "Not within range try again" << endl;
		}

	} while(userNum != ranNum);

	cout << "It took you " << tries << " tries to find the correct number" << endl;

	return 0;
}

string validateGuess(int guess, int rand) {

	string output = "";

	if (guess == rand) {
		output = "Congrats\n";
	} else if ( guess < rand) {
		output = "Too low!\n";
	} else if ( guess > rand) {
		output = "Too high!\n";
	}

	return output;
}

bool checkInputValues(int guess) {
	if (guess > MAX || guess < MIN) {
		return false;
	} else {
		return true;
	}
}
