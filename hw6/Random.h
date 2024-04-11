#ifndef _RANDOM_H_
#define _RANDOM_H_
#include "Player.h"

class Random: public Player {
public:		
	Random();
	~Random();
	bool strategy();
};

#endif
