// Zachary Holmes
// It took too long I had to hurry.
#include <iostream>

using namespace std;

struct Mob {
	Mob();
	Mob(string name, int health, int skill);
	string name;
	int health = 0;
	int skill = 0;
	int damage = 2;
};

class Mario_Twins{
public:
    Mario_Twins();
    Mario_Twins(string my_name);
    static void add_coins(int t);
    static void check_coins();
    static int roll_dice(int number_of_dice);
    bool fight(Mob enemy);
    void collect_coin();
    int my_coins();
    string my_name();
    string my_status() { return status;};

private:
    void set_stats();

    static int coins_left;
    int coins = 0;
    int health = 10;
    int skill = 10;
    int damage = 2;
    string name;
    string status = "alive";
};

class Ring_Master {
//	public
};

int Mario_Twins::coins_left = 0;

int main()
{

	srand(time(NULL));

    Mario_Twins p1("Mario");
    Mario_Twins p2;
    Mario_Twins::add_coins(10);
    string input = "";

    do {
	if (p1.my_status() == "alive") {
		cout << p1.my_name() << " would you like to 'fight' or 'exit'?" << endl;
		cin >> input;
		if (input == "exit") {
			break;
		} else if (input == "fight") {
			p1.fight(Mob("Gumba",Mario_Twins::roll_dice(2) + 12, Mario_Twins::roll_dice(1) + 6));
		} else {
			cout << "I am too lazy to program for your typing mistakes! Your turn as been skipped!" << endl;
		}
	}

	if (p2.my_status() == "alive") {
		cout << p2.my_name() << " would you like to 'fight' or 'exit'?" << endl;
		cin >> input;
		if (input == "exit") {
			break;
		} else if (input == "fight") {
			p2.fight(Mob("Gumba",Mario_Twins::roll_dice(2) + 12, Mario_Twins::roll_dice(1) + 6));
		} else {
			cout << "I am too lazy to program for your typing mistakes! Your turn as been skipped!" << endl;
		}
	}

    } while (p1.my_status() == "alive" || p2.my_status() == "alive");



   // p1.collect_coin();
   // Mario_Twins::check_coins();
   // p2.collect_coin();
   // Mario_Twins::check_coins();
   // p2.collect_coin();
   // Mario_Twins::check_coins();

    cout << p1.my_name() << " has " << p1.my_coins() << " coins.\n";
    cout << p2.my_name() << " has " << p2.my_coins() << " coins.\n";

    return 0;
}



Mario_Twins::Mario_Twins(){
    cout << "Enter your player's name: ";
    cin >> name;
    cout << "Ready Player " << name << endl;
    set_stats();
}

Mario_Twins::Mario_Twins(string my_name){
    name = my_name;
    cout << "Ready Player " << name << endl;
    set_stats();
}

void Mario_Twins::add_coins(int t){
    cout << "Added " << t << " coins to the block.\n";
    coins_left+=t;
}

void Mario_Twins::check_coins(){
    cout << "There are " << coins_left << " coins remaining.\n";
}

int Mario_Twins::roll_dice(int number_of_dice) {
	int total = 0;

	for (int i = 0; i < number_of_dice; i++) {
		total += rand() % 6 + 1;
	}

	return total;
}

void Mario_Twins::collect_coin(){
    if(coins_left > 0){
        cout << name << " got a coin.\n";
        coins++;
        coins_left--;
    }
    else
        cout << "Coin block is empty.  You must add more coins. \n";

}

int Mario_Twins::my_coins(){
    return coins;
}

string Mario_Twins::my_name(){
    return name;
}

void Mario_Twins::set_stats() {
	int diceRoll0 = roll_dice(2);
	int diceRoll1 = roll_dice(1);
	cout << name << " has rolled a " << diceRoll0 << " plus a base of 12 for a total health of " << diceRoll0 + 12 << endl;
	health = diceRoll0 + 12;
	cout << name << " has rolled a " << diceRoll1 << " plus a base of 6 for a total skill of " << diceRoll1 + 6 << endl;
	skill = diceRoll1 + 6;
}

bool Mario_Twins::fight(Mob enemy) {

	cout << "Fight started with " << enemy.name << "!!!" << endl;

	while (health > 0 && enemy.health > 0) {
		int playerDice = roll_dice(2);
		int enemyDice = roll_dice(2);
		cout << name << " rolls for skill " << playerDice << " + " << skill << endl
		     << enemy.name << " rolls for skill " << enemyDice << " + " << enemy.skill << endl;
		if (playerDice + skill > enemyDice + enemy.skill) {
			enemy.health -= damage;
			cout << my_name() << " deals " << damage << " to " << enemy.name << " leaving him with " << enemy.health << " health" << endl;
		} else {
			health -= enemy.damage;
			cout << enemy.name << " deals " << enemy.damage << " to " << name << " leaving you with " << health << " health" << endl;
		}
	}

	if (health <= 0) {
		cout << "You have died!" << endl;
		status = "dead";
		return false;
	} else {
		cout << "You have killed the " << enemy.name << " and earned a coin!" << endl;
		collect_coin();
		return true;
	}
}

Mob::Mob(): Mob("Test",10,10) {};

Mob::Mob(string newName, int newHealth, int newSkill) {
	name = newName;
	health = newHealth;
	skill = newSkill;
	damage = 2;
}
