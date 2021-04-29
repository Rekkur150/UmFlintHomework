// Zachary Holmes
// CSC 375
// Chapter 1, Assignment 1

#ifndef ROAD_H
#define ROAD_H

class Road {

public:
	//Constructor
	Road();
	Road(const float& widthInFeet, const float& lengthInMiles);

	//Set Functions
	void setWidth(const float& feet);
	void setLength(const float& miles);

	//Get Functions
	float getWidth() const;
	float getLength() const;

	//Other Functions
	float Asphalt(const float& roadThickness) const; //Return Cubic Feet of Asphalt Used

private:
	//Helper Function
	float toFeet(const float& miles) const;

	//Variables
	float width = 0; //Width of Road
	float length = 0; //Length of Road
};

#endif

