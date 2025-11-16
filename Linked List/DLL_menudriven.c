#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
}node;
node *head=NULL;

node* createNode(int n){
    node newnode=(node)malloc(sizeof(node));
    newnode->data=n;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

int Create(){
    int n;
    char ch;
    printf("Enter element : ");
    scanf("%d",&n);

    head=createNode(n);
    node *temp=head;

    printf("Want to continue ? (Y/N): ");
    scanf(" %c",&ch);

    while(ch=='Y'||ch=='y'){
        printf("Enter next element : ");
        scanf("%d",&n);

        temp->next=createNode(n);
        temp->next->prev=temp;

        temp=temp->next;

        printf("Want to continue ? (Y/N): ");
        scanf(" %c",&ch);
    }
    return 0;
}

int Display(){
    if(head==NULL){
        printf("List empty\n");
        return 0;
    }
    node *temp=head;
    printf("\nList : ");
    while(temp!=NULL){
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    return 0;
}

int InsertOnFirst(){
    int n;
    printf("Enter element : ");
    scanf("%d",&n);

    node *newnode=createNode(n);

    if(head!=NULL){
        newnode->next=head;
        head->prev=newnode;
    }

    head=newnode;
    return 0;
}

int InsertOnLast(){
    int n;
    printf("Enter element : ");
    scanf("%d",&n);

    node *newnode=createNode(n);

    if(head==NULL){
        head=newnode;
        return 0;
    }

    node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newnode;
    newnode->prev=temp;

    return 0;
}

int InsertOnMiddle(){
    int n,pos,i;
    printf("Enter element : ");
    scanf("%d",&n);

    printf("Enter position : ");
    scanf("%d",&pos);

    if(pos==1){
        InsertOnFirst();
        return 0;
    }

    node *temp=head;

    for(i=1;i<pos-1 && temp!=NULL;i++)
        temp=temp->next;

    if(temp==NULL){
        printf("Invalid position\n");
        return 0;
    }

    node *newnode=createNode(n);
    newnode->next=temp->next;
    newnode->prev=temp;

    if(temp->next!=NULL)
        temp->next->prev=newnode;

    temp->next=newnode;

    return 0;
}

int DeleteFromFirst(){
    if(head==NULL){
        printf("List empty\n");
        return 0;
    }

    node *temp=head;
    head=head->next;

    if(head!=NULL)
        head->prev=NULL;

    printf("Deleted : %d\n",temp->data);
    free(temp);

    return 0;
}

int DeleteFromLast(){
    if(head==NULL){
        printf("List empty\n");
        return 0;
    }

    if(head->next==NULL){
        printf("Deleted : %d\n",head->data);
        free(head);
        head=NULL;
        return 0;
    }

    node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;

    printf("Deleted : %d\n",temp->data);
    temp->prev->next=NULL;
    free(temp);

    return 0;
}

int DeleteFromMiddle(){
    int pos,i;
    printf("Enter position : ");
    scanf("%d",&pos);

    if(pos==1){
        DeleteFromFirst();
        return 0;
    }

    node *temp=head;

    for(i=1;i<pos && temp!=NULL;i++)
        temp=temp->next;

    if(temp==NULL){
        printf("Invalid position\n");
        return 0;
    }

    printf("Deleted : %d\n",temp->data);

    if(temp->prev!=NULL)
        temp->prev->next=temp->next;

    if(temp->next!=NULL)
        temp->next->prev=temp->prev;

    free(temp);

    return 0;
}

int SortList(){
    if(head==NULL){
        printf("List empty\n");
        return 0;
    }

    node *current,*nextnode;
    int swapValue;

    for(current=head; current->next!=NULL; current=current->next){
        for(nextnode=current->next; nextnode!=NULL; nextnode=nextnode->next){

            if(current->data > nextnode->data){
                swapValue=current->data;
                current->data=nextnode->data;
                nextnode->data=swapValue;
            }
        }
    }

    printf("List sorted\n");
    return 0;
}

int main(){
    int ch;

    while(1){
        printf("\n1.Create\n2.Insert first\n3.Insert last\n4.Insert middle\n5.Delete first\n6.Delete last\n7.Delete middle\n8.Display\n10.Sort\nEnter choice : ");
        scanf("%d",&ch);

        switch(ch){
            case 1: Create(); break;
            case 2: InsertOnFirst(); break;
            case 3: InsertOnLast(); break;
            case 4: InsertOnMiddle(); break;
            case 5: DeleteFromFirst(); break;
            case 6: DeleteFromLast(); break;
            case 7: DeleteFromMiddle(); break;
            case 8: Display(); break;
            case 10: SortList(); break;
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
