#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygon.h"

class Triangle : public Polygon {

public:
	Triangle();
	Triangle(int newWidth, int newHeight);
	virtual int getArea() override;

};

#endif
