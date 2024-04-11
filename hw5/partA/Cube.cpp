#include <iostream>
#include "Cube.h"
using namespace std;


// default constructor
Cube::Cube() {
	cout << "Object is constructed" << endl;
	this->x = 1;
	this->y = 1;
	this->z = 1;
}

// constructor with 3 parameters
Cube::Cube(double x, double y, double z) {
	cout << "Object is constructed" << endl;
	this->x = x;
	this->y = y;
	this->z = z;
}

// destructor
Cube::~Cube() {
	cout << "Object is destructed" << endl;
}

// divide the sum
double operator / (const Cube &first, const Cube &second) {
	return (first.x + first.y + first.z) / (second.x + second.y + second.z);
}

//equal volume
bool Cube::operator == (const Cube & right) const {
	return x*y*z == right.x * right.y * right.z;
}

// not equal volume
bool Cube::operator != (const Cube & right) const {
	return !(*this == right);
}

// show the object
void Cube::display() const {
	cout << x << ", " << y << ", " << z << endl;
}


