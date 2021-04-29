#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int>* a = new vector<int>;
	a->push_back(3);
	a->push_back(4);

	cout << a->operator[](1) << endl;
	cout << (*a)[1] << endl;

	return 0;
}
