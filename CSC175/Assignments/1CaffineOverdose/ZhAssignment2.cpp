// Zachary Holmes
// Csc 175
// Assignment 2

#include <iostream>

using namespace std;

// Global Variable Declaration
const int GRAMS_OF_CAFFINE_THAT_IS_REQUIRED_FOR_AN_LETHAL_OVERDOSE = 10; //I think that this is the best and longest variable name ever.
const int MILLIGRAMS_IN_GRAM = 1000;

int main() {

	//Variable Declaration
	float milligramsOfCaffineInDrink = 0;
	float gramsOfCaffineInDrink = 0;
	float amountOfDrinksForLethalDose = 0; //No need to round, one can drink a fraction of a drink.

	//Input
	cout << "Please input amount of milligrams in your drink: ";
	cin >> milligramsOfCaffineInDrink;

	//Calculations
	gramsOfCaffineInDrink = milligramsOfCaffineInDrink/MILLIGRAMS_IN_GRAM;
	amountOfDrinksForLethalDose = GRAMS_OF_CAFFINE_THAT_IS_REQUIRED_FOR_AN_LETHAL_OVERDOSE/gramsOfCaffineInDrink;

	//Output
	cout << "---------------------------------------------------" << endl
	     << "The amount of drinks you have to drink in order to get" << endl
	     << "a lethal dose of caffine is: " << amountOfDrinksForLethalDose << " Drinks" << endl;

	return 0;
}
