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
	bool isEmpty();

};

//Need a function like this for the main, we only keep playing if there are cards left in the deck
bool Deck::isEmpty()
{
	if(size() > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
 
