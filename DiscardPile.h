#pragma once
#include <iostream>
#include <vector>
#include "Card.h"
#include "CardFactory.h"
using namespace std;

class DiscardPile : vector<Card*>{
    public:
        DiscardPile() { size = 0; };
        DiscardPile(istream& in); // is a constructor which accepts an istream and reconstructs the DiscardPile from file. 
        DiscardPile& operator+=(Card*); // discards the card to the pile.
        Card* pickUp(); // returns and removes the top card from the discard pile.
        Card* top(); // returns but does not remove the top card from the discard pile
        void print(ostream&); // to insert all the cards in the DiscardPile to an std::ostream.
        friend ostream& operator << (ostream& out, DiscardPile& d);
    protected:
        int size;
};

DiscardPile::DiscardPile(istream& in) //constructor for when the game is resumed from file
{
	int i = 0;
	while (!in.eof()) {
		string temp;
		in >> temp;
		if (temp == "Blue") {
			Card* blue = new Blue();
			push_back(blue);
			i++;
		}
		if (temp == "Chili") {
			Card* blue = new Chili();
			push_back(blue);
			i++;
		}
		if (temp == "Stink") {
			Card* blue = new Stink();
			push_back(blue);
			i++;
		}
		if (temp == "Green") {
			Card* blue = new Green();
			push_back(blue);
			i++;
		}
		if (temp == "soy") {
			Card* blue = new soy();
			push_back(blue);
			i++;
		}
		if (temp == "black") {
			Card* blue = new black();
			push_back(blue);
			i++;
		}
		if (temp == "Red") {
			Card* blue = new Red();
			push_back(blue);
			i++;
		}
		if (temp == "garden") {
			Card* blue = new garden();
			push_back(blue);
			i++;
		}
		
	}
	size = i;
}
DiscardPile& DiscardPile::operator+=(Card *c)
{
    this->push_back(c);
    size++;
    return *this; 
}

Card* DiscardPile::pickUp()
{
    Card* back = this->back();
    this->pop_back();
    size--;
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

ostream& operator << (ostream& out, DiscardPile& d)
{
    out << "discardpile=";
    for (int i = 0; i < d.size; i++) {
        out << d[i]->getName() <<" ";
    }
    return out;
}