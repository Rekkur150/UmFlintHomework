#include <iostream>

const int t = 7;

void goldSplit(int *a, int *b, int *n) {
	int sum = 0;
	int i = 0;
	int j = 0;
	for (int i = 0; i < t; i++) {
		sum += n[i];
	}

	if (sum % 2 == 1) {
		sum++;
	}

	sum = sum/2;

	std::cout << "Sum = " << sum << std::endl;

	int values[t+1][sum+1];

	for (i = 0; i <= t; i++) {
		for (j = 0; j <= sum; j++) {
			if (j == 0 || i == 0) {
				values[i][j] = 0;
			} else if (n[i-1] <= j) {
				values[i][j] = std::max(n[i-1] + values[i-1][j-n[i-1]], values[i-1][j]);
			} else {
				values[i][j] = values[i-1][j];
			}
		}
	}

	int test = values[t][sum];
	int start = 0;

	for (int i = t; i > 0; i--) {
		if (values[i][sum] > values[i-1][sum]) {
			start = i;
			break;
		}
	}

	int ap = 0;
	int bp = 0;

	for (int d = (t-1); d >= 0; d--) {
		if (n[d] <= test) {
			a[ap] = n[d];
			ap++;
			test = test - n[d];
		} else {
			b[bp] = n[d];
			bp++;
		}
	}


}


int main() {
	int a[t];
	int b[t];
	int n[t] = {5,6,7,10,15,17,19};

	for (int i = 0; i < t; i++) {
		a[i] = 0;
		b[i] = 0;
	}

	goldSplit(a,b,n);


	int total = 0;

	std::cout << "a = ";
	for (int i = 0; i < t; i++) {
		std::cout << a[i] << " ";
		total += a[i];
	}

	std::cout << std::endl;
	std::cout << "a total = " << total << std::endl;

	std::cout << "b = ";
	total = 0;
	for (int i = 0; i < t; i++) {
		std::cout << b[i] << " ";
		total += b[i];
	}
	std::cout << std::endl;
	std::cout << "b total = " << total << std::endl;

	return 0;
}
