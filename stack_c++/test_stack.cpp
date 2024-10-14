#include "stack.h"
#include <iostream>
using namespace std;

void testPush(Stack& s)
{
	cout << "test pushing\n";
	int expectedList[10];
	for (int i = 0; i < 10; i++) {
		s.push(i);
		expectedList[i] = i;
	}
	for (int j = 0; j <= s.top; j++) {
		if (s.elements[j] != expectedList[j] || s.top != 9) {
			cout << "Unsuccessful\n";
			return;
		}
	}
	cout << "Success\n";
}

void testPop(Stack& s)
{
	cout << "\n\ntest popping\n";
	for (int i = 9; i >= 0; i--) {
		if (i != s.pop()) {
			cout << "Unsuccessful\n";
			return;
		}
	}
	cout << "Success\n";
}

void testIsEmpty(Stack& s)
{
	cout << "\n\ntest isEmpty\n";
	if (!s.isEmpty()) {
		cout << "Unsuccessful\n";
		return;
	}
	s.push(1);
	if (s.isEmpty()) {
		cout << "Unsuccessful\n";
		return;
	}
	s.pop();
	if (!s.isEmpty()) {
		cout << "Unsuccessful\n";
		return;
	}
	cout << "Success\n";
}

void testPopingEmptyStack(Stack& s)
{
	cout << "\n\ntest popping empty stack\n";
	while(s.top >= -1){
		s.pop();
	}
}

void testCopyConstructor(Stack& s){
	cout << "\n\ntest copy constructor\n";
	for(int i = 0; i < 5; i++){
		s.push(i);
	}
	static Stack copyStack(s);
	for(int i = 0; i < 5; i++){
		if(s.elements[i] != copyStack.elements[i] || 
		&s.elements[i] == &copyStack.elements[i]){
			cout << "Unsuccessful\n";
			return;
		}
	}
	cout << "Success\n";
}

void testAssigmentToSmallerSize(Stack& s){
	cout << "\n\ntest assigment to smaller stack\n";
	static Stack smallerStack;
	smallerStack.push(6);
	smallerStack = s;
	for(int i = 0; i < 5; i++){
		if(s.elements[i] != smallerStack.elements[i] || 
		&s.elements[i] == &smallerStack.elements[i]){
			cout << "Unsuccessful\n";
			return;
		}
	}
	cout << "Success\n";
}

void testAssigmentToBiggerSize(Stack& s){
	cout << "\n\ntest assigment to bigger stack\n";
	static Stack biggerStack;
	for(int i = 10; i <= 30; i++){
		biggerStack.push(i);
	}
	biggerStack = s;
	for(int i = 0; i < 5; i++){
		if(s.elements[i] != biggerStack.elements[i] || 
		&s.elements[i] == &biggerStack.elements[i]){
			cout << "Unsuccessful\n";
			return;
		}
	}
	cout << "Success\n";
}

void testAssigmentToSameSize(Stack& s){
	cout << "\n\ntest assigment to the same size stack\n";
	static Stack sameSizeStack;
	for(int i = 10; i < 15; i++){
		sameSizeStack.push(i);
	}
	sameSizeStack = s;
	for(int i = 0; i < 5; i++){
		if(s.elements[i] != sameSizeStack.elements[i] || 
		&s.elements[i] == &sameSizeStack.elements[i]){
			cout << "Unsuccessful\n";
			return;
		}
	}
	cout << "Success\n";
}

void testAssigmentToSameObject(Stack& s){
	cout << "\n\ntest assigment stack to the same stack\n";
	static Stack sameStack = s;
	sameStack = sameStack;
	for(int i = 0; i < 5; i++){
		if(s.elements[i] != sameStack.elements[i] || 
		&s.elements[i] == &sameStack.elements[i]){
			cout << "Unsuccessful\n";
			return;
		}
	}
	cout << "Success\n";
}

void testAssigmentEmptyToNotEmptyStack(Stack& s){
	cout << "\n\ntest assigment empty stack to not empty stack\n";
	static Stack emptyStack;
	s = emptyStack;
	(s.top == -1 && s.size == 0 && s.elements == NULL)
	? cout << "Success\n" : cout << "Unsuccessful\n";
}

int main()
{
	static Stack myStack;
	testPush(myStack);
	testPop(myStack);
	testIsEmpty(myStack);
	testCopyConstructor(myStack);
	testAssigmentToSmallerSize(myStack);
	testAssigmentToBiggerSize(myStack);
	testAssigmentToSameSize(myStack);
	testAssigmentToSameObject(myStack);
	testAssigmentEmptyToNotEmptyStack(myStack);
	testPopingEmptyStack(myStack);
	return 0;
}
