#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
	Shape();
	Shape(int newHeight, int newWidth);

	virtual int getArea() = 0;
	int callArea();
	int getHeight();
	int getWidth();
protected:
	int height = 0;
	int width = 0;
private:
	virtual int jimmy() = 0;
};

#endif
