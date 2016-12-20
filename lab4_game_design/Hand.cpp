#include "stdafx.h"
#include "Hand.h"
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

Hand::Hand() {
}

Hand::Hand(const Hand & h) {
	copy(h.cards.begin(), h.cards.end(), back_inserter(cards));
}

Hand& Hand::operator=(const Hand& h) {
	cards.clear();
	copy(h.cards.begin(), h.cards.end(), back_inserter(cards));
	return *this;
}

const int Hand::size() const{
	return cards.size();
}

const bool Hand::operator==(const Hand& h) const {
	if (cards.size() != h.cards.size()) {
		return false;
	}
	auto hfirst = h.cards.begin();
	for (auto first = this->cards.begin(); first != this->cards.end(); first++) {
		if (!(*first == *hfirst)) {
			return false;
		}
		hfirst++;
	}
	return true;
}

const bool Hand::operator<(const Hand& h) const{

	if (this->size() <= h.size()) {
		auto first1 = this->cards.begin();
		auto first2 = h.cards.begin();
		while (first1 != this->cards.end()) {
			if (*first1 < *first2) {
				return true;
			}
			else if (*first2 < *first1) {
				return false;
			}
			first1++;
			first2++;
		}

	}
	else {
		auto first2 = this->cards.begin();
		auto first1 = h.cards.begin();
		while (first1 != h.cards.end()) {
			if (*first1 < *first2) {
				return false;
			}
			else if (*first2 < *first1) {
				return true;
			}
			first1++;
			first2++;
		}
	}
	if (this->size() == h.size()) {
		return false;
	}
	if (this->size() <= h.size()) {
		return true;
	}
	return false;

}

const string Hand::asString() const{
	string str = "";
	for (auto i = cards.begin(); i != cards.end(); i++) {
		str = str + rankMap[i->rank] + suitMap[i->suit] + " ";
	}
	return str;
}

ostream& operator<<(ostream & o, const Hand & h) {
	o << h.asString();
	return o;
}

Hand& operator<<(Hand & h, Deck & d) {
	h.cards.push_back(d.cards.back());
	d.cards.pop_back();
	sort(h.cards.begin(), h.cards.end());
	return h;
}
Hand& operator>>(Hand & h, Deck & d) {
	h.cards.push_back(d.cards.back());
	d.cards.pop_back();
	//sort(h.cards.begin(), h.cards.end());
	return h;
}

Card& Hand::operator[](const size_t n) {

	
	if ((n > (*this).size()) || n == 0) {
		throw "The index is out of range.";
	}
	else {
		return cards[n - 1];
	}
	
}

void Hand::remove_card(const size_t n) {
	
	if ((n > (*this).size()) || n == 0) {
		throw "The index is out of range.";
	}
	else {
		cards.erase(cards.begin() + n - 1);
	}
	
}

int pokertype(const Hand & h) {
	return pokert(h.getCards());
}


bool poker_rank(const Hand & h1, const Hand & h2) {
	int h1t = pokertype(h1);
	int h2t = pokertype(h2);
	if (h1t > h2t) {
		return true;
	}
	else if (h1t < h2t) {
		return false;
	}
	else {
		switch (h1t) {
		case 9:
			return compareSf(h1.getCards(), h2.getCards());
		case 8:
			return compareFk(h1.getCards(), h2.getCards());
		case 7:
			return compareFh(h1.getCards(), h2.getCards());
		case 6:
			return compareF(h1.getCards(), h2.getCards());
		case 5:
			return compareS(h1.getCards(), h2.getCards());
		case 4:
			return compareTk(h1.getCards(), h2.getCards());
		case 3:
			return compareTp(h1.getCards(), h2.getCards());
		case 2:
			return compareOp(h1.getCards(), h2.getCards());
		case 1:
			return compareUn(h1.getCards(), h2.getCards());

		}

	}
	return false;
}

//new add
void Hand::combination(int i, int j, Card r[], int num, vector<Hand> & result, Hand & input) {
	if (j == 1)
	{
		for (int k = 0; k < i; k++)
		{
			vector<Card> temp;
			r[num - 1] = input.cards[k];
			for (int i = 0; i < num; i++)
			{
				temp.push_back(r[i]);
			}
			sort(temp.begin(), temp.end());
			Hand hand;
			hand.cards = temp;
			result.push_back(hand);
		}
	}
	else if (j == 0)
	{
		//do nothing!  
	}
	else
	{
		for (int k = i; k >= j; k--)
		{
			r[j - 2] = input.cards[k - 1];
			combination(k - 1, j - 1, r, num, result, input);
		}
	}
}