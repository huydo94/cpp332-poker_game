// Author: Huy Do
// Email: huy.do@wustl.edu

#include "stdafx.h"
#include "lab1.h"
#include<vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>


using namespace std;
int printcard(const vector<Card>&xyz) {
	for (int y = 0; y < xyz.size(); y++) {
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
			cout << "what" << endl;
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
			cout << "what" << endl;
		}
		string cards = rank + suit;
		cout << cards << endl;
	}
	return 0;
}

Card::Card(ranks rank1=two, suits suit1=spades)
	:Suits(suit1), Ranks(rank1) {}

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

int parsing5(vector<Card>&abc, char* filename) {
	ifstream ifs;
	string infile = filename;
	infile += ".txt";
	ifs.open(infile);
	if (ifs.is_open()) {
		string line;
		while (getline(ifs, line)) {
			cout << line << endl;
			stringstream linestr(line);
			string val;
			vector<Card> fivecards;
			while (linestr >> val) {
				//cout << val << endl;
				string rankss;
				string suitss;
				bool lengthvalid = 1;
				bool suitvalid = 1;
				bool rankvalid = 1;
				if (val.substr(0,2) == "//") { //only works when there's a space before '//'
					break;
				}
				else if (val.length() == 2) {
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
						fivecards.push_back(huy);
					}
				}
			}
			if (fivecards.size() == 5) {
				for (int a = 0; a < 5; a++) {
					abc.push_back(fivecards[a]);
				}
			}
			else {
				cout << "invalid hand" << endl;
			}
		}
		if (abc.size() > 0) {
			return 0;
		}
		else {
			cout << "There is no valid hand in the txt file." << endl;
			return 1;
		}
	}
	else {
		cout << "Invalid .txt file name. Type   lab1 hands to run the program." << endl;
		return 2;
	}
	ifs.close();
}

int pokerhand(const vector<Card>&deck) {
	cout << "Ranking the poker hands: " << endl;
	for (int b = 0; b < deck.size(); b++) {
		vector<Card> five;
		for (int c=0; c < 5; c++) {
			five.push_back(deck[b]);
			b++;
		}
		b--;
		sort(five.begin(), five.end()); //doesn't need a third argument because the operator< is already overloaded
		printcard(five);
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
				cout << "one pair" << endl;
			}
			else if ((pos1&&pos3) + (pos1&&pos4) + (pos2&&pos4) + (fourkind)+(fullhouse) == 1) {
				cout << "two pairs" << endl;
			}
			else if ((pos1&&pos2) + (pos2&&pos3) + (pos3&&pos4) + (fullhouse)+(fourkind) == 1) {
				cout << "three pairs" << endl;
			}
			else if (fourkind) {
				cout << "four of a kind" << endl;
			}
			else if (fullhouse) {
				cout << "full house" << endl;
			}
			else if (samesuit && straight) {
				cout << "straight flush" << endl;
			}
			else if (samesuit && (!straight)) {
				cout << "flush" << endl;
			}
			else if (straight && (!samesuit)) {
				cout << "straight" << endl;
			}
			else {
				cout << "no rank" << endl;
			}
		}
		else {
			cout << "there are duplicates in the hand" << endl;
		}
	}
	return 0;
}

int message(string progname) {
	cout << progname << endl;
	cout << "Invalid number of arguments. Type   lab1 hands to run the program." << endl;
	return 4;
}
int main(int argc, char *argv[])
{
	if (argc == 2) {
		vector<Card> huy1;
		int a = parsing5(huy1, argv[1]);
		if (a == 0) {
			pokerhand(huy1);
		}
		else {
			return a;
		}
	}
	else {
		return message(argv[0]);
	}
}
