#pragma once
#include <iostream>
#include <string>
#include "Chain.h"
#include "Hand.h"
#include <typeinfo>
using namespace std;
class Player {
public:
	Player(istream& in, Chain<Card>& c0, Chain<Card>& c1, Chain<Card>& c2, Hand& h);
	void addCoins(int c) {
		coins += c;
	}
	string& getName() {
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
			if (hand.top() == NULL) {
				o << "Empty";
			}
			else {
				hand.top()->print(o);
			}
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
		cout << "Coins: " << coins << endl;
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
	friend ostream& operator << (ostream& out, DiscardPile& d);
	Chain<Card>& getChainAt(int i) {
		return chains[i];
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

ostream& operator << (ostream& out, Player& p)
{
	out << "name = " << p.getName() << endl;
	out << "coins = " << p.getNumCoins() << endl;
	out << "third = " << p.getNumChains() << endl;
	
	out << "chain0"<<" = " << p.getChainAt(0) << endl;
	out << "chain1" << " = " << p.getChainAt(1) << endl;
	if (p.getNumChains() == 3) {
		out << "chain2" << " = " << p.getChainAt(2) << endl;
	}
	
	out << *p.getHand() << endl;
	
	return out;
}

Player::Player(istream& in, Chain<Card>& c0, Chain<Card>& c1, Chain<Card>& c2, Hand& h) //constructor for when the game is resumed from file
{
	in >> name;
	in >> coins;
	int t;
	in >> t;
	if (t == 3) {
		third = true;
	}
	else {
		third = false;
	}
	chains[0] = c0;
	chains[1] = c1;
	chains[2] = c2;
	hand = h;
}