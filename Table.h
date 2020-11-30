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
        Table(Player, Player, Deck); //Default constructor
        Table(istream& in, const CardFactory*); // is a constructor which accepts an istream and reconstruct the Table from file. 
        bool win(string&); // returns true when a player has won. 
        void printHand(bool); // prints the top card of the player's hand (with argument false) or all of the player's hand (with argument true).
       // friend ostream & operator << (ostream& out, Table t);
        void printTable(Player);
        int tradeAreaSize();
        Deck* getDeck();
        TradeArea& getTradeArea();
    private:
        Player p1;
        Player p2;
        Deck deck;
        DiscardPile discardPile;
        TradeArea tradeArea;
};

//initializes game
Table::Table(Player one, Player two, Deck cards)
{
    p1 = one;
    p2 = two;
    deck = cards;
    discardPile = DiscardPile();
    tradeArea = TradeArea();
}

Table::Table(istream& in, const CardFactory *cf) //constructor for when the game is resumed from file
{
    
}
/*
bool Table::win(string& s)
{

}
*/
void Table::printHand(bool b)
{
    if(b == false) //if false, print top card of player's hand
    {
        
    }
    if(b == true) // if true, print entire hand
    {

    }
}
void Table::printTable(Player p) {
    cout << "\nDiscard Pile: ";
    if (discardPile.top() == NULL) {
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

Deck* Table::getDeck() 
{
    return &deck;
}

TradeArea& Table::getTradeArea() 
{
    return *tradeArea;
}

/*
ostream & operator << (ostream &out, Table t)
{
    out << "Deck " << deck << endl;
    out << "DiscardPile " << discardPile << endl;
    out << "TradeArea " << td.print(out) << endl;
    out << "Player1 " << p1.print(out) << endl; //Print the name, coins, chains 
    out << "Player2 " << p2.print(out) << endl; //Print the name, coins, chains 
} 
*/