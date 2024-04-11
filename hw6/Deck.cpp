#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Deck.h"
using namespace std;

Deck::Deck(const int player_count) {
	deck_count = 1 + (player_count-1) / 4;   // 4 people -> 1 deck
	card_count = deck_count * 52;
	current_count = card_count;     // the number of rest card
	deck = new Card[card_count];

	for(int i = 0; i < card_count; i++) {
		deck[i].set_card(i % 52);
	}
		
}

Deck::~Deck() { }

void Deck::display_deck() {
	for(int i = 0; i < card_count; i++) {
		deck[i].display_card();
	}
	cout << endl;
}

void Deck::shuffle() {
	for(int i = 0; i < current_count; i++) {
		int j = rand() % current_count;

		Card temp;
		temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}

Card& Deck::draw() {
	return deck[--current_count];
}

int Deck::get_currentCount() {
	return current_count;
}

void Deck::reset() {
	current_count = card_count;
}