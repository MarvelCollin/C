#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	char name[100];
	int num;
	Node *next,*prev;
}*head = NULL, *tail = NULL;

Node* createNode(char name[], int num){
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	*newNode = (Node){{0}, num, NULL, NULL};
	strcpy(newNode->name, name);
	
	return newNode;
}

void pushHead(char name[], int num){
	Node* newNode = createNode(name, num);
	
	if(!head){
		head = tail = newNode;		
	} else {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

void pushMid(char name[], int num){
    Node* newNode = createNode(name, num);

    if (!head ) { // head tidak ada + ternyata num < head
 		head = tail = newNode;
 		return;
    } else if(num < head->num){
		pushHead(name, num);
		return;
	}
	
    Node* curr = head;
    while(curr->next && num > curr->next->num){
    	curr = curr->next;
	}
	
	newNode->next = curr->next;
	newNode->prev = curr;
	if(curr->next) curr->next->prev = newNode;
	curr->next = newNode;
    if(!newNode->next) tail = newNode;
}

void display(){
	for(Node* curr = head; curr; curr = curr->next){
		printf("%s -> %d\n", curr->name, curr->num);
	}
}

int main(){
	pushMid("asa",12);
	pushMid("asdas",17);
	pushMid("aasdaisdj",15);
	display();
	return 0;
}
