#include<stdio.h>
#define MAX 10
void enqueue(int val, int Arr[], int *rear){
    Arr[++(*rear)] = val;
    return;
}
void dequeue(int Arr[], int *front){
    (*front)++;
    return;
}
void traverse(int Arr[], int rear, int front){
    for(int i=front; i<=rear; i++){
        printf("%d ", Arr[i]);
    }
    printf("\n");
    return;
}
int main(){
    int arr[MAX];
    int rear = -1, front = 0;
    int choice;
    char ch;
    printf("\n1. Enqueue\n2. Dequeue\n3. Traverse\n");
    do{
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(rear == MAX-1){
                    printf("Queue is Full, can't Enqueue!!!\n");
                    break;
                }
                int val;
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val, arr, &rear);
                printf("%d has been successfully enqueued\n", val);
                break;
            case 2:
                if(front > rear){
                    printf("Queue is Empty, can't dequeue!!\n");
                    break;
                }
                printf("%d has been successfully dequeued!!\n", arr[front]);
                dequeue(arr, &front);
                break;
            case 3:
                if(front > rear){
                    printf("Queue is Empty, nothing to display!!\n");
                    break;
                }
                printf("Displaying queue......\n");
                traverse(arr, rear, front);
                break;
        }
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &ch);
    } while(ch=='y'||ch=='Y');
    return 0;
}
