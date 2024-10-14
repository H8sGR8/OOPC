#include "stack.h"
#include <iostream>
#include <limits.h>
#include <stdlib.h>
using namespace std;

Stack::Stack()
{
	size = 0;
	elements = NULL;
	top = -1;
}

Stack::~Stack()
{
	free(elements);
	exit(1);
}

int* Stack::increaseSize()
{
	int* newElements;
	if (size == INT_MAX) {
		cout << "max size reached\n";
		delete this;
	}
	else if (size > (INT_MAX - 1) / 2)
		size = INT_MAX;
	else if (size == 0)
		size = 1;
	else
		size *= 2;
	newElements = (int*)realloc(elements, sizeof(int) * size);
	if (!newElements) {
		cout << "size increasment error occured\n";
		delete this;
	}
	return newElements;
}

void Stack::push(int element)
{
	if (top == size - 1) {
		elements = increaseSize();
	}
	top++;
	elements[top] = element;
	return;
}

bool Stack::isEmpty()
{
	return top < 0;
}

int Stack::pop()
{
	if (isEmpty()) {
		cout << "poping empty stack detected\n";
		delete this;
	}
	top -= 1;
	return elements[top + 1];
}
