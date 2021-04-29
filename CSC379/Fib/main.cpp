#include <iostream>

int fib(int n) {

	int p1 = 0;
	int p2 = 1;
	int temp;

	if (n < 1) {
		return p1;
	} else if (n == 1) {
		return p2;
	}

	for (int i = 2; i <= n; i++) {
		temp = p1 + p2;
		p1 = p2;
		p2 = temp;
	}

	return p2;
}

int main() {

	std::cout << fib(6) << std::endl;

	return 1;
}
