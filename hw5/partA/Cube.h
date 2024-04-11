class Cube {
private:
	double x, y, z;

public:
	Cube();
	Cube(double, double, double);
	~Cube();
	friend double operator / (const Cube &, const Cube &);
	bool operator == (const Cube &) const;
	bool operator != (const Cube &) const;
	void display() const;
};
