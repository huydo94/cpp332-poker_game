#ifndef DECK_H
#define DECK_H
#include "stdafx.h"
#include "Card.h"
//#include "Hand.h"
#include <vector>
#include <iostream>

using namespace std;

class Deck {
	

private:

	vector<Card> cards;

public:
	friend class Hand;
	friend class FiveCardDraw;
	friend class SevenCardDraw;
	Deck();
	Deck(const char* filename);
	//~Deck();
	int load(const char* filename);
	void shuffle();
	const int size();
	void add_card(Card c);
	friend ostream& operator<<(ostream & o, const Deck & d);
	friend Hand& operator<<(Hand & h, Deck & d);
	friend Hand& operator>> (Hand & h, Deck & d);
};


#endif