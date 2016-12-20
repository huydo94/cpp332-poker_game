#include <iostream>
#include <string>
#include "Hand.h"


using namespace std;

struct Player {
	string name;
	Hand hand;

	int chipaccount;
	bool isfold; //true when player folded
	unsigned int chipbet;
	bool broke() {
		if (chipaccount <= 0) { return true; }
		else { return false; }
	};
	unsigned int win;
	unsigned int los;
	friend ostream & operator<<(ostream & out, const Player & player);
	Player(const string addname);
};

