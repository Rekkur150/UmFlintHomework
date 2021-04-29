#include <iostream>
#include <cstdlib>
#include "BinaryTree.h"

using namespace std;

int main() {

	/*BinaryTree<int> intBTree;


	srand(time(NULL));

	cout << endl << "Randomly inputting numbers" << endl;
	int temp = rand() % 10;
	for (int i = 0; i < 10; i++) {

		while (intBTree.search(temp)) {
			temp = rand() % 10;
		}

		cout << "Putting " << temp << " into binary tree" << endl;
		intBTree.insert(temp);
	}

	cout << endl << "Printing Tree" << endl;
	intBTree.printTree();

	cout << endl << "Deleting 5" << endl;

	intBTree.tdelete(5);

	cout << endl << "Printing Tree" << endl;
	intBTree.printTree();*/


	BinaryTree<int> intBTree;
	BinaryTree<double> doubleBTree;
	BinaryTree<string> stringBTree;

	double doubleTrouble[11] = {0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1};
	string stringArray[11] = {"Apature Science", "Black Mesa", "Portal 3?", "Half Life 3", "Portal 2?", "Still Alive", "Valve", "Team Fortress 2", "Project 3", "Where is my pokemon project?", "Grumble Grumble"};

	srand(time(NULL));

	//Testing Interger Binary Tree

	cout << endl << "------------------------------" << endl;
	cout << "Testing Integer Binary Tree" << endl;

	//Puting random Interget Into Tree

	cout << endl << "Randomly inputting numbers" << endl;
	int temp = rand() % 10;
	for (int i = 0; i < 10; i++) {

		while (intBTree.search(temp)) {
			temp = rand() % 10;
		}

		cout << "Putting " << temp << " into binary tree" << endl;
		intBTree.insert(temp);
	}

	//Testing Print Tree

	cout << endl << "Printing Tree" << endl;
	intBTree.printTree();

	//Testing Integer Search

	cout << endl << "Testing search function... " << endl;
	for (int i = 0; i < 11; i++) {
		cout << "Is there a " << i << "? " << intBTree.search(i);
		if (i != 10) {
			cout << endl;
		} else {
			cout << "   <- Is supposed to return false" << endl;
		}
	}

	//Testing Integer Delete Tree

	cout << endl << "Deleting tree..." << endl << endl;
	intBTree.delete_tree();

	//Checking for Integer Deletion Complete

	cout << "Checking Deletion of the tree" << endl << endl;
	for (int i = 0; i < 11; i++) {
		cout << "Is there a " << i << "? " << intBTree.search(i);
		if (i != 10) {
			cout << endl;
		} else {
			cout << "   <- Is supposed to return false" << endl;
		}
	}

	//Testing Double Binary Tree

	cout << endl << "------------------------------" << endl;
	cout << "Testing Double Binary Tree" << endl;

	//Inputing Doubles into Binary Tree

	cout << endl << "Randomly inputting numbers" << endl;
	for (int i = 0; i < 10; i++) {

		while (doubleBTree.search(doubleTrouble[temp])) {
			temp = rand() % 10;
		}

		cout << "Putting " << doubleTrouble[temp] << " into binary tree" << endl;
		doubleBTree.insert(doubleTrouble[temp]);
	}

	//Testing Print Tree

	cout << endl << "Printing Tree" << endl;
	doubleBTree.printTree();

	//Testing Double Search

	cout << endl << "Testing search function... " << endl;
	for (int i = 0; i < 11; i++) {
		cout << "Is there a " << doubleTrouble[i] << "? " << doubleBTree.search(doubleTrouble[i]);
		if (i != 10) {
			cout << endl;
		} else {
			cout << "   <- Is supposed to return false" << endl;
		}
	}

	//Testing Double Tree Deletion

	cout << endl << "Deleting tree..." << endl << endl;
	doubleBTree.delete_tree();

	//Checking Deletion of Double Tree

	cout << "Checking Deletion of the tree" << endl << endl;
	for (int i = 0; i < 11; i++) {
		cout << "Is there a " << doubleTrouble[i] << "? " << doubleBTree.search(doubleTrouble[i]);
		if (i != 10) {
			cout << endl;
		} else {
			cout << "   <- Is supposed to return false" << endl;
		}
	}


	//Testing String Binary Tree

	cout << endl << "------------------------------" << endl;
	cout << "Testing String Binary Tree" << endl;

	//Inputing Strings into Binary Tree

	cout << endl << "Randomly inputting strings" << endl;
	for (int i = 0; i < 10; i++) {

		while (stringBTree.search(stringArray[temp])) {
			temp = rand() % 10;
		}

		cout << "Putting " << stringArray[temp] << " into binary tree" << endl;
		stringBTree.insert(stringArray[temp]);
	}

	//Testing Print Tree

	cout << endl << "Printing Tree" << endl;
	stringBTree.printTree();

	//Testing String Search

	cout << endl << "Testing search function... " << endl;
	for (int i = 0; i < 11; i++) {
		cout << "Is there a " << stringArray[i] << "? " << stringBTree.search(stringArray[i]);
		if (i != 10) {
			cout << endl;
		} else {
			cout << "   <- Is supposed to return false" << endl;
		}
	}

	//Testing String Tree Deletion

	cout << endl << "Deleting tree..." << endl << endl;
	stringBTree.delete_tree();

	//Checking Deletion of String Tree

	cout << "Checking Deletion of the tree" << endl << endl;
	for (int i = 0; i < 11; i++) {
		cout << "Is there a " << stringArray[i] << "? " << stringBTree.search(stringArray[i]);
		if (i != 10) {
			cout << endl;
		} else {
			cout << "   <- Is supposed to return false" << endl;
		}
	}

	return 0;
}
