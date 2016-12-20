#include "stdafx.h"
#include "Game.h"
#include "FiveCardDraw.h"
#include "SevenCardDraw.h"
using namespace std;

shared_ptr<Game> Game::game = nullptr;

shared_ptr<Game> Game::instance() {
	if (!game) {
		throw "instance_not_available";
	}
	else {
		shared_ptr<Game> copyGame(game);
		return copyGame;
	}
}

void Game::start_game(const string s) {
	if (game) throw "game_already_started";
	if (s == "FiveCardDraw") {
		game = make_shared<FiveCardDraw>();
	}
	else if (s == "SevenCardStud") {
		game = make_shared<SevenCardDraw>();
	}
	else {
		throw "unknown_game";
	}
}

void Game::stop_game() {
	if (!game) throw "no_game_in_progress";
	game.reset();
}

void Game::add_player(const string & s) {
	shared_ptr<Player> player = find_player(s);
	if (player) {
		throw "already_playing";
	}
	else {
		players.push_back(make_shared<Player>(s));

	}
}


shared_ptr<Player> Game::find_player(const string & s) {
	for (auto b = players.begin(); b != players.end(); b++) {
		if ((*b)->name == s) return *b;
	}
	shared_ptr<Player> empty = nullptr;
	return empty;
}

int Game::playernum() {
	return players.size();
}

Game::~Game(){}