#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <sys/time.h>
using namespace std;

// Double every second digit from right to left
// If results in a two-digit number, add the two digits to get a single digit number
int getDigit(int number) {
        number *= 2;

        if(number >= 10)     // two-digit number
                number = 1 + number - 10;
        return number;
}

// Add all single-digit numbers by "getDigit" function
int sumOfDoubleEvenPlace(const char (&cardNumber)[100]) {
        int len = strlen(cardNumber);   // length of card number
        int digit = 0;
        int number = 0;
        int sum = 0;
        int i = 0;

        for(int i = len-2; i >= 0; i -= 2) {
                digit = cardNumber[i] - '0';
                number = getDigit(digit);
                sum += number;
        }
        return sum;
}

// Add all digits in the odd places from right to left in the card number
int sumOfOddPlace(const char (&cardNumber)[100]) {
        int len = strlen(cardNumber);
        int digit = 0;
        int sum = 0;
        int i = 0;

        for(int i = len-1; i >= 0; i -= 2) {
                digit = cardNumber[i] - '0';
                sum += digit;
        }
        return sum;
}

// Return true if substr is the prefix for cardNumber
bool startsWith(const char (&cardNumber)[100], const char (&subStr)[3]) {
        if(subStr[0] == '4' && cardNumber[0] == subStr[0])
                cout << "Visa card";
        else if(subStr[0] == '5' && cardNumber[0] == subStr[0])
                cout << "MasterCard card";
        else if(subStr[0] == '6' && cardNumber[0] == subStr[0])
                cout << "Discover card";
        else if(subStr[0] == '3' && subStr[1] == '7' && cardNumber[0] == subStr[0] && cardNumber[1] == subStr[1])
                cout << "American Express card";
        else
                return false;

        return true;
}

// Return true if the card number is valid
bool isvalid(const char (&cardNumber)[100]) {
        int sum_double, sum_odd, sum = 0;

        sum_double = sumOfDoubleEvenPlace(cardNumber);
        sum_odd = sumOfOddPlace(cardNumber);
        sum = sum_double + sum_odd;

        if(sum % 10 == 0)    return true;      // divisible by 10
        else    return false;
}

// Generate the valid cardNumber
void generate_cardNumber(const char (&subStr)[3]) {
        char cardNumber[100];

        // End until generate a valid card number
        while(true) {
                int i = 1;         // start to generate the number from second digit
                if(subStr[0] == '4')
                        cardNumber[0] = '4';
                else if(subStr[0] == '5')
                        cardNumber[0] = '5';
                else if(subStr[0] == '6')
                        cardNumber[0] = '6';
                else if(subStr[0] == '3' && subStr[1] == '7') {
                        cardNumber[0] = '3';
                        cardNumber[1] = '7';
                        i = 2;     // start to generate the number from third digit
                }

                for(; i < 16; i++)      // generate other digits
                        cardNumber[i] = '0' + rand() % 10;

                if(isvalid(cardNumber) && startsWith(cardNumber, subStr)) {
                        cout << ": ";
                        for(int i = 0; i < 16; i++)    cout << cardNumber[i];
                        cout << "; ";
                        break;
                }
        }
}

int main(){
        fstream file;
        file.open("input.txt", ios::in);
        char input[100];
        char subStr[3];
        struct timeval start;
        struct timeval end;
        unsigned long diff;

        while(file.getline(input, sizeof(input))) {       // read file line by line
                input[strcspn(input, "\r\n")] = '\0';        // remove newline
                // input is brand
                if(strcmp(input, "004") == 0 || strcmp(input, "005") == 0 || strcmp(input, "0037") == 0 || strcmp(input, "006") == 0) {
                        // copy prefix of brand to subStr
                        subStr[0] = input[2];
                        subStr[1] = input[3];

                        cout << "Generate a valid ";
                        gettimeofday(&start, NULL);     // timer start
                        generate_cardNumber(subStr);    // generate the card number
                        gettimeofday(&end, NULL);      // timer end
                        diff = end.tv_usec - start.tv_usec;
                        cout << "Time: " << diff << " microseconds" << endl;
                }
                // input is card number
                else if(strlen(input) >= 13 && strlen(input) <= 16) {
                        cout << input << ": ";
                        if(isvalid(input))    cout << "a valid ";
                        else    cout << "an invalid ";

                        // copy prefix of card number to subStr
                        for(int i = 0; i < 2; i++)     subStr[i] = input[i];
                        startsWith(input, subStr);
                        cout << endl;
                }
                // Error input
                else {
                        cout << "Error input: " << input << endl;
                }
        }
        file.close();
}
