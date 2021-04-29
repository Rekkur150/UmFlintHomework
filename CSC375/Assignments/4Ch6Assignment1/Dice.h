#ifndef DICE_H
#define DICE_H

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

#endif
