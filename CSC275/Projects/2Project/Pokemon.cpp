#include "Pokemon.h"
#include "Power.h" //Power
#include <stdlib.h> //srand, rand, time
#include <iostream> //cout, cin, endl
#include <string> //string

using std::cout;
using std::cin;
using std::endl;
using std::string;

int Pokemon::pokecount = 0;

//Purpose: Creates default pokemon object.
//Preconditions: None
//Postcondition: None
Pokemon::Pokemon() {}

//Purpose: To set the name, the starting power, and starting level
//Preconditions: The name of the pokemon, the starting power of the pokemon, the starting level of the pokemon.
//Postconditions: None
Pokemon::Pokemon(string thename, Power power1, int lvl, string mytype) {
	if (pokecount == 0) {
		srand(time(NULL)); //Sets RNG seed if this is the first Pokemon Object
	}

	name = thename;
	powers[0] = power1;
	level = lvl;
	type = mytype;
	dexnumber = pokecount++;
	powerSize++;

}


//Purpose: To check to see if the pokemon is valid
//Preconditions: None
//Postconditions: True if valid, false if it isn't valid along with printing a message to console.
bool Pokemon::isValid() const {
	if (dexnumber == -1) {
		cout << "Pokemon's dex number is missing" << endl;
		return false;
	} else {
		return true;
	}
}

//Purpose: Return pokemon type
//Preconditions: None
//Postconditions: String of the pokemon's type or an empty string of the object isn't valid
string Pokemon::GetType() const {
	if (!isValid()) {
		return "";
	}

	return type;
}

//Purpose: Return the name
//Preconditions: None
//Postconditions: Returns a string of the pokemon's name or returns "" if object isn't valid
string Pokemon::GetName() const {
	if (!isValid()) {
		return "";
	}

	return name;
}


//Purpose: Return the dex number
//Preconditions: None
//Postconditions: Integer of the pokemon's dexnumber or it returns -1 if the object isn't valid
int Pokemon::GetDexnum() const {
	if (!isValid()) {
		return -1;
	}

	return dexnumber;
}


//Purpose: Return pokemon count
//Preconditions: None
//Postconditions: Integer number of the pokecount
int Pokemon::GetPokecount() {
	return Pokemon::pokecount;
}

//Purpose: Output the stats.
//Preconditions: None
//Postconditions: None
void Pokemon::ListStats() const {
	if (isValid()) {
		cout << "\tName: " << name << endl
		     << "\tDex Number: " << dexnumber << endl
		     << "\tLevel: " << level << endl
		     << "\tHealth: " << currentHealth << endl
		     << "\tMax Health: " << maxHealth << endl
		     << "\tPower Points: " << currentPP << endl
		     << "\tType: " << type << endl
		     << "\tPowers: ";
		PrintPowers();
	}
}


//Purpose: Set the name
//Preconditions: The new name of the pokemon
//Postconditions: None or output telling the user that the pokemons dex number was missing
void Pokemon::SetName(string newName) {
	if (isValid()) {
		name = newName;
	}
}

//Purpose: Increment level by 1 and adds a random amount of maxHealth and maxPP then sets health and pp to max
//Preconditions: None
//Postconditions: True if successfully leveled, false it failed to level or it was an invalid Object
bool Pokemon::AddLevel() {
	if (!isValid()) {
		return false;
	} else if (level >= 100) {
		return false;
	}

	level++;

	maxHealth += 4 * ((rand() % 3) + 1);
	maxPP += 2 * ((rand() % 3) + 1);

	currentHealth = maxHealth;
	currentPP = maxPP;

	return true;

}

//Purpose: Remove a power
//Preconditions: Name of the power you want to remove
//Postconditions: True if pokemon sucessfully forgot a power, false it failed to forget a power.
bool Pokemon::ForgetPower(string powername) {
	if (!isValid()) {
		return false;
	}

	int powerIndex = FindPowerIndex(powername);
	int pSizeM1 = powerSize-1;

	if (isPower(powername)) {
		powers[powerIndex] = Power();

		for (int i = powerIndex; i < pSizeM1; i++) { //Shifts the array to remove empty power indexs
			powers[i] = powers[i + 1];
			powers[i+1] = Power();
		}
		powerSize--; //Decrements the amount of powers.
		return true;

	} else {
		return false;
	}
}

//Purpose: Add a power
//Preconditions: Name of the power.
//Postconditions: True if successfully learned a power, False if it failed.
bool Pokemon::LearnPower(const Power& newpower) {
	if (!isValid()) {
		return false;
	} else if (!newpower.GetIsValid()) {
		cout << "Power is not defined" << endl;
		return false;
	} else if (isPower(newpower)) { //Checks to see if the power already exists.
		cout << "This Pokemon already knows that power!" << endl;
		return false;
	} else if (powerSize < powerMax) { //Checks to see if the array is full.
		powers[powerSize++] = newpower;
		return true;
	} else {
		cout << "This Pokemon already knows " << powerMax << " powers and will have to unlearn something first" << endl;
		return false;
	}
}

//Purpose: Modify health of Pokemon and constrain health within a range
//Preconitions: The change in health (Positive increase in health, negative decrease in health)
//Postconitions: None
void Pokemon::modifyHealth(int healthChange) {
	if (isValid()) {
		currentHealth += healthChange;

		if (currentHealth > maxHealth) {
			currentHealth = maxHealth;
		} else if (currentHealth < 0) {
			cout << "This Pokemon has fainted!" << endl;
			currentHealth = 0;
		}
	}
}

//Purpose: Modify PP of Pokemon and constrain PP within a range
//Preconditions: The change in PP (Positive increase in PP, negative decrease in PP)
//Postconditions: None
void Pokemon::modifyPP(int powerpointChange) {
	if (isValid()) {
		currentPP += powerpointChange;

		if (currentPP > maxPP) {
			currentPP = maxPP;
		} else if (currentPP < 0) {
			currentPP = 0;
		}
	}
}

//Purpose: Allows user to pick a power.
//Preconditions: Prompts user for the name of a power
//Postconditions: Returns the name of the power
int Pokemon::AttackTarget(string targetType) {
	if (!isValid()) {
		return 0;
	} else if (currentHealth <= 0) {
		cout << "Pokemon has fainted and cannot use powers until healed!" << endl;
		return 0;
	} else if (canUseAnyPower()) {
		cout << "Your Pokemon is struggling to attack! It takes 10 damage and only hits for 5!" << endl;
		modifyHealth(-10);
		return 5;
	}

	int input;
	cout << "Choose a power from below! [1-" << powerSize << "]" << endl << "\t";
	PrintPowers();

	cout << ":";
	cin >> input;

	while (!isValidInput(input)) { //While input is not valid.
		cout << ":";
		cin >> input;
	}

	currentPP -= powers[input-1].GetPP();
	return powers[input-1].calcDamage(type, targetType, level);

}

// Purpose: Print out the name of the powers
// Preconditions: None.
// Postconditions: None.
void Pokemon::PrintPowers() const {
	for (int i = 0; i < powerSize; i++) {
		if (i == powerSize-1) { // To prevent printing out "Jump, Dig, "
			cout << "[" << i + 1 << "]" << powers[i].GetName();
		} else {
			cout  << "[" << i + 1 << "]" << powers[i].GetName() << ", "; //Default print
		}
	}

	cout << endl;
}

// Purpose: To return the Index value of a power of a pokemon.
// Preconditions: Name of the power
// Postconditions: If power is found return index of it, if not found return -1;
int Pokemon::FindPowerIndex(string powername) const {
	for (int i = 0; i < powerSize; i++) {
		if (powers[i].GetName() == powername) {
			return i;
		}
	}

	return -1; //powername not found
}

// Purpose: To make checking for a power more human readable.
// Preconditions: The name of the power.
// Postconditions: True if the power exists, false it the power does not exist.
bool Pokemon::isPower(string powername) const {
	return (FindPowerIndex(powername) != -1);
}

// Purpose: To make checking for a power more human readable.
// Preconditions: The power object
// Postconditions: True if the power exists, false it the power does not exist.
bool Pokemon::isPower(const Power& power) const {
	return (FindPowerIndex(power.GetName()) != -1);
}

//Purpose: To make it more human readable to check if the pokemon can use any power that it has
//Preconditions: None
//Postconditions: True if the pokemon can use any power that it has, false if the pokemon cannot use any power that it has
bool Pokemon::canUseAnyPower() const {
	if (getMinimumPP() < currentPP) {
		return false;
	} else {
		return true;
	}
}

//Purpose: To help the AttackTarget function to see if the input is valid or not.
//Preconditions: An integer representing the position of a power
//Postconditions: False if it is invalid input, true if it is valid input.
bool Pokemon::isValidInput(int input) const {
	if (input < 1 || input > powerSize) {
		cout << "Invalid input! Please try again." << endl;
		return false;
	} else if (!powers[input-1].GetIsValid()) {
		cout << "Not a valid power" << endl;
		return false;
	} else if (powers[input-1].GetPP() > currentPP) {
		cout << "You don't have enough PP to use that power" << endl;
		return false;
	}

	return true;
}

//Purpose: To get the minimum required PP to use any power that the pokemon has
//Preconditions: None
//Postconditions: Lowest PP requirement from the powers that the pokemon has
int Pokemon::getMinimumPP() const {
	int minimum = powers[0].GetPP();

	for (int i = 0; i < powerSize; i++) {
		if (powers[i].GetPP() < minimum) {
			minimum = powers[i].GetPP();
		}
	}

	return minimum;
}
