#include <iostream>
#include "Node.h"
#include "LinkList.h"

int main() {

	LinkList<int> linkTest;
	linkTest.append(2);
	linkTest.append(3);
	linkTest.append(4);
	linkTest.prepend(1);

	std::cout << "linkTest[1] = " << linkTest.getData(1) << std::endl;
	linkTest.remove(1);
	std::cout << "linkTest[1] = " << linkTest.getData(1) << std::endl;

	Node<int> *a = new Node<int>(5);
	a->next = new Node<int>(6);

	std::cout << "a = " << a->data << std::endl;
	std::cout << "a = " << a->next->data << std::endl;


	return 0;
}
