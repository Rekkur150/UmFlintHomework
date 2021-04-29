#include <iostream>
using namespace std;

struct bob {
	int id;
};

int main() {

	bob *p = new bob;
	*p->id = 10;


	delete p;

	return 0;
}
