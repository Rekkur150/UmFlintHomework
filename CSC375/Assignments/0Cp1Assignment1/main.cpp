// Zachary Holmes
// CSC 375
// Chapter 1, Assignment 1

//For the Questions relating to problem 10 on page 70.
// I have also added const modifiers to various functions and various reference parameters.
// I have added the contructors which take in the width and length and sets on construction of the object.
// For why I shouldn't remove the set functions it is because I would have to waste resources in creating a whole
// other object when I needed to change the width or the length.



#include <iostream>
#include "RoadDriver.h"
int main() {

	RoadDriver a; 			//Create Driver Object
	a.TestRoad();

	return 0;
}
