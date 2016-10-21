// Author: Huy Do
// Email address: huy.do@wustl.edu
// Contains the declaration for struct Card with the enumeration suits and ranks

#pragma once
#include<vector>


enum suits { spades = 1, clubs=5, diamonds=21, hearts=89 };
enum ranks { two = 1, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };

struct Card {
	Card(ranks rank1, suits suit1);
	bool operator< (const Card &) const;
	bool operator== (const Card &)const;
	suits Suits;
	ranks Ranks;
};

int parsing5(std::vector<Card>&abc, char* filename);
int printcard(const std::vector<Card>&xyz);
int pokerhand(const std::vector<Card>&deck);
int message(std::string progname);
