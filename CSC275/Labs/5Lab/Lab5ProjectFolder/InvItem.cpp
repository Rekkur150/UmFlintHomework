#include "InvItem.h" //InvItem
#include <iostream> //ostream, cout, endl
#include <string> //string

using namespace std;

namespace storefront {

	int InvItem::itemCount = 0;

	InvItem::InvItem() : InvItem(0,"generic item") {
	/*intentionally empty*/
	}

	InvItem::InvItem(int myquant) : InvItem(myquant,"generic item") {
	/*intentionally empty*/
	}

	InvItem::InvItem(string myname) : InvItem(0,myname) {
	/*intentionally empty*/
	}

	InvItem::InvItem(int myquant, string myname) : quantity(myquant), name(myname) {
	    id = itemCount;
	    itemCount += 1;
	}

	void InvItem::setQuantity(int myq){
	    quantity = myq;
	}

	int InvItem::getQuantity(){
	    return quantity;
	}

	string InvItem::getName(){
	    return name;
	}

	int InvItem::getID(){
	    return id;
	}

	void InvItem::printItem(){
	    cout << "Item ID: " << id << endl;
	    cout << "Name: " << name << endl;
	    cout << "Quantity: " << quantity << endl;
	}

	ostream& operator <<(ostream &out, const InvItem &RHS){
	    out << "Item ID: " << RHS.id << endl;
	    out << "Name: " << RHS.name << endl;
	    out << "Quantity: " << RHS.quantity << endl;
	    return out;
	}

	int InvItem::getItemCount(){
	    return itemCount;
	}

}
