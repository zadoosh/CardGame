#include <iostream>
#include "CardFactory.h"
#include "Card.h"
#include <queue>
#include <list>

using namespace std;

class Hand {
    public:
        Hand(istream& in, const CardFactory*); // is a constructor which accepts an istream and reconstruct the Hand from file
        Hand& operator+=(const Card*); // adds the card to the rear of the hand
        Card* play(); // returns and removes the top card from the player's hand
        Card* top(); // returns but does not remove the top card from the player's hand.
        Card* operator[](int); // returns and removes the Card at a given index.
    protected:
        queue<Card*> hand;
        int handSize;
};

Hand::Hand(istream& in, const CardFactory *cf) //constructor for when the game is resumed from file
{

}

Hand& Hand::operator+=(const Card *c)
{
    this->hand += hand.push(*c);
    return *this; //https://stackoverflow.com/questions/4581961/c-how-to-overload-operator
}

Card* Hand::play()
{
    Card* top = hand.front();
    hand.pop();
    return(top);
}

Card* Hand::top()
{
    return(hand.front());
}

Card* Hand::operator[](int index)
{
    
}