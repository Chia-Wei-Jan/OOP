class Coins {
public:
	Coins(char (&inputString)[20]);      // constructor
	~Coins();     // destructor
	bool get_dollar_cent(char (&inputString)[20]);    // get dollar and cent from input string
	void convert();         // convert to q, d, n, p
	void display() const;   // print the output (q, d, n, p)

private:
	int dollor, cent;
	int q, d, n, p;
	char string[20];
};
