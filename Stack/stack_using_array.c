#include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;
void push(int val) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else {
        top++;
        stack[top] = val;
    }
}
void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}
void peep() {
    if(top==-1)
        printf("Stack is empty\n");
        else{
            printf("%d",stack[top]);
        }
}
void traverse() {
    if (top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}
int main() {
    int choice, val;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peep\n4. Traverse\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peep();
                break;
            case 4:
                traverse();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

