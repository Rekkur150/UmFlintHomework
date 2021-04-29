#include "Employee.h"
#include <string>

Employee::Employee(std::string first, std::string last, int month, int day , int year) : Person(first,last,month,day,year) {}

int Employee::getPayRate() {
	return payRate;
}

void Employee::setPayRate(int newPayRate) {
	payRate = newPayRate;
}
