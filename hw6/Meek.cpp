#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Meek.h"
//#include "Player.h"
using namespace std;

Meek::Meek() { }
Meek::~Meek() {}

bool Meek::strategy() { 
	if(check_clubSeven())	return true;  // seven of clubs
	if(get_totalPoint() % 2 == 0)        // even number
		return true;
	else                              // old number
		return false;
}