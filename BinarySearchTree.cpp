#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data; 
	Node *right, *left;
};

Node *createNode(int data){
	Node *newNode = (Node*)malloc(sizeof(Node));
	
	*newNode = (Node){data, NULL, NULL};
	
	return newNode;
}

Node *insert(Node* root, int data){
	if(!root){
		return createNode(data);
	}
	
	if(data < root->data){
		root->left = insert(root->left, data);
	} else if(data > root->data){
		root->right = insert(root->right, data);
	}
	
	return root;
}

Node* findMin(Node* root){
	while(root->left){
		root = root->left;
	}
	
	return root;
}

Node* deleteNode(Node* root, int data){
	if(!root){
		printf("Nothing to delete\n");
		return root;
	}
	
	if(data < root->data){
		root->left = deleteNode(root->left, data);
	} else if(data > root->data){
		root->right = deleteNode(root->right, data);
	} else {
		if(!root->left){
			Node* temp = root->right;
			free(root);
			return temp;
		} else if(!root->right){
			Node* temp = root->left;
			free(root);
			return temp;
		} else {
			Node *temp = findMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
	
	return root;
}

void prePrint(Node *root){
	if(root){
		printf("%d ", root->data);
		prePrint(root->left);
		prePrint(root->right);
	}
}

int main(){
	Node *root = NULL;
	root = insert(root, 23);
	root = insert(root, 5);
	root = insert(root, 10);
	root = insert(root, 3);
	deleteNode(root, 3);
	prePrint(root);
	
	return 0;
}
