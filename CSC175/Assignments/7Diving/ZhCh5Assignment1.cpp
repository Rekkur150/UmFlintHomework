//Zachary Holmes
//Diving Scoring

#include <iostream>
using namespace std;

const int ARRAY_SIZE = 7;
const float MAX_SCORE = 10;
const float MIN_SCORE = 0;
const float MAX_DIFF = 3.8;
const float MIN_DIFF = 1.2;
const float FINAL_MULT = 0.6;
const int JUDGES_AMOUNT = 7;


void arrayRemoveIndex(float array[],int index, int& arraySize); // index = 0-6
int findMaxIndex(float array[], const int& arraySize);
int findMinIndex(float array[], const int& arraySize);
float sumOfArray(float array[], const int& arraySize);

int main() {

	//Varible Declaration
	float diff;
	float scores[ARRAY_SIZE] = {-1,-1,-1,-1,-1,-1,-1};
	float sum = 0;
	int arraySize = 0;

	//Input Code
	do {							//This makes sure that the input is with in range, if it isn't it asks again.
		cout << "Please input the difficulty ("<< MIN_DIFF << "-" << MAX_DIFF <<"): ";
		cin >> diff;

		if (diff >= MIN_DIFF && diff <= MAX_DIFF) {
			break;
		}

		cerr << "Not a Valid Difficulty. Try Again." << endl;

	} while (true);

	cout << "Please input the " << JUDGES_AMOUNT << " judge's scores" << endl;

	for (int i = 0; i < ARRAY_SIZE; i++) {	//Goes through each element of the array filling in the appropriate values.
		do {				//This makes sure that the input is with in range, if it isn't it asks again.
			cout << "Judge " << i + 1 << " score (" << MIN_SCORE << "-" << MAX_SCORE << "): ";
			cin >> scores[i];

			if (scores[i] >= MIN_SCORE && scores[i] <= MAX_SCORE) {
				arraySize++;
				break;
			}

			cerr << "Not a Valid Score. Try Again" << endl;
		} while (true);

	}

	//Calculations
	arrayRemoveIndex(scores, findMaxIndex(scores, arraySize), arraySize);
	arrayRemoveIndex(scores, findMinIndex(scores, arraySize), arraySize);
	sum = sumOfArray(scores, arraySize);

	sum *= diff;
	sum *= FINAL_MULT;

	//Output
	cout << "The final score is " << sum << "!!!" << endl;

	return 0;
}

void arrayRemoveIndex(float array[],int index, int& arraySize) {
	for (int i = index; i < arraySize; i++) {
		array[i] = array[i+1];
	}

	arraySize--;
}

int findMaxIndex(float array[],const int& arraySize) {
	float currentMax = 0;
	int indexOfMax = 0;
	for (int i = 0; i < arraySize; i++) {
		if (array[i] > currentMax) {
			currentMax = array[i];
			indexOfMax = i;
		}
	}

	return indexOfMax;
}

int findMinIndex(float array[],const int& arraySize) {
	float currentMin = MAX_SCORE + 1;
	int indexOfMin = 0;
	for (int i = 0; i < arraySize; i++) {
		if (array[i] < currentMin) {
			currentMin = array[i];
			indexOfMin = i;
		}
	}

	return indexOfMin;
}

float sumOfArray(float array[], const int& arraySize) {
	float sum = 0;
	for (int i = 0; i < arraySize; i++) {
		sum += array[i];
	}

	return sum;
}
