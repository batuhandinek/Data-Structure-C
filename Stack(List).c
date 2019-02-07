#include <stdio.h>
#include <stdlib.h>
#define STACK_SÝZE 5
struct node {
	int data;
	struct node *next;
};

struct stack {
	int cnt;
	struct stack *top;
};
int isFull(struct stack *stk) {
	if (stk->cnt == STACK_SÝZE) {
		return 1;
	}
	else
		return 0;
}
int isEmpty(struct stack *stk) {
	if (stk->cnt == 0)
		return 1;
	else
		return 0;
}
void initialize(struct stack *stk) {
	stk->cnt = 0;
	stk->top = NULL;
}
void push(struct stack *stk, int key) {
	if (isFull(stk))
		printf("Stack is FULL"); 
	else if (stk->cnt == STACK_SÝZE) {
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->data = key;
		temp->next = NULL;
		stk->top = temp;
		stk->cnt++;
	}
	else if(stk->cnt != STACK_SÝZE){
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->data = key;
		temp->next = stk->top;
		stk->top = temp;
		stk->cnt++;
	}
}

int pop(struct stack *stk) {
	if (isEmpty(stk))
		printf("Stack is Empty...\n");
	else {
		struct node *temp = stk->top;
		stk->top = temp->next;
		int x = temp->data;
		free(temp);
		stk->cnt--;
		return x;
	}
}
void print(struct stack *stk) {
	if (isEmpty(stk))
		printf("Satack Bostur...\n");
	else {
		struct node *temp = stk->top;
		while (temp != NULL) {
			printf("%d\n", temp->data);
			temp = temp->next;
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
