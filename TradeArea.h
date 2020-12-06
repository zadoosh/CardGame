#pragma once
#include <iostream>
#include <list>
#include "Card.h"

using namespace std;
class TradeArea {

public:

	// default constructor
	TradeArea() {} 

	// returns true if the card can be legally added to the TradeArea
	bool  legal(Card* c) {
		for (std::list<Card*>::iterator itr = cards.begin(); itr != cards.end(); itr++) {
			if ((*itr)->getName() == c->getName()) {
				return true;
			}
		}
		return false;
	}

	// removes a card of the corresponding bean name from the trade area
	Card* const trade(string name) {
		for (std::list<Card*>::iterator itr = cards.begin(); itr != cards.end(); itr++) {
			if ((*itr)->getName() == name) {
				Card* temp = (*itr);
				cards.erase(itr);
				return temp;
			}
		}
	}

	// to discard a card from the trade area to discard pile
	void discard(DiscardPile &p) {
		for (Card* c: cards) {
			Card* temp = c;
			p+=temp;
		}
		cards = {};
	}

	// returns the number of cards in the trade area
	int numCards() const {
		return cards.size();
	}

	// oututs the trade area to console for the users to play
	void print() const {
		int count = 0;
		for (Card* c : cards)
		{
			cout << "Card #" << count << ": ";
			c->print(cout);
			cout << "\t";
			count++;
		}
	}

	// adds the card to the trade area but it does not check if it is legal to place the card
	TradeArea& operator+=(Card* c) { 
		cards.push_back(c);
		return *this;
	}

	// returns the card name of the card selected by user from the trade area
	string cardNameAt(int pos) {
		int count = 0;
		for (std::list<Card*>::iterator itr = cards.begin(); itr != cards.end(); itr++) {
			Card* temp = (*itr);
			if (count == pos) {
				return temp->getName();
			}
			count++;
		}
	}

	// the insertion operator (friend) to insert all the cards of the trade area to an std::ostream.
	friend ostream& operator << (ostream& out, DiscardPile& d);

	// is a constructor which accepts an istream and reconstruct the TradeArea from file.
	TradeArea(istream& in);

private:
	std::list<Card*> cards = {};

};

// the insertion operator (friend) to insert all the cards of the trade area to an std::ostream.
ostream& operator << (ostream& out, TradeArea& t)
{
	out << "tradearea = ";
	for (int i = 0; i < t.numCards(); i++) {
		out << t.cardNameAt(i)<<" ";
	}
	return out;
}

// is a constructor which accepts an istream and reconstruct the TradeArea from file
// constructor for when the game is resumed from file
TradeArea::TradeArea(istream& in) 
{
	while (!in.eof()) {
		string temp;
		in >> temp;
		if (temp == "Blue") { // check if string from istream matches card name
			Card* tempCard = new Blue(); // create a temp card
			cards.push_back(tempCard); // adds temp card back to trade area to resume playing
		}
		if (temp == "Chili") { // check if string from istream matches card name
			Card* tempCard = new Chili(); // create a temp card
			cards.push_back(tempCard); // adds temp card back to trade area to resume playing
		}
		if (temp == "Stink") { // check if string from istream matches card name
			Card* tempCard = new Stink(); // create a temp card
			cards.push_back(tempCard); // adds temp card back to trade area to resume playing
		}
		if (temp == "Green") { // check if string from istream matches card name
			Card* tempCard = new Green(); // create a temp card
			cards.push_back(tempCard); // adds temp card back to trade area to resume playing
		}
		if (temp == "soy") { // check if string from istream matches card name
			Card* tempCard = new soy(); // create a temp card
			cards.push_back(tempCard); // adds temp card back to trade area to resume playing
		}
		if (temp == "black") { // check if string from istream matches card name
			Card* tempCard = new black(); // create a temp card
			cards.push_back(tempCard); // adds temp card back to trade area to resume playing
		}
		if (temp == "Red") { // check if string from istream matches card name
			Card* tempCard = new Red(); // create a temp card
			cards.push_back(tempCard); // adds temp card back to trade area to resume playing
		}
		if (temp == "garden") { // check if string from istream matches card name
			Card* tempCard = new garden(); // create a temp card
			cards.push_back(tempCard); // adds temp card back to trade area to resume playing
		}
	}
}