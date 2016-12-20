#pragma once
#ifndef SEVENCARDDRAW_H
#define SEVENCARDDRAW_H

#include <iostream>
#include "Card.h"
#include "Hand.h"
#include "Game.h"
#include "Deck.h"

using namespace std;

class Game;

class SevenCardDraw : public Game {

protected:
	size_t dealerpos;
	Deck mainDeck;

	unsigned int maxbet; //maxbet in each phase;
	unsigned int pot;
	int numfolded; //number of players who folded in the round
	bool canCheck; //true when player can check/bet
	bool roundDonebyFold; //true when everyone except one person folded in a round
public:
	SevenCardDraw();

	virtual int before_round();
	virtual int round();
	virtual int turn7(Player &player, int t, bool self);

	virtual int after_round();
	static bool player_Poker_rank(shared_ptr<Player> player1, shared_ptr<Player> player2); //why static
	virtual int betturn(Player & player);
	virtual int betPhase();

	virtual void replaceFive(Player & player);
};

#endif // !SEVENCARDDRAW_H