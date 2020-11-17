#include <iostream>
#include <string>
#include "CardFactory.h"
#include "Player.h"
#include "Deck.h"

using namespace std;

class Table {
    public:
        Table(istream& in, const CardFactory*); // is a constructor which accepts an istream and reconstruct the Table from file. 
        bool win(string& s); // returns true when a player has won. 
        void printHand(bool b); // prints the top card of the player's hand (with argument false) or all of the player's hand (with argument true).
    protected:
        Player p1;
        Player p2;
        Deck deck;
        DiscardPile discardPile;
        TradeArea tradeA;
};

Table::Table(istream& in, const CardFactory *cf) //constructor for when the game is resumed from file
{

}

void Table::printHand(bool b)
{
    if(b == false) //if false, print top card of player's hand
    {

    }
    if(b == true) // if true, print entire hand
    {

    }
}