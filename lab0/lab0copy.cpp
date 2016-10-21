// lab0.cpp : Defines the entry point for the console application.
// Author: Huy Do
// Email address: huy.do@wustl.edu
// Contains the parsing and printing function that read card declaration strings
// from and text file and print them 


#include "stdafx.h"
#include "lab0copy.h"
#include<vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;


int parsing(vector<Card>&abc, char* filename);
int printcard(const vector<Card>&xyz);

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
int parsing(vector<Card>&abc, char* filename) {
	ifstream ifs;
	string infile = filename;
	infile += ".txt";
	ifs.open(infile);

	if (ifs.is_open()) {
		string val;
		while(ifs>>val) {		
			//cout << val << endl;
			string rankss;
			string suitss;
			bool lengthvalid =1;
			bool suitvalid = 1;
			bool rankvalid = 1;

			if (val.length() == 2) {
				suitss = val[1];
				rankss = val[0];
			}
			else if (val.length() == 3) {
				suitss = val[2];
				rankss = val.substr(0,2);
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
		if (abc.size() > 0) {
			return 0;
		}
		else {
			cout << "There is no valid string in the txt file." << endl;
			return 1;
		}
	}
	else {
		cout << "Invalid .txt file name. Type   lab0 card_file to run the program." << endl;
		return 2;
	}
	ifs.close();
}

int message(string progname) {
	cout << progname << endl;
	cout << "Invalid number of arguments. Type   lab0 card_file to run the program." << endl;
	return 4;
}
int main(int argc, char *argv[])
{
	if (argc == 2) {
		vector<Card> huy;
		int a = parsing(huy, argv[1]);
		if (a == 0) {
			printcard(huy);
		}
		else {
			return a;
		}
	}
	else {
		return message(argv[0]);
	}
}

