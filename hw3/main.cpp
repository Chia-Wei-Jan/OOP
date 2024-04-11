#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "Coin.h"
using namespace std;

int main(int argc, char *argv[]) {
	char inputString[20];

	if(argc > 1) {     // get input string from argv[1]
		strcpy(inputString, argv[1]);
		Coins coin(inputString);
	}
	else	cout << "Error input" << endl;
}
