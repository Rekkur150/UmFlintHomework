#ifndef LOADEDDICE_H
#define LOADEDDICE_H

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

#endif
