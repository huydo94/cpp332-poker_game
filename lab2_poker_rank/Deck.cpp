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


Deck& operator<< (Deck& deck2, Hand& somehand4) {
	somehand4.myhand.push_back(deck2.mydeck.back());
	deck2.mydeck.pop_back();
	sort(somehand4.myhand.begin(), somehand4.myhand.end());
	return deck2;
}

