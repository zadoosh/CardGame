#include <iostream>
#include "CardFactory.h"
#include "Card.h"
#include <queue>
#include <list>

using namespace std;

class Hand {
    public:
        Hand(istream& in, const CardFactory cf); // is a constructor which accepts an istream and reconstruct the Hand from file
        Hand& operator+=(Card*); // adds the card to the rear of the hand
        Card* play(); // returns and removes the top card from the player's hand
        Card* top(); // returns but does not remove the top card from the player's hand.
        Card* operator[](int); // returns and removes the Card at a given index.
    private:
        queue<Card*> hand;
};

Hand& operator+=(Card* c)
{
    hand.push(c);
}

Card* Hand::play()
{
    return hand.pop();
}

Card* Hand::top()
{
    return(hand.peek());
}