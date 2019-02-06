#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
	struct node *prev;
};
struct node *insertHead(struct node *head, int key) {
	if (head == NULL) {
		struct node *head = (struct node *)malloc(sizeof(struct node));
		head->data = key;
		head->next = head;
		head->prev = head;
		return head;
	}
	else {
		struct node *last = head;
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->data = key;
		while (last->next != head)
			last = last->next;
		temp->next = head;
		last->next = temp;
		temp->prev = last;;
		head->prev = temp;
		head = temp;
		return head;
	}
}
struct node *insertLast(struct node *head, int key) {
	if (head == NULL) {
		struct node *head = (struct node *)malloc(sizeof(struct node));
		head->data = key;
		head->next = head;
		head->prev = head;
		return head;
	}
	else {
		struct node *temp = head;
		struct node *temp2 = (struct node *)malloc(sizeof(struct node));
		while (temp->next != head) {
			temp = temp->next;
		}
		temp2->data = key;
		temp2->next = head;
		temp2->prev = temp;
		temp->next = temp2;
		head->prev = temp2;
		return head;
	}
}
struct node *deleteNode(struct node *head, int key) {
	if (head == NULL)
		printf("List is Empty");
	else {
		struct node *temp = head;
		struct node *last = head;
		if (head->data == key) {
			while (last->next != head) {
				last = last->next;
			}
			head = head->next;
			head->prev = last;
			last->next = head;
			free(temp);
			return head;
		}
		else {
			while (temp->data != key) {
				temp = temp->next;
			}
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			free(temp);
		}
	}
	return head;
}
void print(struct node *head) {
	if (head == NULL) {
		printf("List is Empty");
		return;
	}
	struct node *temp = head;
	while (temp->next != head) {
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("%d", temp->data);
}
int main() {
	struct node *head = NULL;
	int key;
	int number;
	while (1) {
		printf("\n*****************MENU*****************\n");
		printf("1)insert a node to the head     : \n");
		printf("2)insert a node to the last     : \n");
		printf("3)Delete a node of a given value: \n");
		printf("4)Print all List                : \n");
		printf("*****************MENU*****************\n");
		printf("\n");
		printf("Enter a choise : ");
		scanf_s("%d", &number);
		switch (number) {
		case 1:
			printf("insert to head a Value : ");
			scanf_s("%d", &key);
			head = insertHead(head, key);
			break;
		case 2:
			printf("insert to last a Value : ");
			scanf_s("%d", &key);
			head = insertLast(head, key);
			break;
		case 3:
			printf("Enter a value : ");
			scanf_s("%d", &key);
			head = deleteNode(head, key);
			break;
		case 4:
			print(head);
			break;
		default:
			exit(1);
			break;
		}
	}
	getchar();
	return 0;
}