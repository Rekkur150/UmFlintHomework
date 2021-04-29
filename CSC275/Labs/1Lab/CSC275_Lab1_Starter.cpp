// Zachary Holmes
// CSC275 Lab1

#include <iostream>
#include <string>

using namespace std;

class Int_Item_ZH
{
public:
    Int_Item_ZH();
    void set_name(string my_name);
    void set_purchase_cost(double my_cost);
    void set_sale_price(double my_price);

    double place_order(int num_ordered);
    void receive_all_orders();
    double sell_quantity(int num_sold);

private:
    string name;
    double sale_price;
    double purchase_cost;
    int in_stock;
    int on_order;
};


int main()
{
    double budget = 10.0;
    Int_Item_ZH apple;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    apple.set_name("Apple");
    apple.set_purchase_cost(0.1);
    apple.set_sale_price(0.5);

    cout << "The current budget is: $" << budget << endl;
    /*Replace each comment with a line of code to get the desired functionality.
    I suggest at least getting the method headers correct first
    so that you can do testing.*/
    //Place an order for 5 apples and update the budget
	budget -= apple.place_order(5);
    cout << "The current budget is: $" << budget << endl;
    //Try to sell 2 apples and update the budget (this will cause me to sell 2 apples I don't have unless you did the extra credit)
	budget += apple.sell_quantity(2);
    cout << "The current budget is: $" << budget << endl;
    //Place an order for 3 more apples and update the budget
	budget -= apple.place_order(3);
    cout << "The current budget is: $" << budget << endl;
    //Receive all outstanding orders
	apple.receive_all_orders();
    //Order 4 apples and update the budget
	budget -= apple.place_order(4);
    cout << "The current budget is: $" << budget << endl;
    //Try to sell 8 apples and update the budget
	budget += apple.sell_quantity(8);
    cout << "The current budget is: $" << budget << endl;
    //Try to sell another apple and update the budget
	budget += apple.sell_quantity(1);
    cout << "The current budget is: $" << budget << endl;
    //Try to order 0 apples and update the budget
	budget -= apple.place_order(0);
    cout << "The current budget is: $" << budget << endl;
    //Receive all outstanding orders
	apple.receive_all_orders();
    //Try to sell 2 apples and update the budget
	budget += apple.sell_quantity(2);
    cout << "The current budget is: $" << budget << endl;

    return 0;
}

//Default constructor for Int_Item_ZH initializing name to empty string and all numerical values to 0
Int_Item_ZH::Int_Item_ZH() {
    name = "";
    sale_price = 0;
    purchase_cost = 0;
    in_stock = 0;
    on_order = 0;
}

//set_name
//Purpose:  Store a provided name for the item
//Preconditions:  A string representing the item's new name
//Postconditions:  Store the string as the item's new name
//                 and output confirmation message to the user.
void Int_Item_ZH::set_name(string my_name){
    cout << "Inventory item " << name << " renamed to "
            << my_name << endl;
    name = my_name;
}

//set_sale_price
//Purpose:  Store a provided sale price for the item
//Preconditions:  A floating point value for the item's new sale price
//Postconditions:  If the provided sale price is negative, output an error message
//  Otherwise, store the new price
//             and output confirmation message to the user.
void Int_Item_ZH::set_sale_price(double my_price) {
    if( my_price >= 0) {
        cout << "Inventory item " << name << " sale price adjusted from $"
            << sale_price << " to $" << my_price << endl;
        sale_price = my_price;
    }
    else{
        cout << "Pricing error:  Sale price must be non-negative value." << endl;
    }
}

//set_purchase_cost
//Purpose:  Store a provided purchase for the item
//Preconditions:  A floating point value for the item's new purchase cost
//Postconditions:  If the provided purchase cost is negative, output an error message
//  Otherwise, store the new cost
//             and output confirmation message to the user.
void Int_Item_ZH::set_purchase_cost(double my_cost) {
    if( my_cost >= 0) {
        cout << "Inventory item " << name << " purchase cost adjusted from $"
            << purchase_cost << " to $" << my_cost << endl;
        purchase_cost = my_cost;
    }
    else{
        cout << "Pricing error:  Purchase cost must be non-negative value." << endl;
    }
}

//place_order
//Purpose:  Place an order for additional units of this inventory item.
//Preconditions:  Integer number of items to order.
//Postconditions:  If the number ordered is not positive, output an error message and return 0.
// Otherwise, output order details to the user,
//            add the order to the total quantity on order,
//            and return the total cost of the order as a positive value.
double Int_Item_ZH::place_order(int num_ordered) {
    /*Modify the body of this function to get the desired functionality:*/
	if (num_ordered < 1) {
		cerr << "You can't order a non positive amount of " << name << endl;
		return 0;
	}

    double total_order_cost = num_ordered * purchase_cost;
    cout << "You have ordered " << num_ordered << " new units of " << name << endl;
    cout << "The total cost of the new order is " << total_order_cost << endl;
    cout << "The total quantity on order has increased from " << on_order << " to " << on_order + num_ordered << endl;
	on_order += num_ordered;
    return total_order_cost;
}

//receive_all_orders
//Purpose:  Receive all outstanding orders for this inventory item.
//Preconditions:  None
//Postconditions:  If there are 0 items on order, output an error message.
// Otherwise, output order receipt details to the user
//            and update the on-hand inventory after receipt.
void Int_Item_ZH::receive_all_orders() {
    /*Modify the body of this function to get the desired functionality:*/
	if (on_order == 0) {
		cerr << "No units on order" << endl;
	} else {
    	cout << "You have received " << on_order << " units of " << name << endl;
   		cout << "The new quantity in inventory is " << on_order + in_stock << endl;
		in_stock += on_order;
		on_order = 0;
	}
}

//sell_quantity
//Purpose:  Perform a sale of an integer number of units of this inventory item.
//Preconditions:  Integer number of items to sell.
//Postconditions:  If the number sold is not positive, output an error message and return 0.
// Otherwise, output sale details to the user,
//            update inventory after the sale,
//            and return the total dollar amount earned by the sale as a positive value.
// **** EXTRA CREDIT: +5 points:  If number you want to sell is greater than number in stock, report an error message instead of performing the sale
double Int_Item_ZH::sell_quantity(int num_sold) {
    /*Modify the body of this function to get the desired functionality:*/
	if (num_sold < 1) {
		cerr << "You can't sell non positive units" << endl;
		return 0;
	}

	if ((in_stock - num_sold) < 0) {
		cerr << "You can't sell more than you have in stock" << endl;
		return 0;
	}

    double total_sale_value = num_sold * sale_price;
    cout << "You have sold " << num_sold << " units of " << name << endl;
    cout << "The gross income from the sale is " << total_sale_value << endl;
    cout << "You have " << in_stock - num_sold << " units remaining in stock " << endl;
	in_stock -= num_sold;

    return total_sale_value;

}
