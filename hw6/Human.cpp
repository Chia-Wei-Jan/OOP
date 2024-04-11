#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Human.h"
using namespace std;

Human::Human() { }
Human::~Human() {} 

bool Human::strategy() {
	string input;

	while(true) {
		cout << "Would you like to draw another card (Y or N): ";
		cin >> input;

		if(input == "Y")	return true;
		else if(input == "N")	return false;
		else	cout << "Invalid input" << endl;
	}
}