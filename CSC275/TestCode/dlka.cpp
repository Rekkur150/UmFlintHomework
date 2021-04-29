#include <iostream>

#include <string>

using namespace std;

class ClassA{
public:

    ClassA();

    void printValue();

    int getValue();

protected:

    int value;

};

class ClassB : public ClassA{

public:

    ClassB();

    int getValue();

};

ClassA::ClassA(){    value = 3;}

void ClassA::printValue(){    cout << getValue() << endl;}

int ClassA::getValue(){    return value;}

ClassB::ClassB(){    value = 3;}

int ClassB::getValue(){    return value*2;}


int main(){

    ClassB myObj;

    myObj.printValue();

    return 0;

}
