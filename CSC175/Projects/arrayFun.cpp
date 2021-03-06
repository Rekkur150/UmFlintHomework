#include <iostream>
using namespace std;

const int SIZE = 5;
int STACK_INDEX = 5;

void push(int array[], int number);
void pop (int array[]);
void display(int array[]);

int main() {

	int scores[] = {1,2,3,4,5}; //This is how you initalize it.

	/*for (int i = 0; i < SIZE; i++) {
		scores[i] = 0; //If you didn't do this, the number stored in the array would be what ever was in RAM prior to making the array
		cout << "score at index " << i
		     << " or at position " << i+1 << " in the array"
		     << " = " << scores[i] << endl;
	}

	// To put the data from the user into an array
	cout << "Enter " << SIZE << " scores!" << endl;
	for (int i = 0; i < SIZE; i++) {
		cin >> scores[i];
	}

	// To output the information stored in the array backwards
	cout << "Walking the array backwards (Last position to first position)" << endl;
	for (int i = SIZE-1; i >= 0; i--) {
		cout << "score at index " << i
		     << " or at position " << i+1 << " in the array"
		     << " = " << scores[i] << endl;
	 }*/


	//ADVANCE

//	srand(time(NULL));

//	cout << "Pushing 4 random numbers on the array" << endl;

//	for (int i = 0;i < 4; i++) {
//		push(scores, rand() % 101);
//	}

	display(scores);

	cout << "Poping the array" << endl;
	pop(scores);
	display(scores);

	return 0;
}


void push(int a[], int n) {
	a[STACK_INDEX++] = n;
}

void pop(int a[]) {
	STACK_INDEX--;
}

void display(int a[]) {
	if (STACK_INDEX == 0) {
		cout << "Stack empty" << endl;
	} else {
		for (int i = 0; i < STACK_INDEX; i++) {
			cout << "score at index " << i
			     << " or at position " << i+1 << " in the array"
			     << " = " << a[i] << endl;
		}
	}
}
