#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int val){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node* insert(struct node *root,int val){
    if(root==NULL){
        return createNode(val);
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else if(val>root->data){
        root->right=insert(root->right,val);
    }
    return root;
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void printRange(struct node *root,int low,int high){
    if(root==NULL){
        return;
    }
    if(low<root->data){
        printRange(root->left,low,high);
    }
    if(low<=root->data && root->data<=high){
        printf("%d ",root->data);
    }
    if(high>root->data){
        printRange(root->right,low,high);
    }
}

int main(){
    struct node *root=NULL;
    int choice,val,low,high;
    do{
        printf("\n1.Insert\n2.Inorder\n3.Print range\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d",&val);
                root=insert(root,val);
                break;
            case 2:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Enter low range: ");
                scanf("%d",&low);
                printf("Enter high range: ");
                scanf("%d",&high);
                printf("Elements in range [%d,%d]: ",low,high);
                printRange(root,low,high);
                printf("\n");
                break;

        }
    }while(choice!=4);
    return 0;
}
