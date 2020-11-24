#include <iostream>
#include "CardFactory.h"
#include "Card.h"
#include <vector>

using namespace std;

template <Card *T>
class Chain{
    public:
        Chain(Card* firstCard); // default constructor
        Chain(istream& in, const CardFactory*); //is a constructor which accepts an istream and reconstructs the chain from file when a game is resumed. 
        Chain<T>& operator+=(Card*); //adds a card to the Chain. If the run-time type does not match the template type of the chain and exception of type IllegalType needs to be raised.
        int sell(); //counts the number cards in the current chain and returns the number coins according to the function Card::getCardsPerCoin. 
    protected:
        vector<Card*> cardChain;
};
/*
class Chain<*Blue>: public Chain 
{

}
class Chain<*Chili>: public Chain 
{

}
class Chain<*Stink>: public Chain 
{

}
class Chain<*Green>: public Chain 
{

}
class Chain<*soy>: public Chain 
{

}
class Chain<*black>: public Chain 
{

}
class Chain<*Red>: public Chain 
{

}
class Chain<*garden>: public Chain 
{

}
*/
template <Card *T>
Chain<T>::Chain(Card *firstCard) //default constructor 
{
    cardChain.push_back(firstCard);
}

template <Card *T>
Chain<T>::Chain(istream& in, const CardFactory *cf) //constructor for when the game is resumed from file
{
    
}

template <Card *T>
Chain<T>& Chain<T>::operator+=(Card *c)
{
    cardChain.push_back(c);
}

// counts the number of cards in the current chain and returns the number of coins according to the function Card::getCardsPerCoin
template <Card *T>
int Chain<T>::sell()
{
    int coinsInChain = 0;
    for(Card* element : cardChain)
    {
        //coinsInChain += element->getCardsPerCoin(); //for some reason it says in Card class this function should return number of cards needed for the coins passed as an arguement
    }
    return coinsInChain;
}