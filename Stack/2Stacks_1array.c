#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int arr[MAX_SIZE];
int top1 = -1;
int top2 = MAX_SIZE;

int isFull() {
    return top1 + 1 == top2;
}

void push1(int data) {
    if (isFull()) {
        printf("\n\tERROR: Stack 1 is full! Cannot push %d.\n", data);
        return;
    }
    top1++;
    arr[top1] = data;
    printf("\n\tPushed %d onto Stack 1.\n", data);
}

int pop1() {
    if (top1 == -1) {
        printf("\n\tERROR: Stack 1 is empty!\n");
        return -1;
    }
    int data = arr[top1];
    top1--;
    printf("\n\tPopped %d from Stack 1.\n", data);
    return data;
}

void display1() {
    if (top1 == -1) {
        printf("\n\tStack 1 is Empty.\n");
        return;
    }
    printf("\n\tStack 1 Elements\n\t");
    for (int i = top1; i >= 0; i--) {
        printf("[%d] ", arr[i]);
    }
    printf("\n");
}

void push2(int data) {
    if (isFull()) {
        printf("\n\tERROR: Stack 2 is full! Cannot push %d .\n", data);
        return;
    }
    top2--;
    arr[top2] = data;
    printf("\n\tPushed %d onto Stack 2.\n", data);
}

int pop2() {
    if (top2 == MAX_SIZE) {
        printf("\n\tERROR: Stack 2 is empty!.\n");
        return -1;
    }
    int data = arr[top2];
    top2++;
    printf("\n\tPopped %d from Stack 2.\n", data);
    return data;
}

void display2() {
    if (top2 == MAX_SIZE) {
        printf("\n\tStack 2 is Empty.\n");
        return;
    }
    printf("\n\tStack 2 Elements (Top -> Bottom)\n\t");
    for (int i = top2; i < MAX_SIZE; i++) {
        printf("[%d] ", arr[i]);
    }
    printf("\n");
}

void displayMenu() {
    printf("  Two Stacks in One Array (Max Size: %d)\n", MAX_SIZE);
    printf("1. Push into Stack 1\n");
    printf("2. Push into Stack 2\n");
    printf("3. Pop from Stack 1\n");
    printf("4. Pop from Stack 2\n");
    printf("5. Display Stack 1\n");
    printf("6. Display Stack 2\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice, value;

    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("\n\tInvalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("\n\tEnter value to push into Stack 1: ");
                scanf("%d", &value);
                push1(value);
                break;

            case 2:
                printf("\n\tEnter value to push into Stack 2: ");
                scanf("%d", &value);
                push2(value);
                break;

            case 3:
                pop1();
                break;

            case 4:
                pop2();
                break;

            case 5:
                display1();
                break;

            case 6:
                display2();
                break;

            case 7:
                printf("\n\tExiting program. Goodbye!\n");
                exit(0);

            default:
                printf("\n\tInvalid choice. Please enter a number between 1 and 7.\n");
        }
    }
    return 0;
}
