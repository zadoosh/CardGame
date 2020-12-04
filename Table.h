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
        //Table(istream& in, const CardFactory*); // is a constructor which accepts an istream and reconstruct the Table from file. 
        Table(Player*, Player*, Deck*, DiscardPile*, TradeArea*);
        bool win(string&); // returns true when a player has won. 
        void printHand(bool, Player p); // prints the top card of the player's hand (with argument false) or all of the player's hand (with argument true).
        friend ostream &operator << (ostream& out, Table& t);
        void printTable(Player);
        int tradeAreaSize();
        Deck& getDeck();
        TradeArea* getTradeArea();
        DiscardPile* getDiscardPile();
        Player& getPlayer1();
        Player& getPlayer2();
    private:
        Player* p1;
        Player* p2;
        Deck* deck;
        DiscardPile discardPile;
        TradeArea tradeArea;
};

//initializes game
Table::Table(Player* one, Player* two, Deck* cards)
{
    p1 = one;
    p2 = two;
    deck = cards;
    discardPile = DiscardPile();
    tradeArea = TradeArea();
}
Table::Table(Player* one, Player* two, Deck* cards, DiscardPile* dp, TradeArea* tp )
{
    p1 = one;
    p2 = two;
    deck = cards;
    discardPile = *dp;
    tradeArea = *tp;
}

/*
Table::Table(istream& in, const CardFactory *cf) //constructor for when the game is resumed from file
{
    
}
*/

bool Table::win(string& s)
{
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

void Table::printHand(bool b, Player p)
{
    p.printHand(cout,b);
}
void Table::printTable(Player p) {
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
    cout << "\nYour chains: " << endl;
    p.printChains();
}
int Table::tradeAreaSize() {
    return tradeArea.numCards();
}

Deck& Table::getDeck() 
{
    return *deck;
}
Player& Table::getPlayer1()
{
    return *p1;
}
Player& Table::getPlayer2()
{
    return *p2;
}

TradeArea* Table::getTradeArea() 
{
    return &tradeArea;
}

DiscardPile* Table::getDiscardPile()
{
    return &discardPile;
}

ostream &operator << (ostream &out, Table& t)
{
    out << "[Deck]\n" << t.getDeck() << endl;
    out << "[DiscardPile]\n" << *t.getDiscardPile() << endl;
    out << "[TradeArea]\n" << *t.getTradeArea() << endl;
    out << "[Player1]\n" << t.getPlayer1() << endl; //Print the name, coins, chains 
    out << "[Player2]\n" << t.getPlayer2() << endl; //Print the name, coins, chains 
    return out;
} 
