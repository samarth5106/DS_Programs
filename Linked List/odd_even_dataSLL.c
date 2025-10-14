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
    printf("Node with value %d inserted.\n", value);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sumEven() {
    int sum = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            sum += temp->data;
        }
        temp = temp->next;
    }
    printf("Sum of even numbers: %d\n", sum);
}

void sumOdd() {
    int sum = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data % 2 != 0) {
            sum += temp->data;
        }
        temp = temp->next;
    }
    printf("Sum of odd numbers: %d\n", sum);
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert Node\n");
        printf("2. Display List\n");
        printf("3. Sum of Even Numbers\n");
        printf("4. Sum of Odd Numbers\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                display();
                break;
            case 3:
                sumEven();
                break;
            case 4:
                sumOdd();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
