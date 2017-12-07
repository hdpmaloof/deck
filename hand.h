#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <vector>
#include "card.h"

using namespace std;

class Hand {

  friend ostream &operator<<(ostream &out, const Hand &hand);

  public:
    Hand();
    void add(const Card &card);
    int value() const;

  private:
    vector<Card> cards;

}; // Hand class

#endif
