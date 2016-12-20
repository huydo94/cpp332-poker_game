#include "stdafx.h"
#include <iostream>
#include <string>
#include "Card.h"
#include <fstream>
#include <sstream>
#include <algorithm>


using namespace std;

char * rankMap[13] = { "2","3","4","5","6","7","8","9","10","J","Q","K","A" };
char * suitMap[4] = { "C","D","H","S" };
Card::Card() {}

//const char * Card::rankMap[13] = { "2","3","4","5","6","7","8","9","10","J","Q","K","A" };
//const char * Card::suitMap[4] = { "C","D","H","S" };

//Card::Card(SUIT suit1 = spade, RANK rank1 = two)
	//:suit(suit1), rank(rank1) {}

int parsing(vector<Card> &cards, char * fileName) {
	try {
		ifstream ifs;
		ifs.open(fileName);
		string line;
		if (ifs.is_open()) {
			ifs >> ws;
			while (getline(ifs,line)) {
				ifs >> ws;
				vector<Card> hand;
				int num = 0;
				string i;
				istringstream str(line);
				str >> ws;
				while (str >> i) {
					str >> ws;
					//ifs >> i;
					//if (i == "")break;
					if (i.length() == 2 || i.length() == 3) {
						const char *k = i.c_str();
						if (k[0] == '/' || k[1] == '/') {
							break;
						}
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
						struct Card c = { suit,rank };

						if (rankResult == 0 && suitResult == 0) {
							hand.push_back(c);
							num++;
						}
						else {
							cout << "warning: invalid card definition string" << endl;
						}
					}
					else {
						cout << "Bad form ignored, please check card file" << endl;
					}

				}
				
				if (num == 5) {
					cards.insert(cards.end(),hand.begin(),hand.end());
				}
				else {
					cout << "warning: the number of the hands are not 5." << endl;
				}
				ifs >> ws;
			}
			ifs.close();
			return 0;
		}
		else {
			cout << fileName << " can not be open" << endl;
			ifs.close();
			return 1;
		}
	}
	catch (int e) {
		cout << "error in parse" << e << endl;
		return -1;
	}
}

int parsing2(vector<Card> &cards, const char * fileName) {
	try {
		ifstream ifs;
		ifs.open(fileName);
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
					struct Card c = { suit,rank };

					if (rankResult == 0 && suitResult == 0) {
						cards.push_back(c);
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
			cout << fileName << " can not be open" << endl;
			ifs.close();
			return 1;
		}
	}
	catch (int e) {
		cout << "error in parse" << e << endl;
		return -1;
	}
}



int printing(const vector<Card> &cards) {
	string i;
	int j = 0;
	try {
		for (Card c : cards) {
			cout << rankMap[c.rank] << suitMap[c.suit] << endl;
		}
		return 0;
	}
	catch (int e) {
		cout << "error in printing" << e << endl;
		return -1;
	}


}


int parseRank(char c, Card::RANK &rank) {

	switch (c) {
	case '2':
		rank = Card::RANK::two;
		return 0;
		break;
	case '3':
		rank = Card::RANK::three;
		return 0;
		break;
	case '4':
		rank = Card::RANK::four;
		return 0;
		break;
	case '5':
		rank = Card::RANK::five;
		return 0;
		break;
	case '6':
		rank = Card::RANK::six;
		return 0;
		break;
	case '7':
		rank = Card::RANK::seven;
		return 0;
		break;
	case '8':
		rank = Card::RANK::eight;
		return 0;
		break;
	case '9':
		rank = Card::RANK::nine;
		return 0;
		break;
	case '1':
		rank = Card::RANK::ten;
		return 0;
		break;
	case 'j':
	case 'J':
		rank = Card::RANK::jack;
		return 0;
		break;
	case 'q':
	case 'Q':
		rank = Card::RANK::queen;
		return 0;
		break;
	case 'k':
	case 'K':
		rank = Card::RANK::king;
		return 0;
		break;
	case 'a':
	case 'A':
		rank = Card::RANK::ace;
		return 0;
		break;
	default:
		cout << "error in parseRank, please check the form of card file" << endl;
		return 3;
		break;

	}

}


int parseSuit(char c, Card::SUIT &suit) {

	switch (c) {
	case 's':
	case 'S':
		suit = Card::SUIT::spade;
		return 0;
		break;
	case 'c':
	case 'C':
		suit = Card::SUIT::club;
		return 0;
		break;
	case 'd':
	case 'D':
		suit = Card::SUIT::diamond;
		return 0;
		break;
	case 'h':
	case 'H':
		suit = Card::SUIT::heart;
		return 0;
		break;
	default:
		cout << "error in parseSuit, please check form of card file" << endl;
		return 2;
		break;
	}

}


int usageMessage(char * filename, char* errorMessage) {
	cout << filename << "Please read file Card.h, Card.cpp, main.cpp, card_file.txt." << errorMessage << endl;
	return 1;
}

bool operator<(const Card & a, const Card & b) {
	if (a.rank == b.rank) {
		return a.suit < b.suit;
	}
	 return a.rank < b.rank;
}

bool operator==(const Card & a, const Card &b) {
	if (a.rank == b.rank) {
		if (a.suit == b.suit) {
			return true;
		}
	}
	return false;
}

void poker(const vector<Card> & n) {
	
	for (auto i = n.begin(); i < n.end(); i += 5) {
		vector<Card> temp;
		temp.insert(temp.end(),i,i+5);
		int clubNum = 0;
		int spadeNum = 0;
		int heartNum = 0;
		int diamondNum = 0;
		int same = 0;
		int conse = 0;
		int diff = 0;
		int lian = 0;
		int to = 0;
		sort(temp.begin(), temp.end());
		auto l = temp.end();
		switch ((l - 1)->suit) {
		case Card::SUIT::club:
			clubNum++;
			break;
		case Card::SUIT::spade:
			spadeNum++;
			break;
		case Card::SUIT::diamond:
			diamondNum++;
			break;
		case Card::SUIT::heart:
			heartNum++;
			break;
		}

		for (auto j = temp.begin(); j != temp.end()-1;++j) {
			switch (j->suit) {
			case Card::SUIT::club:
				clubNum++;
			break;
			case Card::SUIT::spade:
				spadeNum++;
				break;
			case Card::SUIT::diamond:
				diamondNum++;
				break;
			case Card::SUIT::heart:
				heartNum++;
				break;
			}
			if ((j->rank) == ((j + 1)->rank)) {
				same++;
				lian++;
			}
			else {
				//diff++;
				if(lian!=0) lian--;
				if ((j->rank+1) == ((j+1)->rank)) {
					conse++;
				}
			}
			if (lian == 2) to++;
		}
		if (conse == 4) {
			if (clubNum == 5 || spadeNum == 5 || diamondNum == 5 || heartNum == 5) {
				cout << "straight flush" << endl;
				continue;
			}
			else {
				cout << "straight" << endl;
				continue;
			}
		}
		if (same == 3) {
			if ((temp.begin()->rank == (temp.begin() + 1)->rank) && ((temp.end() - 1)->rank == (temp.end() - 2)->rank)) {
				cout << "full house" << endl;
				continue;
			}
			else {
				cout << "four of a kind" << endl;
				continue;
			}
		}
		if (clubNum == 5 || spadeNum == 5 || diamondNum == 5 || heartNum == 5) {
			cout << "flush" << endl;
			continue;
		}
		if (same == 2) {
			if (to == 1) {
				cout << "three of a kind" << endl;
				continue;
			}
			else if (to == 0) {
				cout << "two pair" << endl;
				continue;
			}
			
		}
		if (same == 1) {
			cout << "one pair" << endl;
			continue;
		}
		if (same == 0) {
			cout <<"no rank"<< endl;
			continue;
		}

	}
}

int pokert(const vector<Card> & n) {

	for (auto i = n.begin(); i < n.end(); i += 5) {
		vector<Card> temp;
		temp.insert(temp.end(), i, i + 5);
		int clubNum = 0;
		int spadeNum = 0;
		int heartNum = 0;
		int diamondNum = 0;
		int same = 0;
		int conse = 0;
		int diff = 0;
		int lian = 0;
		int to = 0;
		sort(temp.begin(), temp.end());
		auto l = temp.end();
		switch ((l - 1)->suit) {
		case Card::SUIT::club:
			clubNum++;
			break;
		case Card::SUIT::spade:
			spadeNum++;
			break;
		case Card::SUIT::diamond:
			diamondNum++;
			break;
		case Card::SUIT::heart:
			heartNum++;
			break;
		}

		for (auto j = temp.begin(); j != temp.end() - 1; ++j) {
			switch (j->suit) {
			case Card::SUIT::club:
				clubNum++;
				break;
			case Card::SUIT::spade:
				spadeNum++;
				break;
			case Card::SUIT::diamond:
				diamondNum++;
				break;
			case Card::SUIT::heart:
				heartNum++;
				break;
			}
			if ((j->rank) == ((j + 1)->rank)) {
				same++;
				lian++;
			}
			else {
				//diff++;
				if (lian != 0) lian--;
				if ((j->rank + 1) == ((j + 1)->rank)) {
					conse++;
				}
			}
			if (lian == 2) to++;
		}
		if (conse == 4) {
			if (clubNum == 5 || spadeNum == 5 || diamondNum == 5 || heartNum == 5) {
				//cout << "straight flush" << endl;
				return 9;
				//continue;
			}
			else {
				return 5;
				//cout << "straight" << endl;
				//continue;
			}
		}
		if (same == 3) {
			if ((temp.begin()->rank == (temp.begin() + 1)->rank) && ((temp.end() - 1)->rank == (temp.end() - 2)->rank)) {
				//cout << "full house" << endl;
				//continue;
				return 7;
			}
			else {
				//cout << "four of a kind" << endl;
				return 8;
				//continue;
			}
		}
		if (clubNum == 5 || spadeNum == 5 || diamondNum == 5 || heartNum == 5) {
			//cout << "flush" << endl;
			//continue;
			return 6;
		}
		if (same == 2) {
			if (to == 1) {
				return 4;
				//cout << "three of a kind" << endl;
				//continue;
			}
			else if (to == 0) {
				return 3;
				//cout << "two pair" << endl;
				//continue;
			}

		}
		if (same == 1) {
			return 2;
			//cout << "one pair" << endl;
			//continue;
		}
		if (same == 0) {
			return 1;
			//cout << "no rank" << endl;
			//continue;
		}

	}
	return 0;
}

bool compareSf(const vector<Card> & a, const vector<Card> & b) {
	return *(b.end() - 1) < *(a.end() - 1);
}

bool compareFk(const vector<Card> & a, const vector<Card> & b) {
	return *(b.begin() + 1) < *(a.begin()+1);
}

bool compareFh(const vector<Card> & a, const vector<Card> & b) {
	if (*(b.begin() + 2) == *(a.begin() + 2)) {
		Card tempb = *b.begin();
		Card tempa = *a.begin();
		if (*(b.begin() + 2) == *(b.begin())) {
			tempb = *(b.begin()+4);
		}
		if (*(a.begin() + 2) == *(a.begin())) {
			tempa = *(a.begin() + 4);
		}
		return tempb < tempa;
	}
	return *(b.begin() + 2) < *(a.begin() + 2);
}

bool compareF(const vector<Card> & a, const vector<Card> & b) {
	if ((b.end() - 1)->rank < (a.end() - 1)->rank) {
		return true;
	}
	if ((b.end() - 1)->rank == (a.end() - 1)->rank) {
		if ((b.end() - 2)->rank < (a.end() - 2)->rank) {
			return true;
		}
		if ((b.end() - 2)->rank == (a.end() - 2)->rank) {
			if ((b.end() - 3)->rank < (a.end() - 3)->rank) {
				return true;
			}
			if ((b.end() - 3)->rank == (a.end() - 3)->rank) {
				if ((b.end() - 4)->rank < (a.end() - 4)->rank) {
					return true;
				}
				if ((b.end() - 4)->rank == (a.end() - 4)->rank) {
					if ((b.end() - 5)->rank < (a.end() - 5)->rank) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool compareS(const vector<Card> & a, const vector<Card> & b) {
	return *(b.end() - 1) < *(a.end() - 1);
}

bool compareTk(const vector<Card> & a, const vector<Card> & b) {
	return *(b.begin()+2) < *(a.begin()+2);
}

bool compareTp(const vector<Card> & a, const vector<Card> & b) {
	if ((b.begin() + 3)->rank == (a.begin() + 3)->rank) {
		if ((b.begin() + 1)->rank == (a.begin() + 1)->rank) {
			if ((b.begin() + 4)->rank < (a.begin() + 4)->rank) {
				return true;
			}
			else if ((b.begin() + 2)->rank < (a.begin() + 2)->rank) {
				return true;
			}
			else if ((b.begin())->rank < (a.begin())->rank) {
				return true;
			}
			else return false;
		}
		return (b.begin() + 1)->rank < (a.begin() + 1)->rank;
	}
	return (b.begin() + 3)->rank < (a.begin() + 3)->rank;
}

bool compareOp(const vector<Card> & a, const vector<Card> & b) {
	if((b.begin() + 3)->rank == (b.begin() + 4)->rank || (b.begin() + 3)->rank == (b.begin() + 2)->rank) {
		if ((a.begin() + 3)->rank == (a.begin() + 4)->rank || (a.begin() + 3)->rank == (a.begin() + 2)->rank) {
			if ((b.begin() + 3)->rank < (a.begin() + 3)->rank) return true;
			else {
				if ((b.begin() + 3)->rank > (a.begin() + 3)->rank) return false;
				if ((b.begin() + 4)->rank < (a.begin() + 4)->rank) return true;
				if ((b.begin() + 4)->rank > (a.begin() + 4)->rank) return false;
				if ((b.begin() + 3)->rank < (a.begin() + 3)->rank) return true;
				if ((b.begin() + 3)->rank > (a.begin() + 3)->rank) return false;
				if ((b.begin() + 2)->rank < (a.begin() + 2)->rank) return true;
				if ((b.begin() + 2)->rank > (a.begin() + 2)->rank) return false;
				if ((b.begin() + 1)->rank < (a.begin() + 1)->rank) return true;
				if ((b.begin() + 1)->rank > (a.begin() + 1)->rank) return false;
				if (b.begin()->rank < a.begin()->rank) return true;
				return false;
			}
		}
		else {
			if ((b.begin() + 3)->rank < (a.begin() + 1)->rank) return true;
			else {
				if ((b.begin() + 3)->rank >(a.begin() + 1)->rank) return false;
				if ((b.begin() + 4)->rank < (a.begin() + 4)->rank) return true;
				if ((b.begin() + 4)->rank >(a.begin() + 4)->rank) return false;
				if ((b.begin() + 2)->rank < (a.begin() + 3)->rank) return true;
				if ((b.begin() + 2)->rank >(a.begin() + 3)->rank) return false;
				if ((b.begin() + 1)->rank < (a.begin() + 2)->rank) return true;
				if ((b.begin() + 1)->rank >(a.begin() + 2)->rank) return false;
				if (b.begin()->rank < a.begin()->rank) return true;
				return false;
			}
		}
	}
	else {
		if ((a.begin() + 3)->rank == (a.begin() + 4)->rank || (a.begin() + 3)->rank == (a.begin() + 2)->rank) {
			if ((b.begin() + 1)->rank < (a.begin() + 3)->rank) return true;
			else {
				if ((b.begin() + 1)->rank > (a.begin() + 3)->rank) return false;
				if ((b.begin() + 4)->rank < (a.begin() + 4)->rank) return true;
				if ((b.begin() + 4)->rank > (a.begin() + 4)->rank) return false;
				if ((b.begin() + 3)->rank < (a.begin() + 2)->rank) return true;
				if ((b.begin() + 3)->rank > (a.begin() + 2)->rank) return false;
				if ((b.begin() + 2)->rank < (a.begin() + 1)->rank) return true;
				if ((b.begin() + 2)->rank > (a.begin() + 1)->rank) return false;
				if (b.begin()->rank < a.begin()->rank) return true;
				return false;
			}
		}
		else {
			if ((b.begin() + 1)->rank < (a.begin() + 1)->rank) return true;
			else {
				if ((b.begin() + 1)->rank > (a.begin() + 1)->rank) return false;
				if ((b.begin() + 4)->rank < (a.begin() + 4)->rank) return true;
				if ((b.begin() + 4)->rank > (a.begin() + 4)->rank) return false;
				if ((b.begin() + 3)->rank < (a.begin() + 3)->rank) return true;
				if ((b.begin() + 3)->rank > (a.begin() + 3)->rank) return false;
				if ((b.begin() + 2)->rank < (a.begin() + 2)->rank) return true;
				if ((b.begin() + 2)->rank > (a.begin() + 2)->rank) return false;
				if (b.begin()->rank < a.begin()->rank) return true;
				return false;
				
			}
		}
	}
}

bool compareUn(const vector<Card> & a, const vector<Card> & b) {
	 
	if ((b.end() - 1)->rank < (a.end() - 1)->rank) {
		return true;
	}
	if ((b.end() - 1)->rank == (a.end() - 1)->rank) {
		if ((b.end() - 2)->rank < (a.end() - 2)->rank) {
			return true;
		}
		if ((b.end() - 2)->rank == (a.end() - 2)->rank) {
			if ((b.end() - 3)->rank < (a.end() - 3)->rank) {
				return true;
			}
			if ((b.end() - 3)->rank == (a.end() - 3)->rank) {
				if ((b.end() - 4)->rank < (a.end() - 4)->rank) {
					return true;
				}
				if ((b.end() - 4)->rank == (a.end() - 4)->rank) {
					if ((b.end() - 5)->rank < (a.end() - 5)->rank) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

ostream & operator<<(ostream &o, const Card &c) {
	o << rankMap[c.rank] << suitMap[c.suit] << " ";
	return o;
}