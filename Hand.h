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
        Hand(istream& in); // is a constructor which accepts an istream and reconstruct the Hand from file
        Hand& operator+=(Card*); // adds the card to the rear of the hand
        Card* play(); // returns and removes the top card from the player's hand
        Card* top(); // returns but does not remove the top card from the player's hand.
        Card* operator[](int); // returns and removes the Card at a given index.
        friend ostream & operator << (ostream & out, Hand h);
        void printHand(); // prints the player's hand
    private:
        queue<Card*> hand;
        int handSize;
};

Hand::Hand(istream& in) //constructor for when the game is resumed from file
{
    int i = 0;
    while (!in.eof()) {
        string temp;
        in >> temp;
        if (temp == "Blue") {
            Card* blue = new Blue();
            hand.push(blue);
            i++;
        }
        if (temp == "Chili") {
            Card* blue = new Chili();
            hand.push(blue);
            i++;
        }
        if (temp == "Stink") {
            Card* blue = new Stink();
            hand.push(blue);
            i++;
        }
        if (temp == "Green") {
            Card* blue = new Green();
            hand.push(blue);
            i++;
        }
        if (temp == "soy") {
            Card* blue = new soy();
            hand.push(blue);
            i++;
        }
        if (temp == "black") {
            Card* blue = new black();
            hand.push(blue);
            i++;
        }
        if (temp == "Red") {
            Card* blue = new Red();
            hand.push(blue);
            i++;
        }
        if (temp == "garden") {
            Card* blue = new garden();
            hand.push(blue);
            i++;
        }
        
    }
    handSize = i;
}

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
    if (hand.size()== 0) {
        return NULL;
    }
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
     int count = 0;
     while(!handToIterate.empty())
     {
         tempCard = handToIterate.front();
         cout <<"card#"<<count<<": "<< tempCard->getName() << "\t";
         handToIterate.pop();
         count++;
     }
}


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
    out << "cards = ";
    for(int a = 0; a < h.handSize; a++)
    {
        out <<listHand.front()->getName() <<" ";
        handCopy.push(listHand.front());
        listHand.pop_front();
    }
    out << endl;
    h.hand = handCopy;
    return out;
}
