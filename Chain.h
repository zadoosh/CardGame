#include <iostream>
#include "CardFactory.h"
#include <vector>

using namespace std;

class Chain {
    public:
        Chain(istream& in, const CardFactory* cf); //is a constructor which accepts an istream and reconstructs the chain from file when a game is resumed. 
        Chain<T>& operator+=(Card* c); //adds a card to the Chain. If the run-time type does not match the template type of the chain and exception of type IllegalType needs to be raised.
        int sell(); //counts the number cards in the current chain and returns the number coins according to the function Card::getCardsPerCoin. 
    private:
};



int Chain::sell()
{

}