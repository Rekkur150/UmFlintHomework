#include <iostream>
using namespace std;

class my_object {
public:
	int apples;
};

int main() {

	my_object my_struct{5};
	cout << my_struct.apples;
	return 0;
}
