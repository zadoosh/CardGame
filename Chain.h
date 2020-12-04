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
        Chain(istream& in); //is a constructor which accepts an istream and reconstructs the chain from file when a game is resumed. 
        void operator+=(Card*); //adds a card to the Chain. If the run-time type does not match the template type of the chain and exception of type IllegalType needs to be raised.
        int sell(); //counts the number cards in the current chain and returns the number coins according to the function Card::getCardsPerCoin. 
        friend ostream& operator << (ostream & out, Chain<Card>& c);
        bool isEmpty();
        void print();
        vector<Card*>* getChain() {
            return &cardChain;
        }
        string printTypeName();
        Chain() {};
    private:
        vector<Card*> cardChain ; 
};

template <class Card>
Chain<Card>::Chain(istream& in) {
    while (!in.eof()) {
        string temp;
        in >> temp;
        if (temp.size()>0&&temp.at(0)== 'B') {
            for (int i = 0; i < temp.size(); i++) {
                Card* blue = new Blue();
                cardChain.push_back(blue);
            }
        }
        if (temp.size() > 0 && temp.at(0) == 'C') {
            for (int i = 0; i < temp.size(); i++) {
                Card* blue = new Chili();
                cardChain.push_back(blue);
            }
        }
        if (temp.size() > 0 && temp.at(0) == 'S'){
            for (int i = 0; i < temp.size(); i++) {
                Card* blue = new Stink();
                cardChain.push_back(blue);
            }
        }
        if (temp.size() > 0 && temp.at(0) == 'G') {
            for (int i = 0; i < temp.size(); i++) {
                Card* blue = new Green();
                cardChain.push_back(blue);
            }
        }
        if (temp.size() > 0 && temp.at(0) == 's') {
            for (int i = 0; i < temp.size(); i++) {
                Card* blue = new soy();
                cardChain.push_back(blue);
            }
        }
        if (temp.size() > 0 && temp.at(0) == 'b') {
            for (int i = 0; i < temp.size(); i++) {
                Card* blue = new black();
                cardChain.push_back(blue);
            }
        }
        if (temp.size() > 0 && temp.at(0) == 'R') {
            for (int i = 0; i < temp.size(); i++) {
                Card* blue = new Red();
                cardChain.push_back(blue);
            }
        }
        if (temp.size() > 0 && temp.at(0) == 'g') {
            for (int i = 0; i < temp.size(); i++) {
                Card* blue = new garden();
                cardChain.push_back(blue);
            }
        }
    }
}
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


ostream& operator << (ostream &out, Chain<Card>& chain)
{
    for (Card* c : *chain.getChain()) {
        c->print(out);
    }
    if (chain.getChain()->size() == 0) {
        out << " Empty";
    }
    return out;
} 



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

