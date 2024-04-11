#ifndef CARD_H
#define CARD_H

class Card {
private:
	int rank;
	enum Suit {spade, heart, diamond, club} suit;
	int value;

public:
	Card();
	~Card();

	int get_rank() const;
	int get_suit() const;
	int get_value() const;
	void set_value(int);
	void set_card(int);
	void display_card();
};

#endif
