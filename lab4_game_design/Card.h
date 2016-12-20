#ifndef CARD_H
#define CARD_H

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;


extern char * rankMap[13];
extern char * suitMap[4];

enum SUIT { club, diamond, heart, spade };
enum RANK { two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };
struct Card
{
	enum SUIT { club, diamond, heart, spade};
	enum RANK { two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };
	SUIT suit;
	RANK rank;
	Card();
	Card(SUIT s, RANK r) {
		suit = s;
		rank = r;
	};
	friend ostream & operator<<(ostream &o, const Card &c);

};

int parsing(vector<Card> & cards, char * fileName);
int parsing2(vector<Card> &cards, const char * fileName);
int printing(const vector<Card> &cards);
int parseRank(char c, Card::RANK &rank);
int parseSuit(char c, Card::SUIT &suit);
int usageMessage(char * filename, char * errorMessage);
bool operator<(const Card & a, const Card & b);
void poker(const vector<Card> & n);
bool operator==(const Card & a, const Card &b);
int pokert(const vector<Card> & n);

bool compareSf(const vector<Card> & a, const vector<Card> & b);
bool compareFk(const vector<Card> & a, const vector<Card> & b);
bool compareFh(const vector<Card> & a, const vector<Card> & b);
bool compareF(const vector<Card> & a, const vector<Card> & b);
bool compareS(const vector<Card> & a, const vector<Card> & b);
bool compareTk(const vector<Card> & a, const vector<Card> & b);
bool compareTp(const vector<Card> & a, const vector<Card> & b);
bool compareOp(const vector<Card> & a, const vector<Card> & b);
bool compareUn(const vector<Card> & a, const vector<Card> & b);

#endif