#include <iostream>
#include <string>
#include "CardFactory.h"
#include "Player.h"
#include "Deck.h"

using namespace std;

class Table {
    public:
        Table(istream& in, const CardFactory* cf);
        bool win(string& s);
        void printHand(bool b);
    private:
        Player p1;
        Player p2;
        Deck deck;
        DiscardPile discardP;
        TradeArea tradeA;
};

void Table::printHand(bool b)
{
    if(b == false) //if false, print top card of player's hand
    {

    }
    if(b == true) // if true, print entire hand
    {

    }
}