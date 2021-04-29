#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>

class Student : public Person {

	public:
	Student();
	Student(std::string first, std::string last, int month, int day, int year);

	int getCredits();
	void setCredits(int setAmount);

	private:
	int creditHours = 0;

};

#endif
