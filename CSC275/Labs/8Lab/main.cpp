#include <iostream>
#include <string>
#include "MyList.h"

using namespace std;

int main()
{
	MyList<int> myContent;
	char moreContent;
	int data;

	cout << "Here is the content: " << endl << myContent;

	for (int i = 0; i < 5; i++) {
		cout << "Please enter a int: ";
		cin >> myContent;
	}

	cout << "Here is the content: " << endl << myContent;

	cout << "Insertion Sort..." << endl;
	myContent.insertionSort();

	cout << "Here is the content: " << endl << myContent;

	cout << "Reversing data.. " << endl;
	myContent.reverseList();

	cout << "Here is the content: " << endl << myContent;

	cout << "Any data that you want to remove? :  ";
	cin >> moreContent;
	while(moreContent == 'y' || moreContent == 'Y'){
		cout << "Give me another piece of data to remove: ";
		cin >> data;
		if(!myContent.removeContent(data)){
			cout << "No such content in list" << endl;
		}

		cout << "Here's the content we have left: " << endl;
		cout << myContent;
		cout << "Get another data? :  ";
		cin >> moreContent;
	}

	if (myContent.isEmpty()) {
		cout << "No content left! " << endl;
	} else {
		cout << "Here's who we have left: " << endl;
		cout << myContent;
	}


	cout << endl << "Goodbye!" << endl;
	return 0;
}
