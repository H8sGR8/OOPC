#include "stack.h"

void testPush(Stack* s){
	int expectedList[10];
	for(int i = 0; i < 10; i++){
		push(s, i);
		expectedList[i] = i;
	}
	for(int j = 0; j <= s->top; j++){
		if(s->elements[j] != expectedList[j] || s->top != 9){
			printf("Unsuccessful\n");
			return;
		}
	}
	printf("Success\n");
}

void testPop(Stack* s){
	for(int i = 9; i >= 0; i--){
		if(i != pop(s)){
			printf("Unsuccessful\n");
			return;
		}
	}
	printf("Success\n");
}

void testIsEmpty(Stack* s){
	if(!isEmpty(s)){
		printf("Unsuccessful\n");
		return;
	}
	push(s, 1);
	if(isEmpty(s)){
		printf("Unsuccessful\n");
		return;
	}
	pop(s);
	if(!isEmpty(s)){
		printf("Unsuccessful\n");
		return;
	}
	printf("Success\n");
}

void testPopingEmptyStack(Stack* s){
	pop(s);
}

int main(){
	Stack myStack;
	init(&myStack);
	printf("test pushing\n");
	testPush(&myStack);
	printf("\n\ntest popping\n");
	testPop(&myStack);
	printf("\n\ntest isEmpty\n");
	testIsEmpty(&myStack);
	printf("\n\ntest popping empty stack\n");
	testPopingEmptyStack(&myStack);
	destroy(&myStack);
}
