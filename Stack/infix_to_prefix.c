#include<stdio.h>
#include<string.h>
#define MAX 50
int isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}
int precedence(char c) {
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}
void reverse(char str[]) {
    int n = strlen(str);
    for(int i = 0; i < n/2; i++) {
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
}
void infixToPrefix(char infix[]) {
    char stack[MAX], output[MAX];
    int top = -1, k = 0;
    int len = strlen(infix);
    for(int i = len-1; i >= 0; i--) {
        char ch = infix[i];
        if(isOperand(ch)) {
            output[k++] = ch;
        }
        else if(ch == ')') {
            stack[++top] = ch;
        }
        else if(ch == '(') {
            while(top != -1 && stack[top] != ')') {
                output[k++] = stack[top--];
            }
            top--;
        }
        else {
            while(top != -1 && stack[top] != ')' &&
                  precedence(stack[top]) > precedence(ch)) {
                output[k++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }
    while(top != -1) {
        output[k++] = stack[top--];
    }
    output[k] = '\0';
    reverse(output);
    printf("Prefix: %s\n", output);
}
int main() {
    char infix[MAX];
    printf("Enter infix: ");
    scanf("%s", infix);
    infixToPrefix(infix);
    return 0;
}
