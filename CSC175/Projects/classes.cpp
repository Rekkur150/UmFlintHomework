#include <iostream>
using namespace std;


struct Person {
	string name;
	string hairColor;
	int age;
	int height;
};

void display(Person student);

int main() {

	Person jim = Person();
	jim.name = "jim";
	jim.hairColor = "blue";
	jim.age = 84;
	jim.height = 64;

	display(jim);

}

void display(Person student) {
	cout << "name = " << student.name << endl
	     << "hairColor = " << student.hairColor << endl
	     << "age = " << student.age << endl
	     << "height = " << student.height << endl;
}
