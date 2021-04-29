#include <iostream>

//EXTRA CREDIT
// The delete in the copy constructor would cause a runtime error because there was nothing initalized in the pointers to delete.


class Vessel {
public:
	Vessel();
	Vessel(std::string in, int len, int wid);
	Vessel(const Vessel& copy);
	~Vessel();

	std::string getType() const { return *type;};
	int getLength() const { return *length;};
	int getWidth() const { return *width;};

	void setType(std::string t) { *type = t;};
	void setLength(int l) { *length = l;};
	void setWidth(int w) { *width = w;};

	Vessel& operator = (const Vessel& copy) {
		delete type;
		delete width;
		delete length;

		type = new std::string(*copy.type);
		width = new int(*copy.length);
		width = new int(*copy.width);

		return *this;
	}

private:
	std::string *type = nullptr;
	int *length = nullptr;
	int *width = nullptr;
};

Vessel::Vessel() : Vessel("", 0, 0) {}

Vessel::Vessel(std::string in, int len, int wid) {
	type = new std::string(in);
	length = new int(len);
	width = new int(wid);
}

Vessel::Vessel(const Vessel& copy) {
	type = new std::string(*copy.type);
	length = new int(*copy.length);
	width = new int(*copy.width);
}

Vessel::~Vessel() {
	delete type;
	delete length;
	delete width;
}



class Boat : public Vessel {
public:
	Boat();
	Boat(std::string in, int len, int wid);
	Boat(const Boat& copy);

private:

};

Boat::Boat() : Vessel() {};

Boat::Boat(std::string in, int len, int wid) : Vessel(in, len, wid) {}

Boat::Boat(const Boat& copy) : Vessel(copy) {};

std::ostream& operator << (std::ostream& out, const Boat& b) {
	out << b.getType() << " (" << b.getLength() << ", " << b.getWidth() << ")";

	return out;
}



int main() {

	Boat a("A1", 25, 8);
	Boat b("B1", 25, 8);

	Boat c(a);

	std::cout << c << std::endl;

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	a = b;

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	b.setLength(50);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;


	return 0;
}
