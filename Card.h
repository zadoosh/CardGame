#pragma once
#include <stdio.h> 
#include <iostream>
#include <string>
#include <assert.h> 
using namespace std;
class Card {

public:
    
    virtual int getCoinsPerCard(int) {
        return 0;
    }
    virtual string getName() const{
        return name;
    }
    virtual void print(ostream& out) const{
        out<< name.front();
    }
    Card(const Card& t) = delete;
    Card& operator = (const Card& c) = delete;
    Card() {

    }
protected:
    void setName(const string set) {
        name = set;
    }
    string name;
};

ostream& operator<<(std::ostream& os, Card& c)
{
    c.print(os);
    return os;
}

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

class Chili : public Card {
public:
    int getCoinsPerCard(int cards)
    {
        //assert(cards >= 3 && cards <= 18);
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

class garden : public Card {
public:
    int getCoinsPerCard(int cards)
    {
      //  assert(cards <= 6 && cards >= 2);
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