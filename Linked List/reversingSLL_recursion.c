#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void display() {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* reverseRecursive(struct Node* current) {
    if (current == NULL || current->next == NULL) {
        return current;
    }

    struct Node* newHead = reverseRecursive(current->next);
    current->next->next = current;
    current->next = NULL;

    return newHead;
}

void reverse() {
    head = reverseRecursive(head);
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    printf("Original ");
    display();

    reverse();

    printf("Reversed ");
    display();

    return 0;
}
