
// Zachary Holmes
// Chapter 5 Assignment 2

#include <iostream>
#include <fstream>
using namespace std;

// Function Prototypes
char* deleteRepeats(char array[], int& size);
bool searchArray(char searchChar, const char array[], const int& size);
void pushArray(char data, char array[], int& size);
void printArray(const char array[], const int& size);
int getSize(const char array[]);

// Global Variables
const string PATH = "lorem-ipsum_long.txt";

int main() {

	// Variable Declarations
	int size = 0;
	int deletedCharArraySize;
	char a[65000];
	char *deletedCharArray;
	char c;

	// Out
	cout << "Deleting repeat characters in " << PATH << "..." << endl;

	// Read file
	ifstream myFile;
	myFile.open(PATH);

	while(myFile.get(c)) {
		a[size++] = c;
	}

	myFile.close();

	// Process array
	deletedCharArray = deleteRepeats(a, size);
	deletedCharArraySize = getSize(deletedCharArray);

	// Print array with deleted duplicate characters.
	printArray(deletedCharArray, deletedCharArraySize);

	return 0;
}

char* deleteRepeats(char array[], int& size) {
	char *temp = new char[256];
	int tempSize = 0;

	for (int i = 0; i < size; i++) {
		if (!searchArray(array[i], temp, tempSize)) {
			pushArray(array[i], temp, tempSize);
		}
	}

	return temp;
}

void printArray(const char array[], const int& size) {
	for (int i = 0; i < size; i++) {
		cout << array[i];
	}
	cout << endl;
}

void pushArray(char data, char array[], int& size) {
	array[size++] = data;
}

bool searchArray(char searchChar, const char array[], const int& size) {
	for (int i = 0; i < size; i++) {
		if (array[i] == searchChar) {
			return true;
		}
	}

	return false;
}

int getSize(const char array[]) {
	int i = 0;
	while (array[i] != '\0') {
		i++;
	}

	return i;
}
