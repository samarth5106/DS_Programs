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

int findMin(struct node *root){
    if(root==NULL){
        printf("Tree is empty\n");
        return -1;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}
int findMax(struct node *root){
    if(root==NULL){
        printf("Tree is empty\n");
        return -1;
    }
    while(root->right!=NULL){
        root=root->right;
    }
    return root->data;
}
int main(){
    struct node *root=NULL;
    int choice,val,minVal,maxVal;
    do{
        printf("\n1.Insert\n2.Inorder\n3.Find Min\n4.Find Max\n);
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
                minVal=findMin(root);
                if(minVal!=-1){
                    printf("Minimum element: %d\n",minVal);
                }
                break;
            case 4:
                maxVal=findMax(root);
                if(maxVal!=-1){
                    printf("Maximum element: %d\n",maxVal);
                }
                break;
        }
    }while(choice!=5);
    return 0;
}
