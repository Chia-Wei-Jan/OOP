using namespace std;

class Time {
private:
	int day, hour, minute, second;


public:
	Time();      // default constructor
	Time(const int &);    // constructor with second
	Time(const int &, const int &, const int &, const int &);
	~Time();    // destructor

	void operator=(const int &);
	friend ostream &operator<<(ostream &, const Time &);
	friend istream &operator>>(istream &, Time &);
	Time operator+(const Time &);
	Time operator-(const Time &);
	bool operator<(const Time &) const;
	bool operator>(const Time &) const;
	bool operator<=(const Time &) const;
	bool operator>=(const Time &) const;
	bool operator == (const Time &) const;
	bool operator != (const Time &) const;
	Time operator++();
	const Time operator++(int);
	Time operator--();
	const Time operator--(int);
};
