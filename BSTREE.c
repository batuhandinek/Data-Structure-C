#include <stdlib.h>
#include<stdio.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};


struct node* new_node(int key) {
	struct node* p = (struct node*)malloc(sizeof(struct node));
	p->data = key;
	p->left = NULL;
	p->right = NULL;

	return p;
}
struct node* insert(struct node *root, int key) {
	if (root != NULL) {
		if (key < root->data)
			root->left = insert(root->left, key);
		else
			root->right = insert(root->right, key);
	}
	else
		root = new_node(key);
	return root;
}
void preorder(struct node *root) {
	if (root != NULL) {
		printf("%d\t", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct node *root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d\t", root->data);
		inorder(root->right);
	}
}
void postorder(struct node *root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d\t", root->data);
	}
}
int size(struct node *root) { //find the number of node
	if (root != NULL)
		return 0;
	else return 1 + size(root->left) + size(root->right);
}
int height(struct node* root) {//find the number of height 
	if (root == NULL)
		return -1;
	else {
		int lheight, rheight;
		lheight = height(root->left);
		rheight = height(root->right);
		if (rheight > lheight)
			return rheight + 1;
		else
			return lheight + 1;
	}
}
int leaves(struct node *root) {//find the number of leaves 
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return leaves(root->left) + leaves(root->right);
}
int minimum(struct node *root) { //find the number of minimum
	if (root != NULL) {
		while (root->left != NULL)
			root = root->left;
		return root->data;
	}
}
int maximum(struct node *root) {
	if (root != NULL) {
		while (root->right != NULL)
			root = root->right;
		return root->data;
	}
}
struct node *delete_node(struct node *root, int x) {
	struct node * p, * q;
	if (root == NULL) 
		return NULL;
	if (root->data == x) {
		if (root->left == root->right) {
			free(root);
			return NULL;
		}
		else {
			if (root->left == NULL) {
				p = root->right;
				free(root);
				return p;
			}
			else if (root->right == NULL) {
				p = root->left;
				free(root);
				return p;
			}
			else {
				p = q = root->right;
				while (p->left != NULL)
					p = p->left;
				p->left = root->left;
				free(root);
				return q;
			}
		}
	}
	else if (root->data < x)
		root->right = delete_node(root->right, x);
	else
		root->left = delete_node(root->left, x);
	return root;
}
int findNumberNodesinLevel(struct node * root, int level) {
	if (root == NULL)
		return 0;
	if (level == 0)
		return 1;
	else {
		return findNumberNodesinLevel(root->left, level - 1) + findNumberNodesinLevel(root->right, level - 1);
	}
}
struct node* copyOdd(struct node* root, struct node* tek) {
	if (root != NULL) {
		if (root->data % 2 == 1)
			tek = insert(tek, root->data);

		tek = copyOdd(root->left, tek);
		tek = copyOdd(root->right, tek);
	}
	return tek;
}
int main() {
	struct node *root = NULL;
	struct node *odd = NULL;
	int number;
	int key;
	int i = 0;
	int x;
	while (1) {
		printf("\n*****************MENU*****************\n");
		printf("1)insert a value to the Tree: \n");
		printf("2)Delete an Entered Value   : \n");
		printf("3)Print Minimum Value       : \n");
		printf("4)Print Maximum Value       : \n");
		printf("5)Print Tree's Height       : \n");
		printf("6)Print Tree's Leaves	    : \n");
		printf("7)Print all Tree            : \n");
		printf("8)Finding the Number of\n" 
				"Nodes in the Entered Level  : \n");
		printf("9)Send odd number to another tree : \n");
		printf("*****************MENU*****************\n");
		printf("Enter a Choise: ");
		scanf_s("%d", &number);
		switch (number) {
		case 1:
			printf("Enter a Value: ");
			scanf_s("%d", &i);
			root = insert(root, i);
			break;
		case 2:
			printf("Enter a Value:");
			scanf_s("%d", &key);
			delete_node(root, key);
			break;
		case 3:
			printf("Min : %d\n", minimum(root));
			break;
		case 4:
			printf("Max : %d\n", maximum(root));
			break;
		case 5:
			printf("Height: %d\n", height(root));
			break;
		case 6:
			printf("Leaves: %d\n", leaves(root));
			break;
		case 7:
			printf("Preorder = ");
			preorder(root);
			printf("\nInorder = ");
			inorder(root);
			printf("\nPostorder = ");
			postorder(root);
			break;
		case 8:
			printf("Please enter a level:");
			scanf_s("%d", &x);
			printf("%d\n", findNumberNodesinLevel(root, x));
			break;
		case 9:
			odd = copyOdd(root, odd);
			printf("Preorder = ");
			preorder(odd);
			printf("\nInorder = ");
			inorder(odd);
			printf("\nPostorder = ");
			postorder(odd);
			break;
		default:
			exit(1);
			break;
		}
	}
	getchar(0);
	return 0;
}
