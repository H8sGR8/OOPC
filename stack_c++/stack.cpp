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

void Stack::fillMemoryWithData(const Stack& other){
	top = other.top;
	for(int i = 0; i <= top; i++){
		elements[i] = other.elements[i];
	}
}

Stack::Stack(const Stack& other)
{
	size = other.size;
	elements = (int*)malloc(sizeof(int) * size);
	if(!elements){
		cout << "memory allocatrion error occured";
		exit(1);
	}
	fillMemoryWithData(other);
}

void Stack::allocateForAssigment(const Stack& other){
	int* newElements = NULL;
	size = other.size;
	if(!other.elements){
		elements = NULL;
		return;
	}
	newElements = (int*)realloc(elements, sizeof(int) * other.top);
	if(!newElements){
		cout << "memory reallocation error occured";
		exit(2);
	}
	elements = newElements;
}

Stack& Stack::operator=(const Stack& other){
	if(this == &other) return *this;
	if(size <= other.top){
		allocateForAssigment(other);
	}
	fillMemoryWithData(other);
	return *this;
}

Stack::~Stack()
{
	if(elements) free(elements);
}

int* Stack::increaseSize()
{
	int* newElements;
	if (size == INT_MAX) {
		cout << "max size reached\n";
		exit(3);
	}
	else if (size > (INT_MAX - 1) / 2)
		size = INT_MAX;
	else if (size == 0) size = INITIAL_SIZE;
	else size *= 2;
	newElements = (int*)realloc(elements, sizeof(int) * size);
	if (!newElements) {
		cout << "size increasment error occured\n";
		exit(4);
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
		exit(5);
	}
	top -= 1;
	return elements[top + 1];
}
