#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
using namespace std;

int main() {
    int count = 0;    // The count of scores
    int sum = 0;
    int grade = 0;
    float average = 0;
    char string[100];

    cout << "Please input your score:" << endl;
    while(cin >> string) {
        int len = strlen(string);  // Get the length of string
        
	// Check the illegal input
      	for(int i = 0; i < len; i++) {
	    if(i == 0 && string[i] == '-')
		continue;
            if(string[i] < '0' || string[i] > '9') {
                cout << "Illegal input, ending the program..." << endl;
                return 0;
            }
        }

        grade = atoi(string);    // Convert string to integer

        if(grade == -1 && count != 0)     // Compute the average
            break;

        // Check the boundary (0-100)
	if(grade < 0 || grade > 100) {
            cout << "Illegal input, ending the program..." << endl;
            return 0;
	}
        sum += grade;
        count++;

        cout << "Please input your score:" << endl;
    }

    // Compute the average
    average = (float) sum / count;
    cout << "Your average score is: " << setprecision(2) << fixed << average << endl;

    return 0;
}
