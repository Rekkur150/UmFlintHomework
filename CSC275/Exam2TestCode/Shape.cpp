#include "Shape.h"

Shape::Shape() {};

Shape::Shape(int newHeight, int newWidth) {
	height = newHeight;
	width = newWidth;
}

/*int Shape::getArea() {
	return width * height * 5;
}*/

int Shape::callArea() {
	return getArea();
}

int Shape::getHeight() {
	return height;
}

int Shape::getWidth() {
	return width;
}
