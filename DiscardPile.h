#include <iostream>
#include <vector>
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
    private:
        vector<Card*> dPile; // vector to hold the discarded cards
};

Card* DiscardPile::pickUp()
{
    return(dPile.pop_back()); //It is used to pop or remove elements from a vector from the back
}

Card* DiscardPile::top()
{
    return(dPile.back()); //Returns a reference to the last element in the vector
}