// lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Game.h"
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 4) {
		cout << "Enter lab4 FiveCardDraw or lab4 SevenCardStud   and at least 2 players separated by a comma to start." << endl;
		return 1;
	}
	string gametype = argv[1];
	if (gametype == "FiveCardDraw") {
		if (argc > 12) {
			cout << "The maximum number of players to start the game is only 10." << endl;
			return 2;
		}
	};
	if (gametype == "SevenCardStud") {
		if (argc > 9) {
			cout << "The maximum number of players to start the game is only 7." << endl;
			return 3;
		}
	};
	Game game;
	vector<string> names;
	stringstream ss1; //to get player names later
	for (int i = 2; i < argc; i++) {
		names.push_back(argv[i]);
	}

	while (1) {
		try {

			game.start_game(gametype);
			shared_ptr<Game> instance = game.instance();

			for (int i = 0; i < names.size(); i++) {
				instance->add_player(names[i]);
			}

			while (instance->playernum() >= 2) {
				cout << "There are " << instance->playernum() << " players. Let's start a new round." << endl;
				int t1 = instance->before_round();

				if (t1 != 0) {

					game.stop_game();
					throw "Wrong with before_round.";
				}
				int t2 = instance->round();
				if (t2 != 0) {
					game.stop_game();
					throw "Wrong with round.";
				}
				int t3 = instance->after_round();
				if (t3 != 0) {
					game.stop_game();
					throw "Wrong with after_round.";
				}
			}
			cout << "There is less than 2 players." << endl;
			game.stop_game();
			while (1) {
				cout << "Game ended. Choose (continue/quit): " << endl;
				string action3;
				cin >> action3;
				cin.ignore();
				if (action3 == "quit") {
					return 0;
				}
				if (action3 == "continue") {
					while (1) {
						cout << "Enter the type of game (FiveCardDraw/SevenCardStud): " << endl;
						cin >> gametype;
						if (gametype == "FiveCardDraw" || gametype == "SevenCardStud") {
							break;
						}
					}
					cout << "Enter the player names (separated by space): " << endl;
					names.clear();
					string inputs;
					string eachname;
					cin.ignore();
					getline(cin, inputs);
					ss1 << inputs;
					while (ss1>>eachname) {
						names.push_back(eachname);
					}
					ss1.clear();
					if (gametype == "FiveCardDraw") {
						if (names.size() > 10) {
							cout << "The maximum number of players to start the game is only 10." << endl;
							return 6;
						}
					};
					if (gametype == "SevenCardStud") {
						if (names.size() > 7) {
							cout << "The maximum number of players to start the game is only 7." << endl;
							return 7;
						}
					};
					break;
				}
			}
		}
		catch (const char* msg) {
			cout << msg << endl;
			game.stop_game();
			return 10;
		}
	}//end of big while loop
}
