// Deck.h
// Author : Huy Do
// Email: huy.do@wustl.edu

#pragma once
#include<vector>
#include <iostream>
#include<string>

enum suits { spades = 1, clubs = 5, diamonds = 21, hearts = 89 };
enum ranks { zero=0,one,two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };
enum pokerrank{norank=1,onepair,twopair,threeokind,straight1,flush1,fullhouse1,fourkind1,straightflush};

class Deck {
private:
	std::vector<Card> mydeck;
public:
	friend class Hand;
	Deck();//default constructor
	Deck(char* filename);
	void shuffle();
	unsigned int size();
	friend std::ostream& operator<< (std::ostream& os, const Deck& deck1);
	friend Deck& operator<< (Deck& deck2, Hand& somehand4);
	int load(std::vector<Card>&abc, char* filename);
};