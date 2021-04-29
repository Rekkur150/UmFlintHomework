#ifndef INVITEM_H
#define INVITEM_H

#include <iostream> //ostream
#include <string>   //string


namespace storefront {

	class InvItem{
	public:
	    InvItem();
	    InvItem(int myquant);
	    InvItem(std::string myname);
	    InvItem(int myquant, std::string myname);
	    void setQuantity(int myq);
	    int getQuantity();
	    std::string getName();
	    int getID();
	    void printItem();
	    friend std::ostream& operator <<(std::ostream &out, const InvItem &RHS);
	    static int getItemCount();
	    //InvItem& operator=(const InvItem& rtSide);
	private:
	    static int itemCount;
	    int quantity;
	    int id;
	    std::string name;

	};
}

#endif
