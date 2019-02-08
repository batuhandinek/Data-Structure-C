//You should to think this code like a circle array.
#include <stdio.h>
#include <stdlib.h>
#define queue_size 3
struct queue {
	int front;
	int rear;
	int cnt;
	int data[queue_size];
};
void initialize(struct queue *q) {
	q->front = 0;
	q->rear = -1;
	q->cnt = 0;
}
int isEmpty(struct queue *q) {
	if (q->cnt == 0)
		return 1;
	else
		return 0;
}
int isFull(struct queue *q) {
	if (q->cnt == queue_size)
		return 1;
	else
		return 0;
}

void enqueue(struct queue *q, int key) {
	if (isFull(q))
		printf("Queue is Full\n");
	else {
		q->rear++;
		q->cnt++;
		if (q->rear == queue_size) {
			q->rear = 0;
		}
		q->data[q->rear] = key;
	}
}
int dequeue(struct queue *q) {
	if (isEmpty(q))
		printf("Queue is Empty\n");
	else {
		int x = q->data[q->front];
		q->front++;
		if (q->front == queue_size)
			q->front = 0;
		q->cnt--;
		return x;
	}
}
void print(struct queue *q) {
	if (isEmpty(q)) {
		printf("Queue is Empty");
	}
	else {
		for (int i = 0; i < queue_size; i++) { //code working true but when it's printing, if you did dequeue, it will printing with dequeue value but it's already deleted.  
			printf("%d\t", q->data[i]);			// and you try to add(enqueue) something it be add (enqueue) and the print queue. it's printig with new value.
		}
	}
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