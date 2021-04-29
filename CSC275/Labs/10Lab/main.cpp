#include <iostream>
#include <string>

using namespace std;

int getProductID(int ids[], string names[], int numProducts, string target) throw(string);

int main()
{
    int productIds[] = {4,5,8,10,13};
    string products[] = {"computer","flash drive","mouse","printer","camera"};
    string searchtarget;
	try {
		cout << getProductID(productIds, products, 5, "computer") << endl;     //4
		cout << getProductID(productIds, products, 5, "mouse") << endl;     //8
		cout << getProductID(productIds, products, 5, "camera") << endl;    //13
		cout << getProductID(productIds, products, 5, "laptop") << endl;    //-1
		cout << "Give another product you want to search for: ";
		cin >> searchtarget;
		cout << getProductID(productIds, products, 5, searchtarget) << endl;    //?????
	}
	catch (string name) {
		cout << name << " is not found" << endl;
	}

    return 0;
}


int getProductID(int ids[], string names[], int numProducts, string target) throw (string) {
    for(int i = 0; i < numProducts; i++){
        if (names[i] == target)
            return ids[i];
    }
    throw target;  //not found

}
