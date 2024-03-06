#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"

struct QueueNode {
    char slang[50];
    char desc[100];
    struct QueueNode* next;
};

struct Dictionary {
    struct QueueNode *head, *tail;
};

struct Dictionary* dict;

struct Dictionary* createDictionary() {
    struct Dictionary* dict = (struct Dictionary*)malloc(sizeof(struct Dictionary));
    dict->head = dict->tail = NULL;
    return dict;
}

void clr(){
	system("cls");
}

void loading(){
	char spinner[] = {'|', '/', '-', '\\'};
    int i;

    printf("Loading.");

    for (i = 0; i < 20; i++) {
        printf("\b%c", spinner[i % 4]);
        fflush(stdout);
        Sleep(50); 
    }

    printf("\n%sLoading Complete !%s\n", GREEN, RESET);
}

void enter(){
    printf("Press anything to continue");
    getch();
}

int isEmpty() {
    return (dict->head == NULL);
}

void insertQueue(char slang[], char desc[]) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    strcpy(newNode->slang, slang);
    strcpy(newNode->desc, desc);
    newNode->next = NULL;

    if (isEmpty()) {
        dict->head = dict->tail = newNode;
        return;
    }

    dict->tail->next = newNode;
    dict->tail = newNode;
}

void viewAll() {
    if(isEmpty()) {
        printf("Dictionary is empty.\n");
        return;
    }
    
    struct QueueNode* current = dict->head;
    
    printf("Slang words in the dictionary:\n");
    while(current != NULL) {
        printf("%s%s%s -> %s%s%s\n", GREEN, current->slang, RESET, GREEN, current->desc, RESET);
        current = current->next;
    }
}

void exitProgram() {
    printf("Goodbye!\n");
    exit(0);
}

void menu();

void insert() {
	clr();
    char slang[100];
    char desc[100];
    
    do {
        printf("Input a slang word [%sno space && more than 1 character%s] > ", RED, RESET);
        scanf(" %[^\n]", slang);
        getchar();
    } while(strlen(slang) < 2 || strchr(slang, ' '));

    do {
        printf("Input %s%s%s description [%smust be more than 2 words%s] > ", GREEN, slang, RESET, RED, RESET);
        scanf(" %[^\n]", desc);
        getchar();
    } while(strchr(desc, ' ') == NULL);
    
    insertQueue(slang, desc);
    loading();
    printf("Successfully inserted \"%s%s%s\" with description \"%s%s%s\"\n", GREEN, slang, RESET, GREEN, desc, RESET);
	enter();
	menu();
}

void search() {
    char slang[100];
    
    printf("Input slang word to search for: ");
    scanf(" %[^\n]", slang);
    getchar();
    
    struct QueueNode* current = dict->head;
    int found = 0;
    while(current != NULL) {
        if(strcmp(current->slang, slang) == 0) {
            printf("Slang: %s%s%s, Description: %s%s%s\n", GREEN, current->slang, RESET, GREEN, current->desc, RESET);
            found = 1;
            break;
        }
        current = current->next;
    }
    if (!found) {
        printf("Slang not found in the dictionary.\n");
    }
}

void searchByPrefix() {
    char prefix[100];
    printf("Input prefix to search for: ");
    scanf(" %[^\n]", prefix);
    getchar();
    
    struct QueueNode* current = dict->head;
    int found = 0;
    while(current != NULL) {
        if(strncmp(current->slang, prefix, strlen(prefix)) == 0) {
            printf("Slang: %s%s%s, Description: %s%s%s\n", GREEN, current->slang, RESET, GREEN, current->desc, RESET);
            found = 1;
        }
        current = current->next;
    }
    if (!found) {
        printf("No slang words found in the dictionary with the given prefix.\n");
    }
}

void menu() {
    int choice;
    do {
    	clr();
        printf("Main Menu\n");
        printf("1. Release a new slang word\n");
        printf("2. Search a slang word\n");
        printf("3. View all slang words starting with a certain prefix\n");
        printf("4. View all slang words\n");
        printf("5. Exit\n");
        printf("Input your choice [1-5]: ");
        scanf("%d", &choice);
        getchar();
        switch(choice) {
            case 1:
                insert();
                break;
            case 2:
                search();
                break;
            case 3:
                searchByPrefix();
                break;
            case 4:
                viewAll();
                break;
            case 5:
                exitProgram();
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while(choice != 5);
}

int main() {
    dict = createDictionary();
    
    insertQueue("LOL", "Laughing Out Loud");
    insertQueue("BRB", "Be Right Back");
    insertQueue("IDK", "I Don't Know");
    
    menu();
    
    return 0;
}
