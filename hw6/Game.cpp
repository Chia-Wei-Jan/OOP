#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Game.h"
#include "Human.h"
#include "Meek.h"
#include "Random.h"
#include "Dealer.h"
#include "Card.h"
#include "Player.h"
using namespace std;

Game::Game() {
	cout << "Welcome to Blackjack 21!!" << endl << endl;

	cout << "Input the number of total players: ";
	cin >> player_count;

	char line[20];
	int money = 0;
	int length = 0;

	// human
	cout << "Input the number of Human players: ";
	cin >> human_count;
	humans = new Human[human_count];    // call human constructor

	for(int i = 0; i < human_count; i++) {
		cout << "Input the name of Human" << i+1 << ": ";
		cin >> line;
		line[strcspn(line, "\r\n")] = '\0';
		humans[i].set_name(line);

		cout << "Input the bankroll of " << humans[i].get_name() << ": ";
		cin >> money;
		humans[i].set_bankroll(money);
	}

	int left = player_count - human_count;
	meek_count = left / 2;
	random_count = left - meek_count;

	// meek
	meeks = new Meek[meek_count];
	memset(line, 20, '\0');
	strcpy(line, "Meek");
	length = strlen(line);

	for(int i = 0; i < meek_count; i++) {
		char c = '1' + i;
		line[length] = c;
		line[length + 1] = '\0';
		meeks[i].set_name(line);
		meeks[i].set_bankroll(100);
	}

	// random
	randoms = new Random[random_count];
	memset(line, 20, '\0');
	strcpy(line, "Random");
	length = strlen(line);

	for(int i = 0; i < random_count; i++) {
		char c = '1' + i;
		line[length] = c;
		line[length + 1] = '\0';
		randoms[i].set_name(line);
		randoms[i].set_bankroll(100);
	}
	
	// dealer
	dealer = new Dealer[1];
	strcpy(line, "Dealer");
	dealer[0].set_name(line);
	dealer[0].set_bankroll(10000);

	cout << endl;
}

Game::~Game() {
	cout << "Game Over" << endl;
}

int Game::get_playerCount() const {
	return player_count;
}

void Game::display_standing() const {
	cout << "The standings so far:" << endl;
	cout << "-----------------------" << endl;

	// human
	for(int i = 0; i < human_count; i++) {
		cout << humans[i].get_name() << " $" << humans[i].get_bankroll() << endl;
	}
	// meek
	for(int i = 0; i < meek_count; i++) {
		cout << meeks[i].get_name() << " $" << meeks[i].get_bankroll() << endl;
	}
	// random
	for(int i = 0; i < random_count; i++) {
		cout << randoms[i].get_name() << " $" << randoms[i].get_bankroll() << endl;
	}
	// dealer
	cout << dealer[0].get_name() << " $" << dealer[0].get_bankroll() << endl;
	cout << endl;
}

void Game::betting() {
	cout << "Okay, time for betting!" << endl;
	cout << "------------------------" << endl;

	int money = 0;
	// set the bet
	// human
	for(int i = 0; i < human_count; i++) {
		cout << humans[i].get_name() << ", how much would you like to bet? ";
		cin >> money;
		humans[i].set_bet(money);
	}
	// meek
	for(int i = 0; i < meek_count; i++) {
		money = 2 * (1 + meeks[i].get_round() / 3);
		meeks[i].set_bet(money);
	}
	// random
	srand(time(NULL));
	for(int i = 0; i < random_count; i++) {
		int bank = randoms[i].get_bankroll();
		if(bank <= 0) {
			money = 1;
		}
		else {	
			money = rand() % (bank/2);
		}

		randoms[i].set_bet(money);
	}
	// dealer
	dealer[0].set_bet(0);

	// display the bet
	// human
	for(int i = 0; i < human_count; i++) {
		cout << humans[i].get_name() << " bets $" << humans[i].get_bet() << endl;
	}
	// meek
	for(int i = 0; i < meek_count; i++) {
		cout << meeks[i].get_name() << " bets $" << meeks[i].get_bet() << endl;
	}	
	// random
	for(int i = 0; i < random_count; i++) {
		cout << randoms[i].get_name() << " bets $" << randoms[i].get_bet() << endl;
	}
	cout << endl;
}

void Game::betting_result() {
	cout << "Let's see how it turned out:" << endl;
	cout << "-----------------------------" << endl;

	// human
	for(int i = 0; i < human_count; i++) {
		humans[i].win_lose(dealer[0]);
	}
	// meek
	for(int i = 0; i < meek_count; i++) {
		meeks[i].win_lose(dealer[0]);
	}
	// random
	for(int i = 0; i < random_count; i++) {
		randoms[i].win_lose(dealer[0]);
	}

	cout << endl;
}

void Game::initial_draw(Deck &deck) {
	cout << "The initial starting cards are:" << endl;
	cout << "--------------------------------" << endl;
	
	Card drawCard;
	// human
	for(int i = 0; i < human_count; i++) {
		cout << humans[i].get_name() << "'s current hand:[??]";
		for(int j = 0; j < 2; j++) {
			drawCard = deck.draw();
			humans[i].set_handCard(drawCard);
		}
		humans[i].display_secondHandCard();
		cout << endl;
	}
	// meek
	for(int i = 0; i < meek_count; i++) {
		cout << meeks[i].get_name() << "'s current hand:[??]";
		for(int j = 0; j < 2; j++) {
			drawCard = deck.draw();
			meeks[i].set_handCard(drawCard);
		}
		meeks[i].display_secondHandCard();
		cout << endl;
	}
	// random
	for(int i = 0; i < random_count; i++) {
		cout << randoms[i].get_name() << "'s current hand:[??]";
		for(int j = 0; j < 2; j++) {
			drawCard = deck.draw();
			randoms[i].set_handCard(drawCard);
		}
		randoms[i].display_secondHandCard();
		cout << endl;
	}
	
	// dealer
	for(int j = 0; j < 2; j++) {
		drawCard = deck.draw();
		dealer[0].set_handCard(drawCard);
	}

	cout << endl;
}

void Game::draw(Deck &deck) {
	// human
	for(int i = 0; i < human_count; i++) {
		humans[i].turn(deck);
	}
	// meek
	for(int i = 0; i < meek_count; i++) {
		meeks[i].turn(deck);
	}
	// random
	for(int i = 0; i < random_count; i++) {
		randoms[i].turn(deck);
	}
	// dealer
	dealer[0].turn(deck);

}

bool Game::another_round() {
	cout << "Another round? (Y or N): ";
	string input;
	cin >> input;
	
	while(true) {
		if(input == "N") {
			cout << endl;
			return false;
		}
		else if(input == "Y") {
			for(int i = 0; i < human_count; i++) {
				humans[i].reset();
			}
			for(int i = 0; i < meek_count; i++) {
				meeks[i].reset();
			}
			for(int i = 0; i < random_count; i++) {
				randoms[i].reset();
			}
			dealer[0].reset();
			cout << endl;
			return true;
		}
		else {
			cout << "Invalid Input" << endl;
		}
	}
}

void Game::enough_card(Deck &deck) {
	if(deck.get_currentCount() < (player_count + 1) * 5)
		deck.reset();
}