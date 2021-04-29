#include "Student.h"
#include <string>

Student::Student() {}

Student::Student(std::string first, std::string last, int month, int day , int year) : Person(first,last,month,day,year) {}

int Student::getCredits() {
	return creditHours;
}

void Student::setCredits(int setAmount) {
	creditHours = setAmount;
}
