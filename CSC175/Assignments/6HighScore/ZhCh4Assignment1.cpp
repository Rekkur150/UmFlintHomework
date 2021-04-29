// Zachary Holmes
// Chapter 4 Assignment 1
// Get the high score and person from a list

#include <iostream>
#include <fstream>
using namespace std;

// Global Declaration
const string PATH = "scores.txt";

// Function Declaration
void getHighScore(string& person, int& score, string path = PATH);

int main() {
	// Variable Declaration
	string person;
	int score = 0;

	getHighScore(person, score);

	// Output
	cout << "The highscorer is " << person << " with a score of " << score << "!!" << endl;

	return 0;
}

void getHighScore(string& person, int& score, string path) {

	fstream inputFile;
	inputFile.open(path);

	string tempPerson;
	int tempScore;

	while(inputFile >> tempPerson >> tempScore) {
		if (tempScore > score) {
			score = tempScore;
			person = tempPerson;
		}
	}

	inputFile.close();
}
