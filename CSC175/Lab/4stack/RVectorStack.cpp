#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 10;

struct Jim { // Struct everthing is public unless told otherwise with "private:"

};

class Person { //Classes everything is private unless told otherwise with "public:"

private:
	string name; // Encapsulating making things only the object itself can see, everything that is private only the object can change or see.
	int age;
	int weight;

public:
	// SHOULD USE ACCESSORS AND MUTATORS

	// The following below are prototypes
	void set_name(string name_in); //Mutator because it is changing the data in the object
	void set_age(int age_in); //Mutator
	void set_weight(int weight_in); //Mutator
	string get_name(); //Accessor because it gets the data from the object
	int get_age();	//Accessor
	int get_weight(); //Accessor

	//Using accessors and mutators allows you can control and restrict ages or names and such, for instance I could make sure the age isn't below 0

};

//The following below are function definitions for the prototypes in the Person class

void Person::set_name(string name_in) {
	name = name_in;
}

void Person::set_age(int age_in) {
	age = age_in;
}

void Person::set_weight(int weight_in) {
	weight = weight_in;
}

string Person::get_name() {
	return name;
}

int Person::get_age() {
	return age;
}

int Person::get_weight() {
	return weight;
}

// END OF FUNCTION DEFINITION FOR PERSON CLASS

void func1(Person p_in) {
	cout << p_in.get_name() << endl;
}

int main() {
	
	vector<Person> my_person_array;
	cout << "my_person_array.size*() = " << my_person_array.size() << endl;

	Person my_person;

	my_person.set_name("Fred");
	my_person.set_age(21);
	my_person.set_weight(150);

	my_person_array.push_back(my_person);

	my_person.set_name("Frodo");
	my_person.set_age(17);
	my_person.set_weight(110);

	my_person_array.push_back(my_person);
	my_person_array.push_back(my_person);

	cout << "my_person_array.size*() = " << my_person_array.size() << endl;

	//vector object did all the work for us, we didn't need to do anything.
	//vector has basically given us a dynamic array.

	for (int i = 0; i < my_person_array.size(); i++) {
		cout << "my_person_array["<< i << "].name = " << my_person_array[i].get_name() << endl;
		cout << "my_person_array["<< i << "].name = " << my_person_array[i].get_age() << endl;
		cout << "my_person_array["<< i << "].name = " << my_person_array[i].get_weight() << endl;
	}
	return 0;

	int scores[SIZE];
	int scoreTotal = 0;

	for (int i = 0; i < SIZE; i++) {
		scoreTotal += scores[i];
	}

	return 0;
}

