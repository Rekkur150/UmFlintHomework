#include <iostream>
#include <string>

using namespace std;

class InvItem{
public:
    InvItem();
    InvItem(int myquant);
    InvItem(string myname);
    InvItem(int myquant, string myname);
    void setQuantity(int myq);
    int getQuantity();
    string getName();
    int getID();
    void printItem();
    friend ostream& operator <<(ostream &out, const InvItem &RHS);
    static int getItemCount();
    //InvItem& operator=(const InvItem& rtSide);
private:
    static int itemCount;
    int quantity;
    int id;
    string name;

};

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




class Inventory{
public:
    Inventory();
    Inventory(int myshelfspace);
    Inventory(const Inventory& mycopy);
    void addInv(const InvItem& myitem);
    Inventory& operator=(const Inventory& rtSide);
    friend ostream& operator <<(ostream &out, const Inventory &RHS);
    void printInv();
    ~Inventory();
private:
    InvItem *invList;
    int inStock = 0;
    int shelfSpace;
};



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
