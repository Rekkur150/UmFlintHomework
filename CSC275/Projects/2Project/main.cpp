#include <iostream>
#include "Power.h"
#include "Pokemon.h"


using std::cout;
using std::endl;

int main() {

	Power pows[5] = {	Power("Mudball",4,5, "earth", 100),
				Power("Fireball",5,6,"fire",100),
				Power("WaterSpray",6,7,"water",100),
				Power("Lightning",7,8,"lightning",100)};

	cout << "Testing Power Class" << endl << endl;

	//Testing getname

	cout << "Test GetName" << endl;
	cout << pows[0].GetName() << endl << endl; //Test out Power's name

	//Testing getpp

	cout << "Test GetPP" << endl;
	cout << pows[0].GetPP() << endl << endl; //Test the get the PP

	//Testing damage of powers

	cout << "Test damage and damage  multipliers" << endl;
	cout << pows[0].calcDamage("earth","water",2) << endl;
	cout << pows[0].calcDamage("earth","earth",2) << endl;
	cout << pows[0].calcDamage("water","earth",2) << endl << endl;

	//Testing Power valid

	cout << "Test GetIsValid()" << endl;
	cout << pows[5].GetIsValid() << endl;
	cout << pows[0].GetIsValid() << endl << endl;

	//Testing Pokemon Class
	cout << "--------Testing Pokemon Class--------" << endl << endl;

	Pokemon c("Dave", pows[0], 1, "earth");
	Pokemon a("Second", pows[1], 99, "fire");

	//Testing dexnumber

	cout << "Testing Dexnumber" << endl << endl;
	cout << c.GetName() << "'s dexnumber = " << c.GetDexnum() << endl << endl;

	//Testing pokecount

	cout << "Testing pokecount" << endl << endl;
	cout << c.GetName() << "'s pokecount = " << c.GetPokecount() << endl << endl;

	//Testing liststats

	cout << "Testing liststats" << endl << endl;
	cout << c.GetName() << "'s status = " << endl;
	c.ListStats();
	cout << endl;

	//Testing setname function

	cout << "Testing setname" << endl << endl;
	cout << c.GetName() << "'s new name is = ";
	c.SetName("Jim");
	cout << c.GetName() << endl << endl;

	//Testing Pokemon Leveling

	cout << "Testing Leveling!" << endl << endl;

	a.ListStats();

	cout << a.GetName();
	if (a.AddLevel()) {
		cout << " leveled up!" << endl;
	} else {
		cout << " failed to level up!" << endl;
	}

	cout << a.GetName();
	if (a.AddLevel()) {
		cout << " leveled up!" << endl;
	} else {
		cout << " failed to level up!" << endl;
	}

	a.ListStats();

	//Testing learning powers

	cout << "Testing Learning Power" << endl << endl;

	c.ListStats();

	cout << endl;

	for (int i = 0; i < 5; i++) {

		if (!pows[i].GetIsValid()) {
			cout << "The power that " << c.GetName() << " is trying to learn is invalid" << endl;
		}

		cout << c.GetName() << " will try to learn " << pows[i].GetName() << endl;

		if (c.LearnPower(pows[i])) {
			cout << c.GetName() << " learned " << pows[i].GetName() << endl;
		} else {
			cout << c.GetName() << " failed to learn " << pows[i].GetName() << endl;
		}

		cout << endl;
	}

	//Testing forgetting powers

	cout << "Testing Forgetting Powers" << endl << endl;

	c.ListStats();
	cout << endl;

	cout << c.GetName() << " will try to forget " << pows[3].GetName() << endl;

	if (c.ForgetPower(pows[3].GetName())) {
		cout << c.GetName() << " forgot " << pows[3].GetName() << endl;
	} else {
		cout << c.GetName() << " failed to forget " << pows[3].GetName() << endl;
	}

	c.ListStats();
	cout << endl;

	for (int i = 0; i < 5; i++) {

		if (!pows[i].GetIsValid()) {
			cout << "The power that " << c.GetName() << " is trying to forget is invalid" << endl;
		}

		cout << c.GetName() << " will try to forget " << pows[i].GetName() << endl;

		if (c.ForgetPower(pows[i].GetName())) {
			cout << c.GetName() << " forgot " << pows[i].GetName() << endl;
		} else {
			cout << c.GetName() << " failed to forget " << pows[i].GetName() << endl;
		}

		c.ListStats();
		cout << endl;
	}

	// Testing modify health

	cout << "Testing modify health" << endl << endl;

	c.ListStats();
	cout << endl;

	cout << c.GetName() << " will lose 5 health" << endl;
	c.modifyHealth(-5);
	c.ListStats();
	cout << endl;

	cout << c.GetName() << " will lose 9999999 health" << endl;
	c.modifyHealth(-9999999);
	c.ListStats();
	cout << endl;


	cout << c.GetName() << " will gain 5 health" << endl;
	c.modifyHealth(5);
	c.ListStats();
	cout << endl;

	cout << c.GetName() << " will gain 9999999 health" << endl;
	c.modifyHealth(9999999);
	c.ListStats();
	cout << endl;

	// Testing modify pp

	cout << "Testing modify PP" << endl << endl;

	c.ListStats();
	cout << endl;

	cout << c.GetName() << " will lose 5 PP" << endl;
	c.modifyPP(-5);
	c.ListStats();
	cout << endl;

	cout << c.GetName() << " will lose 9999999 PP" << endl;
	c.modifyPP(-9999999);
	c.ListStats();
	cout << endl;


	cout << c.GetName() << " will gain 5 PP" << endl;
	c.modifyPP(5);
	c.ListStats();
	cout << endl;

	cout << c.GetName() << " will gain 9999999 PP" << endl;
	c.modifyPP(9999999);
	c.ListStats();
	cout << endl;

	for (int i = 0; i < 4; i++) {
		c.LearnPower(pows[i]);
	}

	// Testing attacking target

	cout << "Testing Attacking Target" << endl;

	cout << c.GetName() << " will attack a fire pokemon " << endl;

	int damage = c.AttackTarget("fire");

	cout << "It did " << damage << " damage!" << endl << endl;


	cout << c.GetName() << " will attack a water pokemon " << endl;

	damage = c.AttackTarget("water");

	cout << "It did " << damage << " damage!" << endl << endl << endl;

	// Moc battle between two pokemon

	cout << "Mock battle between two pokemon!!" << endl << endl << endl;

	Pokemon pika("Pikachu",Power("Lightning",10,2,"lightning",100),1,"lightning");
	Pokemon squ("Squirtle",Power("WaterSpray",10,2,"water",100),1,"water");


	for (int i = 0; i < 20; i++) {
		pika.AddLevel();
		squ.AddLevel();
	}

	cout << "The battle begins between " << pika.GetName() << " and " << squ.GetName() << "!" << endl;
	cout << pika.GetName() << " stats are " << endl;
	pika.ListStats();
	cout << squ.GetName() << " stats are " << endl;
	squ.ListStats();

	cout << pika.GetName() << " attacks first!" << endl;

	while (true) {

		damage = pika.AttackTarget(squ.GetType()) * -1;

		if (damage == 0) {
			cout << squ.GetName() << " won the fight" << endl;
			break;
		}

		cout << "Damage: " << damage << endl;
		squ.modifyHealth(damage);

		cout << pika.GetName() << " stats are " << endl;
		pika.ListStats();
		cout << squ.GetName() << " stats are " << endl;
		squ.ListStats();

		damage = squ.AttackTarget(pika.GetType()) * -1;

		if (damage == 0) {
			cout << pika.GetName() << " won the fight" << endl;
			break;
		}

		pika.modifyHealth(damage);

		cout << pika.GetName() << " stats are " << endl;
		pika.ListStats();
		cout << squ.GetName() << " stats are " << endl;
		squ.ListStats();
	}


	return 0;

}


