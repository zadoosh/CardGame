#pragma once
#include <iostream>
#include <vector>
#include "Card.h"
#include "CardFactory.h"
using namespace std;

class DiscardPile : vector<Card*>{
    public:
        DiscardPile() { size = 0; };
        DiscardPile(istream& in, const CardFactory*); // is a constructor which accepts an istream and reconstructs the DiscardPile from file. 
        DiscardPile& operator+=(Card*); // discards the card to the pile.
        Card* pickUp(); // returns and removes the top card from the discard pile.
        Card* top(); // returns but does not remove the top card from the discard pile
        void print(ostream&); // to insert all the cards in the DiscardPile to an std::ostream.
    protected:
        int size;
};
/*
DiscardPile::DiscardPile(istream& in, const CardFactory* cf) //constructor for when the game is resumed from file
{
    
}
*/
DiscardPile& DiscardPile::operator+=(Card *c)
{
    this->push_back(c);
    return *this; 
}

Card* DiscardPile::pickUp()
{
    Card* back = this->back();
    this->pop_back();
    return(back); //It is used to pop or remove elements from a vector from the back
}

Card* DiscardPile::top()
{
    if (size == 0) {
        return NULL;
    }
    else {
        return(this->back()); //Returns a reference to the last element in the vector
    }
}

void DiscardPile::print(ostream& out)
{
    out << "DiscardPile" << endl;
    for(Card *c : *this)
    {
        c->print(out);
    }
}