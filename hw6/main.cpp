#include <iostream>
#include "Deck.h"
#include "Game.h"

using namespace std;

int main() {
	Game g;
	g.display_standing();
	
	int player_count = g.get_playerCount();
	Deck d(player_count);

	while(true) {
		g.enough_card(d);
		d.shuffle();

		g.betting();

		g.initial_draw(d);
		g.draw(d);

		g.betting_result();
		g.display_standing();

		if(!g.another_round())	
			break;
	}
}
