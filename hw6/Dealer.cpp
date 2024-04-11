#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Dealer.h"
using namespace std;

Dealer::Dealer() { }
Dealer::~Dealer() { }
	
bool Dealer::strategy() {
	if(get_totalPoint() <= 16)
		return true;
	else
		return false;
}
