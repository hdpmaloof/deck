#include "hand.h"

Hand::Hand() { }

void Hand::add(const Card &card)
{
  cards.push_back(card);
} // Hand::add

int Hand::value() const
{
  int value = 0;
  for (unsigned i = 0; i < cards.size(); i++) {
    value += cards[i].getBlackjackValue();
  } // for
  return value;
} // Hand::value

ostream &operator<<(ostream &out, const Hand &hand)
{
  bool printedOne = false;
  for (unsigned i = 0; i < hand.cards.size(); i++) {
    if (printedOne) out << ',';
    out << hand.cards[i];
    printedOne = true;
  } // for
  return out;
} // operator<<
