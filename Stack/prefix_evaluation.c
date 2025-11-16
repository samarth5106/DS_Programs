
#include<stdio.h>
#include<ctype.h>
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

int length(char str[]){
    int len=0;
    while(str[len]!='\0'){
        len++;
    }
    return len;
}

int evaluatePrefix(char prefix[]){
    int len=length(prefix);
    for(int i=len-1;i>=0;i--){
        if(prefix[i]==' '){
            continue;
        }
        if(prefix[i]>='0' && prefix[i]<='9'){
            int num=0;
            int multiplier=1;
            while(i>=0 && prefix[i]>='0' && prefix[i]<='9'){
                num=num+(prefix[i]-'0')*multiplier;
                multiplier*=10;
                i--;
            }
            i++;
            push(num);
        }
        else{
            int a=pop();
            int b=pop();
            int result=calculate(a,b,prefix[i]);
            push(result);
        }
    }
    return pop();
}

int main(){
    char prefix[MAX];
    printf("Enter prefix expression: ");
    int i=0;
    char ch;
    while((ch=getchar())!='\n' && i<MAX-1){
        prefix[i++]=ch;
    }
    prefix[i]='\0';
    int result=evaluatePrefix(prefix);
    printf("Result: %d\n",result);
    return 0;
}
