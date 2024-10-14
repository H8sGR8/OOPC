#pragma once

class Stack {

	int* increaseSize();
	
	void allocateForAssigment(const Stack&);
	
	void fillMemoryWithData(const Stack&);

  public:
	int* elements;

	int top;

	int size;

	Stack();

	Stack(const Stack&);
	

	Stack& operator=(const Stack&);

	~Stack();

	void push(int);

	bool isEmpty();

	int pop();
};
