#include <iostream>
#include "BinaryTree.h"

int main() {
	BinaryTree<int> a;

	a.push(5);
	a.push(10);
	a.push(7);
	a.push(15);
	a.push(3);
	a.push(2);
	a.push(4);

	a.printTree();

	a.deleteTree();

	a.printTree();

	return 0;
}
