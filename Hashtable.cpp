#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int size = 400;

struct Hash{
	char name[100];
	int age;
	Hash *next, *prev;
}*head[size], *tail[size];

Hash *createHash(char name[], int age){
	Hash* newHash = (Hash*)malloc(sizeof(Hash));
	
	*newHash = (Hash){{0}, age, NULL, NULL};
	strcpy(newHash->name, name);
	
	return newHash;
}

int getKey(char name[]){
	int len = strlen(name);
	
	int key = 0;
	for(int i = 0; i < len; i++){
		key += name[i];
	}
	return key % 200;
}

void push(char name[], int age){
	Hash *newHash = createHash(name, age);
	
	int key = getKey(name);
	
	if(!head[key]){
		head[key] = tail[key] = newHash;
	} else {
		tail[key]->next = newHash;
		newHash->prev = tail[key];
		tail[key] = newHash;
	}
}

void display(){
	for(int i = 0; i < size; i++){
		Hash* curr = head[i];
		while(curr){
			printf("========================\n");
			printf("%s -> %d\n", curr->name, curr->age);
			curr = curr->next;
		}
	}
}

void findData(char name[]){
	int key = getKey(name);
	
	if(!head[key]){
		printf("Doesnt found\n");
		return;
	} 
	
	Hash* curr = head[key];
	
	while(curr){
		if(strcmp(curr->name, name) == 0){
			printf("Found %s -> %d\n", curr->name, curr->age);
			return;
		}
		curr = curr->next;
	}
	
	printf("Doesnt found\n");
}

void deleteData(char name[]){
	int key = getKey(name);
	printf("Key -> %d\n", key);
	if(!head[key]){
		printf("Doesnt found\n");
		return;
	} 
	
	Hash* curr = head[key];
	
	if(strcmp(head[key]->name, name) == 0 && head[key] == tail[key]){
		head[key] = tail[key] = NULL;
		free(curr);
		printf("Deleted\n");
		return;
	}
	
	while(curr){
		if(strcmp(curr->name, name) == 0){
			if(strcmp(head[key]->name, name) == 0){
				head[key] = head[key]->next;
				head[key]->prev = NULL;
				
				free(curr);
				printf("Deleted\n");
				return;
			}
			
			return;
		}
		curr = curr->next;
	}
}

int main(){
	push("asads", 123);
	push("bsads", 123);
	push("aaaaads", 123);
	push("csads", 123);
	push("dsads", 123);
	display();
	findData("asads");
	deleteData("Jason");
	findData("asads");
	return 0;
}
