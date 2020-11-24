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
int main() {
	
	/*
	//test code	
	Chili c;
	cout << c << endl;
	cout << c.getCardsPerCoin(2) << endl;
	Blue b;
	cout << b << endl;
	cout << b.getCardsPerCoin(3) << endl;
	*/

	//SETUP 
	//Input the names of 2 players. Initialize the Deck and draw 5 cards for the Hand of each Player; or
	//Load paused game from file.
	string p1Name; //Player1 Name
	cout<<"Enter Player1 Name: ";
	cin >> p1Name;
	string p2Name; //Player2 Name
	cout<<"Enter Player2 Name: ";
	cin >> p2Name;

	Player p1 = Player(p1Name);
	Player p2 = Player(p2Name);

	Deck deck = CardFactory().getDeck();

	Table game = Table(p1, p2, deck);

	//The game keeps going until there are no cards left
	while(deck.isEmpty == false)
	{
		
	}


	return 1;
}