#ifndef COIN_H
#define COIN_H

class Coin {
public:
  Coin();
  void flip();
  void setBias(int newBias);
  int read() const;

private:
  int side = 1;
  int bias = 1;
};

Coin::Coin() {

  srand(time(NULL));

  bias = 50;

  side = (rand() % 100) + 1;

}

void Coin::flip() {

  side = (rand() % 100) + 1;

}

void Coin::setBias(int newBias) {

  if (newBias > 0 && newBias <= 100) {

    bias = newBias;

  }

}

int Coin::read() const {

  if (side <= bias)  {

    return 0;

  } else {

    return 1;

  }

}

#endif
