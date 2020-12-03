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
private:
	std::list<Card*> cards = {};

};