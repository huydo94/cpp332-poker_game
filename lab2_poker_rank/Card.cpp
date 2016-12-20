// lab2.cpp : Defines the entry point for the console application.
// Author : Huy Do
// Email: huy.do@wustl.edu

#include "stdafx.h"
#include "lab2.h"
#include<vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include<random>

using namespace std;


bool Card::operator<(const Card & sth)const
{
	if (Ranks < sth.Ranks) {
		return true;
	}
	else if (Ranks == sth.Ranks) {
		if (Suits < sth.Suits) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool Card::operator==(const Card & sth1)const
{
	if ((Ranks == sth1.Ranks) && (Suits == sth1.Suits)) {
		return true;
	}
	else {
		return false;
	}
}

Card::Card(ranks rank1 = two, suits suit1 = spades)
	:Suits(suit1), Ranks(rank1) {}


ostream& operator<<(ostream& os, const Deck& deck1) {
	vector<Card> xyz = deck1.mydeck;
	for (unsigned int y = 0; y < xyz.size(); y++) {
		string suit;
		string rank;
		suits suitsof = xyz[y].Suits;
		switch (suitsof) {
		case clubs:
			suit = "C";
			break;
		case diamonds:
			suit = "D";
			break;
		case hearts:
			suit = "H";
			break;
		case spades:
			suit = "S";
			break;
		default:
			os << "what" << endl;
		}

		ranks rankof = xyz[y].Ranks;
		switch (rankof) {
		case two:
			rank = "2";
			break;
		case three:
			rank = "3";
			break;
		case four:
			rank = "4";
			break;
		case five:
			rank = "5";
			break;
		case six:
			rank = "6";
			break;
		case seven:
			rank = "7";
			break;
		case eight:
			rank = "8";
			break;
		case nine:
			rank = "9";
			break;
		case ten:
			rank = "10";
			break;
		case jack:
			rank = "J";
			break;
		case queen:
			rank = "Q";
			break;
		case king:
			rank = "K";
			break;
		case ace:
			rank = "A";
			break;
		default:
			os << "what" << endl;
		}
		string cards = rank + suit;
		os << cards << endl;
	}
	return os;
}
	