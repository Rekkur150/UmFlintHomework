#include <iostream>
using namespace std;

void printZachgo(int pos) {

	int col = 120;
	int plus = 10;
	int pm = 12;

	if (!pos) {
		pos = 0;
	}

	for (int i = 0; i < col; i++) {
		if (i >= pos-pm && i <= pos+pm) {
			cout << "@";
		} else {
			cout << "#";
		}
	}

	cout << endl;

	if (pos < col) {
		printZachgo(pos + plus);
	}
}

int main() {

	printZachgo(0);

	return 0;
}
