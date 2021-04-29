// Zachary Holmes
// CSC 375
// Chapter 1, Assignment 1

#include "Road.h"

//Purpose: Default Constructor
//Preconditions: None
//Postconditions: None
Road::Road() {};

//Purpose: Constructor to set object variables on creation
//Preconditions: Width in feet, Length in miles
//Postconditions: None
Road::Road(const float& wid, const float& len) {
	width = wid;
	length = len;
}

//Purpose: Set the width of the road
//Preconditions: New width of road in feet
//Postconditions: None
void Road::setWidth(const float& feet) {
	width = feet;
}

//Purpose: Set the Length of the Road
//Preconditions: New length of road in miles
//Postconditions: None
void Road::setLength(const float& miles) {
	length = miles;
}

//Purpose: Get the width of the road in feet
//Preconditions: None
//Postconditions: Width of road in feet
float Road::getWidth() const {
	return width;
}

//Purpose: Get the length of the road in miles
//Preconditions:None
//Postconditions: Lenght of the road in miles
float Road::getLength() const {
	return length;
}

//Purpose:Get the area of Asphalt the road needs
//Preconditions: The thickness of Asphalt in feet
//Postconditions: The cubic feet of Asphalt
float Road::Asphalt(const float& roadThickness) const {
	float lenFeet = toFeet(length);
	return lenFeet * width * roadThickness;
}

float Road::toFeet(const float& miles) const {
	return 5280 * miles;
}

