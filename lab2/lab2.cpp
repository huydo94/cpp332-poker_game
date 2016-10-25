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

Deck::Deck(void) {}//default constructor

Deck::Deck(char* filename1) {
	vector<Card> mydeck1;
	load(mydeck1, filename1);
}

void Deck::shuffle(void) {
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(mydeck.begin(), mydeck.end(), g);
}

unsigned int Deck::size(void) {
	return mydeck.size();
}

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

int Deck:: load(vector<Card>&abc, char* filename) {
	ifstream ifs;
	string infile = filename;
	infile += ".txt";
	ifs.open(infile);

	if (ifs.is_open()) {
		string val;
		while (ifs >> val) {
			//cout << val << endl;
			string rankss;
			string suitss;
			bool lengthvalid = 1;
			bool suitvalid = 1;
			bool rankvalid = 1;

			if (val.length() == 2) {
				suitss = val[1];
				rankss = val[0];
			}
			else if (val.length() == 3) {
				suitss = val[2];
				rankss = val.substr(0, 2);
			}
			else {
				lengthvalid = 0;
			}
			if (lengthvalid) {
				Card huy;
				if (suitss == "C" || suitss == "c") {
					huy.Suits = clubs;
				}
				else if (suitss == "D" || suitss == "d") {
					huy.Suits = diamonds;
				}
				else if (suitss == "H" || suitss == "h") {
					huy.Suits = hearts;
				}
				else if (suitss == "S" || suitss == "s") {
					huy.Suits = spades;
				}
				else {
					suitvalid = 0;
				}

				if (rankss == "2") {
					huy.Ranks = two;
				}
				else if (rankss == "3") {
					huy.Ranks = three;
				}
				else if (rankss == "4") {
					huy.Ranks = four;
				}
				else if (rankss == "5") {
					huy.Ranks = five;
				}
				else if (rankss == "6") {
					huy.Ranks = six;
				}
				else if (rankss == "7") {
					huy.Ranks = seven;
				}
				else if (rankss == "8") {
					huy.Ranks = eight;
				}
				else if (rankss == "9") {
					huy.Ranks = nine;
				}
				else if (rankss == "10") {
					huy.Ranks = ten;
				}
				else if (rankss == "J" || rankss == "j") {
					huy.Ranks = jack;
				}
				else if (rankss == "Q" || rankss == "q") {
					huy.Ranks = queen;
				}
				else if (rankss == "K" || rankss == "k") {
					huy.Ranks = king;
				}
				else if (rankss == "A" || rankss == "a") {
					huy.Ranks = ace;
				}
				else {
					rankvalid = 0;
				}
				if (suitvalid && rankvalid) {
					abc.push_back(huy);
				}
			}
		}
		if (abc.size() > 44) {
			mydeck = abc;
			return 0;
		}
		else {
			//cout << "There is less than 45 valid card strings in the txt file." << endl;
			throw "There is less than 45 valid card strings in the txt file.";
		}
	}
	else {
		//cout << "Invalid .txt file name. Type   lab2 card_file to run the program." << endl;
		throw "Invalid .txt file name. Type   lab2 card_file to run the program.";
	}
	ifs.close();
}

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

Deck& operator<< (Deck& deck2, Hand& somehand4) {
	somehand4.myhand.push_back(deck2.mydeck.back());
	deck2.mydeck.pop_back();
	sort(somehand4.myhand.begin(), somehand4.myhand.end());
	return deck2;
}

bool Hand:: operator< (const Hand &somehand6) const { //to sort the hands in lexical order (didn't take the Suits into account though)
	int sumweight1 = myhand[0].Ranks + (myhand[1].Ranks) * 10 + (myhand[2].Ranks) * 100 + (myhand[3].Ranks) * 1000 + (myhand[4].Ranks) * 10000;
	int sumweight2 = somehand6.myhand[0].Ranks + (somehand6.myhand[1].Ranks) * 10 + (somehand6.myhand[2].Ranks) * 100 + (somehand6.myhand[3].Ranks) * 1000 + (somehand6.myhand[4].Ranks) * 10000;
	return sumweight1 < sumweight2;
}

int pokerhand(Hand&somehand5) {//determine what type of hand
		vector<Card> five = somehand5.myhand;
		five.erase(unique(five.begin(), five.end()), five.end()); //checking if there are duplicates in the hand
		if (five.size() == 5) {
			bool samesuit = (five[0].Suits + five[1].Suits + five[2].Suits + five[3].Suits + five[4].Suits) / 5 == five[4].Suits;
			bool straight = (((five[4].Ranks - five[3].Ranks) == 1) && ((five[3].Ranks - five[2].Ranks) == 1) && ((five[2].Ranks - five[1].Ranks) == 1) && ((five[1].Ranks - five[0].Ranks) == 1)) || (five[0].Ranks == two && five[4].Ranks == ace && five[1].Ranks == three && five[2].Ranks == four && five[3].Ranks == ranks::five);

			bool pos1 = five[0].Ranks == five[1].Ranks;
			bool pos2 = five[1].Ranks == five[2].Ranks;
			bool pos3 = five[2].Ranks == five[3].Ranks;
			bool pos4 = five[3].Ranks == five[4].Ranks;

			bool fourkind = (pos1&&pos2&&pos3) || (pos2&&pos3&&pos4);
			bool fullhouse = (pos1&&pos2&&pos4) || (pos1&&pos3&&pos4);
			if (pos1 + pos2 + pos3 + pos4 == 1) {
				somehand5.handrank = onepair;
			}
			else if ((pos1&&pos3) + (pos1&&pos4) + (pos2&&pos4) + (fourkind)+(fullhouse) == 1) {
				somehand5.handrank = twopair;
			}
			else if ((pos1&&pos2) + (pos2&&pos3) + (pos3&&pos4) + (fullhouse)+(fourkind) == 1) {
				somehand5.handrank = threeokind;
			}
			else if (fourkind) {
				somehand5.handrank = fourkind1;
			}
			else if (fullhouse) {
				somehand5.handrank = fullhouse1;
			}
			else if (samesuit && straight) {
				somehand5.handrank = straightflush;
			}
			else if (samesuit && (!straight)) {
				somehand5.handrank = flush1;
			}
			else if (straight && (!samesuit)) {
				somehand5.handrank = straight1;
			}
			else {
				somehand5.handrank = norank;
			}
		}
		else {
			//cout << "there are duplicates in the hand/ not enough 5 cards" << endl;
			return 1;
		}
		return 0;
	}

bool equalrank(const Card &x, const Card&y) {
	return (x.Ranks == y.Ranks);
}

bool poker_rank(const Hand &hand1x, const Hand &hand2x) { //compare the ranks of two hands
	Hand hand1 = hand1x;
	Hand hand2 = hand2x;

	int a =pokerhand(hand1);
	int b =pokerhand(hand2);
	int sumrank1 = hand1.myhand[0].Ranks + hand1.myhand[1].Ranks + hand1.myhand[2].Ranks + hand1.myhand[3].Ranks + hand1.myhand[4].Ranks; //sum of all 5 cards' ranks
	int sumrank2 = hand2.myhand[0].Ranks + hand2.myhand[1].Ranks + hand2.myhand[2].Ranks + hand2.myhand[3].Ranks + hand2.myhand[4].Ranks;
	int sumweight1 = hand1.myhand[0].Ranks + hand1.myhand[1].Ranks*10 + hand1.myhand[2].Ranks*100 + hand1.myhand[3].Ranks*1000 + hand1.myhand[4].Ranks*10000; //sum with weight. 
	int sumweight2 = hand2.myhand[0].Ranks + hand2.myhand[1].Ranks*10 + hand2.myhand[2].Ranks*100 + hand2.myhand[3].Ranks*1000 + hand2.myhand[4].Ranks*10000;
	int whichhand1 = hand1.handrank;
	int whichhand2 = hand2.handrank;
	//cout << hand1;
	//cout << hand2;
	//cout << whichhand1 << ' ' << whichhand2 << endl;

	if (a + b == 0) {//checking if the two hands are valid 
		if (hand1.handrank > hand2.handrank) {
			return true;
		}
		else if (hand1.handrank < hand2.handrank) {
			return false;
		}
		else if(hand1.handrank == hand2.handrank) {//same hand ranks
			if (hand1.handrank == fourkind1 || hand1.handrank==threeokind) {
				return (hand2.myhand[2].Ranks < hand1.myhand[2].Ranks); 
			}
			if (hand1.handrank == fullhouse1) {
				if (hand2.myhand[2].Ranks < hand1.myhand[2].Ranks) { return true; }
				else if (hand2.myhand[2].Ranks == hand1.myhand[2].Ranks) {
					return (sumrank1 > sumrank2);
				}
				else { return false; }
			}
			if (hand1.handrank == flush1||hand1.handrank==norank) {
				return (sumweight1 > sumweight2);
			}
			if (hand1.handrank == straight1 || hand1.handrank == straightflush) {
				if (hand1.myhand[4].Ranks != ace && hand2.myhand[4].Ranks != ace) {
					return (hand2.myhand[4].Ranks < hand1.myhand[4].Ranks);
				} else {
					return (sumrank1 > sumrank2);
				}
			}
			if (hand1.handrank == twopair) {
				if (hand1.myhand[3].Ranks > hand2.myhand[3].Ranks) { return true; }
				else if (hand1.myhand[3].Ranks == hand2.myhand[3].Ranks) {
					if (hand1.myhand[1].Ranks > hand2.myhand[1].Ranks) { return true; }
					else if (hand1.myhand[1].Ranks == hand2.myhand[1].Ranks) { return sumrank1 > sumrank2; }
					else { return false; }
				}
				else { return false; }
			}
			if (hand1.handrank == onepair) {
				vector<Card>::iterator i1;
				vector<Card>::iterator i2;
				i1 = adjacent_find(hand1.myhand.begin(), hand1.myhand.end(), equalrank); //find position of the pair
				i2 = adjacent_find(hand2.myhand.begin(), hand2.myhand.end(), equalrank);

				if ((*i1).Ranks > (*i2).Ranks) { return true; }
				else if ((*i1).Ranks == (*i2).Ranks) {
					(*i1).Ranks = zero; // set the pair's rank to be zero
					(*(i1 + 1)).Ranks = zero;
					(*i2).Ranks = zero;
					(*(i2 + 1)).Ranks = zero;
					sort(hand1.myhand.begin(), hand1.myhand.end()); //sort again
					sort(hand2.myhand.begin(), hand2.myhand.end());
					int sumweight1x = hand1.myhand[2].Ranks + hand1.myhand[3].Ranks * 50 + hand1.myhand[4].Ranks * 5000;// weighted sum of the remaining three cards
					int sumweight2x = hand2.myhand[2].Ranks + hand2.myhand[3].Ranks * 50 + hand2.myhand[4].Ranks * 5000;
					//cout << sumweight1x << ' ' << sumweight2x << endl;
					return (sumweight1x > sumweight2x);
				}
				else { return false; }
			}
			throw "couldn't return a true/false value. There's bug in the poker_rank function.";
		}
		else {
			throw "One of the hands cannot be recognized.";
		}
	}
	else {
		throw "Cannot sort. One or many hands are invalid (contain duplicates/ less than 5 cards per hand)";
		//cout << "either or both hands are invalid (contain duplicates/ less than 5 cards per hand" << endl;
	}
}

int main(int argc, char *argv[])
{
	string shuffle = "-shuffle";
	if (argc == 2  && shuffle.compare(argv[1])==0) {
		cout << "Enter lab2 card_file to run " << endl;
		return 1;
	}else if(argc == 3 && shuffle.compare(argv[1]) != 0 && shuffle.compare(argv[2]) != 0){
		cout << "Enter lab2 card_file -shuffle to run" << endl;
		return 2;
	}
	else if (argc == 1) {
		cout << "Not enough input arguments" << endl;
		return 3;
	}
	else if (argc > 3) {
		cout << "Too many input arguments" << endl;
		return 4;
	}
	Deck deck1;
	if(argc == 2 && shuffle.compare(argv[1]) != 0){
		try {
			Deck deck2(argv[1]);
			deck1 = deck2;
		}
		catch (const char* msg) {
			cout << msg << endl;
			return 5;
		}
	}
	if (argc == 3 && shuffle.compare(argv[1]) == 0) {
		try {
			Deck deck2(argv[2]);
			deck2.shuffle();
			deck1 = deck2;
		}catch (const char* msg) {
			cout << msg << endl;
			return 5;
		}
	}
	else if (argc == 3 && shuffle.compare(argv[2]) == 0) {
		try {
			Deck deck2(argv[1]);
			deck2.shuffle();
			deck1 = deck2;
		}
		catch (const char* msg) {
			cout << msg << endl;
			return 5;
		}
	}
	vector<Hand> ninehands;
	for (int z = 0; z < 9; z++) {
		ninehands.push_back(Hand());
	}

	for (int a = 0; a < 9; a++) {
		for (int b = 0; b < 5; b++) {
			deck1 << ninehands[a];
		}
	}
	cout << "Printing the contents of nine hands just dealt:" << endl;
	for (int y = 0; y < 9; y++) {
		cout << ninehands[y];
		pokerhand(ninehands[y]);
		//cout << ninehands[y].handrank << endl;
	}
	cout << "Sort nine hands in lexical order: (from low to high)" << endl;

	std::sort(ninehands.begin(), ninehands.end());

	for (int z = 0; z < 9; z++) {
		cout << ninehands[z];
	}

	cout << "Sort nine hands due to their ranks: (from high to low)" << endl;
	try {
		std::sort(ninehands.begin(), ninehands.end(), poker_rank);
		for (int y = 0; y < 9; y++) {
			cout << ninehands[y];
		}
	}
	catch (const char* msg) {
		cout << msg << endl;
		return 6;
	}
	// some debug codes

	/*Deck deck1("card_file");
	cout << deck1;
	cout << "there are " << deck1.size() << " cards" << endl;
	Deck deck2("card_file2");
	cout << deck2;
	deck2.shuffle();
	cout << "there are "<<deck2.size()<<" cards"<<endl;
	cout << deck2;*/
	/*Hand hand3 = hand1;
	cout << hand3;*/

	/*Deck deck1("card_file2");
	Hand hand1;
	deck1 << hand1;
	deck1 << hand1;
	deck1 << hand1;
	deck1 << hand1;
	deck1 << hand1;
	cout << hand1;
	Hand hand2;
	deck1 << hand2;
	deck1 << hand2;
	deck1 << hand2;
	deck1 << hand2;
	deck1 << hand2;
	cout << hand2;
	cout << poker_rank(hand1, hand2) << endl;*/
	
    return 0;
}

