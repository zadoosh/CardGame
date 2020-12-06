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

	static CardFactory* getFactory(); // returns a pointer to the only instance of CardFactory

	Deck& getDeck() // returns a deck with all 104 bean cards
	{
		return *cards;
	}

private:

	static CardFactory* factory;

	CardFactory(const CardFactory&);

	// generate the deck from the card factory
	CardFactory() { 
		cards = new Deck();
		for (int i = 0; i < 20; i++) {
			Card* tempCard = new Blue();
			cards->push_back(tempCard);
		}
		for (int i = 0; i < 18; i++) {
			Card* tempCard = new Chili();
			cards->push_back(tempCard);
		}
		for (int i = 0; i < 16; i++) {
			Card* tempCard = new Stink();
			cards->push_back(tempCard);
		}
		for (int i = 0; i < 14; i++) {
			Card* tempCard = new Green();
			cards->push_back(tempCard);
		}
		for (int i = 0; i < 12; i++) {
			Card* tempCard = new soy();
			cards->push_back(tempCard);
		}
		for (int i = 0; i < 10; i++) {
			Card* tempCard = new black();
			cards->push_back(tempCard);
		}
		for (int i = 0; i < 8; i++) {
			Card* tempCard = new Red();
			cards->push_back(tempCard);
		}
		for (int i = 0; i < 6; i++) {
			Card* tempCard = new garden();
			cards->push_back(tempCard);
		}
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

		// shuffle the deck 
		shuffle(cards->begin(), cards->end(), default_random_engine(seed));
	}

	// deck of cards
	Deck* cards;
};
CardFactory* CardFactory:: factory = NULL;

// returns a pointer to this factory
CardFactory* CardFactory::getFactory() {
	if (factory == NULL) {
		factory = new CardFactory();
	}
	return(factory);
}

