#include <iostream>

int smallestProduct(int *a, int length) {
	int numNeg = 0;
	int maxNeg = -100000000;
	int numZero = 0;
	int minPos = 100000000;
	int product = 1;
	for (int i = 0; i < length; i++) {
		if (a[i] == 0) {
			numZero++;
			continue;
		} else if(a[i] < 0) {
			numNeg++;
			maxNeg = std::max(maxNeg, a[i]);
		} else {
			minPos = std::min(minPos, a[i]);
		}

		product = product * a[i];

	}

	if (numNeg == 0) {
		if (numZero != 0) {
			return 0;
		} else {
			return minPos;
		}
	}

	if (numNeg % 2 == 0) {
		product = product/maxNeg;
	}

	return product;


}





int main() {
	int length = 5;
	int numbers[length] = {0,0,0,0,0};

	std::cout << "Number: " << smallestProduct(numbers,length) << std::endl;

	return 0;
}
