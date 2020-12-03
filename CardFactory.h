#pragma once
#include <iostream>
#include "Deck.h"
#include "Card.h"
#include <algorithm>
#include <random>  
#include <chrono>

using namespace std;
class CardFactory {
public:
	static CardFactory* getFactory();
	Deck& getDeck() {
		return *cards;
	}
private:
	static CardFactory* factory;
	CardFactory(const CardFactory&);
	CardFactory() { 
		cards = new Deck();
		for (int i = 0; i < 20; i++) {
			Card* temp = new Blue();
			cards->push_back(temp);
		}
		for (int i = 0; i < 18; i++) {
			Card* temp = new Chili();
			cards->push_back(temp);
		}
		for (int i = 0; i < 16; i++) {
			Card* temp = new Stink();
			cards->push_back(temp);
		}
		for (int i = 0; i < 14; i++) {
			Card* temp = new Green();
			cards->push_back(temp);
		}
		for (int i = 0; i < 12; i++) {
			Card* temp = new soy();
			cards->push_back(temp);
		}
		for (int i = 0; i < 10; i++) {
			Card* temp = new black();
			cards->push_back(temp);
		}
		for (int i = 0; i < 8; i++) {
			Card* temp = new Red();
			cards->push_back(temp);
		}
		for (int i = 0; i < 6; i++) {
			Card* temp = new garden();
			cards->push_back(temp);
		}
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

		shuffle(cards->begin(), cards->end(), default_random_engine(seed));
	}
	CardFactory& operator = (const CardFactory&);

	Deck* cards;
};
CardFactory* CardFactory:: factory = NULL;

CardFactory* CardFactory::getFactory() {
	if (factory == NULL) {
		factory = new CardFactory();
	}
	return(factory);
}

