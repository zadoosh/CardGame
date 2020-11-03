#include <iostream>
#include "Card.h"
#include "CardFactory.h"
#include "Chain.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "Hand.h"
#include "Player.h"
#include "Table.h"
#include "TradeArea.h"
using namespace std;
void main(void) {
	
	//test code

	Chili c;
	cout << c << endl;
	cout << c.getCardsPerCoin(2) << endl;
	
	Blue b;
	cout << b << endl;
	cout << b.getCardsPerCoin(3) << endl;
}