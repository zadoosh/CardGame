#pragma once
#include <iostream>
#include "CardFactory.h"
#include "Card.h"
#include <queue>
#include <list>

using namespace std;

class Hand {
    public:
        Hand() {
            handSize = 0;
        }
        Hand(istream& in, const CardFactory*); // is a constructor which accepts an istream and reconstruct the Hand from file
        Hand& operator+=(Card*); // adds the card to the rear of the hand
        Card* play(); // returns and removes the top card from the player's hand
        Card* top(); // returns but does not remove the top card from the player's hand.
        Card* operator[](int); // returns and removes the Card at a given index.
        friend ostream & operator << (ostream & out, Hand h);
        void printHand(); // prints the player's hand
    protected:
        queue<Card*> hand;
        int handSize;
};
/*
Hand::Hand(istream& in, const CardFactory *cf) //constructor for when the game is resumed from file
{

}
*/
Hand& Hand::operator+=(Card *c)
{
    hand.push(c);
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
    list<Card*> listHand;
    handSize = hand.size();
    Card* cardToReturn=NULL; 
    for(int a = 0; a < handSize; a++)
    {
        listHand.push_back(hand.front());
        hand.pop();
    }
    for(int a = 0; a < handSize; a++)
    {
        if(a != index)
        {
            hand.push(listHand.front());
            listHand.pop_front();
        }
        if(a == index)
        {
            cardToReturn = listHand.front();
            listHand.pop_front();
        }
    }
    return(cardToReturn);
}

void Hand::printHand() // used to print hand so user can select which card to remove from hand
{
     queue<Card*> handToIterate = hand;
     Card *tempCard;
     while(!handToIterate.empty())
     {
         tempCard = handToIterate.front();
         cout << tempCard->getName() << "\t";
         handToIterate.pop();
     }
}

/*
ostream & operator << (ostream& out, Hand h)
{
    queue<Card*> handCopy;
    list<Card*> listHand;
    h.handSize = h.hand.size();
    for(int a = 0; a < h.handSize; a++)
    {
        listHand.push_back(h.hand.front());
        h.hand.pop();
    }
    out << "Hand ";
    for(int a = 0; a < h.handSize; a++)
    {
        listHand.front()->print(out);
        handCopy.push(listHand.front());
        listHand.pop_front();
    }
    out << endl;
    h.hand = handCopy;
}
*/