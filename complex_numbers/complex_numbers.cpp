#define _USE_MATH_DEFINES

#include <cmath>
#include "complex_numbers.h"


ComplexNumber::ComplexNumber (double realPart, double imaginaryPart){
	this->realPart = realPart;
	this->imaginaryPart = imaginaryPart;
}

double ComplexNumber::getRealPart(){
	return realPart;
}

double ComplexNumber::getImaginaryPart(){
	return imaginaryPart;
}

void ComplexNumber::setRealPart(double realPart){
	this->realPart = realPart;
}

void ComplexNumber::setImaginaryPart(double imaginaryPart){
	this->imaginaryPart = imaginaryPart;
}

ostream& operator<< (ostream& os, const ComplexNumber& number){
	string oper = "+";
	double iP = number.imaginaryPart;
	if (number.realPart){
		os << number.realPart;
		if (number.imaginaryPart){
			if(number.imaginaryPart < 0){
				oper = "-";
				iP = iP * -1;
			}
			os << " " << oper << " ";
			if(iP != 1) os << iP;
			os << "i";
		}
	}
	else if (number.imaginaryPart){
		if(number.imaginaryPart != 1 && number.imaginaryPart != -1) os << number.imaginaryPart;
		if (number.imaginaryPart == -1) os << "-";
		os  <<"i";
	}
	else os << 0;
	return os;
}

ComplexNumber& ComplexNumber::operator+= (const ComplexNumber& other){
	this->realPart += other.realPart;
	this->imaginaryPart += other.imaginaryPart;
	return *this;
}

ComplexNumber& ComplexNumber::operator-= (const ComplexNumber& other){
	this->realPart -= other.realPart;
	this->imaginaryPart -= other.imaginaryPart;
	return *this;
}

ComplexNumber& ComplexNumber::operator*= (const ComplexNumber& other){
	double rP = this->realPart * other.realPart - this->imaginaryPart * other.imaginaryPart;
	double iP = this->realPart * other.imaginaryPart + this->imaginaryPart * other.realPart;
	this->realPart = rP;
	this->imaginaryPart = iP;
	return *this;
}

ComplexNumber& ComplexNumber::operator/= (const ComplexNumber& other){
	double divisor = pow(other.realPart, 2) + pow(other.imaginaryPart, 2);
	if (!divisor){
		cout << "Dividing by 0 detected" << endl;
		return *this;
	}
	double rP = (this->realPart * other.realPart + this->imaginaryPart * other.imaginaryPart)/divisor;
	double iP = (this->imaginaryPart * other.realPart - this->realPart * other.imaginaryPart)/divisor;
	this->realPart = rP;
	this->imaginaryPart = iP;
	return *this;
}

ComplexNumber operator+ (const ComplexNumber& num1, const ComplexNumber& num2){
	ComplexNumber result;
	result.realPart = num1.realPart + num2.realPart;
	result.imaginaryPart = num1.imaginaryPart + num2.imaginaryPart;
	return result;
}

ComplexNumber operator- (const ComplexNumber& num1, const ComplexNumber& num2){
	ComplexNumber result;
	result.realPart = num1.realPart - num2.realPart;
	result.imaginaryPart = num1.imaginaryPart - num2.imaginaryPart;
	return result;
}

ComplexNumber operator* (const ComplexNumber& num1, const ComplexNumber& num2){
	ComplexNumber result;
	result.realPart = num1.realPart * num2.realPart - num1.imaginaryPart * num2.imaginaryPart;
	result.imaginaryPart = num1.realPart * num2.imaginaryPart + num1.imaginaryPart * num2.realPart;
	return result;
}

ComplexNumber operator/ (const ComplexNumber& num1, const ComplexNumber& num2){
	ComplexNumber result;
	double divisor = pow(num2.realPart, 2) + pow(num2.imaginaryPart, 2);
	if (!divisor){
		cout << "Dividing by 0 detected" << endl;
		return NAN;
	}
	result.realPart = (num1.realPart * num2.realPart + num1.imaginaryPart * num2.imaginaryPart)/divisor;
	result.imaginaryPart = (num1.imaginaryPart * num2.realPart - num1.realPart * num2.imaginaryPart)/divisor;
	return result;
}

bool operator== (const ComplexNumber& num1, const ComplexNumber& num2){
	if(num1.realPart != num2.realPart || num1.imaginaryPart != num2.imaginaryPart) return false;
	return true;
}

bool operator!= (const ComplexNumber& num1, const ComplexNumber& num2){
	if(num1.realPart != num2.realPart || num1.imaginaryPart != num2.imaginaryPart) return true;
	return false;
}

double ComplexNumber::getMagnitude(){
	return sqrt(pow(this->realPart, 2) + pow(this->imaginaryPart, 2));
}

double ComplexNumber::getPhase(){
	return atan(this->imaginaryPart / this->realPart);
}

string ComplexNumber::getPhaseWithPi(){
	double phase = getPhase();
	string prefix = "pi/";
	if(phase < 0){
		prefix = "-pi/";
		phase *= -1;
	}
	string divisor = to_string(pow(phase / M_PI, -1));
	int currentCharNumber = divisor.length() - 1;
	while(divisor[currentCharNumber] == '0'){
		divisor[currentCharNumber] = '\0';
		currentCharNumber--;
	}
	if(currentCharNumber != (int)(divisor.length() - 1)){
		if(divisor[currentCharNumber] == '.') divisor[currentCharNumber] = '\0';
		else  divisor[currentCharNumber + 1] = '\0';
	}
	if (divisor == "-inf") return "pi";
	else if(divisor == "inf") return "0";
	return prefix + divisor;
}
