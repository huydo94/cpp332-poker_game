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


Hand::Hand(void) {}

Hand::Hand(const Hand &somehand):
	myhand(somehand.myhand) {}//copy constructor

Hand& Hand::operator=(const Hand &somehand1) {
	if (&somehand1 == this)
		return *this;
	myhand = somehand1.myhand;
	return *this;
}

unsigned int Hand::size(void) {
	return myhand.size();
}

bool Hand::operator== (const Hand &somehand2)const {
	vector<Card> otherhand = somehand2.myhand;
	return std::equal(myhand.begin(), myhand.end(), otherhand.begin());
	/*if (myhand.size() != otherhand.size()) {
		return false;
	}
	else {
		int x = 0;
		for (unsigned int i = 0; i < myhand.size(); i++) {
			if (myhand[i] == otherhand[i]) {
				x += 1;
			}
		}
		if (x == 5) {
			return true;
		}
		else { return false; }
	}*/
}

string Hand::as_string()const {
	string wholehand;
	for (unsigned int y = 0; y < myhand.size(); y++) {
		string suit;
		string rank;
		suits suitsof = myhand[y].Suits;
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
			cout << "what" << endl;
		}

		ranks rankof = myhand[y].Ranks;
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
			cout << "what" << endl;
		}
		string cards = rank + suit;
		wholehand = wholehand + cards + ' ';
	}
	return wholehand;
}

ostream& operator<< (std::ostream& os1, const Hand& somehand3) {
	os1 << somehand3.as_string();
	os1 << endl;
	return os1;
}


bool Hand:: operator< (const Hand &somehand6) const { //to sort the hands in lexical order (didn't take the Suits into account though)
	int sumweight1 = myhand[0].Ranks + (myhand[1].Ranks) * 10 + (myhand[2].Ranks) * 100 + (myhand[3].Ranks) * 1000 + (myhand[4].Ranks) * 10000;
	int sumweight2 = somehand6.myhand[0].Ranks + (somehand6.myhand[1].Ranks) * 10 + (somehand6.myhand[2].Ranks) * 100 + (somehand6.myhand[3].Ranks) * 1000 + (somehand6.myhand[4].Ranks) * 10000;
	return sumweight1 < sumweight2;
}

