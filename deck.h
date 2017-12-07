#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>
#include "hand.h"
#include "card.h"

using namespace std;

class Deck {

  friend ostream &operator<<(ostream &out, const Deck &deck);

  public:
    Deck();
    bool empty() const;
    void shuffle();
    Hand dealHand(unsigned nCards) throw (invalid_argument);
    Card dealCard() throw (invalid_argument);

  private:
    vector<Card> cards;

}; // Deck class

#endif
