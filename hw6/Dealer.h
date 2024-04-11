#ifndef _DEALER_H_
#define _DEALER_H_
#include "Player.h"

class Dealer: public Player {
public:
	Dealer();
	~Dealer();
	bool strategy();
};

#endif
