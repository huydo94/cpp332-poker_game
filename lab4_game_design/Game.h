#ifndef  GAME_H
#define GAME_H

#include <memory>
#include "Deck.h"
#include "Player.h"


using namespace std;
class Game {
protected:
	static shared_ptr<Game> game;
	Deck mainDeck;
	vector<shared_ptr<Player>> players;

public:
	static shared_ptr<Game> instance();
	static void start_game(const string s);
	static void stop_game();
	void add_player(const string & s);
	shared_ptr<Player> find_player(const string & s);
	int playernum();
	virtual ~Game();
	virtual int before_turn(Player & p) { return 0; };
	virtual int turn(Player & p) { return 0; };
	virtual int after_turn(Player & p) { return 0; };
	virtual int before_round() { return 0; };
	virtual int round() { return 0; };
	virtual int after_round() { return 0; };
	virtual int betPhase() { return 0; }; // new add

	virtual int betturn(Player & player) { return 0; } ;
	virtual int turn7(Player &player, int t, bool self) { return 0; };

	virtual void replaceFive(Player & player) {}; // new add

};

#endif // ! GAME_H