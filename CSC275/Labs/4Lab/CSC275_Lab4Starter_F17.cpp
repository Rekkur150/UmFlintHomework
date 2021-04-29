// Zachary Holmes
// Lab 4
// 1-30-2018

#include <iostream>
#include <random>
#include <time.h>

using namespace std;

const int MAX_SIZE_DEFAULT = 151;

class Pokeman{
public:
    Pokeman();
    Pokeman(string myname, string myeyecolor);
    string getName() const;
    string getEyeColor() const;

    bool sameas(const Pokeman& poke2) const;
    const Pokeman splice(const Pokeman& poke2) const;
    void output() const;

private:
    string name;
    string eyecolor;

};

class Pokedex{
public:
    Pokedex();
    Pokedex(string my_name, int dex_size, const Pokeman& firstmon);
    void renameTrainer(string newname);
    void addPokeman(const Pokeman& newmon);
    Pokeman getPokeman(int index);
    void printPokedex();

    //Your three functions for the assignment:
    Pokedex(const Pokedex& mycopy);
    Pokedex& operator=(const Pokedex& rtSide);
    ~Pokedex();

private:
    string trainer_name;
    Pokeman *plist;
    int nump = 0;
    int maxp;
};


int main()
{

    Pokedex ashPokedex;
    Pokedex garyPokedex("Gary", MAX_SIZE_DEFAULT+1, Pokeman("Ratatatatata", "Green"));
    ashPokedex.addPokeman(Pokeman()); //Add a pokemon to me

    Pokedex mistyPokedex(ashPokedex); //Creates a new pokedex with my stuff
    mistyPokedex.renameTrainer("Misty");

    ashPokedex = garyPokedex; //Sets ashPokedex to gary's
    ashPokedex.renameTrainer("Ash"); //Renames ashpokedex

    garyPokedex.addPokeman(Pokeman("Squirrel", "Brown"));
    ashPokedex.addPokeman(Pokeman("Pikachoose", "Black"));
    mistyPokedex.addPokeman(Pokeman("Zyduck", "Blue"));


    ashPokedex.printPokedex();
    garyPokedex.printPokedex();
    mistyPokedex.printPokedex();
    return 0;
}

Pokeman::Pokeman(): Pokeman("Squirrel","Brown")  {}
Pokeman::Pokeman(string myname, string myeyecolor) : name(myname), eyecolor(myeyecolor) {}
string Pokeman::getEyeColor() const{return eyecolor;}
string Pokeman::getName() const{return name;}
bool Pokeman::sameas(const Pokeman& poke2) const{
    return ((name == poke2.name) && (eyecolor == poke2.eyecolor));
}
const Pokeman Pokeman::splice(const Pokeman& poke2) const{
    string newcolor, newname;
    int rnum;
    rnum = rand()%100;
    if(rnum > 50)
        newname = name;
    else
        newname = poke2.name;
    rnum = rand()%100;
    if(rnum > 50)
        newcolor = eyecolor;
    else
        newcolor = poke2.eyecolor;
    return Pokeman(newname, newcolor);
}
void Pokeman::output() const{
    cout << "Who's that pokeman?" << endl;
    cout << "It's " << name << "!" << endl;
    cout << "\"" <<name <<"! " << name << " " << name << "!\"" << endl;
    cout << name << " has " << eyecolor << " eyes." << endl << endl;
}

Pokedex::Pokedex() : maxp(MAX_SIZE_DEFAULT) {
    /*default constructor*/
    cout << "What's your name? :  ";
    cin >> trainer_name;
    cout << "Welcome, " << trainer_name << endl;
    cout << "Your pokedex size is " << maxp << "." << endl;
    plist = new Pokeman[maxp];

    cout << "You have no starter.  Remember to add a pokeman!" << endl;

}
Pokedex::Pokedex(string my_name, int dex_size, const Pokeman& firstmon) : maxp(dex_size), trainer_name(my_name) {
    cout << "Welcome, " << trainer_name << endl;
    cout << "Your pokedex size is " << maxp << "." << endl;
    plist = new Pokeman[maxp];

    cout << "Your starter is a " << firstmon.getName() << " with " << firstmon.getEyeColor() << " eyes." << endl;
    plist[nump] = firstmon;
    nump++;
}
void Pokedex::addPokeman(const Pokeman& newmon){
    cout << "Adding a pokeman #" << nump+1 << " to your pokedex, " << trainer_name<< "!" << endl;
    if(nump == 0)
        cout << "Your starter is a " << newmon.getName() << " with " << newmon.getEyeColor() << " eyes." << endl;
    else
        cout << "Added " << newmon.getName() << " with " << newmon.getEyeColor() << " eyes to the pokedex." << endl;
    plist[nump] = newmon;
    nump++;
}
void Pokedex::renameTrainer(string newname){
    trainer_name = newname;
}
Pokeman Pokedex::getPokeman(int index){
    return plist[index];
}
void Pokedex::printPokedex(){
    cout << "Trainer " << trainer_name << ": " << endl;
    cout << "Pokeman #\t\tPokeman Name\t\tEye Color" << endl;
    for(int i = 0; i < nump; i++)
        cout << "#" << i << "\t\t" << plist[i].getName() << "\t\t" << plist[i].getEyeColor() << endl;
}


Pokedex::Pokedex(const Pokedex& mycopy){
    /*make the private data of the new Pokedex object a deep copy of mycopy*/
    trainer_name = mycopy.trainer_name;
    nump = mycopy.nump;
    maxp = mycopy.maxp;
    plist = new Pokeman[maxp];

    for (int i = 0; i < nump; i++) {
	plist[i] = mycopy.plist[i];
    }

}
Pokedex& Pokedex::operator=(const Pokedex& rtSide){
    /*make the private data of the new Pokedex object a deep copy of rtSide*/
    /*make sure to delete the calling object's plist first for memory cleanup.*/
    /*return the calling object; need to dereference the special pointer to the calling object*/

	trainer_name = rtSide.trainer_name;
	nump = rtSide.nump;
	maxp = rtSide.maxp;

	delete [] plist;

	plist = new Pokeman[maxp];

	for (int i = 0; i < nump; i++) {
		plist[i] = rtSide.plist[i];
	}

	return *this;

}
Pokedex::~Pokedex(){
    /*deconstructor for the dynamic array plist*/
    delete [] plist;
}
