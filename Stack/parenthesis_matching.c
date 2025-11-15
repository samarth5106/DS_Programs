#include<stdio.h>
#include<string.h>
#define MAX 50
int main(){
    char stack[MAX];
    char string[MAX];
    int top=-1;
    printf("Enter parenthesis string: ");
    scanf("%s",string);
    int len=strlen(string);
    char ch;
    for(int i=0;i<len;i++){
        if(string[i]=='('||string[i]=='{'||string[i]=='['){
            stack[++top]=string[i];
            ch=stack[top];
           }

           else{
                if(top==-1){
            printf("Paranthesis String Not balanced!!!\n");
                    return 0;
                }
                 ch=stack[top];
            if((string[i]==')'&&ch!='(')||(string[i]=='}'&&ch!='{')||(string[i]==']'&&ch!='[')){
                printf("Paranthesis String Not balanced!!!\n");
                return 0;
            }
            else{
                top--;

            }

           }
    }
    if(top==-1)
printf("It is balanced Parenthesis String!!\n");

else{
    printf("Paranthesis String Not balanced!!!\n");

}
 return 0;
}
