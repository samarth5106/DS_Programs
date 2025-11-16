#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 50
int stack[MAX];
int top=-1;
void push(int val){
    if(top==MAX-1){
        printf("Stack Full\n");
        return;
    }
    stack[++top]=val;
}
int pop(){
    if(top==-1){
        printf("Stack Empty\n");
        return 0;
    }
    return stack[top--];
}
int calculate(int a,int b,char op){
    switch(op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        case '^':{
            int res=1;
            for(int i=0;i<b;i++)
                res*=a;
            return res;
        }
    }
    return 0;
}
int evaluatePostfix(char postfix[]){
    int i=0;
    while(postfix[i]!='\0'){
        if(postfix[i]==' '){
            i++;
            continue;
        }
        if(isdigit(postfix[i])){
            int num=0;
            while(isdigit(postfix[i])){
                num=num*10+(postfix[i]-'0');
                i++;
            }
            push(num);
            continue;
        }
        else{
            int b=pop();
            int a=pop();
            int result=calculate(a,b,postfix[i]);
            push(result);
        }
        i++;
    }
    return pop();
}
int main(){
    char postfix[MAX];
    printf("Enter postfix expression: ");
    fgets(postfix,MAX,stdin);
    postfix[strcspn(postfix,"\n")]='\0';
    int result=evaluatePostfix(postfix);
    printf("Result: %d\n",result);
    return 0;
}
