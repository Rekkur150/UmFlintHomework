#ifndef POKEMON_H
#define POKEMON_H

#include <string> //string
#include "Power.h" //Power

class Pokemon {
public:

	// Constructors
	Pokemon();
	Pokemon(std::string thename, Power power1, int lvl, std::string mytype);

	// Public Functions
	std::string GetType() const;
	std::string GetName() const;
	int GetDexnum() const;
	static int GetPokecount();
	void ListStats() const;
	void SetName(std::string newname);
	bool AddLevel();
	bool ForgetPower(std::string powername);
	bool LearnPower(const Power& newpower);
	void modifyHealth(int healthChange);
	void modifyPP(int powerpointChange);
	int AttackTarget(std::string targetType);

private:

	// Private Helper Functions
	void PrintPowers() const;
	int FindPowerIndex(std::string powername) const;
	bool isPower(std::string powername) const;
	bool isPower(const Power& power) const;
	bool canUseAnyPower() const;
	bool isValidInput(int input) const;
	int getMinimumPP() const;
	bool isValid() const;

	// Private Variables
	const int powerMax = 4; // The maxium size of the array;
	int powerSize = 0; //The amount of the powers in the array
	Power powers[4]; //The name of the powers
	std::string name; //The name of the pokemon
	int level = -1; //The level of the pokemon
	int dexnumber = -1; //The dex number of the pokemon
	static int pokecount; //A variable that is shared to keep the pokemon's dexnumbers different.
	int currentHealth = 10; //Current Health of the pokemon
	int maxHealth = 10; //Max health of the pokemon
	int currentPP = 10; //Current PP of the pokemon
	int maxPP = 10; //Max PP of the pokemon
	std::string type = ""; //Type of pokemon
};

#endif
