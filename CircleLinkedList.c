#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *insertHead(struct node *head, int key) {
	if (head == NULL) {
		struct node *head = (struct node *)malloc(sizeof(struct node));
		head->data = key;
		head->next = head;
	}
	else {
		struct node *last = head;
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->data = key;
		while (last->next != head) {
			last = last->next;
		}
		temp->next = head;
		last->next = temp;
		head = temp;
	}
}
struct node *addLast(struct node *head, int key) {
	if (head == NULL) {
		struct node *head = (struct node *)malloc(sizeof(struct node));
		head->data = key;
		head->next = head;
	}
	else {
		struct node *last = head;
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->data = key;
		while (last->next != head) {
			last = last->next;
		}
		last->next = temp;
		temp->next = head;
	}
}
struct node *combine(struct node *head, struct node *head2) {
	if (head != NULL && head2 != NULL) {
		struct node *last = head;
		struct node *last2 = head2;
		while (last->next != head) {
			last = last->next;
		}
		while (last2->next != head2) {
			last2 = last2->next;
		}
		last->next = head2;
		last2->next = head;
	}
}
struct node *deleteValue(struct node *head, int key) {
	if (head == NULL)
		printf("list is Empty");
	else if (head->data == key && head->next == NULL) {
		free(head);
	}
	else {
		struct node *temp = head;
		struct node *temp2 = head;
		struct node *temp3 = head;
		while (temp->data != key) {
			temp = temp->next;
		}
		while (temp2->next != temp) {
			temp2 = temp2->next;
		}
		temp3 = temp->next;
		temp2->next = temp3;
		free(temp);
	}
	return head;
}
void print(struct node *head) {
	if (head == NULL) {
		printf("List is Empty");
	}
	else {
		struct node *temp = head;
		while (temp->next != head) {
			printf("%d\t", temp->data);
			temp = temp->next;
		}
		printf("%d\t", temp->data);
	}
}
int countList(struct node *head) {
	if (head != NULL) {
		struct node *temp = head;
		int i = 1; //i = 1 because if temp->next!= head => last list doesnt count so we must to start from 1.
		while (temp->next != head) {
			temp = temp->next;
			i++;
		}
		return i;
	}
	else {
		printf("List is Empty");
	}
}
int deleteAllList(struct node *head) {
	if (head == NULL) {
		return 0;
	}
	else {
		struct node *temp = head;
		struct node *last = head;
		while (last->next != head) {
			last = last->next;
		}
		while (temp->next != head) {
			temp = temp->next;
			free(head);
			head = temp;
			last->next = head;
		}
		free(head);
		return 0;
	}
}

int main() {
	struct node *head = NULL;
	struct node *head2 = (struct node *)malloc(sizeof(struct node));
	head2->data = 15000;
	head2->next = head2;
	int number;
	int key;
	while (1) {
		printf("\n*****************MENU****************\n");
		printf("1)Insert a node for head           : \n");
		printf("2)Insert a node for last           : \n");
		printf("3)Deleting a given value           : \n");
		printf("4)Print all list                   : \n");
		printf("5)Counting the elements of the list: \n");
		printf("6)Combining two list               : \n");
		printf("7)Delete ALL List                  : \n");
		printf("*****************MENU*****************\n");
		printf("\n");
		printf("Choose your choice: ");
		scanf_s("%d", &number);

		switch (number) {
		case 1:
			printf("insert a key for List : ");
			scanf_s("%d", &key);
			head = insertHead(head, key);
			break;
		case 2:
			printf("insert a key to the last : ");
			scanf_s("%d", &key);
			head = addLast(head, key);
			break;
		case 3:
			printf("Please enter a value: ");
			scanf_s("%d", &key);
			head = deleteValue(head, key);
			break;
		case 4:
			print(head);
			break;
		case 5:
			printf("List count : %d\n", countList(head));
			break;
		case 6:
			head = combine(head, head2);
			break;
		case 7:
			head = deleteAllList(head);
			break;
		default:
			exit(1);
			break;
		}
	}
	getchar();
	return 0;
}
