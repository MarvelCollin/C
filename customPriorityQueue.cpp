#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient{
	char name[100];
	int level; 
	// 1 -> good, 2 -> fair, 3 -> serious, 4 -> critical
	Patient *next, *prev;
}*head = NULL, *tail = NULL;

Patient *createPatient(char name[], int level){
	Patient *newPatient = (Patient*)malloc(sizeof(Patient));
	
	*newPatient = (Patient){{0}, level, NULL, NULL};
	strcpy(newPatient->name, name);

	return newPatient;
}

void push(char name[], char condition[]){
	int level = 0;
	
	if(!strcmp(condition, "Critical")){
		level = 4;
	} else if(!strcmp(condition, "Serious")){
		level = 3;
	} else if(!strcmp(condition, "Fair")){
		level = 2;
	} else if(!strcmp(condition, "Good")){
		level = 1;
	} else {
		printf("Typo !\n");
		return;	
	}
	
	Patient *newPatient = createPatient(name, level);

    if(!head || level < head->level){
		// push head
        newPatient->next = head;
        if(head) head->prev = newPatient;
        head = newPatient;
        if(!tail) tail = newPatient;
		printf("Pushed %s %s\n", name, condition);
        return;
    }

    Patient *curr = head;
    while(curr->next && curr->next->level <= level){
        curr = curr->next;
    }
    
    if(curr == tail){
    	// push tail
        tail->next = newPatient;
        newPatient->prev = tail;
        tail = newPatient;
    } else {
    	// push mid
        newPatient->next = curr->next;
        newPatient->prev = curr;
        curr->next->prev = newPatient;
        curr->next = newPatient;
    }
	printf("Pushed %s %s\n", name, condition);

}

void printAll(){
	printf("\n\nCurrent list : \n");
	for(Patient *curr = head; curr; curr = curr->next){
		printf("%s %d\n", curr->name, curr->level);
	}
}

void pop(){
	if(!head){
        printf("Queue is empty\n");
        return;
    }

	int currentLevel = tail->level;
	
	if(head->level == currentLevel){ // level cuman 1
		// pop head
		Patient *temp = head;
		printf("Popped %s\n", temp->name);
		head = head->next;
		head->prev = NULL;
		free(temp);
	} else if(tail->prev->level != currentLevel) {
//		3 3 3 4 cuman ada 1 level di tail  
		
		// pop tail
		Patient *temp = tail;
		printf("Popped %s\n", temp->name);
		tail = tail->prev;
		tail->next = NULL;
		free(temp);
		 
	} else {
		// pop mid
		Patient *temp = head;
		
//		1   1  2  2
//		h   <------
//		       t
		while(temp && temp->level != currentLevel){
			temp = temp->next;
		}
		
		printf("Popped %s\n", temp->name);
		temp->next->prev = temp->prev;	
		temp->prev->next = temp->next;
		free(temp);
	}
	
}

int main(){
	push("aaasda", "Serious");
	push("dddd", "Fair");
	push("asda", "Critical");
	push("zaazz", "Good");
	push("zzzzz", "Good");
	push("zzxzz", "Good");
	push("accdda", "Serious");
	push("acxxa", "Critical");
	
	printAll();
	
	pop();
	printAll();
	pop();
	printAll();
	pop();
	printAll();
	
	return 0;
}
