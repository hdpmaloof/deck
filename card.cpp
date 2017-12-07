#include "card.h"

Card::Card()
{
  setSuit( 'S' );
  setRank( "A" );
} // Card::Card

Card::Card(char suit, string rank) throw ( invalid_argument )
{
  setSuit( suit );
  setRank( rank );
} // Card::Card

Card::Card(int suit, int rank) throw ( invalid_argument )
{
  setSuit( intToSuit(suit) );
  setRank( intToRank(rank) );
} // Card::Card

char Card::getSuit() const
{
  return suit;
} // Card::getSuit

string Card::getRank() const
{
  return rank;
} // Card::getRank

int Card::getBlackjackValue(bool soft) const
{
  if (rank == "A")
    return soft ? 11 : 1;
  if (rank == "10" || rank == "K" || rank == "Q" || rank == "J")
    return 10;
  else
    return int(rank.at(0)) - 48;
} // Card::getBlackjackValue

char Card::intToSuit(int suit) const
{
  char cardSuit = '\0';
  switch (suit) {
    case 0:
      cardSuit = 'C';
      break;
    case 1:
      cardSuit = 'D';
      break;
    case 2:
      cardSuit = 'H';
      break;
    case 3:
      cardSuit = 'S';
      break;
  } // switch
  return cardSuit;
} // Card::intToSuit

string Card::intToRank(int rank) const
{
  if (rank == 0)
    return "A";
  if (rank >= 1 && rank <= 8) {
    string iHateCPlusPlus;  // No constructor for chars in string!!??
    iHateCPlusPlus += char(rank + 49);
    return iHateCPlusPlus;
  } // if
  if (rank == 9)
    return "10";
  if (rank == 10)
    return "J";
  if (rank == 11)
    return "Q";
  if (rank == 12)
    return "K";
  return "";
} // Card::intToRank

void Card::setSuit(char suit) throw ( invalid_argument )
{
  if (suit != 'C' && suit != 'D' && suit != 'H' && suit != 'S') {
    stringstream ss;
    ss << "Card::setSuit: Invalid suit: " << suit;
    throw invalid_argument( ss.str() );
  } // if
  this->suit = suit;
} // Card::setSuit

void Card::setRank(string rank) throw ( invalid_argument )
{
  bool error = false;
  if (rank.size() == 1) {
    string ranks = "23456789JQKA";
    if (rank.find( ranks ) != string::npos) {
      error = true;
    } // if
  } // if
  else if (rank != "10") {
    error = true;
  } // else
  if ( error ) {
    stringstream ss;
    ss << "Card::setRank: Invalid rank: " << rank;
    throw invalid_argument( ss.str() );
  } // if
  this->rank = rank;
} // Card::setRank

ostream &operator<<(ostream &out, const Card &card)
{
  out << "[" << card.rank << "," << card.suit << "]";
  return out;
} // operator<<
