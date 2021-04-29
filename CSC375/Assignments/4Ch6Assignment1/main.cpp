#include <iostream>

// Classes
// ---------------------------------------------
// Dice Class
// ---------------------------------------------

class Dice {
public:
	Dice();
	Dice( int numSides);
	virtual int rollDice() const;

protected:
	int numSides;
};

Dice::Dice() {
	numSides = 6;
	srand(time(NULL));
}

Dice::Dice(int numSides) {
	this->numSides = numSides;
	srand(time(NULL));
}

int Dice::rollDice() const {
	return (rand() % numSides) + 1;
}

// Take two dice objects, roll them, and return the sum
int rollTwoDice(const Dice& die1, const Dice& die2) {
	return die1.rollDice() + die2.rollDice();
}

// ---------------------------------------------
// LoadedDice Class
// ---------------------------------------------

class LoadedDice : public Dice {
public:
	LoadedDice();
	LoadedDice(const int& numberOfDice);

	virtual int rollDice() const;
};

LoadedDice::LoadedDice() : Dice() {}

LoadedDice::LoadedDice(const int& numberOfDice) : Dice(numberOfDice) {}

int LoadedDice::rollDice() const {
	if ((rand() % 2) == 1) {
		return numSides;
	} else {
		return Dice::rollDice();
	}
}

// ---------------------------------------------
// Main Function
// ---------------------------------------------

int main() {

	LoadedDice a;
	LoadedDice b;

	for (int i = 0; i < 10; i++) {
		std::cout << rollTwoDice(a,b) << std::endl;
	}



	return 0;
}
