#pragma once

class Stack {

  public:
	
	int* elements;
	
	int top;
	
	int size;
	
	Stack();

	~Stack();

	int* increaseSize();

	void push(int);

	bool isEmpty();

	int pop();
};
