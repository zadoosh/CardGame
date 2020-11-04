#include <iostream>
#include "Card.h"
#include "CardFactory.h"
using namespace std;

class DiscardPile {
    public:
        DiscardPile(istream& in, const CardFactory* cf); // is a constructor which accepts an istream and reconstructs the DiscardPile from file. 
        DiscardPile& operator+=(Card*); // discards the card to the pile.
        Card* pickUp(); // returns and removes the top card from the discard pile.
        Card* top(); // returns but does not remove the top card from the discard pile
        void print(ostream& out); // to insert all the cards in the DiscardPile to an std::ostream.
};