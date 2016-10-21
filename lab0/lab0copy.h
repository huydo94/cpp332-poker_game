// Author: Huy Do
// Email address: huy.do@wustl.edu
// Contains the declaration for struct Card with the enumeration suits and ranks

#pragma once


enum suits { spades=1,clubs, diamonds, hearts };
enum ranks { two=1, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };

struct Card {
	Card(suits suit1, ranks rank1);
	bool operator< (const Card &) const;
	suits Suits;
	ranks Ranks;
};

