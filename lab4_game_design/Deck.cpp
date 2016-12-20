#include "stdafx.h"
#include "Deck.h"
//#include "Card.h"
//#include "Card.cpp"
#include<iostream>
#include<vector>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

//char * rankMap[13] = { "2","3","4","5","6","7","8","9","10","J","Q","K","A" };
//char * suitMap[4] = { "C","D","H","S" };


Deck::Deck(){}
Deck::Deck(const char* filename) {

	int e = load(filename);

	if (e) {
		throw e;
	}


}
int Deck::load(const char* filename) {

	int load = parsing2(cards, filename);
	if (load) {
		return -1;
	}
	return 0;
	/*
	try {
		ifstream ifs;
		ifs.open(filename);
		if (ifs.is_open()) {
			while (1) {
				string i;
				ifs >> i;
				if (i == "")break;
				if (i.length() == 2 || i.length() == 3) {
					const char *k = i.c_str();
					Card::RANK rank;
					Card::SUIT suit;
					int rankResult = parseRank(k[0], rank);
					int suitResult;
					if (i.length() == 2) {
						suitResult = parseSuit(k[1], suit);
					}
					else if (i.length() == 3) {
						suitResult = parseSuit(k[2], suit);
					}
					struct Card c = {suit, rank};

					if (rankResult == 0 && suitResult == 0) {
						this->cards.push_back(c);
					}
				}
				else {
					cout << "Bad form ignored, please check card file" << endl;
				}

			}
			ifs.close();
			return 0;
		}
		else {
			cout << filename << " can not be open" << endl;
			ifs.close();
			return 1;
		}
	}
	catch (int e) {
		cout << "error in parse" << e << endl;
		return -1;
	}
	*/
}

void Deck::add_card(Card c) {
	cards.push_back(c);
}

void Deck::shuffle() {
	random_device rd;
	mt19937 g(rd());
	std::shuffle(cards.begin(), cards.end(),g);

}

const int Deck::size() {
	return cards.size();
}

//void Deck::getCard(Card & c) {
	
//}

ostream& operator<<(ostream & o, const Deck & d) {
	for (auto i = d.cards.begin(); i != d.cards.end(); i++) {
		o << rankMap[i->rank] << suitMap[i->suit] << endl;
	}
	return o;
}

