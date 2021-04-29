#include <iostream>
using namespace std;

class myClass {
public:
	myClass();
	static int getVar() { return myVar;};
	static int addVar() { myVar++;};
	static int myVar;
};

myClass::myClass() {}
int myClass::myVar = 0;


int main() {

	myClass Jim;
	myClass Blue;

	cout << Jim.myVar << endl;
	Jim.addVar();
	cout << Blue.getVar() << endl;

	return 0;
}
