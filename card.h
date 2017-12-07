#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

class Card {

  friend ostream &operator<<(ostream &out, const Card &card);

  public:
    Card();
    Card(char suit, string rank) throw ( invalid_argument );
    Card(int suit, int rank) throw ( invalid_argument );
    int getBlackjackValue(bool soft = true) const;
    char getSuit() const;
    string getRank() const;
    void setSuit(char suit) throw ( invalid_argument );
    void setRank(string rank) throw ( invalid_argument );

    static const int suits = 4;
    static const int values = 13;

  private:
    char suit;
    string rank;

    char intToSuit(int suit) const;
    string intToRank(int rank) const;

}; // Card class

#endif
