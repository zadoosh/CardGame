#pragma once
#include <iostream>
#include <string>
#include "CardFactory.h"
#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"

using namespace std;

class Table {
    public:
        Table(Player*, Player*, Deck*); //Default constructor
        Table(Player*, Player*, Deck*, DiscardPile*, TradeArea*); // is a constructor which accepts an istream and reconstruct the Table from file. 
        bool win(string&)const; // returns true when a player has won. 
        void printHand(bool, Player p)const; // prints the top card of the player's hand (with argument false) or all of the player's hand (with argument true).
        friend ostream &operator << (ostream& out, Table& t); // the insertion operator (friend) to print a Table to an std::ostream
        void printTable(Player)const; // prints discard pile, trade area, and player's chains 
        int tradeAreaSize()const; // returns the size of trade area
        Deck& getDeck(); // returns reference to deck
        TradeArea* getTradeArea(); // returns pointer to trade area
        DiscardPile* getDiscardPile(); // returns pointer to discard pile
        Player& getPlayer1(); // returns reference to player 1
        Player& getPlayer2(); // returns reference to player 2
    private:
        Player* p1;
        Player* p2;
        Deck* deck;
        DiscardPile discardPile;
        TradeArea tradeArea;
};

// initializes game
Table::Table(Player* one, Player* two, Deck* cards)
{
    p1 = one;
    p2 = two;
    deck = cards;
    discardPile = DiscardPile();
    tradeArea = TradeArea();
}

// constructor for when the game is resumed from file
Table::Table(Player* one, Player* two, Deck* cards, DiscardPile* dp, TradeArea* tp )
{
    p1 = one;
    p2 = two;
    deck = cards;
    discardPile = *dp;
    tradeArea = *tp;
}

// returns true when a player has won
bool Table::win(string& s)const
{
    // The winning condition is that all cards from the deck must have been picked up and then the player with the most coins wins
    if (deck->size() != 0) {
        return false;
    }
    else {
        if (s == p1->getName()) {
            if (p1->getNumCoins() > p2->getNumCoins()) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if (p2->getNumCoins() > p1->getNumCoins()) {
                return true;
            }
            else {
                return false;
            }
        }
    }
}

// prints the top card of the player's hand (with argument false) or all of the player's hand (with argument true)
void Table::printHand(bool b, Player p)const
{
    p.printHand(cout,b);
}

// outputs the discard pile, trading area, and player's chains for the player to play 
void Table::printTable(Player p)const {
    cout << "\nDiscard Pile: ";
    if (discardPile.top()==NULL) {
        cout << "None";
    }
    else {
        discardPile.top()->print(cout);
    }
    cout << endl;
    cout << "\nTrading Area: ";
    tradeArea.print();
    cout << endl;
    /*
    cout << "\nYour chains: " << endl;
    p.printChains();
    */
}

// returns the trading area size
int Table::tradeAreaSize() const{
    return tradeArea.numCards();
}

// returns a reference to the deck
Deck& Table::getDeck() 
{
    return *deck;
}

// returns a reference to player1
Player& Table::getPlayer1()
{
    return *p1;
}

// returns a reference to player2
Player& Table::getPlayer2()
{
    return *p2;
}

// returns a pointer to trade area
TradeArea* Table::getTradeArea() 
{
    return &tradeArea;
}

// returns a pointer to discard pile 
DiscardPile* Table::getDiscardPile()
{
    return &discardPile;
}

// the insertion operator to print a Table to an std::ostream
ostream &operator << (ostream &out, Table& t)
{
    out << "[Deck]\n" << t.getDeck() << endl; //Print the deck 
    out << "[DiscardPile]\n" << *t.getDiscardPile() << endl; //Print the discard pile
    out << "[TradeArea]\n" << *t.getTradeArea() << endl; //Print the trade area
    out << "[Player1]\n" << t.getPlayer1() << endl; //Print the name, coins, chains, hand
    out << "[Player2]\n" << t.getPlayer2() << endl; //Print the name, coins, chains, hand
    return out;
} 
