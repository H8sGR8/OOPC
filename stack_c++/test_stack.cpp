#include "stack.h"
#include <iostream>
using namespace std;

void testPush(Stack* s)
{
	int expectedList[10];
	for (int i = 0; i < 10; i++) {
		s->push(i);
		expectedList[i] = i;
	}
	for (int j = 0; j <= s->top; j++) {
		if (s->elements[j] != expectedList[j] || s->top != 9) {
			cout << "Unsuccessful\n";
			return;
		}
	}
	cout << "Success\n";
}

void testPop(Stack* s)
{
	for (int i = 9; i >= 0; i--) {
		if (i != s->pop()) {
			cout << "Unsuccessful\n";
			return;
		}
	}
	cout << "Success\n";
}

void testIsEmpty(Stack* s)
{
	if (!s->isEmpty()) {
		cout << "Unsuccessful\n";
		return;
	}
	s->push(1);
	if (s->isEmpty()) {
		cout << "Unsuccessful\n";
		return;
	}
	s->pop();
	if (!s->isEmpty()) {
		cout << "Unsuccessful\n";
		return;
	}
	cout << "Success\n";
}

void testPopingEmptyStack(Stack* s)
{
	s->pop();
}

int main()
{
	Stack myStack;
	cout << "test pushing\n";
	testPush(&myStack);
	cout << "\n\ntest popping\n";
	testPop(&myStack);
	cout << "\n\ntest isEmpty\n";
	testIsEmpty(&myStack);
	cout << "\n\ntest popping empty stack\n";
	testPopingEmptyStack(&myStack);
}
