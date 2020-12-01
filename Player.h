#pragma once
#include <iostream>
#include <string>
#include "Chain.h"
#include "Hand.h"
#include <typeinfo>
using namespace std;
class Player {
public:
	string const getName() {
		return name;
	}
	void addCard(Card *c) {
		hand += c;
	}
	int const getNumCoins() {
		return coins;
	}
	int getMaxNumChains() {
		if (third) {
			return 3;
		}
		else {
			return 2;
		}
	}
	int getNumChains() {
		int count = 0;
		for (Chain<Card> c : chains) {
			if (!((&c)->isEmpty())) {
				count++;
			}
		}
		return count;
	}
	void printHand(ostream &o,bool b)
	{
		if (b == false) //if false, print top card of player's hand
		{
			hand.top()->print(o);
		}
		if (b == true) // if true, print entire hand
		{
			hand.printHand();
		}
	}
	Chain<Card>& operator[](int i) {
		return chains[i];
	}

	void buyThirdChain() {
		if (coins < 3) {
			throw("NotEnoughCoins");
		}
		third = true;
		coins = coins - 2;
	}
	Player(string n) {
		name = n;
		coins = 0;
	}
	Player() {
		coins = 0;
		name = "";
	}
	void printChains() {
		for (int i = 0; i < getMaxNumChains(); i++) {
			cout << "Chain" << (i + 1) << ": " ;
			if (chains[i].isEmpty()) {
				cout << "Empty" << endl;
			}
			else {
				(&chains[i])->print();
				cout << "\n";
			}
		}
	}
	Hand* getHand() {
		return &hand;
	}
	bool addToChain(Card* c) {
		for (int i = 0; i < getMaxNumChains();i++) { // trying to add card to existing chain of that card
			if (!((&chains[i])->isEmpty())) {
				Chain<Card> temp = chains[i];
				if (temp.printTypeName()== c->getName()) {
					chains[i] += c;
					return true;
				}
			}
		}
		for (int i = 0; i < getMaxNumChains(); i++) { // if it reaches here than it was unsuccessful in adding to a chain, so look for an empty spot and create a chain if there is space for a new chain to be created
			if (((&chains[i])->isEmpty())) {
				chains[i] += c;
				return true;
			}
		}
		return false; // returns false if unable to add card to a chain or create a new chain since chain slots are full
	}
	int sellChainAndAdd(int pos, Card* c) {
		int coins = ((&chains[pos])->sell());
		chains[pos] = Chain<Card>(c);
		return coins;
	}
private:
	Player& operator+=(int n) {
		coins += n;
	}
	string name;
	int coins=0;
	bool third = false;
	Chain<Card> chains[3] ;
	Hand hand;
};