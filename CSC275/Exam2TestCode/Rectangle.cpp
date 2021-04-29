#include "Rectangle.h"

Rectangle::Rectangle() {}

Rectangle::Rectangle(int newWidth, int newHeight) {
	width = newWidth;
	height = newHeight;
}

int Rectangle::getArea() {
	return width * height;
}

int Rectangle::jimmy() {
	return 101;
}
