// Zachary Holmes
// Chapter 2 Assignment 1
// 10/1/18

#ifndef RECTANGLE_H
#define RECTANGLE_H

//Please note, class T has to have a method for being able to be multiplied by an integer.

template <class T>
class Rectangle {
public:

	//Constructors
	Rectangle();
	Rectangle(const T& width, const T& length);

	//Mutator Functions
	void setLength(const T& length);
	void setWidth(const T& width);

	//Accessor Functions
	bool isLengthGreaterThanWidth() const;
	T getArea() const;
	T getPerimeter() const;

private:
	T length = 0; //Length of the Rectangle
	T width = 0; //Width of the Rectangle

};


//Purpose: Default Constructor
//Preconditions: None
//Postconditions: None
template <class T>
Rectangle<T>::Rectangle() {}

//Purpose: Constuctor that sets length and width
//Precondtions: Width and length
//Postconditions: None
template <class T>
Rectangle<T>::Rectangle(const T& newWidth, const T& newLength) : width(newWidth), length(newLength) {}

//Purpose: Set the length
//Preconditions: Length
//Postconditions: None
template <class T>
void Rectangle<T>::setLength(const T& newLength) {
	length = newLength;
}

//Purpose: Set the width
//Preconditions: Width
//Postconditions: None
template <class T>
void Rectangle<T>::setWidth(const T& newWidth) {
	width = newWidth;
}

//Purpose: To check if the length is greater than the width
//Preconditions: None
//Postconditions: True if length is greater than width, false is width is greater or equal to length
template <class T>
bool Rectangle<T>::isLengthGreaterThanWidth() const {
	if (length > width) {
		return true;
	} else {
		return false;
	}
}

//Purpose: To get the area of the rectangle
//Preconditions: None
//Postconditions: The area of the rectangle
template <class T>
T Rectangle<T>::getArea() const {
	return length * width;
}

//Purpose: To get the perimeter of the rectangle
//Preconditions: None
//Postconditions: Perimeter of the rectangle
template <class T>
T Rectangle<T>::getPerimeter() const {
	return ((length * 2) + (width * 2));
}

#endif

