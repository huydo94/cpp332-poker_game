// Card.h
// Author : Huy Do
// Email: huy.do@wustl.edu

#pragma once
#include<vector>
#include <iostream>
#include<string>

enum suits { spades = 1, clubs = 5, diamonds = 21, hearts = 89 };
enum ranks { zero=0,one,two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };
enum pokerrank{norank=1,onepair,twopair,threeokind,straight1,flush1,fullhouse1,fourkind1,straightflush};

struct Card {
	Card(ranks rank1, suits suit1);
	bool operator< (const Card &) const;
	bool operator== (const Card &)const;
	suits Suits;
	ranks Ranks;
};
bool equalrank(const Card &x, const Card&y);