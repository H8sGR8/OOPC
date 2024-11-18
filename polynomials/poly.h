#pragma once

#include <iostream>
using namespace std;

#define INITIAL_SIZE 0;

class Coefficient{
	
	public:
		double power;
		double multiplier;
		Coefficient(double power = 0, double multiplier = 0);
		Coefficient& operator= (double);
		Coefficient& operator+= (double);
		Coefficient& operator-= (double);
};

class Poly{
	Coefficient createCoefficient(double, double multiplier = 0);
	Coefficient& add(double);
	int sort(int);
	
	public:
		void clear();
		int size;
		Coefficient* coefficients;
		Poly();
		Poly(double);
		~Poly();
		Poly& operator= (const Poly&);
		int bSearch(double, int, int);
		Coefficient& operator[] (double);
		double operator() (double) const;
};

ostream& operator<< (ostream&, const Poly&);
Poly operator+ (const Poly&, const Poly&);
Poly operator- (const Poly&, const Poly&);
Poly operator* (const Poly&, const Poly&);
Poly operator- (const Poly&);

