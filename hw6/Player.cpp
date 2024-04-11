#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Player.h"
using namespace std;

Player::Player() {
	bankroll = 0;
	bet = 0;
	handCard_count = 0;
	totalPoint = 0;
}

Player::~Player() { }

void Player::set_name(char (&line)[20]) {
	strcpy(name, line);
}

string Player::get_name() {
	return name;
}

void Player::set_bet(const int money) {
	bet = money;
}

int Player::get_bet() {
	return bet;
}

void Player::set_bankroll(const int money) {
	bankroll = money;
}

int Player::get_bankroll() {
	return bankroll;
}

int Player::get_handCard_count() {
	return handCard_count;
}

void Player::set_handCard(Card &card) {
	handCard[handCard_count++] = card;
}

void Player::display_secondHandCard() {
	handCard[1].display_card();
}

void Player::display_handCard() {
	for(int i = 0; i < handCard_count; i++) {
		handCard[i].display_card();
	}
}

void Player::compute_totalPoint() {
	totalPoint = 0;
	int value = 0;

	for(int i = 0; i < handCard_count; i++) {
		value = handCard[i].get_value();
		if(value == 0) {
			if((totalPoint + value) > 21) {
				totalPoint += 1;
				handCard[i].set_value(1);
			}
			else {
				totalPoint += 11;
			}
		}
		else {
			totalPoint += value;
		}
	}

	if(totalPoint <= 21)	return;
	
	// set Ace value
	for(int j = 0; j < handCard_count; j++) {
		if(handCard[j].get_value() == 11) {
			handCard[j].set_value(1);
			totalPoint -= 10;
		}
		if(totalPoint <= 21)	break;
	}
}

int Player::get_totalPoint() {
	compute_totalPoint();
	return totalPoint;
}

bool Player::check_bust() {
	if(get_totalPoint() > 21) {
		cout << name << " busted at " << get_totalPoint() << "!" << endl;
		return true;
	}
	return false;
}

void Player::turn(Deck &deck) {
	cout << get_name() << "'s turn:" << endl;
	cout << "------------------" << endl;

	while(true) {
		cout << get_name() << "'s current hand: ";
		display_handCard();
		cout << " (" << get_totalPoint() << " points)" << endl;

		if(check_bust())	break;
		
		if(strategy()) {
			cout << get_name() << " chooses to draw." << endl;
			set_handCard(deck.draw());
		}
		else {
			cout << get_name() << " chooses to stay." << endl;
			break;
		}
	}
	cout << endl;

}

bool Player::check_clubSeven() {
	for(int i = 0; i < handCard_count; i++) {
		if(handCard[i].get_suit() == 3 && handCard[i].get_value() == 7)
			return true;
	}
	return false;
}

void Player::win_lose(Player &dealer) {
	int dealer_point = dealer.get_totalPoint();
	int dealer_bankroll = dealer.get_bankroll();
	int player_point = get_totalPoint();

	if(player_point > dealer_point && player_point <= 21) {
		cout << "Yowzah! " << name << " wins $" << bet << endl;
		bankroll += bet;
		dealer_bankroll -= bet;
		round++;    // win round in a row
	}
	else {
		cout << "Ouch! " << name << " loses $" << bet << endl;
		bankroll -= bet;
		dealer_bankroll += bet;
		round = 0;
	}
	dealer.set_bankroll(dealer_bankroll);
}

void Player::reset() {
	handCard_count = 0;
	totalPoint = 0;
}

int Player::get_round() {
	return round;
}

