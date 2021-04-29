#include <iostream>
#include <cstdlib>

using namespace std;

const int RANGE = 100;
const int PROBABILITY_GREATOR = 75;
const string GREATOR = "Heads";
const string LESS = "Tails";

int main() {

	int heads = 0;
	int tails = 0;
	int count = 0;

	int randNum;

	srand(time(NULL));

	do {
		randNum = rand() % RANGE;
		if (randNum > PROBABILITY_GREATOR-1) {
			//cout << GREATOR << endl;
			heads++;
		} else if (randNum <= PROBABILITY_GREATOR-1) {
			//cout << LESS << endl;
			tails++;
		}
		count++;
	} while (count <= 100000);

	cout << "Heads: " << heads << endl
	     << "Tails: " << tails << endl;

	return 0;
}
