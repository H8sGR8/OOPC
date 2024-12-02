#include "matrix.h"

void testReferenceCounting(){
	cout << "Test reference counting\n" << endl;
	Matrix m1(2, 2);
	Matrix m2(m1);
	Matrix m3 = m2;
	Matrix m4(2, 2);
	if(m1.matrix != m2.matrix){
		cout << "Unsucesful" << endl;
		return;
	}
	if(m1.matrix != m3.matrix){
		cout << "Unsucesful" << endl;
		return;
	}
	if(m3.matrix != m2.matrix){
		cout << "Unsucesful" << endl;
		return;
	}
	if(m4.matrix == m2.matrix){
		cout << "Unsucesful" << endl;
		return;
	}
	m4 = m1;
	if(m4.matrix != m2.matrix){
		cout << "Unsucesful" << endl;
		return;
	}
	cout << "Succesful" << endl;
}

void testWrittingToCell(){
	cout << "\n\nTest writting to cell\n" << endl;
	Matrix m1(3, 3);
	Matrix m2(m1);
	if(m1.matrix != m2.matrix){
		cout << "Unsucesful" << endl;
		return;
	}
	m2(2, 2) = 10;
	if(m1.matrix == m2.matrix){
		cout << "Unsucesful" << endl;
		return;
	}
	cout << m2 << endl;
	cout << "Succesful" << endl;
}

void testMatrixFromFile(){
	cout << "\n\nTest uploading matrix from text file\n" << endl;
	Matrix m1("correctMatrix.txt");
	Matrix m2(m1);
	m2.copyFromFile("correctMatrix.txt");
	if(m1.matrix == m2.matrix){
		cout << "Unsucesful" << endl;
		return;
	}
	cout << m2 << endl;
	cout << "Succesful" << endl;
}

void testMultiEqual(){
	cout << "\n\nTest *= operator\n" << endl;
	Matrix m1("correctMatrix.txt");
	Matrix m2(m1);
	m2 *= 3;
	if(m1.matrix == m2.matrix){
		cout << "Unsucesful" << endl;
		return;
	}
	cout << m2 << endl;
	cout << "Succesful" << endl;
}

void testPlusEqual(){
	cout << "\n\nTest += operator\n" << endl;
	Matrix m1("correctMatrix.txt");
	Matrix m2(m1);
	m2 += m1;
	if(m1.matrix == m2.matrix){
		cout << "Unsucesful" << endl;
		return;
	}
	cout << m2 << endl;
	cout << "Succesful" << endl;
}

void testMinusEqual(){
	cout << "\n\nTest -= operator\n" << endl;
	Matrix m1("correctMatrix.txt");
	Matrix m2(m1);
	m2 -= m1;
	if(m1.matrix == m2.matrix){
		cout << "Unsucesful" << endl;
		return;
	}
	cout << m2 << endl;
	cout << "Succesful" << endl;
}

void testMulti(){
	cout << "\n\nTest * operator\n" << endl;
	Matrix m1("correctMatrix.txt");
	Matrix m2 = m1 * 4.5;
	if(m1.matrix == m2.matrix){
		cout << "Unsucesful" << endl;
		return;
	}
	cout << m2 << endl;
	cout << "Succesful" << endl;
}

void testPlus(){
	cout << "\n\nTest + operator\n" << endl;
	Matrix m1("correctMatrix.txt");
	Matrix m2 = m1 + m1;
	if(m1.matrix == m2.matrix){
		cout << "Unsucesful" << endl;
		return;
	}
	cout << m2 << endl;
	cout << "Succesful" << endl;
}

void testMinus(){
	cout << "\n\nTest - operator\n" << endl;
	Matrix m1("correctMatrix.txt");
	Matrix m2 = m1 - m1;
	if(m1.matrix == m2.matrix){
		cout << "Unsucesful" << endl;
		return;
	}
	cout << m2 << endl;
	cout << "Succesful" << endl;
}

void testIsEqual() {
	cout << "\n\nTest == operator\n" << endl;
	Matrix m1(2, 2);
	Matrix m2(m1);
	Matrix m3(2, 2);
	Matrix m4(3, 3);
	if((m1 == m2) != true){
		cout << "Unsucesful" << endl;
		return;
	}
	if((m1 == m3) != true){
		cout << "Unsucesful" << endl;
		return;
	}
	if((m1 == m4) == true){
		cout << "Unsucesful" << endl;
		return;
	}
	m3(1, 1) = 1;
	if((m1 == m3) == true){
		cout << "Unsucesful" << endl;
		return;
	}
	cout << "Sucesful" << endl;
}

void testIsNotEqual() {
	cout << "\n\nTest != operator\n" << endl;
	Matrix m1(2, 2);
	Matrix m2(m1);
	Matrix m3(2, 2);
	Matrix m4(3, 3);
	if((m1 != m2) == true){
		cout << "Unsucesful" << endl;
		return;
	}
	if((m1 != m3) == true){
		cout << "Unsucesful" << endl;
		return;
	}
	if((m1 != m4) != true){
		cout << "Unsucesful" << endl;
		return;
	}
	m3(1, 1) = 1;
	if((m1 != m3) != true){
		cout << "Unsucesful" << endl;
		return;
	}
	cout << "Sucesful" << endl;
}

void testWrongDimException(){
	cout << "\n\nTest wrong dimentions exception\n" << endl;
	try{
		Matrix m1(0, 0);
	}catch(wrongDimentionsException &e){
		cout << e.what() << endl;
	}
}

void testDiffDimException(){
	cout << "\n\nTest diffrend dimentions exception\n" << endl;
	try{
		Matrix m2(2, 2);
		Matrix m3(3, 3);
		m3 += m2;
	}catch(differndDimentionsException &e){
		cout << e.what() << endl;
	}
}

void testWrongMatrixException(){
	cout << "\n\nTest wrong matrix exception\n" << endl;
	try{
		Matrix m4("wrongMatrix.txt");
	}catch(wrongMatrixFromFileException &e){
		cout << e.what() << endl;
	}
}

void testRangeException(){
	cout << "\n\nTest range exception\n" << endl;
	try{
		Matrix m5(2, 2);
		cout << m5(3, 3);
	}catch(rangeException &e){
		cout << e.what() << endl;
	}
}

void testRefRangeException(){
	cout << "\n\nTest range exception for reference\n" << endl;
	try{
		Matrix m5(2, 2);
		m5(3, 3) = 10;
	}catch(rangeException &e){
		cout << e.what() << endl;
	}
}



int main() {
	testReferenceCounting();
	testWrittingToCell();
	testMatrixFromFile();
	testMultiEqual();
	testPlusEqual();
	testMinusEqual();
	testMulti();
	testPlus();
	testMinus();
	testIsEqual();
	testIsNotEqual();
	testWrongDimException();
	testDiffDimException();
	testWrongMatrixException();
	testRangeException();
	testRefRangeException();
	return 0;
}
