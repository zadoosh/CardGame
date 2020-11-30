#pragma once
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
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
	
	CardFactory* cardFactory = CardFactory::getFactory();
	Deck deck = (*cardFactory).getDeck();

	Table game = Table(p1, p2, deck);

	for (int i = 0; i < 5; i++) {
		p1.addCard(deck.draw());
		p2.addCard(deck.draw());
	}
	
	//The game keeps going until there are no cards left
	
	while(deck.isEmpty() == false)
	{
		//Player 1
		game.printTable(p1); //Display table
		p1.addCard(deck.draw()); //Player draws top card from Deck
		if (game.tradeAreaSize() != 0) //If TradeArea is not empty
		{ 
			//Add bean cards from the TradeArea to chains or discard them.
		}
		bool step2 = true;
		string repeat;
		char const *yes = "y";
		do {
			Card* play = p1.getHand()->play(); //Play topmost card from Hand
			bool played = p1.addToChain(play); //If chain is ended, cards for chain are removed and player receives coin(s).
			//cout << "test";
			if (!played) { // if the card could not be added to chain, tie and sell an old chain and create a new chain
				int sell;
				cout << "Which chain would you like to sell (1-" << p1.getNumChains() << ": " ;
				cin >> sell;
				p1.sellChainAndAdd(sell, play); //If chain is ended, cards for chain are removed and player receives coin(s).
			}
			cout << "Would you like to repeat this step? (Y/N) " ;
			cin >> repeat;
			repeat = tolower(repeat[0]);
			if(strcmp(repeat.c_str(),yes)!=0) //it returns 0 if they are equal
			{
				step2 = false;
			}
		//If player decides to
			 //Play the now topmost card from Hand. 
		} while(step2); //player is allowed to repeat step 2
		
		//If player decides to
                //Show the player's full hand and player selects an arbitrary card
                //Discard the arbitrary card from the player's hand and place it on the discard pile.
		string discardCard;
		cout << "Would you like to display your hand and discard an arbitrary card? (Y/N) ";
		cin >> discardCard;
		discardCard = tolower(discardCard[0]);
		if(strcmp(discardCard.c_str(),yes))
		{
			p1.getHand()->printHand();
		}

        //Draw three cards from the deck and place cards in the trade area
		for(int x = 0; x < 3; x++)
		{
			game.getTradeArea() += (game.getDeck()->draw());
		}

        //while top card of discard pile matches an existing card in the trade area
            //draw the top-most card from the discard pile and place it in the trade area
        //end
		


            //for all cards in the trade area 
                //if player wants to chain the card 
                    //chain the card.
                //else
                    //card remains in trade area for the next player.
            //end
            //Draw two cards from Deck and add the cards to the player's hand (at the back).
        //end
    //end

		
	}
	
	
	return 1;
}

//FILE OUTPUT FORMAT
/*
	TradeArea:
	DiscardPile:
	Deck:
	Player1: name, coins, Chains, hand
	Player2: name, coins, Chains, hand
*/