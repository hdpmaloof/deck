#include "deck.h"

Deck::Deck()
{
  for (int suit = 0; suit < Card::suits; suit++) {
    for (int value = 0; value < Card::values; value++) {
      Card newCard(suit, value);
      cards.push_back( newCard );
    } // for
  } // for
  shuffle();
} // Deck::Deck

bool Deck::empty() const
{
  return cards.empty();
} // Deck::empty()

void Deck::shuffle()
{
  random_shuffle(cards.begin(), cards.end());
} // Deck::shuffle()

Hand Deck::dealHand(unsigned nCards) throw (invalid_argument)
{
  Hand hand;
  if (empty() || cards.size() < nCards) {
    throw invalid_argument( "Deck::dealHand: Not enough cards in deck." );
  } // if
  for (unsigned i = 0; i < nCards; i++) {
    hand.add( dealCard() );
  } // for
  return hand;
} // Deck::dealHand

Card Deck::dealCard() throw (invalid_argument)
{
  if ( empty() ) {
    throw invalid_argument( "Deck::dealCard: Deck is empty." );
  } // if
  int card = rand() % cards.size();
  Card dealtCard = cards[card];
  swap( cards[card], cards.back() );
  cards.pop_back();
  return dealtCard;
} // Deck::dealCard

ostream &operator<<(ostream &out, const Deck &deck)
{
  bool printedOne = false;
  for (unsigned i = 0; i < deck.cards.size(); i++) {
    if (printedOne) out << ',';
    out << deck.cards[i];
    printedOne = true;
  } // for
  return out;
} // operator<<
