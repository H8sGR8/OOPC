#pragma once

#include <iostream>
using namespace std;

class ComplexNumber {
	
	private:
		double realPart;
		double imaginaryPart;
	
	public:
		ComplexNumber (double realPart = 0, double imaginaryPart = 0);
		
		double getRealPart();
		
		double getImaginaryPart();
		
		void setRealPart(double);
		
		void setImaginaryPart(double);
		
		friend ostream& operator<< (ostream&, const ComplexNumber&);
		
		ComplexNumber& operator+= (const ComplexNumber&);
		
		ComplexNumber& operator-= (const ComplexNumber&);
		
		ComplexNumber& operator*= (const ComplexNumber&);
		
		ComplexNumber& operator/= (const ComplexNumber&);
		
		friend ComplexNumber operator+ (const ComplexNumber&, const ComplexNumber&);
		
		friend ComplexNumber operator- (const ComplexNumber&, const ComplexNumber&);
		
		friend ComplexNumber operator* (const ComplexNumber&, const ComplexNumber&);
		
		friend ComplexNumber operator/ (const ComplexNumber&, const ComplexNumber&);	
		
		friend bool operator== (const ComplexNumber&, const ComplexNumber&);
		
		friend bool operator!= (const ComplexNumber&, const ComplexNumber&);
		
		double getMagnitude();
		
		double getPhase();
		
		string getPhaseWithPi();
};
