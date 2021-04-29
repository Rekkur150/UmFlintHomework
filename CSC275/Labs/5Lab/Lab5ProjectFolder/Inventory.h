#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream> //ostream
#include "InvItem.h" //InvItem

namespace storefront {

	class Inventory{
	public:
	    Inventory();
	    Inventory(int myshelfspace);
	    Inventory(const Inventory& mycopy);
	    void addInv(const InvItem& myitem);
	    Inventory& operator=(const Inventory& rtSide);
	    friend std::ostream& operator <<(std::ostream &out, const Inventory &RHS);
	    void printInv();
	    ~Inventory();
	private:
	    InvItem *invList;
	    int inStock = 0;
	    int shelfSpace;
	};

}

#endif
