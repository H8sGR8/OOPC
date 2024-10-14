#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct{
	int* elements;
	int top;
	int size;
} Stack;

void destroy(Stack*);

void init(Stack*);

int* increaseSize(Stack*);

void push(Stack* , int);

bool isEmpty(Stack*);

int pop(Stack*);
