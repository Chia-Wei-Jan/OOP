#ifndef _GAME_H_
#define _GAME_H_
#include "Human.h"
#include "Meek.h"
#include "Random.h"
#include "Dealer.h"

class Game {
private:
	int player_count, human_count, meek_count, random_count;
	Human* humans;
	Meek* meeks;
	Random* randoms;
	Dealer* dealer;	

public:
	Game();
	~Game();
	int get_playerCount() const;
	void display_standing() const;
	void betting();
	void betting_result();
	void initial_draw(Deck &);
	void draw(Deck &);
	bool another_round();
	void enough_card(Deck &);
};

#endif
