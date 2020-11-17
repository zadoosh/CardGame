#pragma once
#include <iostream>
#include <string>
#include <assert.h> 
using namespace std;
class Card {
public:
    
    virtual int getCardsPerCoin(const int coins) = 0;
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
    int getCardsPerCoin(const int coins)
    {
        assert(coins <= 4 && coins>=1);
        switch (coins) {
            case 1:
                return 4;
            case 2:
                return 6;
            case 3:
                return 8;
            case 4:
                return 10;
        }

    }
    Blue() {
        setName("Blue");
    }
};

class Chili : public Card {
public:
    int getCardsPerCoin(const int coins)
    {
        assert(coins <= 4 && coins >= 1);
        switch (coins) {
        case 1:
            return 3;
        case 2:
            return 6;
        case 3:
            return 8;
        case 4:
            return 9;
        }

    }
    Chili() {
        setName("Chili");
    }
};

class Stink : public Card {
public:
    int getCardsPerCoin(const int coins)
    {
        assert(coins <= 4 && coins >= 1);
        switch (coins) {
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 7;
        case 4:
            return 8;
        }

    }
    Stink() {
        setName("Stink");
    }
};

class Green : public Card {
public:
    int getCardsPerCoin(const int coins)
    {
        assert(coins <= 4 && coins >= 1);
        switch (coins) {
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 6;
        case 4:
            return 7;
        }

    }
    Green() {
        setName("Green");
    }
};

class soy : public Card {
public:
    int getCardsPerCoin(const int coins)
    {
        assert(coins <= 4 && coins >= 1);
        switch (coins) {
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 6;
        case 4:
            return 7;
        }

    }
    soy() {
        setName("soy");
    }
};

class black : public Card {
public:
    int getCardsPerCoin(const int coins)
    {
        assert(coins <= 4 && coins >= 1);
        switch (coins) {
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        }

    }
    black() {
        setName("black");
    }
};

class Red : public Card {
public:
    int getCardsPerCoin(const int coins)
    {
        assert(coins <= 4 && coins >= 1);
        switch (coins) {
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        }

    }
    Red() {
        setName("Red");
    }
};

class garden : public Card {
public:
    int getCardsPerCoin(const int coins)
    {
        assert(coins <= 4 && coins >= 1);
        switch (coins) {
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 0;
        }

    }
    garden() {
        setName("garden");
    }
};