// Project 1
// CSC275
// Zachary Holmes
// Jan 20th, 2018

#include <iostream>
#include <vector>
using namespace std;

void testing(const int& t);

class Pokemon {
public:

	// Constructors
	Pokemon();
	Pokemon(string thename);
	Pokemon(string thename, string power1, int lvl);

	// Public Functions
	string GetName() const;
	int GetDexnum() const;
	static int GetPokecount();
	string ChoosePower() const;
	void ListStats() const;
	void SetName(string newname);
	bool AddLevel();
	bool ForgetPower(string powername);
	bool LearnPower(string powername);
private:

	// Private Helper Functions
	void PrintPowers() const;
	int FindPowerIndex(string powername) const;
	bool isPower(string powername) const;

	// Private Variables
	const int powerMax = 4; // The maxium size of the array;
	int powerSize = 0; //The amount of the powers in the array
	string powers[4]; //The name of the powers
	string name; //The name of the pokemon
	int level; //The level of the pokemon
	int dexnumber; //The dex number of the pokemon
	static int pokecount; //A variable that is shared to keep the pokemon's dexnumbers different.
};

int Pokemon::pokecount = 0;

int main() {

	int a = 10;
	testing(a);

	vector<int>b;
	b.push_back(5);


	cout << b[0] << endl;

	b.pop_back();

	cout << b[0] << endl;
	/*

	// --------------------------------------
	// Testing
	// --------------------------------------

	Pokemon p1;
	Pokemon p2("Dave");
	Pokemon p3("Jim","Dance",100);
	Pokemon p4("Blue","Jump",99);

	string allPowers[5] = {"Jump","Dance","Throw","Stalk","Run"};

	// Change Name Test
	cout << "Change the name of the pokemon" << endl << "/tPokemon " << p4.GetName() << " will change it's name to 'Blueberry'" << endl;
	p4.SetName("Blueberry");
	cout << "\t\tThe name is now " << p4.GetName() << endl << endl;

	// Testing Dex Number
	cout << "The Dex number for " << endl
		 << "p1 is " << p1.GetDexnum() << endl
		 << "p2 is " << p2.GetDexnum() << endl
		 << "p3 is " << p3.GetDexnum() << endl
		 << "p3 is " << p4.GetDexnum() << endl << endl;

	// Testing GetPokecount
	cout << "The Pokemon count is " << Pokemon::GetPokecount() << endl << endl;
	// Test States
	cout << "The stats for the pokemon are " << endl;
	p1.ListStats();
	cout << endl;
	p2.ListStats();
	cout << endl;
	p3.ListStats();
	cout << endl;
	p4.ListStats();
	cout << endl;

	// Test Adding a level
	if (p3.AddLevel()) {
		cout << "p3 gained a level" << endl << endl;
	} else {
		cout << "p3 failed to gain a level" << endl << endl;
	}

	if (p4.AddLevel()) {
		cout << "p4 gained a level" << endl << endl;
	} else {
		cout << "p4 failed to gain a level" << endl << endl;
	}

	// Adding powers.

	for (int i = 0; i < 5; i++) {
		cout << "p4 will try to learn " << allPowers[i] << endl;
		if (p4.LearnPower(allPowers[i])) {
			cout << "p4 learned " << allPowers[i] << endl;
		} else {
			cout << "p4 failed to learn " << allPowers[i] << endl;
		}
	}

	cout << endl;

	//Testing Choose Power

	cout << "Choose a power from p4!" << endl;

	p4.ChoosePower();

	// Test Forgetting a power

	for (int i = 4; i >= 0; i--) {
		cout << "p4 will try to forget " << allPowers[i] << endl;
		if (p4.ForgetPower(allPowers[i])) {
			cout << "p4 forgot " << allPowers[i] << endl;
		} else {
			cout << "p4 failed to forget " << allPowers[i] << endl;
		}

		cout << endl;

		p4.ListStats();

		cout << endl;
	}

	// Test Forgetting a power in the beginning of an array

	for (int i = 0; i < 5; i++) {
		p4.LearnPower(allPowers[i]);
	}

	p4.ListStats();


	for (int i = 0; i < 5; i++) {
		cout << "p4 will try to forget " << allPowers[i] << endl;
		if (p4.ForgetPower(allPowers[i])) {
			cout << "p4 forgot " << allPowers[i] << endl;
		} else {
			cout << "p4 failed to forget " << allPowers[i] << endl;
		}

		cout << endl;
		p4.ListStats();
		cout << endl;
	}*/

	return 0;
}

void testing(const int& t) {
	cout << t <<" is working" << endl;
}


//Purpose: Create default pokemon, prompt user for name.
//Preconditions: Prompts user for the name.
//Postcondition: None
Pokemon::Pokemon() : name("Jimmy"),level(1337) {
	string thename;
	cout << "Please input the name for this pokemon: ";
	cin >> thename;
	//name = thename;
}

//Purpose: Set the name, but default the power and level.
//Preconditions: The name of the pokemon.
//Postconditions: None
Pokemon::Pokemon(string thename) : Pokemon(thename, "", 1) {}

//Purpose: To set the name, the starting power, and starting level
//Preconditions: The name of the pokemon, the starting power of the pokemon, the starting level of the pokemon.
//Postconditions: None
Pokemon::Pokemon(string thename, string power1, int lvl) {
	name = thename;
	powers[0] = power1;
	level = lvl;
	dexnumber = pokecount++;

	if (power1 != "") {
		powerSize++;
	}

}

//Purpose: Return the name
//Preconditions: None
//Postconditions: Returns a string of the pokemon's name
string Pokemon::GetName() const {
	return name;
}


//Purpose: Return the dex number
//Preconditions: None
//Postconditions: Integer of the pokemon's dexnumber
int Pokemon::GetDexnum() const {
	return dexnumber;
}


//Purpose: Return pokemon count
//Preconditions: None
//Postconditions: Integer number of the pokecount
int Pokemon::GetPokecount() {
	return Pokemon::pokecount;
}


//Purpose: Allows user to pick a power.
//Preconditions: Prompts user for the name of a power
//Postconditions: Returns the name of the power
string Pokemon::ChoosePower() const {
	string input;
	cout << "Choose a power from below!" << endl << "\t";
	PrintPowers();

	cout << ":";
	cin >> input;

	while (!isPower(input)) { //While input is not a power.
		cout << "Invalid input! Please try again." << endl << ":";
		cin >> input;
	}

	return input;
}

//Purpose: Output the stats.
//Preconditions: None
//Postconditions: None
void Pokemon::ListStats() const {
	cout << "\tName: " << name << endl
	     << "\tDex Number: " << dexnumber << endl
	     << "\tLevel: " << level << endl
	     << "\tPowers: ";
	PrintPowers();
}


//Purpose: Set the name
//Preconditions: The new name of the pokemon
//Postconditions: None
void Pokemon::SetName(string newName) {
	name = newName;
}

//Purpose: Increment level by 1.
//Preconditions: None
//Postconditions: True if successfully leveled, false it failed to level
bool Pokemon::AddLevel() {
	if (level < 100) {
		level++;
		return true;
	} else {
		return false;
	}
}

//Purpose: Remove a power
//Preconditions: Name of the power you want to remove
//Postconditions: True if pokemon sucessfully forgot a power, false it failed to forget a power.
bool Pokemon::ForgetPower(string powername) {
	int powerIndex = FindPowerIndex(powername);
	int pSizeM1 = powerSize-1;

	if (isPower(powername)) {
		powers[powerIndex] = "";

		for (int i = powerIndex; i < pSizeM1; i++) { //Shifts the array to remove empty power indexs
			powers[i] = powers[i + 1];
			powers[i+1] = "";
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
bool Pokemon::LearnPower(string powername) {
	if (isPower(powername)) { //Checks to see if the power already exists.
		cout << "This Pokemon already knows that power!" << endl;
		return false;
	} else if (powerSize < powerMax) { //Checks to see if the array is full.
		powers[powerSize++] = powername;
		return true;
	} else {
		cout << "This Pokemon already knows " << powerMax << " powers and will have to unlearn something first" << endl;
		return false;
	}
}


// Purpose: Print out the name of the powers
// Preconditions: None.
// Postconditions: None.
void Pokemon::PrintPowers() const {
	for (int i = 0; i < powerSize; i++) {
		if (i == powerSize-1) { // To prevent printing out "Jump, Dig, "
			cout << powers[i];
		} else {
			cout << powers[i] << ", "; //Default print
		}
	}

	cout << endl;
}

// Purpose: To return the Index value of a power of a pokemon.
// Preconditions: Name of the power
// Postconditions: If power is found return index of it, if not found return -1;
int Pokemon::FindPowerIndex(string powername) const {
	for (int i = 0; i < powerSize; i++) {
		if (powers[i] == powername) {
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
