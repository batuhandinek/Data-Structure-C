#include <stdio.h>
#include <stdlib.h>
#define queue_size 5
struct node {
	struct node *next;
	int data;
};
struct queue {
	struct node *front;
	struct node *rear;
	int cnt;
};
void initialize(struct queue* q) {
	q->cnt = 0;
	q->front = q->rear = NULL;
}
int isEmpty(struct queue* q) {
	if (q->cnt == 0)
		return 1;
	else
		return 0;
}
int isFull(struct queue * q) {
	if (q->cnt == queue_size)
		return 1;
	else
		return 0;
}
void enqueue(struct queue* q, int key) {
	if (!isFull(q)) {
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->data = key;
		temp->next = NULL;
		if (isEmpty(q))
			q->front = q->rear = temp;
		else {
			q->rear->next = temp;
			q->rear = temp;
		}
		q->cnt++;
	}
	else
		printf("Queue is Full..");
}
int dequeue(struct queue* q) {
	if (!isEmpty(q)) {
		struct node* temp = q->front;
		int x = temp->data;
		q->front = temp->next;
		free(temp);
		q->cnt--;
		return x;
	}
	else
		printf("Queue is Empty..");
}
void print(struct queue* q) {
	if (!isEmpty(q)) {
		struct node* temp = q->front;
		while (temp != NULL) {
			printf("%d\t", temp->data);
			temp = temp->next;
		}
	}
	else
		printf("Queue is Empty..");
}
int main() {
	struct queue q;
	initialize(&q);
	int key;
	int number;
	while (1) {
		printf("\n*****************MENU*****************\n");
		printf("1)insert a value to the Queue: \n");
		printf("2)Delete a value from Queue  : \n");
		printf("3)Print all Queue            : \n");
		printf("*****************MENU*****************\n");
		printf("\n");
		printf("Enter a choise : ");
		scanf_s("%d", &number);
		switch (number) {
		case 1:
			printf("insert a Value : ");
			scanf_s("%d", &key);
			enqueue(&q, key);
			break;
		case 2:
			printf("%d", dequeue(&q));
			break;
		case 3:
			print(&q);
			break;
		default:
			exit(1);
			break;
		}
	}
	getchar();
	return 0;
}