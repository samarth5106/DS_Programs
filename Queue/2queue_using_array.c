#include<stdio.h>
#define MAX 10
void enqueue1(int val,int Arr[],int *rear1){
Arr[++(*rear1)]=val;
return;
}
void dequeue1(int *front1){
    (*front1)++;
    return;
}
void traverse1(int Arr[],int *rear1,int *front1){
    for(int i=(*front1);i<=(*rear1);i++){
        printf("%d ",Arr[i]);
    }
    return ;
}
void enqueue2(int val,int Arr[],int *rear2){
    Arr[--(*rear2)]=val;
    return;
}
void dequeue2(int *front2){
    --(*front2);
    return;
}
void traverse2(int Arr[],int *rear2,int *front2){
    for(int i=(*front2);i>=(*rear2);i--){
        printf("%d ",Arr[i]);
    }
    return;
}

int main(){
    int arr[MAX];
    int rear1 = -1, front1 = 0;
    int rear2=MAX;
    int front2=MAX-1;
    int choice,val;
    char ch;
    printf("\n1. Enqueue into queue 1\n2. Dequeue from queue 1\n3. Traverse queue 1\n4.Enqueue into queue 2\n5.Dequeue from queue 2\n6.Traverse queue 2");
    do{
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            if(rear1+1==rear2){
              printf("Queue is Full, can't enqueue!!\n");
                    break;
            }

            printf("Enter value to enqueue: ");
            scanf("%d",&val);
            printf("\n%d is finally enqueued in Queue 1!!!",val);
            enqueue1(val,arr,&rear1);
            break;
        case 2:
            if(front1>rear1){
                 printf("Queue is Empty, can't dequeue!!\n");
                    break;
            }
             printf("%d has been successfully dequeued from queue 1!!\n", arr[front1]);
                dequeue1(&front1);
                break;
        case 3:
            if(front1>rear1){
                printf("Queue is Empty, can't trverse!!\n");
                    break;
            }
            printf("Traversing Queue 1 ........\n ");
            traverse1(arr,&rear1,&front1);
            break;

        case 4:
             if(rear2-1==rear1){
               printf("Queue is Full, can't enqueue!!\n");
                    break;
            }

            printf("Enter value to enqueue: ");
            scanf("%d",&val);
             printf("\n%d is finally enqueued in Queue 2!!!",val);
            enqueue2(val,arr,&rear2);
            break;
        case 5:
             if(front2<rear2){
                 printf("Queue is Empty, can't dequeue!!\n");
                    break;
            }
             printf("%d has been successfully dequeued from queue 2!!\n", arr[front2]);
                dequeue2(&front2);
                break;
        case 6:
             if(front2<rear2){
                printf("Queue is Empty, can't trverse!!\n");
                    break;
            }
            printf("Traversing Queue 2........\n ");
            traverse2(arr,&rear2,&front2);
            break;


        }
         printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &ch);
    }while(ch=='y'||ch=='Y');
    return 0;
}
