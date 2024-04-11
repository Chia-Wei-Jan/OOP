#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Card.h"
#include "Deck.h"
using namespace std;

class Player {
private:
	char name[20];
	int bankroll;
	int bet;
	Card handCard[10];
	int handCard_count;
	int totalPoint;
	int round;

public:
	Player();
	~Player();
	void set_name(char (&line)[20]);
	std::string get_name();
	void set_bet(const int);
	int get_bet();
	void set_bankroll(const int);
	int get_bankroll();
	int get_handCard_count();
	void set_handCard(Card &);
	void display_secondHandCard();
	void display_handCard();
	void compute_totalPoint();
	int get_totalPoint();
	bool check_bust();
	void turn(Deck &);
	bool check_clubSeven();
	void win_lose(Player &);
	void reset();
	int get_round();
	virtual bool strategy() = 0;
};

#endif
