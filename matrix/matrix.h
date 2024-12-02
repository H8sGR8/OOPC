#pragma once

#include <exception>
#include <iostream>
using namespace std;

class wrongDimentionsException : public exception {
	public:
		char* what();
};

class differndDimentionsException : public exception {
	
	public:
		char* what();
};

class wrongMatrixFromFileException : public exception {
	
	public:
		char* what();
};

class rangeException : public exception {
	
	public:
		char* what();
};

struct refMatrix{
	int referencesNum;
	int rows;
	int columns;
	double** matrixTable;
};

class Matrix {
	
	void copyMatrix();
	
	public:
		class Dref;
		refMatrix* matrix;
		Matrix(int, int);
		Matrix(const Matrix&);
		Matrix(string);
		~Matrix();
		Matrix& operator= (const Matrix&);
		Matrix& operator+= (const Matrix&);
		Matrix& operator-= (const Matrix&);
		Matrix& operator*= (double);
		void copyFromFile (string);
		double operator() (int, int) const;
		Dref operator() (int, int);
};

ostream& operator<< (ostream&, const Matrix&);
Matrix operator+ (const Matrix&, const Matrix&);
Matrix operator- (const Matrix&, const Matrix&);
Matrix operator* (const Matrix&, double);
Matrix operator* (double, const Matrix&);
bool operator== (const Matrix&, const Matrix&);
bool operator!= (const Matrix&, const Matrix&);
bool isMatrixCorrect(const string*, int, int);

class Matrix::Dref {
    friend class Matrix;
    Matrix& m;
    int r;
    int c;
    Dref(Matrix& mm, unsigned int rr, unsigned int cc) : m(mm), r(rr), c(cc){};

  public:
    operator double() const
    {
        return m.matrix->matrixTable[r][c];
    }
    Matrix::Dref& operator=(double d)
    {
        if(m.matrix->referencesNum > 1) m.copyMatrix();
        m.matrix->matrixTable[r][c] = d;
        return *this;
    }
    Matrix::Dref& operator=(const Dref& ref)
    {
        return operator=((double)ref);
    }
};

