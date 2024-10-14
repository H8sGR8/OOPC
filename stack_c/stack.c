#include "stack.h"
#include "test_allocation.h"


void destroy(Stack* s){
	free(s->elements);
	exit(1);
}

void init(Stack* s){
	s->size = 0;
	s->elements = NULL;
	s->top = -1;
	return;
}

int* increaseSize(Stack* s){
	int* newElements;
	if(s->size == INT_MAX){
		printf("max size reached\n");
		destroy(s);
	}
	else if(s->size > (INT_MAX - 1) / 2) s->size = INT_MAX;
	else if(s->size == 0) s->size = 1;
	else s->size *= 2;
	newElements = realloc(s->elements, sizeof(int) * s->size);
	if(!newElements){
		printf("size increasment error occured\n");
		destroy(s);
	}
	return newElements;
}

void push(Stack* s, int element){
	if(s->top == s->size - 1){
		s->elements = increaseSize(s);
	}
	s->top++;
	s->elements[s->top] = element;
	return;
}

bool isEmpty(Stack* s){
	return s->top < 0;
}	

int pop(Stack* s){
	if(isEmpty(s)){
		printf("poping empty stack detected\n");
		destroy(s);
	}
	s->top -= 1;
	return s->elements[s->top + 1];
}
