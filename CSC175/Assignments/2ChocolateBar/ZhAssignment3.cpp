// Zachary Holmes
// Assignment 3
// 9/27/17

#include <iostream>
using namespace std;

// Global Variables
const int COST_OF_CHOCOLATE_BAR = 1;
const int NUMBER_OF_COUPONS_PER_REDEEM = 7;
const int NUMBER_OF_COUPONS_PER_CHOCOLATE_BAR = 1;
const int NUMBER_OF_CHOCOLATE_BARS_PER_REDEEMED_COUPONS = 1;

int main() {

	// Variables
	int amountOfCoupons = 0;
	int amountOfChocolateBars = 0;
	int money = 0;

	// Input
	cout << "How much money are you going to spend on chocolate bars?" << endl
	     << "Money Input: ";
	cin >> money;

	//Calculations
	amountOfChocolateBars += money/COST_OF_CHOCOLATE_BAR;
	amountOfCoupons = amountOfChocolateBars * NUMBER_OF_COUPONS_PER_CHOCOLATE_BAR;

	//While loop to compute coupons per time
	while (amountOfCoupons >= NUMBER_OF_COUPONS_PER_REDEEM) {
		amountOfChocolateBars += NUMBER_OF_CHOCOLATE_BARS_PER_REDEEMED_COUPONS;
		amountOfCoupons += NUMBER_OF_COUPONS_PER_CHOCOLATE_BAR;

		amountOfCoupons -= NUMBER_OF_COUPONS_PER_REDEEM;
	}

	//Output
	cout << "With " << money << " dollars you will get " << endl
	     << amountOfChocolateBars << " Chocolate bars with a remainder of " << amountOfCoupons << " coupons" << endl;


	return 0;
}
