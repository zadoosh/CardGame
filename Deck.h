#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Deck : public std::vector<Card*> {
public:
	
	Card* draw() {
		Card* temp = back();
		pop_back();
		return temp;
	}

};
 
