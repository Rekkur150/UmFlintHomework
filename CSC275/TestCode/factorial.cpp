#include <iostream>

using namespace std;

int factorial(int n);

int main() {

	cout << factorial(10) << endl;

	return 0;
}

int factorial(int n) {
	if (n < 0) {
		cout << "Nope";
	} else if (n == 1) {
		return 1;
	}

	return factorial(n-1)*n;


}
