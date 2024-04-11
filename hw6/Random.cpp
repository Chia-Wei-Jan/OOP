#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Random.h"
using namespace std;

Random::Random() {}
Random::~Random() {}

bool Random::strategy() {
	srand(time(NULL));

	int point = get_totalPoint();

	if(point <= 9)	
		return true;
	else if(point >= 10 && point <= 12) {
		if((rand() % 10 + 1) <= 8)	
			return true;
		else	
			return false;
	}
	else if(point >= 13 && point <= 15) {
		if((rand() % 10 + 1)  <= 7)
			return true;
		else 
			return false;
	}
	else if(point >= 16 && point <= 18) {
		if((rand() % 10 + 1) <= 5)
			return true;
		else 
			return false;
	}
	else
		return false;
}