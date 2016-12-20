#ifndef HAND_H
#define HAND_H
#include "stdafx.h"
//#include "Card.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Deck.h"

using namespace std;

class Hand {

private:
	vector<Card> cards;
public:

	friend class Deck;
	friend class SevenCardDraw;
	Hand();
	Hand(const Hand & h);
	Hand& operator=(const Hand& h);
	const int size() const;
	const bool operator==(const Hand& h) const;
	const bool operator<(const Hand& h) const;
	const string asString() const;

	Card& operator[](const size_t n);
	void remove_card(const size_t n);
	friend ostream& operator<<(ostream & o, const Hand & h);
	friend Hand& operator<<(Hand & h, Deck & d);
	friend Hand& operator>>(Hand & h, Deck & d);
	vector<Card> getCards()const {
		return cards;
	};
	void combination(int i, int j, Card r[], int num, vector<Hand> & result, Hand & input);
};


bool poker_rank(const Hand & h1, const Hand & h2);
int pokertype(Hand & h);

#endif