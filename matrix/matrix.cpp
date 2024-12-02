#include "matrix.h"
#include <fstream>

char* wrongDimentionsException::what(){
	return (char*)"Number of rows and number of columnst should be a positive natural number";
}

char* differndDimentionsException::what(){
	return (char*)"Matrixes have diffrend dimentions";
}

char* wrongMatrixFromFileException::what(){
	return (char*)"Matrix in file is wrong";
}

char* rangeException::what(){
	return (char*)"Indexes out of range";
}

Matrix::Matrix(int rows, int columns){
	if(rows <= 0 || columns <= 0) throw wrongDimentionsException();
	matrix = new refMatrix;
	matrix->referencesNum = 1;
	matrix->rows = rows;
	matrix->columns = columns;
	matrix->matrixTable = new double*[rows];
	for(int i = 0; i < rows; i++){
		matrix->matrixTable[i] = new double[columns];
		for(int j = 0; j < columns; j++) matrix->matrixTable[i][j] = 0;
	}
}

Matrix::Matrix(const Matrix& other){
	matrix = other.matrix;
	matrix->referencesNum++;
}

Matrix::Matrix(string path){
	ifstream file(path);
	string* lines;
	string line;
	char* end;
	matrix = new refMatrix;
	matrix->referencesNum = 1;
	matrix->rows = 0;
	matrix->columns = 1;
	while(getline(file, line)){
		matrix->rows++;
		string* newLines = new string[matrix->rows];
		if(matrix->rows - 1 != 0){
			copy(lines, lines + matrix->rows - 1, newLines);
			delete[] lines;
		}
		lines = newLines;
		lines[matrix->rows - 1] = line;
	}
	if(matrix->rows <= 0 || matrix->columns <= 0) throw wrongDimentionsException();
	for(uint i = 0; i < lines[0].length(); i++) if(lines[0][i] == ' ') matrix->columns++;
	if (!isMatrixCorrect(lines, matrix->rows, matrix->columns)){
		delete matrix;
		delete[] lines;
		throw wrongMatrixFromFileException();
	}
	matrix->matrixTable = new double*[matrix->rows];
	for(int i = 0; i < matrix->rows; i++){
		matrix->matrixTable[i] = new double[matrix->columns];
		end = (char*)lines[i].c_str();
		for(int j = 0; j < matrix->columns; j++) matrix->matrixTable[i][j] = strtod(end, &end);
	}
	delete[] lines;
}

Matrix::~Matrix(){
	if(--matrix->referencesNum != 0) return;
	for(int row = matrix->rows - 1; row >= 0; row--) delete[] matrix->matrixTable[row];
	delete[] matrix->matrixTable;
	delete matrix;
}

void Matrix::copyFromFile(string path){
	if(--matrix->referencesNum == 0){
		for(int row = matrix->rows - 1; row >= 0; row--) delete[] matrix->matrixTable[row];
	delete[] matrix->matrixTable;
	delete matrix;
	}
	ifstream file(path);
	string* lines;
	string line;
	char* end;
	matrix = new refMatrix;
	matrix->referencesNum = 1;
	matrix->rows = 0;
	matrix->columns = 1;
	while(getline(file, line)){
		matrix->rows++;
		string* newLines = new string[matrix->rows];
		if(matrix->rows - 1 != 0){
			copy(lines, lines + matrix->rows - 1, newLines);
			delete[] lines;
		}
		lines = newLines;
		lines[matrix->rows - 1] = line;
	}
	if(matrix->rows <= 0 || matrix->columns <= 0) throw wrongDimentionsException();
	for(unsigned int i = 0; i < lines[0].length(); i++) if(lines[0][i] == ' ') matrix->columns++;
	if (!isMatrixCorrect(lines, matrix->rows, matrix->columns)){
		delete matrix;
		delete[] lines;
		throw wrongMatrixFromFileException();
	}
	matrix->matrixTable = new double*[matrix->rows];
	for(int i = 0; i < matrix->rows; i++){
		matrix->matrixTable[i] = new double[matrix->columns];
		end = (char*)lines[i].c_str();
		for(int j = 0; j < matrix->columns; j++) matrix->matrixTable[i][j] = strtod(end, &end);
	}
	delete[] lines;
}

Matrix& Matrix::operator= (const Matrix& other){
	if(--matrix->referencesNum == 0){
		for(int row = matrix->rows - 1; row >= 0; row--) delete[] matrix->matrixTable[row];
	delete[] matrix->matrixTable;
	delete matrix;
	}
	matrix = other.matrix;
	matrix->referencesNum++;
	return *this;
}

void Matrix::copyMatrix(){
	matrix->referencesNum--;
	refMatrix* newMatrix = new refMatrix;
	newMatrix->referencesNum = 1;
	newMatrix->rows = matrix->rows;
	newMatrix->columns = matrix->columns;
	newMatrix->matrixTable = new double*[matrix->rows];
	for(int i = 0; i < matrix->rows; i++){
		newMatrix->matrixTable[i] = new double[matrix->columns];
		for(int j = 0; j < matrix->columns; j++) newMatrix->matrixTable[i][j] = matrix->matrixTable[i][j];
	}
	matrix = newMatrix;
}

Matrix& Matrix::operator+= (const Matrix& other){
	if(matrix->rows != other.matrix->rows || matrix->columns != other.matrix->columns) throw differndDimentionsException();
	if(matrix->referencesNum > 1) copyMatrix();
	for(int i = 0; i < matrix->rows; i++){
		for(int j = 0; j < matrix->columns; j++) matrix->matrixTable[i][j] += other.matrix->matrixTable[i][j];
	}
	return *this;
}

Matrix& Matrix::operator-= (const Matrix& other){
	if(matrix->rows != other.matrix->rows || matrix->columns != other.matrix->columns) throw differndDimentionsException();
	if(matrix->referencesNum > 1) copyMatrix();
	for(int i = 0; i < matrix->rows; i++){
		for(int j = 0; j < matrix->columns; j++) matrix->matrixTable[i][j] -= other.matrix->matrixTable[i][j];
	}
	return *this;
}

Matrix& Matrix::operator*= (double scalar){
	if(matrix->referencesNum > 1) copyMatrix();
	for(int i = 0; i < matrix->rows; i++){
		for(int j = 0; j < matrix->columns; j++) matrix->matrixTable[i][j] *= scalar;
	}
	return *this;
}

double Matrix::operator() (int posR, int posC) const{
	if(posR > matrix->rows || posC > matrix->columns) throw rangeException();
	return matrix->matrixTable[posR - 1][posC - 1];
}

Matrix::Dref Matrix::operator() (int posR, int posC){
	if(posR > matrix->rows || posC > matrix->columns) throw rangeException();
	return Dref(*this, posR - 1, posC - 1);
}

ostream& operator<< (ostream& out, const Matrix& m){
	for(int i = 1; i <= m.matrix->rows; i++){
		for(int j = 1; j <= m.matrix->columns; j++){
			if(j != 1) out << ", ";
			out << m(i, j);
		}
		out << "\n";
	}
	return out;
}

Matrix operator+ (const Matrix& m1, const Matrix& m2){
	if(m1.matrix->rows != m2.matrix->rows || m1.matrix->columns != m2.matrix->columns) throw differndDimentionsException();
	Matrix result(m1.matrix->rows, m1.matrix->columns);
	for(int i = 1; i <= result.matrix->rows; i++){
		for(int j = 1; j <= result.matrix->columns; j++){
			result(i, j) = m1(i, j) + m2(i , j);
		}
	}
	return result;
}

Matrix operator- (const Matrix& m1, const Matrix& m2){
	if(m1.matrix->rows != m2.matrix->rows || m1.matrix->columns != m2.matrix->columns) throw differndDimentionsException();
	Matrix result(m1.matrix->rows, m1.matrix->columns);
	for(int i = 1; i <= result.matrix->rows; i++){
		for(int j = 1; j <= result.matrix->columns; j++){
			result(i, j) = m1(i, j) - m2(i , j);
		}
	}
	return result;
}

Matrix operator* (const Matrix& m, double scalar){
	Matrix result(m.matrix->rows, m.matrix->columns);
	for(int i = 1; i <= result.matrix->rows; i++){
		for(int j = 1; j <= result.matrix->columns; j++){
			result(i, j) = m(i, j) * scalar;
		}
	}
	return result;
}

Matrix operator* (double scalar, const Matrix& m){
	Matrix result(m.matrix->rows, m.matrix->columns);
	for(int i = 1; i <= result.matrix->rows; i++){
		for(int j = 1; j <= result.matrix->columns; j++){
			result(i, j) = m(i, j) * scalar;
		}
	}
	return result;
}

bool operator== (const Matrix& m1, const Matrix& m2){
	if(&m1.matrix == &m2.matrix) return true;
	if (m1.matrix->rows != m2.matrix->rows || m1.matrix->columns != m2.matrix->columns) return false;
	for(int i = 1; i <= m1.matrix->rows;i++){
		for(int j = 1; j <= m1.matrix->columns; j++) if(m1(i, j) != m2(i, j)) return false;
	}
	return true;
}

bool operator!= (const Matrix& m1, const Matrix& m2){
	return !(m1 == m2);
}

bool isMatrixCorrect (const string* lines, int rows, int columns){
	int col;
	for(int i = 0; i < rows; i++){
		col = 1;
		if(lines[i].length() == 0) return false;
		for(unsigned int j = 0; j < lines[i].length(); j++){
			if(lines[i][j] == ' ') col++;
		}
		if(col != columns) return false;
	}
	return true;
}

