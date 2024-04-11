#ifndef DECK_H
#define DECK_H
#include "Card.h"

class Deck {
private:
	Card* deck;
	int deck_count;
	int card_count;
	int current_count;

public:
	Deck(const int);
	~Deck();
	void display_deck();
	void shuffle();
	Card& draw();
	int get_currentCount();
	void reset();
};


#endif