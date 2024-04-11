#include <iostream>
#include <cstring>
#include "Time.h"
using namespace std;

// default constructor
Time::Time() {
	//cout << "Object is constructed" << endl;
	day = 0;
	hour = 0;
	minute = 0;
	second = 0;
}

// constructor with second
Time::Time(const int &s) {
	//cout << "Object is constructed" << endl;
	if(s < 0) {
		day = 0;
		hour = 0;
		minute = 0;
		second = 0;
	}
	else {
		second = s;    // assign to private
		
		minute = second / 60;
		second %= 60;
		hour = minute / 60;
		minute %= 60;
		day = hour / 24;
		hour %= 24;
	}	
}

// constructor with day, hour, minute and second
Time::Time(const int &d, const int &h, const int &m, const int &s) {
	//cout << "Object is constructed" << endl;
	if(d < 0 || h < 0 || m < 0 || s < 0) {
		second = 0;
		minute = 0;
		hour = 0;
		day = 0;
	}
	else {
		second = s;
		minute = m;
		hour = h;
		day = d;
		
		minute += (second / 60);
		second %= 60;
		hour += (minute / 60);
		minute %= 60;
		day += (hour / 24);
		hour %= 24;
	}
}

Time::~Time() {
        //cout << "Object is destructed" << endl;
}

void Time::operator=(const int &s) {
        if(s > 0) {
                second = s;    // assign to private
                minute = second / 60;
                second %= 60;
                hour = minute / 60;
                minute %= 60;
                day = hour / 24;
                hour %= 24;
	}
}

istream &operator>>(istream &stream, Time &t) { 
	char input[100];
	char num[10];
	int j = 0;     // index of value
	int turn = 0;    // turn "0" is hour, turn "1" is minute

	stream >> input;

	int i = 0;   // index of input
	for(i = 0; i < strlen(input); i++) {
		// error checking
		if(!isdigit(input[i]) && input[i] != '~' && input[i] != ':') {
			cout << "Invalid time, set time to zero." << endl;
			t.day = t.hour = t.minute = t.second = 0;
			break;
		}

		if(input[i] == '~') {
			t.day = atoi(num);    // get the day
			j = 0;
			memset(num, '\0', sizeof(num));    // reset the array
			continue;
		}
		else if(input[i] == ':') {
			if(turn == 0)
				t.hour = atoi(num);   // get the hour
			else if(turn == 1) 
				t.minute = atoi(num);   // get the minute
			
			// reset index and array
			j = 0;
			memset(num, '\0', sizeof(num));   // reset the array
			turn++;
		}
		else
			num[j++] = input[i];
	}

	if(i == strlen(input))
		t.second = atoi(num);     // get the second

	if(t.day < 0 || t.hour < 0 || t.minute < 0 || t.second < 0) {
		cout << "Negative time, set time to zero." << endl;
		t.day = t.hour = t.minute = t.second = 0;
	}
    
	t.minute += (t.second / 60);
	t.second %= 60;
	t.hour += (t.minute / 60);
	t.minute %= 60;
	t.day += (t.hour / 24);
	t.hour %= 24;
	
	return stream; 
} 

ostream &operator<<(ostream &stream, const Time &t) { 
	stream << t.day << "~";
	if(t.hour < 10)    cout << "0";
	cout << t.hour << ":"; 
	if(t.minute < 10)	cout << "0";
	cout << t.minute << ":";
       	if(t.second < 10)	cout << "0";
       	cout << t.second;

	return stream; 
} 


Time Time::operator+(const Time &right) {
	Time t(day + right.day, hour + right.hour, minute + right.minute, second + right.second);
	
	t.minute += (t.second / 60);
	t.second %= 60;
	t.hour += (t.minute / 60);
	t.minute %= 60;
	t.day += (t.hour / 24);
	t.hour %= 24;

        if(t.day < 0 || t.hour < 0 || t.minute < 0 || t.second < 0) {
		t.day = t.hour = t.minute = t.second = 0;	
	}

	return t;
}

Time Time::operator-(const Time &right) {
	int d = day - right.day;
	int h = hour - right.hour;
	int m = minute - right.minute;
	int s = second - right.second;

	if(s < 0) {
		s += 60;
		m--;
	}
	if(m < 0) {
		m += 60;
		h--;
	}
	if(h < 0) {
		h += 24;
		d--;
	}
	
	Time t(d, h, m, s);
        
	return t;
}

bool Time::operator<(const Time &right) const {
	if(day < right.day)
		return true;
	else if(day == right.day && hour < right.hour)
		return true;
	else if(day == right.day && hour == right.hour && minute < right.minute)
		return true;
	else if(day == right.day && hour == right.hour && minute == right.minute && second < right.second)
		return true;
	else
		return false;
}

bool Time::operator>(const Time &right) const {
	if(day > right.day)
		return true;
	else if(day == right.day && hour > right.hour)
		return true;
	else if(day == right.day && hour == right.hour && minute > right.minute)
		return true;
	else if(day == right.day && hour == right.hour && minute == right.minute && second > right.second)
		return true;
	else
		return false;
}

bool Time::operator<=(const Time &right) const {
	if(day < right.day)
		return true;
	else if(day == right.day && hour < right.hour)
		return true;
	else if(day == right.day && hour == right.hour && minute < right.minute)
		return true;
	else if(day == right.day && hour == right.hour && minute == right.minute && second <= right.second)
		return true;
	else
		return false;
}

bool Time::operator>=(const Time &right) const {
	if(day > right.day)
		return true;
	else if(day == right.day && hour > right.hour)
		return true;
	else if(day == right.day && hour == right.hour && minute > right.minute)
		return true;
	else if(day == right.day && hour == right.hour && minute == right.minute && second >= right.second)
		return true;
	else
		return false;
}

bool Time::operator==(const Time &right) const {
	return	(day == right.day && hour == right.hour && minute == right.minute && second == right.second);
}

bool Time::operator!=(const Time &right) const {
	return	!(*this == right);
}

Time Time::operator++() {
	second++;
	if(second >= 60) {
		minute++;
		second -= 60;
	}
	if(minute >= 60) {
		hour++;
		minute -= 60;
	}
	if(hour >= 24) {
		day++;
		hour -= 24;
	}
	
	return *this;
}

const Time Time::operator++(int) {  // slient pass 0
	Time oldValue = *this;
	++second;

        if(second >= 60) {
		minute++;
	        second -= 60;
	}
        if(minute >= 60) {
	        hour++;
	        minute -= 60;
	}
        if(hour >= 24) {
	        day++;
	        hour -= 24;
	}	

	return oldValue;
}

Time Time::operator--() {
	second--;

	if(second < 0) {
		minute--;
		second += 60;
	}
	if(minute < 0) {
		hour--;
		minute += 60;
	}
	if(hour < 0) {
		day--;
		day += 24;
	}

	if(day < 0 || hour < 0 || minute < 0 || second < 0)
		day = hour = minute = second = 0;

	return *this;
}

const Time Time::operator--(int) {  // slient pass 0
	Time oldValue = *this;
	--second;

        if(second < 0) {
                minute--;
                second += 60;
	}
	if(minute < 0) {
                hour--;
                minute += 60;
        }
        if(hour < 0) {
                day--;
                day += 24;
        }

	if(day < 0 || hour < 0 || minute < 0 || second < 0)
	        day = hour = minute = second = 0;

	return oldValue;
}
	
