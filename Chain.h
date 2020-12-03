#pragma once
#include <iostream>
#include "CardFactory.h"
#include "Card.h"
#include <vector>
#include <exception>
#include <memory>
#include <functional>

using namespace std;

template <class Card>
class Chain{
   
    public:
        Chain(Card *firstCard); // default constructor
        Chain(istream& in, const CardFactory*); //is a constructor which accepts an istream and reconstructs the chain from file when a game is resumed. 
        void operator+=(Card*); //adds a card to the Chain. If the run-time type does not match the template type of the chain and exception of type IllegalType needs to be raised.
        int sell(); //counts the number cards in the current chain and returns the number coins according to the function Card::getCardsPerCoin. 
        friend ostream & operator << (ostream &, Chain<Card>);
        bool isEmpty();
        void print();
        string printTypeName();
        Chain() {};
    private:
        vector<Card*> cardChain ; 
};

template <class Card>
Chain<Card>::Chain(Card *firstCard) //default constructor 
{
   
    cardChain.push_back(firstCard);
 
}
template <class Card>
string Chain<Card>::printTypeName() {
    return cardChain[0]->getName();
}

template <class Card>
Chain<Card>::Chain(istream& in, const CardFactory *cf) //constructor for when the game is resumed from file
{
    
}

template <class Card>
void Chain<Card>::operator+=(Card *c)
{
    cardChain.push_back(c);
    
}

// counts the number of cards in the current chain and returns the number of coins according to the function Card::getCardsPerCoin
template <class Card>
int Chain<Card>::sell()
{
    return (cardChain[0]->getCoinsPerCard(cardChain.size()));
}
/*
template <class Card>
ostream & operator << (ostream &out, Chain<Card> chain)
{
    out << string(T) << "\t" << (string(T).at(0))*(chain.size()) << endl;
} 
*/

template <class Card>
bool Chain<Card>::isEmpty() {
    return(cardChain.empty());
}

template <class Card>
void Chain<Card>::print() {
    if (isEmpty()) {
        cout << "Empty";
    }
    else {
        for (Card* c : cardChain) {
            c->print(cout);
        }
    }
}

