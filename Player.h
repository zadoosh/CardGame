#pragma once
#include <iostream>
#include <string>
#include "Chain.h"
#include "Hand.h"
#include <typeinfo>
using namespace std;

class Player {
public:
	// constructor to reconstruct player object from file
	Player(istream& in, Chain<Card>& c0, Chain<Card>& c1, Chain<Card>& c2, Hand& h);

	// adds coins player earns from selling a chain
	void addCoins(int c) {
		coins += c;
	}

	// returns a reference to player's name
	string& getName() {
		return name;
	}

	// adds a card to the player's hand
	void addCard(Card *c) {
		hand += c;
	}

	// returns player's coin total
	int const getNumCoins() {
		return coins;
	}

	// returns player's number of chains
	// returns 3 by checking boolean third which would be true if player has a 3rd chain
	// returns 2 if third is false
	int getMaxNumChains() {
		if (third) {
			return 3;
		}
		else {
			return 2;
		}
	}

	// returns the number of chains the player has currently
	int getNumChains() {
		int count = 0;
		// must check if chain is empty to not count that as a chain the player has
		for (Chain<Card> c : chains) {
			if (!((&c)->isEmpty())) {
				count++;
			}
		}
		return count;
	}

	// prints the top card of the player's hand (with argument false) or all of the player's hand (with argument true) to the supplied ostream
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

	// overwrite operator [] to returns the chain at position i
	Chain<Card>& operator[](int i) {
		return chains[i];
	}

	// adds an empty third chain to the player for three coins
	// reduces the coin count for the player by two
	void buyThirdChain() {
		if (coins < 3) {
			throw("NotEnoughCoins");
		}
		third = true;
		coins = coins - 2;
	}

	// Player constructor with name
	Player(string n) {
		name = n;
		coins = 0;
	}

	// Default player constructor
	Player() {
		coins = 0;
		name = "";
	}

	// to print player's chains and coins to console
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

	// returns a pointer to the player's hand
	Hand* getHand() {
		return &hand;
	}

	// checks to see if the player is able to add the current card being played to a current chain
	// returns true if it could add to a current chain or if a chain was empty and it could start a new one 
	// returns false if it could not 
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

	// sells the chain selected by the player and returns the coins earned for selling the chain and creating a new one at that position
	int sellChainAndAdd(int pos, Card* c) {
		int coins = ((&chains[pos])->sell());
		chains[pos] = Chain<Card>(c);
		return coins;
	}
	// the insertion operator (friend) to print a Player to an std::ostream 
	friend ostream& operator << (ostream& out, DiscardPile& d);

	Chain<Card>& getChainAt(int i) {
		return chains[i];
	}

private:

	// overwrites += operator to add to player coins
	Player& operator+=(int n) {
		coins += n;
	}

	string name; // player name
	int coins=0; // playe coins
	bool third = false; // if player has a third chain successfully purchased
	Chain<Card> chains[3]; // holds player's chains (default size 3)
	Hand hand; // player's hand
};

// the insertion operator (friend) to print a Player to an std::ostream 
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