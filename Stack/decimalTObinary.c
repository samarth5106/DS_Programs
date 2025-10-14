#include<stdio.h>
#define MAX 100
int main(){
 int val;
 printf("\nEnter the val: ");
 scanf("%d",&val);
 int stack[MAX];
 int top=-1;
 while(val>0){
        stack[++top]=val%2;
 val=val/2;

 }
 int i=top;
 while(i>=0){
    printf("%d",stack[i]);
    i--;
 }
 return 0;
}


