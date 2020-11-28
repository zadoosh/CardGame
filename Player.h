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
		for (Chain<Card>* c : chains) {
			if (!(c->isEmpty())) {
				count++;
			}
		}
		return count;
	}
	
	Chain<Card>& operator[](int i) {
		return *chains[i];
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
			if (chains[i] == NULL) {
				cout << "Empty" << endl;
			}
			else {
				chains[i]->print();
			}
		}
	}
	Hand* getHand() {
		return &hand;
	}
	bool addToChain(Card* c) {
		for (int i = 0; i < getMaxNumChains();i++) {
			if (!(chains[i]->isEmpty())) {
				if (typeid(chains[i]) == typeid(c)) {
					*chains[i] += c;
					return true;
				}
			}
		}
		for (int i = 0; i < getMaxNumChains(); i++) {
			if ((chains[i]->isEmpty())) {
				*chains[i] += c;
				return true;
			}
		}
		return false;
	}
	int sellChainAndAdd(int pos, Card* c) {
		int coins = (chains[pos]->sell());
		chains[pos] = &Chain<Card>(c);
		return coins;
	}
private:
	Player& operator+=(int n) {
		coins += n;
	}
	string name;
	int coins=0;
	bool third = false;
	Chain<Card>* chains[3];
	Hand hand;
};