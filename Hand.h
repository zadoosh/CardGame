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
        friend ostream & operator << (ostream & out, Hand h); // the insertion operator (friend) to print Hand on an std::ostream
        void printHand(); // prints the player's hand
    private:
        queue<Card*> hand; // queue of Card pointers to hold the player's hand
        int handSize; // to keep track of the hand size 
};

Hand::Hand(istream& in) //constructor for when the game is resumed from file
{
    int i = 0; // to keep track of hand size
    while (!in.eof()) {
        string temp;
        in >> temp;
        if (temp == "Blue") { // if the string from istream is equal to card name
            Card* tempCard = new Blue(); // creates temp Blue card
            hand.push(tempCard); // adds card to hand
            i++; // increments hand size counter 
        }
        if (temp == "Chili") { // if the string from istream is equal to card name
            Card* tempCard = new Chili(); // creates temp Chili card
            hand.push(tempCard); // adds card to hand
            i++; // increments hand size counter 
        }
        if (temp == "Stink") { // if the string from istream is equal to card name
            Card* tempCard = new Stink(); // creates temp Stink card
            hand.push(tempCard); // adds card to hand
            i++; // increments hand size counter 
        }
        if (temp == "Green") { // if the string from istream is equal to card name
            Card* tempCard = new Green(); // creates temp Green card
            hand.push(tempCard); // adds card to hand
            i++; // increments hand size counter 
        }
        if (temp == "soy") { // if the string from istream is equal to card name
            Card* tempCard = new soy(); // creates temp soy card
            hand.push(tempCard); // adds card to hand
            i++; // increments hand size counter 
        }
        if (temp == "black") { // if the string from istream is equal to card name
            Card* tempCard = new black(); // creates temp black card
            hand.push(tempCard); // adds card to hand
            i++; // increments hand size counter 
        }
        if (temp == "Red") { // if the string from istream is equal to card name
            Card* tempCard = new Red(); // creates temp Red card
            hand.push(tempCard); // adds card to hand
            i++; // increments hand size counter 
        }
        if (temp == "garden") { // if the string from istream is equal to card name
            Card* tempCard = new garden(); // creates temp garden card
            hand.push(tempCard); // adds card to hand
            i++; // increments hand size counter 
        }
        
    }
    handSize = i; // sets the hand size after counting how many cards are in hand from the file
}

// adds the card to the rear of the hand
Hand& Hand::operator+=(Card *c)
{
    hand.push(c);
    return *this; 
}

// returns and removes the top card from the player's hand
Card* Hand::play()
{
    Card* top = hand.front();
    hand.pop();
    return(top);
}

// returns but does not remove the top card from the player's hand
Card* Hand::top()
{
    // if no card in hand, return NULL
    if (hand.size()== 0) {
        return NULL;
    }
    return(hand.front());
}

// returns and removes the Card at a given index
Card* Hand::operator[](int index)
{
    list<Card*> listHand; // temp list to store cards
    handSize = hand.size();
    Card* cardToReturn=NULL; 
    for(int a = 0; a < handSize; a++) // to add each card to new temp list 
    {
        listHand.push_back(hand.front());
        hand.pop();
    }
    for(int a = 0; a < handSize; a++) // check if the index is the same as the one in list, and take out card
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
    return(cardToReturn); // return card taken out of hand
}

// used to print hand so user can select which card to remove from hand
void Hand::printHand() 
{
     queue<Card*> handToIterate = hand; // store hand in another queue to use
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

// the insertion operator to print Hand on an std::ostream
ostream & operator << (ostream& out, Hand h)
{
    queue<Card*> handCopy; // another queue to copy hand
    list<Card*> listHand; // temp list to hold hand
    h.handSize = h.hand.size();
    for(int a = 0; a < h.handSize; a++) // add each Card from hand object to list
    {
        listHand.push_back(h.hand.front());
        h.hand.pop();
    }
    out << "cards = ";
    for(int a = 0; a < h.handSize; a++) // output Cards from list and add back to temp queue
    {
        out <<listHand.front()->getName() <<" ";
        handCopy.push(listHand.front());
        listHand.pop_front();
    }
    out << endl;
    h.hand = handCopy; // copy temp queue back to original hand queue
    return out;
}
