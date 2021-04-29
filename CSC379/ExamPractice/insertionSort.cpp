#include <iostream>
#include <math.h>

void insertionSort(int *array, int length) {
	int temp;
	int j;


	for (int i = 0; i < length; i++) {	//O(length)
		j = i;				//O(length)
		while(array[j] < array[j-1] && j != 0) {	//Summation of j = 0 to length of j
			temp = array[j];
			array[j] = array[j-1];
			array[j-1] = temp;
			j--;
		}
	}
}

void mergesort(int *array,int length) {
	if (length > 1) {
		int div = floor(length/2);
		std::cout << "DIV = " << div << ", Length-div = " << length-div << ", length = " << length << std::endl;
		int arr1[div];
		int arr2[length-div];
		for(int i = 0; i < div;i++) {
			arr1[i] = array[i];
		}

		for(int i = 0; i < length-div;i++) {
			arr2[i] = array[i+div];
		}

		mergesort(arr1,div);
		mergesort(arr2,length-div);

		int a1 = 0;
		int a2 = 0;

		for (int i = 0; i < length; i++) {
			if (arr1[a1] < arr2[a2] && a1 < div) {
				array[i] = arr1[a1];
				a1++;
			} else if (arr1[a1] > arr2[a2] && a2 < length-div) {
				array[i] = arr2[a2];
				a2++;
			} else if (arr1[a1] == arr2[a2]) {
				array[i] = arr2[a2];
				a2++;
			}
		}

		std::cout << "array[";
		for (int i = 0; i < length; i++) {
			std::cout << ", " << array[i];
		}

		std::cout << std::endl;

	}


}

void printArray(int *array, int length) {
	for (int i = 0; i < length; i++) {
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	}
}


int main() {

	int array[8];
	srand(time(NULL));

	for (int i = 0; i < 8; i++) {
		array[i] = rand()%100;
	}

	printArray(array,8);
	mergesort(array,8);
//	insertionSort(array,8);
	printArray(array,8);

	return 0;
}
