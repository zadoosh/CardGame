#pragma once
#include <iostream>
#include <string>
#include "Chain.h"
#include "Hand.h"
using namespace std;
class Player {
public:
	string const getName() {
		return name;
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
		
	}
	/*
	Chain<Card>& operator[](int i) {
		return *chains[i];
	}
	*/
	void buyThirdChain() {
		if (coins < 3) {
			throw("NotEnoughCoins");
		}
		third = true;
		coins = coins - 2;
	}
	Player(string n) {
		name = n;
	}
	Player() {

	}
private:
	Player& operator+=(int n) {
		coins += n;
	}
	string name;
	int coins;
	bool third = false;
	//Chain<Card>* chains[3];
	Hand hand;
};