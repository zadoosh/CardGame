#pragma once
#include <stdio.h> 
#include <iostream>
#include <string>
#include <assert.h> 
using namespace std;
class Card {

public:

    // Will implement in the derived classes the table for how many cards are necessary to receive the corresponding number of coins
    virtual int getCoinsPerCard(int) { 
        return 0;
    }

    // Returns the full name of the card (e.g., Blue).
    virtual string getName() const{
        return name;
    }

    // Inserts the first character for the card into the output stream supplied as argument
    virtual void print(ostream& out) const{
        out<< name.front();
    }

    // Deletion of card
    Card(const Card& t) = delete;

    Card& operator = (const Card& c) = delete;
    
    // Default constructor
    Card() {}
protected:

    // Sets the name of the card
    void setName(const string set) {
        name = set;
    }

    // Each card will hold a name attribute
    string name;
};

//  Global stream insertion operator for printing any objects
ostream& operator<<(std::ostream& os, Card& c)
{
    c.print(os);
    return os;
}

// Blue card class
class Blue : public Card {
public:
    int getCoinsPerCard(int cards)
    {
        // assert(cards >= 4 && cards<=20);
        if (cards >= 4 && cards <= 5) return 1;
        else if (cards >= 6 && cards <= 7) return 2;
        else if (cards >= 8 && cards <= 9) return 3;
        else if (cards >= 10) return 4;
        else return 0;
        /*
        switch (cards) {
            case 4 ... 5:
                return 1;
            case 6 ... 7:
                return 2;
            case 8 ... 9:
                return 3;
            case 10 ... 20:
                return 4;
            default:
                return 0;
        }
        */
    }
    Blue() {
        setName("Blue");
    }
};

// Chili card class
class Chili : public Card {
public:
    int getCoinsPerCard(int cards)
    {
        // assert(cards >= 3 && cards <= 18);
        if (cards >= 3 && cards <= 5) return 1;
        else if (cards >= 6 && cards <= 7) return 2;
        else if (cards >= 8 && cards <= 9) return 3;
        else if (cards >= 10) return 4;
        else return 0;
        /*
        switch (cards) {
        case 3 ... 5:
            return 1;
        case 6 ... 7:
            return 2;
        case 8 ... 9:
            return 3;
        case 10 ... 18:
            return 4;
        default:
            return 0;
        }
        */
    }
    Chili() {
        setName("Chili");
    }
};

// Stink card class
class Stink : public Card {
public:
    int getCoinsPerCard(int cards)
    {
        // assert(cards <= 16 && cards >= 3);
        if (cards >= 3 && cards <= 4) return 1;
        else if (cards >= 5 && cards <= 6) return 2;
        else if (cards ==7) return 3;
        else if (cards >= 8) return 4;
        else return 0;
        /*
        switch (cards) {
        case 3 ... 4:
            return 1;
        case 5 ... 6:
            return 2;
        case 7:
            return 3;
        case 8 ... 16:
            return 4;
        default: 
            return 0;
        }
        */
    }
    Stink() {
        setName("Stink");
    }
};

// Green card class
class Green : public Card {
public:
    int getCoinsPerCard(int cards)
    {
        // assert(cards <= 14 && cards >= 3);
        if (cards >= 3 && cards <= 4) return 1;
        else if (cards ==5) return 2;
        else if (cards ==6) return 3;
        else if (cards >= 7) return 4;
        else return 0;
        /*
        switch (cards) {
        case 3 ... 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7 ... 14:
            return 4;
        default:
            return 0;
        }
        */
    }
    Green() {
        setName("Green");
    }
};

// soy card class
class soy : public Card {
public:
    int getCoinsPerCard(int cards)
    {
      //  assert(cards <= 12 && cards >= 2);
        if (cards >= 2 && cards <= 3) return 1;
        else if (cards >= 4 && cards <= 5) return 2;
        else if (cards ==6) return 3;
        else if (cards >= 7) return 4;
        else return 0;
        /*
        switch (cards) {
        case 2 ... 3:
            return 1;
        case 4 ... 5:
            return 2;
        case 6:
            return 3;
        case 7 ... 12:
            return 4;
        default:
            return 0;
        }
        */
    }
    soy() {
        setName("soy");
    }
};

// black card class
class black : public Card {
public:
    int getCoinsPerCard(int cards)
    {
        // assert(cards <= 10 && cards >= 2);
        if (cards >= 2 && cards <= 3) return 1;
        else if (cards == 4 ) return 2;
        else if (cards ==5) return 3;
        else if (cards >= 6) return 4;
        else return 0;
        /*
        switch (cards) {
        case 2 ... 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6 ... 10:
            return 4;
        default:
            return 0;
        }
        */
    }
    black() {
        setName("black");
    }
};

// Red card class 
class Red : public Card {
public:
    int getCoinsPerCard(int cards)
    {
        // assert(cards <= 8 && cards >= 2);
        if (cards ==2) return 1;
        else if (cards ==3) return 2;
        else if (cards ==4) return 3;
        else if (cards >= 5) return 4;
        else return 0;
        /*
        switch (cards) {
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5 ... 8:
            return 4;
        default:
            return 0;
        }
        */
    }
    Red() {
        setName("Red");
    }
};

// garden card class
class garden : public Card {
public:
    int getCoinsPerCard(int cards)
    {
        // assert(cards <= 6 && cards >= 2);
        if (cards ==2) return 2;
        else if (cards >= 3) return 3;
        else return 0;
        /*
        switch (cards) {
        case 2:
            return 2;
        case 3 ... 6:
            return 3;
        default:
            return 0;
        }
        */
    }
    garden() {
        setName("garden");
    }
};