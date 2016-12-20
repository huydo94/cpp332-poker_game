#pragma once
#ifndef FIVECARDDRAW_H
#define FIVECARDDRAW_H

#include "Card.h"
#include "Hand.h"
#include "Game.h"
#include "Deck.h"

using namespace std;

class Game;

class FiveCardDraw: public Game {
protected:
	size_t dealerpos;
	Deck mainDeck;
	Deck discardDeck;

	bool canCheck; //true when player can check/bet
	unsigned int maxbet; //maxbet in each phase;
	unsigned int pot;
	int numfolded;  //number of players who folded
	bool roundDonebyFold; //true when everyone except one person folded in a round
public:
	FiveCardDraw();
	virtual int before_turn(Player& someplayer);
	virtual int turn(Player &player);
	virtual int after_turn(Player &player);
	virtual int before_round();
	virtual int round();
	virtual int after_round();
	virtual int betPhase() ; // new add
	static bool player_Poker_rank(shared_ptr<Player> player1, shared_ptr<Player> player2); //why static

	virtual int betturn(Player & player) ;
	
};

#endif // !FIVECARDDRAW_H