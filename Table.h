#include <iostream>
#include <string>
#include "CardFactory.h"

using namespace std;

class Table {
    public:
        Table(istream& in, const CardFactory* cf);
        bool win(string& s);
        void printHand(bool b);
};