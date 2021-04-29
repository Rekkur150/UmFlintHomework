#include <iostream>
#include "Person.h"
#include "Student.h"
#include "GradStudent.h"
#include "Employee.h"

using namespace std;

int main()
{
    Person matt("Matt", "Spradling", 2, 20, 1983);
    cout << matt.getName() << " born on: " << matt.getBirthdate() << endl;

	Student jim("Jimmy","John", 1,2,1920);
	jim.setCredits(50);
	cout << jim.getName() << " has " << jim.getCredits() << " credits, additionally, his birthday is " << jim.getBirthdate() << ".   Just so you know...." << endl;

	GradStudent bob("Bob","JOHNNY", 312,12,193120);
	bob.setCredits(50);
	bob.updateGradStatus();
	cout << bob.getName() << " graduation status is " << bob.canGraduate() << "! Additionally, his birthday is " << bob.getBirthdate() << ".   Just so you know...." << endl;

	Employee tim("Little","Timmy", 1,1,2012);
	tim.setPayRate(-10);
	cout << "Employee " << tim.getName() << " pay rate is " << tim.getPayRate() << " dollars an hour! (We make some money off of Little Timmy) Additionally, his birthday is " << tim.getBirthdate() << endl;



    return 0;
}

