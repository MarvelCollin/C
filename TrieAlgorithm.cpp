#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode* createNode() {
    struct TrieNode* newNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    if (newNode) {
        newNode->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            newNode->children[i] = NULL;
        }
    }
    return newNode;
}

void insert(struct TrieNode* root, const char* key) {
    struct TrieNode* current = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (!current->children[index]) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

bool search(struct TrieNode* root, const char* key) {
    struct TrieNode* current = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (!current->children[index]) {
            return false;
        }
        current = current->children[index];
    }
    return current && current->isEndOfWord;
}

void suggestionsUtil(struct TrieNode* root, char prefix[], int idx) {
    if (root->isEndOfWord) {
        prefix[idx] = '\0';
        printf("%s\n", prefix);
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            prefix[idx] = i + 'a';
            suggestionsUtil(root->children[i], prefix, idx + 1);
        }
    }
}

void findSuggestions(struct TrieNode* root, const char* prefix) {
    struct TrieNode* current = root;
    int n = strlen(prefix);
    char word[n + 1];
    for (int i = 0; i < n; i++) {
        int index = prefix[i] - 'a';
        if (!current->children[index]) {
            printf("No words found with prefix '%s'\n", prefix);
            return;
        }
        word[i] = prefix[i];
        current = current->children[index];
    }
    word[n] = '\0';
    suggestionsUtil(current, word, n);
}

int main() {
    struct TrieNode* root = createNode();
    insert(root, "hello");
    insert(root, "hellob");
    insert(root, "world");

    printf("Searching for 'hello': %s\n", search(root, "hello") ? "Found" : "Not Found");
    printf("Searching for 'world': %s\n", search(root, "world") ? "Found" : "Not Found");
    printf("Searching for 'apple': %s\n", search(root, "apple") ? "Found" : "Not Found");
    
    printf("Suggestions for prefix 'hell':\n");
    findSuggestions(root, "hell");

    return 0;
}
