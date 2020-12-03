#pragma once
#include <iostream>
#include <limits>
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
	char const* yes = "y";
	Player p1 = Player(p1Name);
	Player p2 = Player(p2Name);
	Player* current = &p1;
	bool player1 = true;
	CardFactory* cardFactory = CardFactory::getFactory();
	Deck& deck = (*cardFactory).getDeck();

	Table game = Table(&p1, &p2, &deck);

	for (int i = 0; i < 5; i++) {
		p1.addCard(deck.draw());
		p2.addCard(deck.draw());
	}
	
	//The game keeps going until there are no cards left
	int num;
	while(deck.isEmpty() == false)
	{
		//Player 1
		game.printTable(*current); //Display table
		
		//p1.addCard(deck.draw()); //Player draws top card from Deck
		if ((*current).getNumCoins() >= 3 && (*current).getMaxNumChains() == 2) {
			string answer;
			cout << "Would you like to buy a third chain for 3 coins (Y/N): " << endl;
			cin >> answer;
			if (strcmp(answer.c_str(), yes) == 0) {
				(*current).buyThirdChain();
			}
		}
		if (game.tradeAreaSize() != 0) //If TradeArea is not empty
		{ 
			//Add bean cards from the TradeArea to chains or discard them.
			do {
				cout << "Trading area: ";
				game.getTradeArea()->print();
				cout << "\n";
				cout << (*current).getName()<< " enter a card number from trade area to add to a current chain or -1 to discard trade area: ";
				cin >> num;
				if (num < 0) {
					game.getTradeArea()->discard(*game.getDiscardPile());
				}
				else {
					Card* temp = game.getTradeArea()->trade(game.getTradeArea()->cardNameAt(num));
					bool played = (*current).addToChain(temp); //If chain is ended, cards for chain are removed and player receives coin(s).
			//cout << "test";
					if (!played) { // if the card could not be added to chain, tell player
						cout << "Card does not match chain and one could not be created." << endl;
						*game.getTradeArea() += temp;
							}
					else {
						cout << "Card added to chain." << endl;
						(*current).printChains();
					}
				}
			} while (num >= 0 && game.tradeAreaSize() != 0);
		}
		bool step2 = true;
		string repeat;
		do {
			string enter;
			cout << "Your top card is: ";
			(*current).printHand(cout, false);
			cout << "\n";
			cin.clear();
			cout << (*current).getName() << " enter any character to play top card:" << endl;
			cin >> enter;
			Card* play = (*current).getHand()->play(); //Play topmost card from Hand
			bool played = (*current).addToChain(play); //If chain is ended, cards for chain are removed and player receives coin(s).
			//cout << "test";
			if (!played) { // if the card could not be added to chain, tie and sell an old chain and create a new chain
				int sell;
				cout << "Which chain would you like to sell (1-" << (*current).getNumChains() << "): " ;
				cin >> sell;
				(*current).addCoins((*current).sellChainAndAdd(sell-1, play)); //If chain is ended, cards for chain are removed and player receives coin(s).
				(*current).printChains();
			}
			else {
				cout << "\nCard added to chain." << endl;
				(*current).printChains();
			}
			cout << "Your top card is: ";
			(*current).printHand(cout, false);
			cout << "\n";
			cin.clear();
			cout << "Would you like to repeat this step? (Y/N) " ;
			cin >> repeat;
			repeat = tolower(repeat[0]);
			if(strcmp(repeat.c_str(),yes)!=0) //it returns 0 if they are equal
			{
				step2 = false;
			}
			if (step2 == true && (*current).getHand()->top() == NULL) {
				cout << "You cannot continue, your hand is empty." << endl;
				step2 = false;
			}
			cin.clear();
		//If player decides to
			 //Play the now topmost card from Hand. 
		} while(step2); //player is allowed to repeat step 2
		
		//If player decides to
                //Show the player's full hand and player selects an arbitrary card
                //Discard the arbitrary card from the player's hand and place it on the discard pile.
		int discardCard;
		cout << (*current).getName() << "'s hand: ";
		(*current).getHand()->printHand();
		cout << "\nEnter a card number to remove or -1 to leave cards:  ";
		cin.clear();
		cin >> discardCard;
		if(discardCard>=0)
		{
			Hand* pHand = (*current).getHand();
			Card* toRemove = (*pHand)[discardCard];
			//cout << toRemove->getName();
			*game.getDiscardPile() += toRemove;
		}
		
        //Draw three cards from the deck and place cards in the trade area
		for(int x = 0; x < 3; x++)
		{
			*game.getTradeArea() += ((game).getDeck().draw());
			
		}
		cout << "Drawing three cards from deck for trade area." << endl;
        //while top card of discard pile matches an existing card in the trade area
            //draw the top-most card from the discard pile and place it in the trade area
        //end

		while (game.getDiscardPile()->top()!=NULL&&game.getTradeArea()->legal(game.getDiscardPile()->top())) {
			*game.getTradeArea() += game.getDiscardPile()->pickUp();
		}
		
            //for all cards in the trade area 
                //if player wants to chain the card 
                    //chain the card.
                //else
                    //card remains in trade area for the next player.
            //end
		if (game.tradeAreaSize() != 0) //If TradeArea is not empty
		{
			//Add bean cards from the TradeArea to chains or discard them.
			do {
				cout << "Trade Area:";
				game.getTradeArea()->print();
				cout << "\n";
				cout << "Enter a card number to add to a current chain or -1 to leave cards: ";
				cin >> num;
				if (num >= 0) {
					Card* temp = game.getTradeArea()->trade(game.getTradeArea()->cardNameAt(num));
					bool played = (*current).addToChain(temp); //If chain is ended, cards for chain are removed and player receives coin(s).
			//cout << "test";
					if (!played) { // if the card could not be added to chain, tie and sell an old chain and create a new chain
						int sell;
						(*current).printChains();
						cout << "Which chain would you like to sell (1-" << (*current).getNumChains() << "): ";
						cin >> sell;
						(*current).addCoins((*current).sellChainAndAdd(sell-1, temp)); //If chain is ended, cards for chain are removed and player receives coin(s).
						(*current).printChains();
					}
					else {
						cout << "\nCard added to chain." << endl;
						(*current).printChains();
					}
				}
			} while (num >= 0 && game.tradeAreaSize() != 0);
		}
            //Draw two cards from Deck and add the cards to the player's hand (at the back).
		if (game.win((*current).getName())) {
			cout << "Congrats! " << (*current).getName() << " WON" << endl;
			break;
		}
		else if (game.getDeck().size()>0) {
			(*current).addCard(game.getDeck().draw());
			if (game.getDeck().size() > 0) {
				(*current).addCard(game.getDeck().draw());
			}
		}
        //end
    //end

		if (player1) {
			current = &p2;
			player1 = false;
		}
		else {
			current = &p1;
			player1 = true;
		}

		cout << "###################################################" << endl;
		cout << "\t\t"<< (*current).getName() << "'s Turn."<<endl;
		cout << "###################################################" << endl;
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