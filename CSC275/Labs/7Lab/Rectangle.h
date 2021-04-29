#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygon.h"

class Rectangle : public Polygon {
public:
	Rectangle();
	Rectangle(int width, int height);
	virtual int getArea() override;
};

#endif
