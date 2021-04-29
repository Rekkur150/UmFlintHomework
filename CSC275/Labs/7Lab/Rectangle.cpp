#include "Rectangle.h"

Rectangle::Rectangle() {};

Rectangle::Rectangle(int width, int height): Polygon(width,height) {};

int Rectangle::getArea() {
	return width * height;
}


