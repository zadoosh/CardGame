#pragma once
#include <iostream>
#include <string>
#include <assert.h> 
using namespace std;
class Card {
public:
    
    virtual int getCoinsPerCard(const int cards);
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
    int getCoinsPerCard(const int cards)
    {
        assert(cards >= 4 && cards<=10);
        switch (cards) {
            case 4:
                return 1;
            case 6:
                return 2;
            case 8:
                return 3;
            case 10:
                return 4;
        }

    }
    Blue() {
        setName("Blue");
    }
};

class Chili : public Card {
public:
    int getCoinsPerCard(const int cards)
    {
        assert(cards >= 3 && cards <= 9);
        switch (cards) {
        case 3:
            return 1;
        case 6:
            return 2;
        case 8:
            return 3;
        case 10:
            return 4;
        }

    }
    Chili() {
        setName("Chili");
    }
};

class Stink : public Card {
public:
    int getCoinsPerCard(const int cards)
    {
        assert(cards <= 8 && cards >= 3);
        switch (cards) {
        case 3:
            return 1;
        case 5:
            return 2;
        case 7:
            return 3;
        case 8:
            return 4;
        }

    }
    Stink() {
        setName("Stink");
    }
};

class Green : public Card {
public:
    int getCoinsPerCard(const int cards)
    {
        assert(cards <= 7 && cards >= 3);
        switch (cards) {
        case 3:
            return 1;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 4;
        }

    }
    Green() {
        setName("Green");
    }
};

class soy : public Card {
public:
    int getCoinsPerCard(const int cards)
    {
        assert(cards <= 7 && cards >= 2);
        switch (cards) {
        case 2:
            return 1;
        case 4:
            return 2;
        case 6:
            return 3;
        case 7:
            return 4;
        }

    }
    soy() {
        setName("soy");
    }
};

class black : public Card {
public:
    int getCoinsPerCard(const int cards)
    {
        assert(cards <= 6 && cards >= 2);
        switch (cards) {
        case 2:
            return 1;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 4;
        }

    }
    black() {
        setName("black");
    }
};

class Red : public Card {
public:
    int getCoinsPerCard(const int cards)
    {
        assert(cards <= 5 && cards >= 2);
        switch (cards) {
        case 2:
            return 1;
        case 3:
            return 2;
        case 4;
            return 3;
        case 5:
            return 4;
        }

    }
    Red() {
        setName("Red");
    }
};

class garden : public Card {
public:
    int getCoinsPerCard(const int cards)
    {
        assert(cards <= 3 && cards >= 2);
        switch (cards) {
        case 2:
            return 2;
        case 3:
            return 3;
        }

    }
    garden() {
        setName("garden");
    }
};