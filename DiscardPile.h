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
        Card* top()const; // returns but does not remove the top card from the discard pile
        void print(ostream&)const; // to insert all the cards in the DiscardPile to an std::ostream.
        friend ostream& operator << (ostream& out, DiscardPile& d); // the insertion operator (friend) to insert only the top card of the discard pile to an std::ostream
    protected:
        int size; // keep track of discard pile size
};

//constructor for when the game is resumed from file
DiscardPile::DiscardPile(istream& in) 
{
	int i = 0; // counter to keep track of discard pile size
	while (!in.eof()) {
		string temp;
		in >> temp;
		if (temp == "Blue") { // checks if string in istream is Blue 
			Card* tempCard = new Blue(); // creates temp card to add to discard pile
			push_back(tempCard); // adds card to discard pile
			i++; // increments counter to keep track of discard pile size
		}
		if (temp == "Chili") { // checks if string in istream is Chili 
			Card* tempCard = new Chili(); // creates temp card to add to discard pile
			push_back(tempCard); // adds card to discard pile
			i++; // increments counter to keep track of discard pile size
		}
		if (temp == "Stink") { // checks if string in istream is Stink 
			Card* tempCard = new Stink(); // creates temp card to add to discard pile
			push_back(tempCard); // adds card to discard pile
			i++; // increments counter to keep track of discard pile size
		}
		if (temp == "Green") { // checks if string in istream is Green 
			Card* tempCard = new Green(); // creates temp card to add to discard pile
			push_back(tempCard); // adds card to discard pile
			i++; // increments counter to keep track of discard pile size
		}
		if (temp == "soy") { // checks if string in istream is soy 
			Card* tempCard = new soy(); // creates temp card to add to discard pile
			push_back(tempCard); // adds card to discard pile
			i++; // increments counter to keep track of discard pile size
		}
		if (temp == "black") { // checks if string in istream is black 
			Card* tempCard = new black(); // creates temp card to add to discard pile
			push_back(tempCard); // adds card to discard pile
			i++; // increments counter to keep track of discard pile size
		}
		if (temp == "Red") { // checks if string in istream is Red 
			Card* tempCard = new Red(); // creates temp card to add to discard pile
			push_back(tempCard); // adds card to discard pile
			i++; // increments counter to keep track of discard pile size
		}
		if (temp == "garden") { // checks if string in istream is garden 
			Card* tempCard = new garden(); // creates temp card to add to discard pile
			push_back(tempCard); // adds card to discard pile
			i++; // increments counter to keep track of discard pile size
		}
		
	}
	size = i;  // sets discard pile size after adding Cards to discard pile 
}

// discards the card to the pile
DiscardPile& DiscardPile::operator+=(Card *c)
{
    this->push_back(c);
    size++;
    return *this; 
}

// returns and removes the top card from the discard pile
Card* DiscardPile::pickUp()
{
    Card* back = this->back();
    this->pop_back();
    size--;
    return(back); //It is used to pop or remove elements from a vector from the back
}

// returns but does not remove the top card from the discard pile
Card* DiscardPile::top() const{
    if (size == 0) {
        return NULL;
    }
    else {
        return(this->back()); //Returns a reference to the last element in the vector
    }
}

// to insert all the cards in the DiscardPile to an std::ostream
void DiscardPile::print(ostream& out)const
{
    out << "DiscardPile" << endl;
    for(Card *c : *this)
    {
        c->print(out);
    }
}

// the insertion operator to insert only the top card of the discard pile to an std::ostream
ostream& operator << (ostream& out, DiscardPile& d)
{
    out << "discardpile=";
    for (int i = 0; i < d.size; i++) {
        out << d[i]->getName() <<" ";
    }
    return out;
}