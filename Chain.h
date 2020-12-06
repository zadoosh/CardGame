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
        Chain(istream& in); // is a constructor which accepts an istream and reconstructs the chain from file when a game is resumed. 
        void operator+=(Card*); // adds a card to the Chain. If the run-time type does not match the template type of the chain and exception of type IllegalType needs to be raised.
        int sell(); // counts the number cards in the current chain and returns the number coins according to the function Card::getCardsPerCoin. 
        friend ostream& operator << (ostream & out, Chain<Card>& c); // insertion operator (friend) to print Chain on an std::ostream
        bool isEmpty()const; // checks if the chain is empty
        void print()const; // prints the chain
        vector<Card*>* getChain() { // returns a pointer to the chain 
            return &cardChain;
        }
        string printTypeName()const; // returns the type of Card the Chain holds
        Chain() {}; // default constructor 
    private:
        vector<Card*> cardChain ; // the chain is stored in a vector of Card pointers
};

// to regenerate the chain from file
// takes an istream as an argument
template <class Card>
Chain<Card>::Chain(istream& in) {
    while (!in.eof()) {
        string temp;
        in >> temp;
        if (temp.size()>0&&temp.at(0)== 'B') { // checks if the letter is the same as the one in the file 
            for (int i = 0; i < temp.size(); i++) { // if true, loop as many times as the size of the string to add that many cards into the chain
                Card* tempCard = new Blue(); // creates a temporary card of type Blue
                cardChain.push_back(tempCard); // adds card to chain
            }
        }
        if (temp.size() > 0 && temp.at(0) == 'C') { // checks if the letter is the same as the one in the file
            for (int i = 0; i < temp.size(); i++) { // if true, loop as many times as the size of the string to add that many cards into the chain
                Card* tempCard = new Chili(); // creates a temporary card of type Chili
                cardChain.push_back(tempCard); // adds card to chain
            }
        }
        if (temp.size() > 0 && temp.at(0) == 'S') { // checks if the letter is the same as the one in the file
            for (int i = 0; i < temp.size(); i++) { // if true, loop as many times as the size of the string to add that many cards into the chain
                Card* tempCard = new Stink(); // creates a temporary card of type Stink
                cardChain.push_back(tempCard); // adds card to chain
            }
        }
        if (temp.size() > 0 && temp.at(0) == 'G') { // checks if the letter is the same as the one in the file
            for (int i = 0; i < temp.size(); i++) { // if true, loop as many times as the size of the string to add that many cards into the chain
                Card* tempCard = new Green(); // creates a temporary card of type Green
                cardChain.push_back(tempCard); // adds card to chain
            }
        }
        if (temp.size() > 0 && temp.at(0) == 's') { // checks if the letter is the same as the one in the file
            for (int i = 0; i < temp.size(); i++) { // if true, loop as many times as the size of the string to add that many cards into the chain
                Card* tempCard = new soy(); // creates a temporary card of type soy
                cardChain.push_back(tempCard); // adds card to chain
            }
        }
        if (temp.size() > 0 && temp.at(0) == 'b') { // checks if the letter is the same as the one in the file
            for (int i = 0; i < temp.size(); i++) { // if true, loop as many times as the size of the string to add that many cards into the chain
                Card* tempCard = new black(); // creates a temporary card of type black
                cardChain.push_back(tempCard); // adds card to chain
            }
        }
        if (temp.size() > 0 && temp.at(0) == 'R') { // checks if the letter is the same as the one in the file
            for (int i = 0; i < temp.size(); i++) { // if true, loop as many times as the size of the string to add that many cards into the chain
                Card* tempCard = new Red(); // creates a temporary card of type Red
                cardChain.push_back(tempCard); // adds card to chain
            }
        }
        if (temp.size() > 0 && temp.at(0) == 'g') { // checks if the letter is the same as the one in the file
            for (int i = 0; i < temp.size(); i++) { // if true, loop as many times as the size of the string to add that many cards into the chain
                Card* tempCard = new garden(); // creates a temporary card of type garden
                cardChain.push_back(tempCard); // adds card to chain
            }
        }
    }
}

//default constructor
template <class Card>
Chain<Card>::Chain(Card *firstCard)  
{
    // adds the card provided to create a chain
    cardChain.push_back(firstCard); 
}

// returns Card type of Chain
template <class Card>
string Chain<Card>::printTypeName()const {
    return cardChain[0]->getName();
}

// overwrites += operator to easily add a Card to chain
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

// the insertion operator (friend) to print Chain on an std::ostream
ostream& operator << (ostream &out, Chain<Card>& chain)
{
    // checks if empty first to print "Empty" next to player's chain
    if (chain.getChain()->size() == 0) {
        out << " Empty";
    }
    // If not empty, for each card in the chain, print the card
    for (Card* c : *chain.getChain()) {
        c->print(out);
    }
    return out;
} 

// returns bool value for whether the chain is empty
template <class Card>
bool Chain<Card>::isEmpty() const{
    return(cardChain.empty());
}

// prints chain to console 
template <class Card>
void Chain<Card>::print() const{
    if (isEmpty()) {
        cout << "Empty";
    }
    else {
        for (Card* c : cardChain) {
            c->print(cout);
        }
    }
}

