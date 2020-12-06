#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Deck : public std::vector<Card*> {
public:

	Deck() {}; // default constructor

	Card* const draw() { // draw a card from the deck
		Card* temp = back();
		pop_back();
		return temp;
	}

	bool isEmpty(); // to check if the deck is empty

	// the insertion operator (friend) to insert all the cards in the deck to an std::ostream
	friend ostream& operator << (ostream& out, Deck& d);

	// is a constructor which accepts an istream and reconstructs the deck from file
	Deck(istream& in);
};

Deck::Deck(istream& in) //constructor for when the game is resumed from file
{
	while (!in.eof()) {
		string temp;
		in >> temp;
		if (temp == "Blue") { // checks if the string from istream is the card Blue
			Card* tempCard = new Blue(); // creates a temp card
			push_back(tempCard); // adds new temp card back to deck to be used in the game again
		}
		if (temp == "Chili") { // checks if the string from istream is the card Chili
			Card* tempCard = new Chili(); // creates a temp card
			push_back(tempCard); // adds new temp card back to deck to be used in the game again
		}
		if (temp == "Stink") { // checks if the string from istream is the card Stink
			Card* tempCard = new Stink(); // creates a temp card
			push_back(tempCard); // adds new temp card back to deck to be used in the game again
		}
		if (temp == "Green") { // checks if the string from istream is the card Green
			Card* tempCard = new Green(); // creates a temp card
			push_back(tempCard); // adds new temp card back to deck to be used in the game again
		}
		if (temp == "soy") { // checks if the string from istream is the card soy
			Card* tempCard = new soy(); // creates a temp card
			push_back(tempCard); // adds new temp card back to deck to be used in the game again
		}
		if (temp == "black") { // checks if the string from istream is the card black
			Card* tempCard = new black(); // creates a temp card
			push_back(tempCard); // adds new temp card back to deck to be used in the game again
		}
		if (temp == "Red") { // checks if the string from istream is the card Red
			Card* tempCard = new Red(); // creates a temp card
			push_back(tempCard); // adds new temp card back to deck to be used in the game again
		}
		if (temp == "garden") { // checks if the string from istream is the card garden
			Card* tempCard = new garden(); // creates a temp card
			push_back(tempCard); // adds new temp card back to deck to be used in the game again
		}
	}
}
// checks if deck is empty (used for winning condition and to end game)
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
 
// the insertion operator (friend) to insert all the cards in the deck to an std::ostream
ostream& operator << (ostream& out, Deck& t)
{
	out << "deck = ";
	for (int i = 0; i < t.size();i++) {
		out << t[i]->getName()<<" " ;
	}
	return out;
}