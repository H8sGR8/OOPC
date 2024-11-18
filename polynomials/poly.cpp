#include "poly.h"
#include <math.h>


Coefficient::Coefficient(double power, double multiplier){
	this->power = power;
	this->multiplier = multiplier;
}

Coefficient& Coefficient::operator= (double value){
	this->multiplier = value;
	return *this;
}

Coefficient& Coefficient::operator+= (double value){
	this->multiplier += value;
	return *this;
}

Coefficient& Coefficient::operator-= (double value){
	this->multiplier -= value;
	return *this;
}

Poly::Poly(){
	this->size = INITIAL_SIZE;
	this->coefficients = new Coefficient[size];
}

Poly::Poly(double multiplier){
	Coefficient c(0, multiplier);
	this->size = 1 + INITIAL_SIZE;
	this->coefficients = new Coefficient[size];
	this->coefficients[0] = c;
}

Poly::~Poly(){
	delete[] this->coefficients;
}

Poly& Poly::operator = (const Poly& other){
	this->size = other.size;
	delete[] this->coefficients;
	this->coefficients = new Coefficient[size];
	copy(other.coefficients, other.coefficients + other.size, this->coefficients);
	return *this;
}

int Poly::bSearch(double power, int start, int end){
	int index = (int)((start + end)/2);
	if(((end - start) == 0 && coefficients[index].power != power) || (end - start) < 0) return -1;
	if(coefficients[index].power == power) return index;
	else if(coefficients[index].power < power) return this->bSearch(power, start, index - 1);
	else if(coefficients[index].power > power) return this->bSearch(power, index + 1, end);
	return 0;
}

int Poly::sort(int index){
	double power;
	double multiplier;
	if (this->size < 2) return index;
	while(this->coefficients[index].power > this->coefficients[index - 1].power){
		power = this->coefficients[index].power;
		multiplier = this->coefficients[index].multiplier;
		this->coefficients[index].power = this->coefficients[index - 1].power;
		this->coefficients[index].multiplier = this->coefficients[index - 1].multiplier;
		this->coefficients[index - 1].power = power;
		this->coefficients[index - 1].multiplier = multiplier;
		index--;
		if(index == 0) break;
	}
	return index;
}

Coefficient Poly::createCoefficient(double power, double multiplier){
	Coefficient c(power, multiplier);
	return c;
}

Coefficient& Poly::add(double power){
	Coefficient c(power);
	Coefficient* newCoefficients = new Coefficient[size + 1];
	copy(this->coefficients, this->coefficients + this->size, newCoefficients);
	delete[] this->coefficients;
	this->coefficients = newCoefficients;
	this->coefficients[size] = c;
	this->size++;
	return this->coefficients[this->sort(size - 1)];
	
}

Coefficient& Poly::operator[] (double power){
	this->clear();
	int index = this->bSearch(power, 0, this->size - 1);
	if(index < 0) return this->add(power);
	return this->coefficients[index];
}

double Poly::operator() (double value) const{
	double result = 0;
	for(int i = 0; i < this->size; i++){
		result += (pow(value, this->coefficients[i].power) * this->coefficients[i].multiplier);
	}
	return result;
}

void Poly::clear(){
	int deletedAmount = 0;
	int index;
	double power;
	double multiplier;
	for(int i = this->size - 1; i >= 0; i--){
		if(!this->coefficients[i].multiplier){
			deletedAmount++;
			index = i;
			while(index < this->size - 1){
				power = this->coefficients[index].power;
				multiplier = this->coefficients[index].multiplier;
				this->coefficients[index].power = this->coefficients[index + 1].power;
				this->coefficients[index].multiplier = this->coefficients[index + 1].multiplier;
				this->coefficients[index + 1].power = power;
				this->coefficients[index + 1].multiplier = multiplier;
				index++;
			}
		} 
	}
	Coefficient* newCoefficients = new Coefficient[this->size - deletedAmount];
	copy(this->coefficients, this->coefficients + (this->size - deletedAmount), newCoefficients);
	delete[] this->coefficients;
	this->coefficients = newCoefficients;
	this->size -= deletedAmount;
}


ostream& operator<< (ostream& out, const Poly& p){
	int printed = 0;
	for (int i = 0; i < p.size; i++){
		if(p.coefficients[i].multiplier != 0){ 
			out << ((printed != 0)?((p.coefficients[i].multiplier < 0) ? " - ":" + ") : "");
			if(p.coefficients[i].multiplier != 1) out << ((!printed) ? p.coefficients[i].multiplier : abs(p.coefficients[i].multiplier));
			if(p.coefficients[i].power != 0){
				out << "x";
				if(p.coefficients[i].power != 1) out << "^" << p.coefficients[i].power;
			}
			printed++;
		}
	}
	if(printed == 0) out << 0;
	return out;
}

Poly operator+ (const Poly& poly1, const Poly& poly2){
	Poly poly;
	for(int i = 0; i < poly1.size; i++) poly[poly1.coefficients[i].power] += poly1.coefficients[i].multiplier;
	for(int i = 0; i < poly2.size; i++) poly[poly2.coefficients[i].power] += poly2.coefficients[i].multiplier;
	return poly;
}

Poly operator- (const Poly& poly1, const Poly& poly2){
	Poly poly;
	for(int i = 0; i < poly1.size; i++) poly[poly1.coefficients[i].power] += poly1.coefficients[i].multiplier;
	for(int i = 0; i < poly2.size; i++) poly[poly2.coefficients[i].power] -= poly2.coefficients[i].multiplier;
	return poly;
}

Poly operator* (const Poly& poly1, const Poly& poly2){
	Poly poly;
	for(int i = 0; i < poly1.size; i++) for(int j = 0; j < poly2.size; j++){
		poly[poly1.coefficients[i].power + poly2.coefficients[j].power] += poly1.coefficients[i].multiplier * poly2.coefficients[j].multiplier;
	}
	return poly;
}

Poly operator- (const Poly& poly){
	Poly negated;
	for (int i = 0; i < poly.size; i++) negated[poly.coefficients[i].power] = poly.coefficients[i].multiplier * -1;
	return negated;
}

