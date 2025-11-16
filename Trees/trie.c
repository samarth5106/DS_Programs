#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct trienode {
    char ref;
    struct trienode *alphabet[26];
    int isEnd;
} trienode;

trienode* getnode() {
    trienode *node = (trienode*)malloc(sizeof(trienode));
    for (int i = 0; i < 26; i++)
        node->alphabet[i] = NULL;
    node->ref = '\0';
    node->isEnd = 0;
    return node;
}

int getidx(char c) {
    return c - 'a';
}
void insert(trienode *root, char word[]) {
    trienode *temp = root;
    for (int i = 0; i < strlen(word); i++) {
        int idx = getidx(word[i]);
        if (temp->alphabet[idx] == NULL) {
            temp->alphabet[idx] = getnode();
            temp->alphabet[idx]->ref = word[i];
        }
        temp = temp->alphabet[idx];
    }
    temp->isEnd = 1;
    printf("Word '%s' inserted successfully!\n", word);
}

void search(trienode *root, char word[]) {
    trienode *temp = root;
    for (int i = 0; i < strlen(word); i++) {
        int idx = getidx(word[i]);
        if (temp->alphabet[idx] == NULL) {
            printf("Word '%s' NOT found!\n", word);
            return;
        }
        temp = temp->alphabet[idx];
    }
    if (temp->isEnd == 1)
        printf("Word '%s' FOUND!\n", word);
    else
        printf("Word '%s' NOT found (prefix only)!\n", word);
}

int main() {
    trienode *root = getnode();
    int choice;
    char word[50];
    while (1) {
        printf("1. Insert Word\n");
        printf("2. Search Word\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter word to insert: ");
                scanf("%s", word);
                insert(root, word);
                break;
            case 2:
                printf("Enter word to search: ");
                scanf("%s", word);
                search(root, word);
                break;
        }
    }

    return 0;
}
