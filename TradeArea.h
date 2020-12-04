#pragma once
#include <iostream>
#include <list>
#include "Card.h"

using namespace std;
class TradeArea {

public:
	TradeArea() {

	}
	bool const legal(Card* c) {
		for (std::list<Card*>::iterator itr = cards.begin(); itr != cards.end(); itr++) {
			if ((*itr)->getName() == c->getName()) {
				return true;
			}
		}
		return false;
	}
	Card* const trade(string name) {
		for (std::list<Card*>::iterator itr = cards.begin(); itr != cards.end(); itr++) {
			if ((*itr)->getName() == name) {
				Card* temp = (*itr);
				cards.erase(itr);
				return temp;
			}
		}
	}
	void discard(DiscardPile &p) {
		for (Card* c: cards) {
			Card* temp = c;
			p+=temp;
		}
		cards = {};
	}
	int const numCards() {
		return cards.size();
	}
	void print() {
		int count = 0;
		for (Card* c : cards)
		{
			cout << "Card #" << count << ": ";
			c->print(cout);
			cout << "\t";
			count++;
		}
	}

	TradeArea& operator+=(Card* c) { 
		cards.push_back(c);
		return *this;
	}
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
	friend ostream& operator << (ostream& out, DiscardPile& d);
	TradeArea(istream& in);

private:
	std::list<Card*> cards = {};

};
ostream& operator << (ostream& out, TradeArea& t)
{
	out << "tradearea = ";
	for (int i = 0; i < t.numCards(); i++) {
		out << t.cardNameAt(i)<<" ";
	}
	return out;
}
TradeArea::TradeArea(istream& in) //constructor for when the game is resumed from file
{
	while (!in.eof()) {
		string temp;
		in >> temp;
		if (temp == "Blue") {
			Card* blue = new Blue();
			cards.push_back(blue);
		}
		if (temp == "Chili") {
			Card* blue = new Chili();
			cards.push_back(blue);
		}
		if (temp == "Stink") {
			Card* blue = new Stink();
			cards.push_back(blue);
		}
		if (temp == "Green") {
			Card* blue = new Green();
			cards.push_back(blue);
		}
		if (temp == "soy") {
			Card* blue = new soy();
			cards.push_back(blue);
		}
		if (temp == "black") {
			Card* blue = new black();
			cards.push_back(blue);
		}
		if (temp == "Red") {
			Card* blue = new Red();
			cards.push_back(blue);
		}
		if (temp == "garden") {
			Card* blue = new garden();
			cards.push_back(blue);
		}
	}
}