#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Card.h"
using namespace std;


Card::Card() {
		rank = 0; 
		suit = spade;
		value = 0;
}

Card::~Card() { }

int Card::get_rank() const {
	return rank;
}
int Card::get_suit() const {
	return suit;
}
int Card::get_value() const {
	return value;
}
void Card::set_value(int new_value) {
	value = new_value;
}

void Card::set_card(int index) {
	// rank
	rank = index % 13;
	
	// suit
	if((index / 13) == 0)	suit = spade;
	else if((index / 13) == 1)	suit = heart;
	else if((index / 13) == 2)	suit = diamond;
	else if((index / 13) == 3)	suit = club;
	
	// value
	if(rank >= 10)	value = 10;
	else if(rank == 0)	value = 11;
	else	value = rank + 1;
}

void Card::display_card() {
	int num = rank + 1;
	char c;

	if(suit == spade)	c = 'S';
	else if(suit == heart)	c = 'H';
	else if(suit == diamond)	c = 'D';
	else if(suit == club) 	c = 'C';

	cout << "[" << num << c << "]";
}