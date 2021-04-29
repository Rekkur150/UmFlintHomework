#include "GradStudent.h"
#include <string>

GradStudent::GradStudent(std::string first, std::string last, int month, int day , int year) : Student(first,last,month,day,year) {}

bool GradStudent::canGraduate() {
	return canGrad;
}

void GradStudent::updateGradStatus() {
	if (getCredits() > 30) {
		canGrad = true;
	} else {
		canGrad = false;
	}
}
