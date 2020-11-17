#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Deck : public std::vector<Card*> {
public:
	
	Card* const draw() {
		Card* temp = back();
		pop_back();
		return temp;
	}

};
 
