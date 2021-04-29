#include <iostream>

using namespace std;

int main(){

int value = 5;

try{

       cout << "First: " << value << endl;
       throw value;

       cout << "Second: " << value * 2 << endl;
}
catch(int e){
       cout << "Third: " << e * 3 << endl;
       e = 1;
}

cout << "Fourth: " << value * 4;

return 0;

}
