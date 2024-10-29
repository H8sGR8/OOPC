#include "complex_numbers.h"
#include <iostream>
using namespace std;
#include <sstream>

void testGettersAndSetters(){
	cout << "Test get and set functions for complex numbers\n" << endl;
	ComplexNumber c(0, 0);
	double rP = 4.5;
	double iP = 3;
	double gotRP;
	double gotIP;
	c.setRealPart(rP);
	c.setImaginaryPart(iP);
	gotRP = c.getRealPart();
	gotIP = c.getImaginaryPart();
	cout << "Expected (" << rP << ", " << iP << ") got (" << gotRP << ", " << gotIP << ")" << endl;
	if (rP == gotRP && iP == gotIP) cout << "Success" << endl;
	else cout << "Unsuccessful" << endl;
}

void compareCout(ComplexNumber& c, string expectedOutput){
	std::stringstream buffer;
	streambuf* prevCoutBuf = cout.rdbuf(buffer.rdbuf());
	cout << c;
	string output = buffer.str();
	cout.rdbuf(prevCoutBuf);
	cout << "expected (" << expectedOutput << ") got (" << output << ")" << endl;
	if (!output.compare(expectedOutput)) cout << "Success\n" << endl;
	else cout << "Unsuccessful\n" << endl;
}

void compareBool(bool test, bool expectedOutput){
	cout << "Expected (" << expectedOutput <<") got (" << test << ")" << endl;
	if(test != expectedOutput) cout << "Unsuccessful\n" << endl;
	else cout << "Success\n" << endl;
}

void compareDouble(ComplexNumber& c, double expectedOutput){
	cout << "Expected (" << expectedOutput << ") got (" << c.getMagnitude()<< ")" << endl;
	if (c.getMagnitude() != expectedOutput) cout << "Unsuccessful\n" << endl;
	else cout << "Success\n" << endl;
}

void compareString(ComplexNumber& c, string expectedOutput){
	cout << "Expected (" << expectedOutput << ") got (" << c.getPhaseWithPi() << ")" << endl;
	if (c.getPhaseWithPi() != expectedOutput) cout << "Unsuccessful\n" << endl;
	else cout << "Success\n" << endl;
}

void testCoutOperator(){
	cout << "\n\nTest cout operator for complex numbers\n" << endl;
	ComplexNumber c1(1, 1);
	ComplexNumber c2(1, 2);
	ComplexNumber c3(1, -1);
	ComplexNumber c4(1, -2);
	ComplexNumber c5(-1, 1);
	ComplexNumber c6(-1, 2);
	ComplexNumber c7(-1, -1);
	ComplexNumber c8(-1, -2);
	ComplexNumber c9(1, 0);
	ComplexNumber c10(-1, 0);
	ComplexNumber c11(0, 1);
	ComplexNumber c12(0, 2);
	ComplexNumber c13(0, -1);
	ComplexNumber c14(0, -2);
	string test1Expected = "1 + i";
	string test2Expected = "1 + 2i";
	string test3Expected = "1 - i";
	string test4Expected = "1 - 2i";
	string test5Expected = "-1 + i";
	string test6Expected = "-1 + 2i";
	string test7Expected = "-1 - i";
	string test8Expected = "-1 - 2i";
	string test9Expected = "1";
	string test10Expected = "-1";
	string test11Expected = "i";
	string test12Expected = "2i";
	string test13Expected = "-i";
	string test14Expected = "-2i";
	compareCout(c1, test1Expected);
	compareCout(c2, test2Expected);
	compareCout(c3, test3Expected);
	compareCout(c4, test4Expected);
	compareCout(c5, test5Expected);
	compareCout(c6, test6Expected);
	compareCout(c7, test7Expected);
	compareCout(c8, test8Expected);
	compareCout(c9, test9Expected);
	compareCout(c10, test10Expected);
	compareCout(c11, test11Expected);
	compareCout(c12, test12Expected);
	compareCout(c13, test13Expected);
	compareCout(c14, test14Expected);
}

void testPlusEqualOperator(){
	cout << "\n\nTest += operator for complex numbers\n" << endl;
	ComplexNumber c1(1, 1);
	ComplexNumber c2(2, 2);
	ComplexNumber c3(3, 3);
	string test1Expected = "2 + i";
	string test2_1And3_1Expected = "6 + 6i";
	string test2_2Expected = "5 + 5i";
	string test3_2Expected = "2 + 2i";
	c1 += 1;
	compareCout(c1, test1Expected);
	c1.setRealPart(1);
	c1 += (c2 += c3);
	compareCout(c1, test2_1And3_1Expected);
	compareCout(c2, test2_2Expected);
	c1.setRealPart(1);
	c1.setImaginaryPart(1);
	c2.setRealPart(2);
	c2.setImaginaryPart(2);
	(c1 += c2) += c3;
	compareCout(c1, test2_1And3_1Expected);
	compareCout(c2, test3_2Expected);
	
}

void testMinusEqualOperator(){
	cout << "\n\nTest -= operator for complex numbers\n" << endl;
	ComplexNumber c1(1, 1);
	ComplexNumber c2(2, 2);
	ComplexNumber c3(3, 3);
	string test1Expected = "i";
	string test2_1Expected = "2 + 2i";
	string test2_2Expected = "-1 -i";
	string test3_1Expected = "-4 - 4i";
	string test3_2Expected = "2 + 2i";
	c1 -= 1;
	compareCout(c1, test1Expected);
	c1.setRealPart(1);
	c1 -= (c2 -= c3);
	compareCout(c1, test2_1Expected);
	compareCout(c2, test2_2Expected);
	c1.setRealPart(1);
	c1.setImaginaryPart(1);
	c2.setRealPart(2);
	c2.setImaginaryPart(2);
	(c1 += c2) += c3;
	compareCout(c1, test3_1Expected);
	compareCout(c2, test3_2Expected);
}

void testMultiplyEqualOperator(){
	cout << "\n\nTest *= operator for complex numbers\n" << endl;
	ComplexNumber c1(1, 1);
	ComplexNumber c2(4, 2);
	string test1Expected = "3 + 3i";
	string test2Expected = "6 + 18i";
	c1 *= 3;
	compareCout(c1, test1Expected);
	c2 *= c1;
	compareCout(c2, test2Expected);
	
}

void testDivideEqualOperator(){
	cout << "\n\nTest /= operator for complex numbers\n" << endl;
	ComplexNumber c1(3, 3);
	ComplexNumber c2(4, 2);
	string test1Expected = "1 + i";
	string test2Expected = "1 - 3i";
	c1 /= 3;
	compareCout(c1, test1Expected);
	c2 /= c1;
	compareCout(c2, test2Expected);
	c1 /= 0;
	compareCout(c1, test1Expected);
}

void testPlusOperator(){
	cout << "\n\nTest + operator for complex numbers\n" << endl;
	ComplexNumber c1(1, 1);
	ComplexNumber c2(2, 2);
	string testExpected = "3 + 3i";
	ComplexNumber c3 = c1 + c2;
	compareCout(c3, testExpected);
}

void testMinusOperator(){
	cout << "\n\nTest - operator for complex numbers\n" << endl;
	ComplexNumber c1(1, 1);
	ComplexNumber c2(2, 2);
	string testExpected = "-1 - i";
	ComplexNumber c3 = c1 - c2;
	compareCout(c3, testExpected);
}

void testMultiplyOperator(){
	cout << "\n\nTest * operator for complex numbers\n" << endl;
	ComplexNumber c1(1, 1);
	ComplexNumber c2(2, 2);
	string testExpected = "4i";
	ComplexNumber c3 = c1 * c2;
	compareCout(c3, testExpected);
}

void testDivideOperator(){
	cout << "\n\nTest / operator for complex numbers\n" << endl;
	ComplexNumber c1(1, 1);
	ComplexNumber c2(2, 2);
	string test1Expected = "0.5";
	string test2Expected = "nan";
	ComplexNumber c3 = c1 / c2;
	compareCout(c3, test1Expected);
	ComplexNumber c4 = c1 / 0;
	compareCout(c4, test2Expected);
}

void testIsEqualOperator(){
	cout << "\n\nTest == operator for complex numbers\n" << endl;
	ComplexNumber c1(1, 1);
	ComplexNumber c2(2, 2);
	ComplexNumber c3(1, 2);
	ComplexNumber c4(2, 1);
	ComplexNumber c5(1, 1);
	compareBool((c1 == c2), false);
	compareBool((c1 == c3), false);
	compareBool((c1 == c4), false);
	compareBool((c1 == c5), true);
	compareBool((c1 == 3), false);
	compareBool((3 == c2), false);
}

void testIsDiffrendOperator(){
	cout << "\n\nTest != operator for complex numbers\n" << endl;
	ComplexNumber c1(1, 1);
	ComplexNumber c2(2, 2);
	ComplexNumber c3(1, 2);
	ComplexNumber c4(2, 1);
	ComplexNumber c5(1, 1);
	compareBool((c1 != c2), true);
	compareBool((c1 != c3), true);
	compareBool((c1 != c4), true);
	compareBool((c1 != c5), false);
	compareBool((c1 != 3), true);
	compareBool((3 != c2), true);
}

void testGetMagnitude(){
	cout << "\n\nTest get magnitude for complex numbers\n" << endl;
	ComplexNumber c1(3, 4);
	ComplexNumber c2(-5, 12);
	ComplexNumber c3(6, -8);
	ComplexNumber c4(-10, -24);
	double test1Expected = 5;
	double test2Expected = 13;
	double test3Expected = 10;
	double test4Expected = 26;
	compareDouble(c1, test1Expected);
	compareDouble(c2, test2Expected);
	compareDouble(c3, test3Expected);
	compareDouble(c4, test4Expected);
}

void testGetPhase(){
	cout << "\n\nTest get phase for complex numbers" << endl;
	ComplexNumber c1(1, 0);
	ComplexNumber c2(1, 1);
	ComplexNumber c3(0, 1);
	ComplexNumber c4(-1, 1);
	ComplexNumber c5(-1, 0);
	ComplexNumber c6(-1, -1);
	ComplexNumber c7(0, -1);
	ComplexNumber c8(1, -1);
	string test1Expected = "0";
	string test2Expected = "pi/4";
	string test3Expected = "pi/2";
	string test4Expected = "pi/1.333333";
	string test5Expected = "pi";
	string test6Expected = "-pi/1.333333";
	string test7Expected = "-pi/2";
	string test8Expected = "-pi/4";
	compareString(c1, test1Expected);
	compareString(c2, test2Expected);
	compareString(c3, test3Expected);
	compareString(c4, test4Expected);
	compareString(c5, test5Expected);
	compareString(c6, test6Expected);
	compareString(c7, test7Expected);
	compareString(c8, test8Expected);
	
}


int main(){
	testGettersAndSetters();
	testCoutOperator();
	testPlusEqualOperator();
	testMinusEqualOperator();
	testMultiplyEqualOperator();
	testDivideEqualOperator();
	testPlusOperator();
	testMinusOperator();
	testMultiplyOperator();
	testDivideOperator();
	testIsEqualOperator();
	testIsDiffrendOperator();
	testGetMagnitude();
	testGetPhase();
	return 0;
}
