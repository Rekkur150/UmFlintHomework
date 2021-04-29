#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape {
public:
	Rectangle();
	Rectangle(int newWidth, int newHeight);

	virtual int getArea() override;
	int cheese();
private:
	virtual int jimmy() override;
};

#endif
