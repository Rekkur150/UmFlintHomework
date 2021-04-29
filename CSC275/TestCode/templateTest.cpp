#include <iostream>

using namespace std;

template <classT>
T maxium(const T& A, const T& B);

int main() {

	int a,c;
	float b;
	a = 5;
	b = 10.5;

	c = maxium(a,b);

	cout << c << endl;

	return 0;
}

template <class T>
T maxium(const T& A, const T& B) {
	if (A > B) {
		return A;
	} else {
		return B;
	}
}

