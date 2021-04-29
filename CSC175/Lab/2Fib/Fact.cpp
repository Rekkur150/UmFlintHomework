#include <iostream>

using namespace std;

long factorial(long number);

int main() {

	long facto;

	cout << "Factorial: ";
	cin >> facto;
	cout << facto << "! = " << factorial(facto) << endl;

	return 0;
}

long factorial(long n) {

	if (n == 1) {
		return 1;
	}

	return n * factorial(n-1);
}


