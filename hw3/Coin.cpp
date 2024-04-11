#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "Coin.h"
using namespace std;

const int TRUE = 1;
const int FALSE = 0;


Coins::Coins(char (&inputString)[20]) {      // constructor
       	cout << "Object is being created" << endl;
	
	// Convert and display if the input is valid
	if(get_dollar_cent(inputString)) {
		convert();
		display();
	}
	else
		cout << "Error input" << endl;
}

Coins::~Coins() {         // destructor
	cout << "Object is being deleted" << endl;
}

bool Coins::get_dollar_cent(char (&inputString)[20]) {
	int j = 0, k = 0;
	int decimalPoint = FALSE;
	char dollor_arr[15];
	char cent_arr[5];

	for(int i = 0; i < strlen(inputString); i++) {
	        if(!isdigit(inputString[i]) && inputString[i] != '.') 
        		return false;	

		if(inputString[i] == '.')
			decimalPoint = TRUE;
		else if(decimalPoint == FALSE)       // the left of decimal point
			dollor_arr[j++] = inputString[i];
		else if(decimalPoint == TRUE)       // the right of decimal point
			cent_arr[k++] = inputString[i];
	}

        if(k > 2)          // The smallest unit of US dollar is cent (only two digit)
        	return false;
	else if(k == 1)         // Only one digit in cent_arr
		cent_arr[k++] = '0';     // add zero to the second digit 

	dollor_arr[j] = '\0';
	cent_arr[k] = '\0';
	dollor = atoi(dollor_arr);
	cent = atoi(cent_arr);
        strcpy(string, inputString);

	return true;
}

void Coins::convert() {
        int money = dollor * 100 + cent;   // change to cent

        q = money / 25;    // get quarters
        money %= 25;
        d = money / 10;     // get dimes
        money %= 10;
        n = money / 5;    // get nickels
        money %= 5;
        p = money / 1;     // get pennies
}

void Coins::display() const {
        cout << "$" << string << " = " << q << " quarters, " << d << " dimes, " << n << " nickels, " << p << " pennies" << endl;
}

