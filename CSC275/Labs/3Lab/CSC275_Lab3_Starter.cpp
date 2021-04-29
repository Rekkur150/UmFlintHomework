// Zachary Holmes
// Lab 3
// 1/23/18

#include <iostream>
#include <random>
#include <time.h>

using namespace std;

class Pokeman{
public:
    Pokeman();
    Pokeman(string myname, string myeyecolor);
    string getName() const;
    string getEyeColor() const;

    bool sameas(const Pokeman& poke2) const;
    const Pokeman splice(const Pokeman& poke2) const;
    void output() const;

    friend bool operator ==(const Pokeman& poke1, const Pokeman& poke2);
    friend const Pokeman operator +(const Pokeman& poke1, const Pokeman& poke2);
    friend ostream& operator <<(ostream& outputStream, const Pokeman&poke1);

private:
    string name;
    string eyecolor;

};


int main()
{
    /*Modify the main function so that it uses ==, + and << instead of the functions sameas, splice, and output*/
    int gen_num = 0;
    srand (time(NULL));
    Pokeman A;
    Pokeman B("Pika", "black");
    cout << "Generation " << gen_num << " is: " << endl << A << B;
    gen_num++;
    cout << "Generation " << gen_num << " !  A new generation arrives!" << endl;
    Pokeman C = A + B;
    Pokeman D = B + A;
    cout << C << D;


    while (!(C == D))
    {
        gen_num++;
        C = A + B;
        D = B + A;
        cout << "Generation " << gen_num << " !  A new generation arrives!" << endl << C << D;

    }
    cout << "Twins after " << gen_num << " new generations." << endl;

    return 0;
}










Pokeman::Pokeman(): Pokeman("squirrel","brown")  {}
Pokeman::Pokeman(string myname, string myeyecolor) : name(myname), eyecolor(myeyecolor) {}

string Pokeman::getEyeColor() const{
    return eyecolor;
}

string Pokeman::getName() const{
    return name;
}


bool Pokeman::sameas(const Pokeman& poke2) const{
    return ((name == poke2.name) && (eyecolor == poke2.eyecolor));

}
bool operator ==(const Pokeman& poke1, const Pokeman& poke2){
    return ((poke1.name == poke2.name) && (poke1.eyecolor == poke2.eyecolor));
    /*write operator overload here based on sameas method*/
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
const Pokeman operator +(const Pokeman& poke1, const Pokeman& poke2){
    string newcolor, newname;
    int rnum;
    rnum = rand()%100;
    if(rnum > 50)
        newname = poke1.name;
    else
        newname = poke2.name;
    rnum = rand()%100;
    if(rnum > 50)
        newcolor = poke1.eyecolor;
    else
        newcolor = poke2.eyecolor;
    return Pokeman(newname, newcolor);

    /*write operator overload here based on splice method*/
}



void Pokeman::output() const{
    cout << "Who's that pokeman?" << endl;
    cout << "It's " << name << "!" << endl;
    cout << "\"" <<name <<"! " << name << " " << name << "!\"" << endl;
    cout << name << " has " << eyecolor << " eyes." << endl << endl;
}
ostream& operator <<(ostream& outputStream, const Pokeman&poke1){
    outputStream << "Who's that pokeman?" << endl;
    outputStream << "It's " << poke1.name << "!" << endl;
    outputStream << "\"" << poke1.name <<"! " << poke1.name << " " << poke1.name << "!\"" << endl;
    outputStream << poke1.name << " has " << poke1.eyecolor << " eyes." << endl << endl;

    return outputStream;

    /*write operator overload here based on output method*/
}
