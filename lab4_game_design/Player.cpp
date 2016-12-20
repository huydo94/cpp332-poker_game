#include "stdafx.h"
#include "Player.h"
#include <fstream>
#include <sstream>
#include <cstdlib>


Player::Player(const string addname) {
	win = 0;
	los = 0;
	chipbet = 0;
	this->name = addname;
	chipaccount = 20;

	ifstream ifs;
	ifs.open(name);
	string line;
	if (ifs.is_open()) {
		getline(ifs, line);
		istringstream str(line);
		str >> ws;
		string n;
		str >> n;
		if (n != "") {
			this->name = n;
			str >> ws;
			str >> this->win;
			str >> ws;
			str >> this->los;
			str >> ws;
			str >> this->chipaccount;
		}
	}
	else {
		cout << name << " can not be open, and I will build the file." << endl;
		ifs.close();
	}
	//cout << "player setup" << name << win << los << endl;

}

ostream & operator<<(ostream & out, const Player & player) {
	out << player.name << "  Games Won: " << player.win << "  Games Lost: " << player.los << " Chip Account: " << player.chipaccount << endl;
	return out;
}