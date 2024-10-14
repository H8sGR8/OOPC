#include "stack.h"

void testPush(Stack* s){
	printf("test pushing\n");
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
	printf("\n\ntest popping\n");
	for(int i = 9; i >= 0; i--){
		if(i != pop(s)){
			printf("Unsuccessful\n");
			return;
		}
	}
	printf("Success\n");
}

void testIsEmpty(Stack* s){
	printf("\n\ntest isEmpty\n");
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
	printf("\n\ntest popping empty stack\n");
	while(s->top >= -1){
		pop(s);
	}
}

int main(){
	Stack myStack;
	init(&myStack);
	testPush(&myStack);
	testPop(&myStack);
	testIsEmpty(&myStack);
	testPopingEmptyStack(&myStack);
	return(0);
}
