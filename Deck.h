#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Deck : public std::vector<Card*> {
public:
	Deck() {};
	Card* const draw() {
		Card* temp = back();
		pop_back();
		return temp;
	}
	bool isEmpty();
	friend ostream& operator << (ostream& out, Deck& d);
	Deck(istream& in);
};

Deck::Deck(istream& in) //constructor for when the game is resumed from file
{
	while (!in.eof()) {
		string temp;
		in >> temp;
		if (temp == "Blue") {
			Card* blue = new Blue();
			push_back(blue);
		}
		if (temp == "Chili") {
			Card* blue = new Chili();
			push_back(blue);
		}
		if (temp == "Stink") {
			Card* blue = new Stink();
			push_back(blue);
		}
		if (temp == "Green") {
			Card* blue = new Green();
			push_back(blue);
		}
		if (temp == "soy") {
			Card* blue = new soy();
			push_back(blue);
		}
		if (temp == "black") {
			Card* blue = new black();
			push_back(blue);
		}
		if (temp == "Red") {
			Card* blue = new Red();
			push_back(blue);
		}
		if (temp == "garden") {
			Card* blue = new garden();
			push_back(blue);
		}
	}
}
//Need a function like this for the main, we only keep playing if there are cards left in the deck
bool Deck::isEmpty()
{
	if(!(this == NULL)|| size() > 0 )
	{
		return false;
	}
	else
	{
		return true;
	}
}
 
ostream& operator << (ostream& out, Deck& t)
{
	out << "deck = ";
	for (int i = 0; i < t.size();i++) {
		out << t[i]->getName()<<" " ;
	}
	return out;
}