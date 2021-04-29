#include <iostream>
#include "Pokemon.h"
using std::cout;
using std::endl;

int main() {

	Pokemon dave;
	cout << dave.getHealth() << endl;
	dave.setHealth(10);
	cout << dave.getHealth() << endl;
	dave.pint[0] = 0;
	dave.pint[1] = 101;
	cout << dave.pint[0+1] << endl;

	return 0;
}
