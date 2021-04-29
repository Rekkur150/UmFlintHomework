#include "Triangle.h"

Triangle::Triangle() {};

Triangle::Triangle(int newWidth, int newHeight):Polygon(newWidth,newHeight) {}

int Triangle::getArea() {
	return width * height / 2;
}
