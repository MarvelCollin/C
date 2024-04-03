#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display();

struct Music{
	char title[100];
	char artist[100];
	char duration[10];
	Music *next, *prev;
}*head = NULL, *tail = NULL;

Music* createMusic(char title[], char artist[], char duration[]){
	Music* newMusic = (Music*)malloc(sizeof(Music)); /// buat buletan
	
//	*newMusic = (Music){age, {0}, {0}, {0}, NULL, NULL};
	strcpy(newMusic->title, title);
	strcpy(newMusic->artist, artist);
	strcpy(newMusic->duration, duration);
	newMusic->prev = NULL;
	newMusic->next = NULL;
	
	return newMusic;
}

void pushTail(char title[], char artist[], char duration[]){
	Music* newMusic = createMusic(title, artist, duration);
	
	if(head == NULL){ // ga ada musik
		head = tail = newMusic;
	} else { // ada musik
		tail->next = newMusic;
		newMusic->prev = tail;
		tail = newMusic;
	}
}

bool find(char title[]){
	Music* curr = head;
	
	while(curr != NULL){
		if(strcmp(curr->title, title) == 0){
//			printf("ketemu %s %s %s\n", curr->title, curr->artist, curr->duration);
			return true;
		}
		curr = curr->next;
	}
	
	return false;
}

void pushAfter(char target[], char title[], char artist[], char duration[]){
	Music* newMusic = createMusic(title, artist, duration);
	
	if(!find(target)){
		printf("Target not found\n");
	}
	else if(strcmp(tail->title, target) == 0){ // handle error utk pushtail
		tail->next = newMusic;
		newMusic->prev = tail;
		tail = newMusic;
	} else {
		Music* curr = head;
		
		while(curr){
			if(strcmp(curr->title, target) == 0){ // udah di target
				newMusic->next = curr->next;
				newMusic->prev = curr;
				curr->next = newMusic;
				newMusic->next->prev = newMusic;
				return;
			}
			curr = curr->next;
		}
	}
}

void pushBefore(char target[], char title[], char artist[], char duration[]){
	Music* newMusic = createMusic(title, artist, duration);
	
	if(!find(target)){
		printf("Target not found\n");
	}
	else if(strcmp(head->title, target) == 0){ // handle error utk pushtail
		head->prev = newMusic;
		newMusic->next = head;
		head = newMusic;
	} 
	else {
		Music* curr = head;
		
		while(curr){
//			if(strcmp(curr->next->title, target) == 0){ // udah di target
//				newMusic->next = curr->next;
//				newMusic->prev = curr;
//				curr->next = newMusic;
//				newMusic->next->prev = newMusic;
//				return;
//			}
			if(strcmp(curr->title, target) == 0){ // udah di target
				newMusic->next = curr;
				newMusic->prev = curr->prev;
				curr->prev = newMusic;
				newMusic->prev->next = newMusic;
				return;
			}
	
			curr = curr->next;
		}
	}
}

void popMid(char title[]){
	Music* curr = head;
	// popHead
	if(strcmp(head->title, title) == 0){
		head = head->next;
		head->prev = NULL;
		free(curr);
		printf("deleted %s\n", title);
		return;
	}
	if (strcmp(tail->title, title) == 0){
		curr = tail;
		tail = tail->prev;
		tail->next = NULL;
		free(curr);
		printf("deleted %s\n", title);
		return;
	}
	
	while(curr){
		if(strcmp(curr->title, title) == 0){
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			free(curr);
			printf("deleted %s\n", title);
			return;
		}
		curr = curr->next;
	}
	
	printf("not found\n");
}

void popAll(){
	Music* temp = head;
	Music* nextMusic;
	
	while(temp != NULL){ // apakah curr itu ada value (tidak null)
		nextMusic = temp->next;
		free(temp);
		temp = nextMusic;
	}
	head = tail = NULL;
	display();
}

void display(){
	Music* curr = head;
	if(!curr){
		printf("Tidak ada\n");
		
		return;
	}
	
	while(curr != NULL){ // apakah curr itu ada value (tidak null)
		printf("%s - %s - %s\n", curr->title, curr->artist, curr->duration);
		curr = curr->next;
	}
	
//	for(Music* curr = head; curr; curr = curr->next){
//		printf("%s - %s - %s\n", curr->title, curr->artist, curr->duration);
//	}
}

int main(){
	pushTail("asda", "sadas", "04:15");
	pushTail("asdas", "sadaasdds", "05:15");
	pushTail("asdacc", "sadasddd", "04:17");
	pushBefore("asda", "xxxxxx", "cvcccc", "09:00");
	popAll();
	return 0;
}
