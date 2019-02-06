#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 5

struct stack {
	int top;
	int data[STACK_SIZE];
};
void initialize(struct stack *stk) {
	stk->top = -1;
}
void push(struct stack *stk, int key) {
	if (stk->top == STACK_SIZE-1) {
		printf("Stack is Full");
	}
	else {
		stk->top++;
		stk->data[stk->top] = key;
	}
}
int pop(struct stack *stk) {
	if (stk->top == -1) {
		printf("Stack is Empty");
	}
	else {
		int c = stk->top--;
		return c;
	}
}
void print(struct stack *stk) {
	if (stk->top == -1) {
		printf("Stack is Empty");
	}
	else {
		for (int i = 0; i < stk->top + 1; i++) {
			printf("%d\t", stk->data[i]);
		}
	}
}
int main() {
	struct stack stk;
	initialize(&stk);
	int key;
	int number;
	while (1) {
		printf("\n*****************MENU*****************\n");
		printf("1)insert a value to the top     : \n");
		printf("2)Delete a value from stack     : \n");
		printf("3)Print all List                : \n");
		printf("*****************MENU*****************\n");
		printf("\n");
		printf("Enter a choise : ");
		scanf_s("%d", &number);
		switch (number) {
		case 1:
			printf("insert to head a Value : ");
			scanf_s("%d", &key);
			push(&stk, key);
			break;
		case 2: 
			pop(&stk);
			break;
		case 3:
			print(&stk);
			break;
		default:
			exit(1);
			break;
		}
	}
	getchar();
	return 0;
}