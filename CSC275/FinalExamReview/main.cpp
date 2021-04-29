#include <iostream>
#include "DoublyLinkedList.h"
#include <map>
#include <deque>
#include <vector>

using namespace std;

int main() {

	std::map<string,float> myStudents;
	std::deque<int> noob;
	std::vector<int> fjalsdj;

	DoublyLinkedList<int> intLL;

	for (int i = 0; i < 10; i++) {
		cout << "Please input int: ";
		cin >> intLL;
	}

	intLL.printDataFromHead();
	cout << "InsetionSort!" << endl;
	intLL.insertionSort();
	intLL.printDataFromHead();


	return 0;
}
