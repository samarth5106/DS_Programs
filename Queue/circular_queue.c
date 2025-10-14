#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int main()
{
    int CQ[MAX];
    int front = -1, rear = -1;
    int ch, val, i;

    do
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n");
        printf("\n\tEnter choice: ");
        if (scanf("%d", &ch) != 1) {
            printf("\n\tInvalid input. Exiting.\n");
            break;
        }
        switch(ch)
        {
            case 1:
            if((front == 0 && rear == MAX - 1) || (front == rear + 1))
            {
                printf("\n\t\t\t Queue is full");
            }
            else
            {
                printf("\n\t\tEnter the value: ");
                scanf("%d", &val);
                if(front == -1)
                {
                    front = 0;
                    rear = 0;
                }
                else
                {
                    rear = (rear + 1) % MAX;
                }
                CQ[rear] = val;
                printf("\n\t\t%d is enqueued", val);
            }
            break;

            case 2:
            if(front == -1)
            {
                printf("\n\t\t\t Queue is empty");
            }
            else
            {
                val = CQ[front];
                printf("\n\t\t%d is dequeued", val);
                if(front == rear)
                {
                    front = -1;
                    rear = -1;
                }
                else
                {
                    front = (front + 1) % MAX;
                }
            }
            break;

            case 3:
            if(front == -1)
            {
                printf("\n\t\t\t Queue is empty");
            }
            else
            {
                printf("\n\t\tQueue Elements: ");
                i = front;
                while(1)
                {
                    printf("[%d] ", CQ[i]);
                    if(i == rear) break;
                    i = (i + 1) % MAX;
                }
            }
            break;
        }
    } while (ch<=3);
    return 0;
}

