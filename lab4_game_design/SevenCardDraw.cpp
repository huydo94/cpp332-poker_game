#include "stdafx.h"
#include <iostream>
#include <memory>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include "SevenCardDraw.h"
#include "Card.h"

using namespace std;

SevenCardDraw::SevenCardDraw() :dealerpos(0) {
}

int SevenCardDraw::before_round() {
	mainDeck.cards.clear();
	Card::RANK allranks[] = { Card::RANK::two, Card::RANK::three, Card::RANK::four, Card::RANK::five, Card::RANK::six, Card::RANK::seven, Card::RANK::eight, Card::RANK::nine, Card::RANK::ten, Card::RANK::jack, Card::RANK::queen, Card::RANK::king, Card::RANK::ace };
	Card::SUIT allsuits[] = { Card::SUIT::club, Card::SUIT::diamond, Card::SUIT::heart, Card::SUIT::spade };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			Card card1 = Card(allsuits[i], allranks[j]);
			mainDeck.add_card(card1);
		}
	}
	mainDeck.shuffle();
	int numPlayers = players.size();
	pot = 0;
	for (int i = 0; i < numPlayers; i++) {
		(*players[i]).chipaccount -= 1;
		pot += 1;
	}

	for (int j = 1; j <= numPlayers; j++) {
	
		(*players[j - 1]).isfold = false;    //reset the folded flag
		(*players[j - 1]).chipbet = 0;    //reset the chipbet each round
	}
	numfolded = 0;
	roundDonebyFold = false;
	return 0;
}

int SevenCardDraw::round() {
	int numPlayers = players.size();

	for (int t = 1; t <= 5; t++) {
		if (t == 1) {
			for (auto p : players) {
				(*p).hand >> mainDeck; //use a different operator to not sort the hand
				(*p).hand >> mainDeck;
				(*p).hand >> mainDeck;
			}
		}
		else {
			for (auto p : players) {
				(*p).hand >> mainDeck;
			}
		}
		if (!roundDonebyFold) {
			cout << "Turn " << t << " begins: " << endl;
			for (int i = 0; i < numPlayers; i++) {
				(*players[i]).chipbet = 0;	//reset the chipbet each phase
				if ((*players[i]).isfold) continue;
				cout << (*players[i]).name << "'s view: " << endl;
				for (int j = 0; j < numPlayers; j++) {
					if ((*players[j]).isfold) continue;
					turn7(*(players[j]), t, i == j);
				}
			}
			betPhase();
		}

	}
	return 0;
}

int SevenCardDraw::turn7(Player &player, int t, bool self) {
	if (self) {
		cout << player.name <<"'s hand: "<< player.hand << endl;
		return 0;
	}
	cout << player.name <<"'s hand: "<<  " (*) (*) ";
	if (t == 5) {
		for (int i = 3; i < t + 2; i++) {
			cout << player.hand[i] << " ";
		}
		cout << "(*)" << endl;
	}
	else {
		for (int j = 3; j < t + 3; j++) {
			cout << player.hand[j] << " ";
		}
		cout << endl;
	}
	return 0;
}

bool SevenCardDraw::player_Poker_rank(shared_ptr<Player> player1, shared_ptr<Player> player2) {
	if (!player1) return false;
	else {
		if (!player2) return true;
		else return poker_rank(player1->hand, player2->hand);
	}
}

void SevenCardDraw::replaceFive(Player & player) { // new add
	vector<Hand> handVector;
	Card resulttemp[5];
	player.hand.combination(7, 5, resulttemp, 5, handVector, player.hand);

	sort(handVector.begin(), handVector.end(), &poker_rank);
	player.hand = handVector[0];
}

int SevenCardDraw::after_round() {

	// begin
	
	vector<shared_ptr<Player>> temp(players);
	for (auto i = temp.begin(); i != temp.end(); i++) {
		replaceFive((*(*i)));
	}
	sort(temp.begin(), temp.end(), &player_Poker_rank);

	bool winPrint = true;
	for (auto i = temp.begin(); i != temp.end(); i++) {
		if ((!(*i)->isfold)&&(winPrint == true)) {
			(*i)->win++;
			(*i)->chipaccount += pot;
			if (!roundDonebyFold) {
				cout << (*(*i)) << "won with hand: " << endl;
				cout << (*i)->hand << endl;
			}
			else {
				cout << (*(*i)) << "won" << endl;
			}
			winPrint = false;		
		}
		else {
			(*i)->los++;
			if (!(*i)->isfold) {
				cout << (*(*i)) << "lost with hand: " << endl;
				cout << (*i)->hand << endl;
			}
			else {
				cout << (*(*i)) << "folded." << endl;
			}
		}
		(*i)->hand.cards.clear();
	}
	// end
	while (1) {

		cout << "Is there any player want to leave? (yes/no) " << endl;
		string leave;
		cin >> leave;
		cin.ignore();

		if (leave == "no") {
			break;
		}
		if (leave == "yes") {
			cout << "Please tell me the name of the player? " << endl;
			string pname;
			cin >> pname;
			cin.ignore();

			shared_ptr<Player> player = find_player(pname);

			if (player) {
				ofstream out;
				out.open(player->name);
				out << player->name << " " << player->win << " " << player->los << endl;
				out.close();
				cout << player->name << " is leaving." << endl;
				for (auto k = players.begin(); k != players.end(); ++k) {
					if ((*k)->name == pname) {
						players.erase(k);
						break;
					}
				}

			}
			else cout << "Don't find that player." << endl;
			if (players.size() == 0) {
				cout << "There's no player left ." << endl;
				break;
			}
		}

	}

	while (1) {
		if (players.size() == 7) {
			cout << "Maximum number of players reached. (7 players)" << endl;
			break;
		}
		cout << "Is there any player want to join the game? (yes/no)" << endl;
		string join;
		cin >> join;
		cin.ignore();
		if (join == "no") {
			break;
		}
		if (join == "yes") {
			cout << "Please tell me the name of the player? " << endl;
			string pname;
			cin >> pname;
			cin.ignore();

			try {
				add_player(pname);
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
		}
	}
	for (auto k = players.begin(); k != players.end(); ++k) {
		if ((*k)->broke()) {
			while (1) {
				cout << (*k)->name << " is broke. You have to quit or put 20 in. Type (quit/continue):" << endl;
				string action3;
				cin >> action3;
				if (action3 == "quit") {
					ofstream out;
					out.open((*k)->name);
					out << (*k)->name << " " << (*k)->win << " " << (*k)->los << " " << (*k)->chipaccount << endl;
					out.close();
					cout << (*k)->name << " is leaving." << endl;
					players.erase(k);
					break;
				}
				if (action3 == "continue") {
					(*k)->chipaccount = 20;
					break;
				}
			}
		}
	}
	if (dealerpos<players.size()) dealerpos++;
	else dealerpos = 0;
	return 0;

}


int SevenCardDraw::betPhase() { // new add
	int numPlayers = players.size();
	int k = 0;
	canCheck = true;
	maxbet = 0;

	int idle = 0;
	for (int j = 0; j < numPlayers; j++) {
		if ((*players[j]).broke() || ((*players[j]).isfold)) {
			idle++;
		}
	}
	if (idle == (numPlayers - 1)) {
		return 0;
	}

	while (1) {
		if (roundDonebyFold) break;
		for (int j = 1; j <= numPlayers; j++) {
			if (numfolded < (numPlayers - 1)) { //if number of players folded < everyone - 1
				k += betturn((*players[(j + dealerpos) % numPlayers]));
			}
			else { 
				roundDonebyFold = true; 
				break;
			}
		}
		if (numfolded == (numPlayers - 1)) { //everybody folded
			roundDonebyFold = true;
			break;
		};
		if (k == numPlayers) { //everybody checks
			break;
		}

		int samebet = 0;
		int numbetting = 0;
		for (int i = 0; i < numPlayers; i++) {
			if (!(((*players[i]).broke()) || (*players[i]).isfold)) { //if player didn't fold or didn't run out of money
				numbetting += 1;
				if ((*players[i]).chipbet == maxbet) {
					samebet += 1;
				}
			}
		}
		if (samebet == numbetting) {
			break;
		}
	}

	return 0;
}

int SevenCardDraw::betturn(Player &player) {
	if ((!canCheck) && (!player.isfold) && (!player.broke()) && (player.chipbet != maxbet)) {
		cout << player.name << "'s turn begins. Chips bet in the phase:" << player.chipbet << " Chips remaining: " << player.chipaccount << " Pot: " << pot << endl;

		while (1) {
			cout << "What do you wanna do? (fold/call/raise) " << endl;
			string action2;
			cin >> action2;
			cin.ignore();
			if (action2 == "fold") {
				player.isfold = true;
				numfolded += 1;
				break;
			}
			if (action2 == "call") {
				player.chipaccount -= (maxbet - player.chipbet);
				if (player.chipaccount >= 0) {
					pot += (maxbet - player.chipbet);
					player.chipbet = maxbet;
				}
				else {	
					pot += (maxbet + player.chipaccount);
					player.chipbet += (maxbet + player.chipaccount);
					player.chipaccount = 0;
				}
				break;
			}
			if (action2 == "raise") {
				int amountraise;
				cout << "How much do you wanna raise? (1 or 2)" << endl;
				cin >> amountraise;
				cin.ignore();
				maxbet += amountraise;
				player.chipaccount -= (maxbet - player.chipbet);
					pot += (maxbet - player.chipbet);
					player.chipbet = maxbet;
				break;
			}
		}
		cout << player.name << "'s bet turn ends. Chips bet in the phase: " << player.chipbet << " Chips remaining: " << player.chipaccount << endl;
	}
	if (canCheck && (!player.isfold) && (!player.broke())) {
		cout << player.name << "'s turn begins. Chips bet in the phase:" << player.chipbet << " Chips remaining: " << player.chipaccount << " Pot: " << pot << endl;
		while (1) {

			cout << "What do you wanna do? (check/bet) " << endl;
			string action1;
			cin >> action1;
			cin.ignore();

			if (action1 == "check") {
				cout << "checked" << endl;
				return 1;
			}
			if (action1 == "bet") {
				canCheck = false;
				int amountbet;
				cout << "How much do you wanna bet? (1 or 2)" << endl;
				cin >> amountbet;
				cin.ignore();
				maxbet = amountbet;
				player.chipbet += amountbet;
				player.chipaccount -= amountbet;
				pot += amountbet;
				break;
			}
		}
		cout << player.name << "'s bet turn ends. Chips bet in the phase: " << player.chipbet << " Chips remaining: " << player.chipaccount << endl;
	}
	return 0;
}

