#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};
/**/
struct node *insertHead(struct node *head, int key) {
	if (head == NULL) {
		struct node *head = (struct node *)malloc(sizeof(struct node));
		head->data = key;
		head->next = NULL;
		return head;
	}
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->next = head;
	head = temp;
	return head;
}
struct node *addLast(struct node *head, int key) {
	if (head == NULL) {
		struct node *head = (struct node *)malloc(sizeof(struct node));
		head->data = key;
		head->next = NULL;
		return head;
	}
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->next = NULL;
	struct node *temp2 = head;
	while (temp2->next != NULL) {
		temp2 = temp2->next;
	}
	temp2->next = temp;
	return head;
}
struct node *deleteHead(struct node *head) {
	if (head == NULL)
		printf("list is empty");
	else if (head->next == NULL) {
		free(head);
	}
	else {
		struct node *temp = head;
		head = temp->next;
		free(temp);
	}
	return head;
}
struct node *deleteLast(struct node *head) {
	if (head == NULL)
		printf("list is empty");
	else if (head->next == NULL) {
		free(head);
	}
	else {
		struct node *temp2 = head;
		struct node *temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		while (temp2->next != temp) {
			temp2 = temp2->next;
		}
		temp2->next = NULL;
		free(temp);
	}
	return head;
}
struct node *deleteValue(struct node *head, int key) {
	if (head == NULL)
		printf("list is Empty");
	else if (head->data == key) {
		deleteHead(head);
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
struct node *deleteAllList(struct node *head) {
	if (head == NULL) {
		return 0;
	}
	else {
		struct node *temp = head;
		while (temp != NULL){
			temp = temp->next;
			free(head);
			head = temp;
		}
		return head;
	}
}
void print(struct node *head) {
	if (head == NULL) {
		printf("List is Empty");
	}
	struct node *temp = head;
	while (temp != NULL) {
		printf("%d\t", temp->data);
		temp = temp->next;
	}
}
int countList(struct node *head) {
	int i = 0;
	struct node *temp = head;
	while (temp != NULL) {
		temp = temp->next;
		i++;
	}
	return i;
}
void search(struct node *head, int key) {
	if (head == NULL) {
		printf("List is Empty");
	}
	struct node *temp = head;
	while (temp != NULL) {
		if (temp->data == key) {
			printf("Key is available..");
		}
		if(temp->data == NULL){
			printf("key is not available");
		}
		temp = temp->next;
	}

}
struct node *combine(struct node *head, struct node *head2) {
	struct node *temp = head;
	if (head != NULL && head2 != NULL) {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = head2;
		return head;
	}
}
int main() {
	struct node *head = NULL;
	struct node *head2 = (struct node *)malloc(sizeof(struct node));
	head2->data = 15000;
	head2->next = NULL;
	int number;
	int key;
	while (1) {
		printf("\n*****************MENU****************\n");
		printf("1)Insert a node for head           : \n");
		printf("2)Insert a node for last           : \n");
		printf("3)Deleting a node from head        : \n");
		printf("4)Deleting a node from last        : \n");
		printf("5)Deleting a given value           : \n");
		printf("6)Print all list                   : \n");
		printf("7)Counting the elements of the list: \n");
		printf("8)Searching the Lists              : \n");
		printf("9)Combining two list               : \n");
		printf("10)Delete ALL List                 : \n");
		printf("*****************MENU****************\n");
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
			head = deleteHead(head);
			break;
		case 4:
			head = deleteLast(head);
			break;
		case 5:
			printf("Please enter a value: ");
			scanf_s("%d", &key);
			head = deleteValue(head, key);
			break;
		case 6:
			print(head);
			break;
		case 7:
			printf("List count : %d\n",countList(head));
			break;
		case 8:
			printf("Please enter a Value: ");
			scanf_s("%d", &key);
			search(head, key);
			break;
		case 9:
			head = combine(head, head2);
			break;
		case 10:
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

