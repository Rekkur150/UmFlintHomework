#include <iostream>
#include "Inventory.h" //Inventory
#include "InvItem.h" //InvItem

using namespace std;
using namespace storefront;

int main()
{
    cout << "====-Starting Program-====" << endl;
    cout << "[[[[  Item count: " << InvItem::getItemCount() << " ]]]]"<< endl;
    cout << "=====-Creating inventory item for 3 apples...-====" <<  endl;
    InvItem x = InvItem(3,"Apples");
    cout << "=====-Apples created.-===="  << endl;
    cout << "[[[[  Item count: " << InvItem::getItemCount() << " ]]]]"<< endl;
    cout << "=====-Creating store with max shelf space of 6...-====" <<  endl;
    Inventory myStore(6);
    cout << "=====-Original store created.-====" <<  endl;
    cout << "[[[[  Item count: " << InvItem::getItemCount() << " ]]]]"<< endl;
    cout << "=====-Adding 3 apples to original store...-====" <<  endl;
    myStore.addInv(x);
    cout << "=====-Apples added.-====" <<  endl;
    cout << "[[[[  Item count: " << InvItem::getItemCount() << " ]]]]"<< endl;
    cout << "=====-Creating inventory item for 5 bananas and adding to original store...-====" <<  endl;
    myStore.addInv(InvItem(5,"Bananas"));
    cout << "=====-Inventory creation and adding complete.-====" << endl;
    cout << "[[[[  Item count: " << InvItem::getItemCount() << " ]]]]"<< endl;

    cout << "=====-Current inventory of the original store:" <<  myStore << endl;

    cout << "=====-Creating a copy of the original store...-====" <<endl;
    Inventory newStore(myStore);
    cout << "=====-Copy created.-====" <<endl;
    cout << "[[[[  Item count: " << InvItem::getItemCount() << " ]]]]"<< endl;
    cout << "=====-Creating and adding 4 Cucumbers to the original...-==="<<endl;
    myStore.addInv(InvItem(4,"Cucumbers"));
    cout << "=====-Added Cucumbers.-==="<<endl;
    cout << "[[[[  Item count: " << InvItem::getItemCount() << " ]]]]"<< endl;
    cout << "=====-Creating and adding 2 squash to the copy...-==="<<endl;
    newStore.addInv(InvItem(2,"Squash"));
    cout << "=====-Added Squash.-==="<<endl;
    cout << "[[[[  Item count: " << InvItem::getItemCount() << " ]]]]"<< endl;


    cout << "=====-Current inventory of the original store:" << myStore <<  endl;
    cout << "=====-Current inventory of the copy:" << myStore << endl;

    cout << "=====-Assigning copy to the original store...-====" <<endl;
    myStore = newStore;
    cout << "=====-Assignment complete.-====" <<endl;
    cout << "[[[[  Item count: " << InvItem::getItemCount() << " ]]]]"<< endl;
    cout << "=====-Current inventory of the original store:" << myStore << endl;

    return 0;

}
