#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person {

	public:
	Employee(std::string first, std::string last, int month, int day, int year);
	int getPayRate();
	void setPayRate(int amount);


	private:
	int payRate = 0;

};


#endif
