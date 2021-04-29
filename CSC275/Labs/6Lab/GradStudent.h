#ifndef GRADSTUDENT_H
#define GRADSTUDENT_H

#include "Student.h"
#include <string>

class GradStudent : public Student {
	public:
	GradStudent(std::string first, std::string last, int month, int day, int year);
	bool canGraduate();
	void updateGradStatus();

	private:
	int canGrad = false;
};

#endif
