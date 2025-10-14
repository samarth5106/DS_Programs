
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

int main() {
    int choice, val;
    char resp;

    do {

        printf("1. Enqueue\n2. Dequeue\n3. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Enqueue
                printf("Enter value: ");
                scanf("%d", &val);
                if (top1 == MAX - 1) {
                    printf("Queue Overflow!\n");
                } else {
                    while (top1 != -1) {
                        s2[++top2] = s1[top1--];
                    }
                    s1[++top1] = val;

                    while (top2 != -1) {
                        s1[++top1] = s2[top2--];
                    }
                    printf("%d enqueued\n", val);
                }
                break;

            case 2:  // Dequeue
                if (top1 == -1) {
                    printf("Queue is empty!\n");
                } else {
                    val = s1[top1--];
                    printf("Dequeued: %d\n", val);
                }
                break;
            case 3:  // Display
                if (top1 == -1) {
                    printf("Queue is empty!\n");
                } else {
                    printf("Queue elements: ");
                    for (int i = top1; i >= 0; i--) {
                        printf("%d ", s1[i]);
                    }
                    printf("\n");
                }
                break;
            default:
                printf("Invalid choice!\n");
        }
        printf("want to continue?");
        scanf(" %c",&resp);
    } while(resp=='y');

    return 0;
}

