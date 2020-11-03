#include <iostream>
#include "Card.h"
#include "CardFactory.h"
using namespace std;

class Hand {
    public:
        Hand(istream& in, const CardFactory* cf);
        Hand& operator+=(Card*);
        Card* play();
        Card* top();
        Card* operator[](int);
};