#include "../../Pokemon.h"

Pokemon::Pokemon() {
	health = 100;
	pint = new int[10];
}

Pokemon::~Pokemon() {
	delete [] pint;
}

int Pokemon::getHealth() const {
	return health;
}

void Pokemon::setHealth(int newHealth) {
	health =  newHealth;
}
