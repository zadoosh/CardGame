#pragma once
#include <iostream>
#include <list>
#include "Card.h"

using namespace std;
class TradeArea {

public:
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
	int const numCards() {
		return cards.size();
	}
	void print() {
		for (Card* c : cards)
		{
			c->print(cout);
		}
	}
//private:
	TradeArea& operator+=(Card* c) { 
		cards.push_back(c);
		return *this;
	}
	std::list<Card*> cards;
};