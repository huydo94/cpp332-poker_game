// .h
// Author : Huy Do
// Email: huy.do@wustl.edu

#pragma once
#include<vector>
#include <iostream>
#include<string>

enum suits { spades = 1, clubs = 5, diamonds = 21, hearts = 89 };
enum ranks { zero=0,one,two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };
enum pokerrank{norank=1,onepair,twopair,threeokind,straight1,flush1,fullhouse1,fourkind1,straightflush};

class Hand {
private:
	std::vector<Card> myhand;
	
public:
	pokerrank handrank;
	friend class Deck;
	Hand(); //default constructor
	Hand(const Hand &somehand); //copy constructor
	Hand& operator=(const Hand& somehand1);
	unsigned int size();
	bool operator< (const Hand &somehand6) const;
	bool operator== (const Hand &somehand2)const;
	std::string as_string()const;
	friend std::ostream& operator<< (std::ostream& os1, const Hand& somehand3);
	friend Deck& operator<< (Deck& deck2, Hand& somehand4);
	friend int pokerhand(Hand&somehand5);
	friend bool poker_rank(const Hand &hand1, const Hand &hand2);
};