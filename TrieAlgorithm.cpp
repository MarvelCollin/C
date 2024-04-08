#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    char desc[1000];
    bool isEndOfWord;
} TrieNode;

TrieNode* root = NULL;

TrieNode* createNode(char desc[]) {
    TrieNode* node = (TrieNode*) malloc(sizeof(TrieNode));
        node->isEndOfWord = false;
//        for (int i = 0; i < ALPHABET_SIZE; i++) {
//            node->children[i] = NULL;
//        }
        memset(node->children, 0, sizeof(node->children));
        strcpy(node->desc, desc);
    return node;
}

void insert(char word[], char desc[]) {
    if (!root) {
        root = createNode(desc);
    }
    TrieNode* current = root;
    
    int i = 0;
    while (word[i] != '\0') {
        int index = word[i] - 'a';
        if (!current->children[index]) {
            current->children[index] = createNode(desc);
        }
        current = current->children[index];
        i++;
    }
    current->isEndOfWord = true;
}

void printWords(TrieNode* node, char prefix[], int depth) {
    if (node->isEndOfWord) {
        prefix[depth] = '\0';
        printf("End : %s\n", prefix);
    }
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            prefix[depth] = 'a' + i;
            printWords(node->children[i], prefix, depth + 1);
        }
    }
}

void search(const char word[]) {
    if (!root) {
        printf("Nah\n");
        return;
    }
    
    TrieNode* current = root;
    int i = 0;
    char prefix[1000];  
    
    while (word[i] != '\0') {
        int index = word[i] - 'a';
        if (!current->children[index]) {
            printf("Nah\n");
            return;
        }
        prefix[i] = word[i];
        current = current->children[index];
        i++;
    }
    
    prefix[i] = '\0';
    printf("Words matching prefix '%s':\n", prefix);
    
    printWords(current, prefix, i);
}




int main() {
    insert("appPle", "asd");
    insert("banana", "asdaasdags");
    insert("app", "asdagsdgayshda");
    insert("bat", "ashhaushaushd");
    search("ap");

    return 0;
}
