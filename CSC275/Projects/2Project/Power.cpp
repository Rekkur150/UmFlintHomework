#include "Power.h"
#include <iostream> //cout, endl
#include <string> //string
#include <stdlib.h> //srand, rand, time

bool Power::firstPowerObject = true;

//Purpose: Default constructor
//Preconditions: None
//Postconditions: None
Power::Power() {}

//Purpose: Constructor that makes a valid power
//Preconditions: Name of the power, pp cost of the power, damage of the power, type of power, and accuracy of power.
//Postconditions: None
Power::Power(std::string myname, int mypp, int mydmg, std::string mytype, int myacc) {
	powername = myname;
	pp = mypp;
	basedmg = mydmg;
	powertype = mytype;
	accuracy = myacc;
	isValid = true;

	if (firstPowerObject) {	//Sets the RNG seed if this power is the first object called.
		srand(time(NULL));
		firstPowerObject = false;
	}

}

//Purpose: To get the name of power
//Preconditions: None
//Postconditions: Name of the power, or an empty string if the object isn't valid
std::string Power::GetName() const {
	if (isValid) {
		return powername;
	} else {
		std::cout << "Power is not defined" << std::endl;
		return "";
	}
}

//Purpose: Get the pp cost of the power
//Preconditions: None
//Postconditions: The pp cost, or 0 if the object isn't valid
int Power::GetPP() const {
	if (!isValid) {
		std::cout << "Power is not defined" << std::endl;
		return 0;
	}

	return pp;

}

//Purpose: Calculate the damage done
//Preconditions: The type of the user, the target's type , and the users level
//Postconditions: The damage done
int Power::calcDamage(std::string userType, std::string targetType, int userLvl) const {
	if (!isValid) {
		std::cout << "Power is not defined" << std::endl;
		return 0;
	}

	int randNum = (rand() % userLvl) + 1;
	int damage = basedmg * userLvl + randNum;

	if (powertype == userType) {
		damage *= 2;
	} //Didn't put in an else if, for the case where both userType and targetType are the same.

	if (powertype == targetType) {
		damage /= 2;
	}

	return damage;
}

//Purpose: To see if the object is valid
//Preconditions: None
//Postconditions: True if object is valid, false if object is false.
bool Power::GetIsValid() const {
	return isValid;
}
