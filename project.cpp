#pragma once
#include <iostream>
#include <istream>
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
#include "ini.h"
using namespace std;
int main() {

	//SETUP 

	//initialize variables
	string p1Name; //Player1 Name
	string p2Name; //Player2 Name
	Player p1; // Player1
	Player p2; // Player2

	// To keep track of the current player	
	Player* current = &p1; 
	bool player = true;
	bool first = true;
	bool second = false;

	// Initialize game components
	CardFactory* cardFactory = CardFactory::getFactory();
	Deck& deck = (*cardFactory).getDeck();
	Table game = Table(&p1, &p2, &deck);

	char const* yes = "y";
	string load;

	//Input the names of 2 players. Initialize the Deck and draw 5 cards for the Hand of each Player; or
	//Load paused game from file.
	//Load game from file
	cout << "Would you like to Load game from file? (Y/N): ";
	cin >> load;
	if (strcmp(load.c_str(), yes) == 0) {
		mINI::INIFile file("saveFile.ini");
		// next, create a structure that will hold data
		mINI::INIStructure ini;
		// now we can read the file
		file.read(ini);
		// read a value

		//Player 1 input streams
		stringstream player1;
		stringstream p1Chain0;
		stringstream p1Chain1;
		stringstream p1Chain2;
		stringstream p1Hand;
		player1<< ini["player1"]["name"]<<endl;
		player1<< ini["player1"]["coins"] << endl;
		player1<< ini["player1"]["third"]<<endl;
		p1Chain0 << ini["player1"]["chain0"] << endl;
		p1Chain1 << ini["player1"]["chain1"] << endl;
		if (ini["player1"].has("chain2")) {
			p1Chain2 << ini["player1"]["chain2"] << endl;
		}
		p1Hand << ini["player1"]["cards"] << endl;
		
		//Player 2 input streams
		stringstream player2;
		stringstream p2Chain0;
		stringstream p2Chain1;
		stringstream p2Chain2;
		stringstream p2Hand;
		player2 << ini["player2"]["name"] << endl;
		player2 << ini["player2"]["coins"] << endl;
		player2 << ini["player2"]["third"] << endl;
		p2Chain0 << ini["player2"]["chain0"] << endl;
		p2Chain1 << ini["player2"]["chain1"] << endl;
		if (ini["player2"].has("chain2")) {
			p1Chain2 << ini["player2"]["chain2"] << endl;
		}
		p2Hand << ini["player2"]["cards"] << endl;

		//Game input streams
		stringstream cardDeck;
		cardDeck << ini["Deck"]["deck"];
		stringstream trade;
		trade << ini["TradeArea"]["tradearea"];
		stringstream dpile;
		dpile << ini["DiscardPile"]["discardpile"];
		string currentPlayer= ini["current"]["name"];

		
		//Create player1
		Chain<Card> player1Chain0 = Chain<Card>(p1Chain0);
		Chain<Card> player1Chain1 = Chain<Card>(p1Chain1);
		Chain<Card> player1Chain2 = Chain<Card>(p1Chain2);
		Hand player1Hand = Hand(p1Hand);
		p1 = Player(player1, player1Chain0, player1Chain1, player1Chain2, player1Hand);
		//Create player2
		Chain<Card> player2Chain0 = Chain<Card>(p2Chain0);
		Chain<Card> player2Chain1 = Chain<Card>(p2Chain1);
		Chain<Card> player2Chain2 = Chain<Card>(p2Chain2);
		Hand player2Hand = Hand(p2Hand);
		p2 = Player(player2, player2Chain0, player2Chain1, player2Chain2, player2Hand);

		//Create game objects (table)
		deck = Deck(cardDeck);
		DiscardPile dp = DiscardPile(dpile);
		TradeArea tp = TradeArea(trade);
		game = Table(&p1,&p2,&deck,&dp,&tp);

		//Set the current player from the file
		if (currentPlayer == p1.getName()) {
			current = &p1;
		}
		else {
			current = &p2;
			player = false;
			first = false;
		}
	}
	// If user wants to start new game instead
	else {
		cout << "Enter Player1 Name: ";
		cin >> p1Name;
		cout << "Enter Player2 Name: ";
		cin >> p2Name;
		//Create Player objects with names entered
		p1= Player(p1Name);
		p2 = Player(p2Name);
		//Draw 5 cards for each player from the deck and place in hand
		for (int i = 0; i < 5; i++) {
			p1.addCard(deck.draw());
			p2.addCard(deck.draw());
		}
	}
	
	//The game keeps going until there are no cards left
	int num;
	while(deck.isEmpty() == false)
	{
		if (!first&&second) {
			string save;
			cout << "Would you like to Save and exit game? (Y/N): " << endl;
			cin >> save;
			if (strcmp(save.c_str(), yes) == 0) {
				ofstream savefile;
				savefile.open("saveFile.ini");
				savefile << game;
				savefile << "[current]\n" << "name = " << (*current).getName() << endl;
				savefile.close();
				cout << "Game saved!";
				break;
			}
		}

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
		// 1 #################################################################################################################################
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

		// 2 #################################################################################################################################
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
		// 3 #################################################################################################################################
		} while(step2); //player is allowed to repeat step 2
		
		// 4 #################################################################################################################################
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
		
		// 5 #################################################################################################################################
		cout << "Drawing three cards from deck for trade area." << endl;
        //Draw three cards from the deck and place cards in the trade area
		for(int x = 0; x < 3; x++)
		{
			if (game.getDeck().size() > 0) {
				*game.getTradeArea() += ((game).getDeck().draw());
			}
		}
		
		cout << "If the top-most card matches a card in the trade area, it will be placed there now" << endl;
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
            
		//Check winning condition before drawing cards from deck
		if (game.win((*current).getName())) {
			cout << "Congrats! " << (*current).getName() << " WON" << endl;
			break;
		}

		// 6 #################################################################################################################################
		//Draw two cards if possible from Deck and add the cards to the player's hand (at the back).
		else if (game.getDeck().size()>0) {
			(*current).addCard(game.getDeck().draw());
			if (game.getDeck().size() > 0) {
				(*current).addCard(game.getDeck().draw());
			}
		}

		// will be used to alternate player turns
		if (player) {
			current = &p2;
			player = false;
		}
		else {
			current = &p1;
			player = true;
		}

		// To let users know who's turn it is 
		cout << "###################################################" << endl;
		cout << "\t\t"<< (*current).getName() << "'s Turn."<<endl;
		cout << "###################################################" << endl;

		// will be used to alternate player turns
		if (first) {
			first = false;
		}
		else {
			second = true;
		}
	}
	return 1;
}