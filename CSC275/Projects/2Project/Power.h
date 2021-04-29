#ifndef POWER_H
#define POWER_H

#include <string>

class Power {

	public:

	//Constructor
	Power();
	Power(std::string myname, int mypp, int mydmg, std::string mytype, int myacc);

	//Public Accessor Functions
	std::string GetName() const;
	int GetPP() const;
	int calcDamage(std::string userType, std::string targetType, int userLvl) const;
	bool GetIsValid() const;

	private:

	//Private Varibles
	std::string powername = ""; //A string to store the power's name
	int pp = 0; //A int for storing the pp cost for the power
	int basedmg = 0; //An int for storing base damage
	std::string powertype = ""; //A string for storing power type
	int accuracy = 0; //A int to store accuracy for power
	bool isValid = false; //A boolean to varify proper construction of object

	//Static Varible
	static bool firstPowerObject; //Check to see if it is the first power object to set the RNG seed.

};


#endif
