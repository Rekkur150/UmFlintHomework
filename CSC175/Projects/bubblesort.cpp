#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 5;

void display(const int arry[]);
void bubbleSort(int arr[]);

int main() {

	srand(time(NULL));

	int array[SIZE];

	for (int i = 0; i < SIZE; i++) {
		array[i] = rand()%1000+1;
	}

	cout << "Before" << endl;
	display(array);
	bubbleSort(array);
	cout << "After" << endl;
	display(array);

	return 0;
}

void display(const int arr[]) {
	for (int i = 0; i < SIZE; i++) {
		cout << "Index: " << i << " = " << arr[i] << endl;
	}
}

void bubbleSort(int arr[]) {
	bool swapped;
	do {
		swapped = false;
		for (int i = 0; i < SIZE-1; i++) {
			if (arr[i] > arr[i+1]) {
				int t = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = t;
				swapped = true;
			}
		}
	} while (swapped);

}
