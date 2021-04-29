#include "Inventory.h" //Inventory
#include "InvItem.h" //InvItem
#include <iostream> //osteam, cin, cout, endl

using namespace std;

namespace storefront {

	Inventory::Inventory(){
	    cout << "Input max shelf space: ";
	    cin >> shelfSpace;
	    invList = new InvItem[shelfSpace];
	}
	Inventory::Inventory(int myshelfspace){
	    shelfSpace = myshelfspace;
	    invList = new InvItem[shelfSpace];
	}
	Inventory::Inventory(const Inventory& mycopy){
	    shelfSpace = mycopy.shelfSpace;
	    inStock = mycopy.inStock;
	    invList = new InvItem[shelfSpace];
	    for(int i = 0; i < inStock; i++){
		invList[i] = mycopy.invList[i];
	    }
	}
	void Inventory::addInv(const InvItem& myitem){
	    if(inStock == shelfSpace){
		cout << "Max capacity reached." << endl;
	    }
	    else{
		invList[inStock] = myitem;
		inStock += 1;
	    }
	}
	void Inventory::printInv(){
	    cout << endl <<  "Store total shelf space: " << shelfSpace << endl;
	    cout << "Store total inStock: " << inStock << endl;
	    cout << "Store remaining shelf space: " << shelfSpace - inStock << endl;
	    for(int i = 0; i< inStock; i++){
		cout << invList[i] << endl;
	    }
	}


	ostream& operator <<(ostream &out, const Inventory &RHS){
	    out << endl << "Store total shelf space: " << RHS.shelfSpace << endl;
	    out << "Store total inStock: " << RHS.inStock << endl;
	    out << "Store remaining shelf space: " << RHS.shelfSpace - RHS.inStock << endl;
	    for(int i = 0; i< RHS.inStock; i++){
		out << RHS.invList[i] << endl;
	    }
	    return out;
	}


	Inventory::~Inventory(){
	    delete [] invList;
	}
	Inventory& Inventory::operator=(const Inventory& rtSide){
	    shelfSpace = rtSide.shelfSpace;
	    inStock = rtSide.inStock;
	    delete [] invList;
	    invList = new InvItem[shelfSpace];
	    for(int i = 0; i < inStock; i++){
		invList[i] = rtSide.invList[i];
	    }
	    return *this;
	}

}
