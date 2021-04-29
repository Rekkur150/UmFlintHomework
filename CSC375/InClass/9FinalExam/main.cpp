#include <iostream>

class point {
public:
	point();
	point& operator = (const point& a);
	int getX() const {return *x;}
	int getY() const {return *y;}

	friend std::ostream& operator << (std::ostream& out, const point& a);

private:

	int *x;
	int *y;
};

point::point(): x(new int(1)), y(new int(2)) {}

point& point::operator = (const point& a) {
	if (this != &a) {
		*x = a.getX();
		*y = a.getY();
	}

	return *this;
}

std::ostream& operator << (std::ostream& out, const point& a) {
	out << a.*x << std::endl;
	return out;
}



int main() {

	return 1;
}
