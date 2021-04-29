#include <iostream>

using namespace std;

int flip();

bool read(int bias, int flip);

int main() {

  int bias, tosses;

  int result = 0;

  int heads = 0;

  int tails = 0;

  int side = 0;

  srand(time(NULL));

  cout << "Bias of coinflip: ";

  cin >> bias;

  cout << endl << "Number of tosses: ";

  cin >> tosses;

  while (result < tosses) {

    side = read(bias, flip());

    if (side == 0) {

      heads++;

    } else {

      tails++;

    }

    result++;

  }

  cout << "Heads: " << heads << endl

         << "Tails: " << tails << endl;

  return 0;

}

int flip() {

  return (rand() % 100 + 1); //rand() % 100 would be 0-99 + 1 makes it 1-100

}

bool read(int bias, int flip) {

  if (flip <= bias) {

    return 0;

  }

  return 1;

}



