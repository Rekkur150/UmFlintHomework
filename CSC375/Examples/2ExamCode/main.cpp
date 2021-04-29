#include <iostream>
#include "Coin.h"
using namespace std;

int main(void)
{
    Coin c;
    int heads = 0,
        tails = 0,
        tosses = 0,
        bias = 50;

    // user input for bias
    cout << "Enter bias [50 = fair coin, 75 biases towards heads, etc.]: ";
    cin >> bias;
    c.setBias(bias); // apply the bias the user gives us

    // user input for coin tosses
    cout << "How many tosses? ";
    cin >> tosses;

    // simulate the series of coin tosses
    for (int i = 0; i < tosses; i++) {
        c.flip();
        if (c.read() == 0) heads++;
        else tails++;
    }

    // display the results
    cout << "Heads: " << heads << endl;
    cout << "Tails: " << tails << endl;

    return(0);
}
