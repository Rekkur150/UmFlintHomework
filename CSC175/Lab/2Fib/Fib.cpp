#include <iostream>
using namespace std;

int findFib(int position);

int main() {

	int position;

	cout << "What position in the fibonacci sequence: ";
	cin >> position;

	cout << "The number is " << findFib(position) << endl;

	return 0;
}

int findFib(int position) {
	if (position == 1) {
		return 1;
	} else if (position < 1) {
		return 0;
	}

	return findFib(position-1) + findFib(position-2);
}
