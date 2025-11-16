
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 50

int operandStack[MAX];
char operatorStack[MAX];
int opTop = -1;
int orTop = -1;
void pushOperand(int val) {
    if(opTop == MAX-1) {
        printf("Operand Stack Full!\n");
        return;
    }
    operandStack[++opTop] = val;
    printf("  Pushed operand: %d\n", val);
}

int popOperand() {
    if(opTop == -1) {
        printf("Operand Stack Empty!\n");
        return 0;
    }
    return operandStack[opTop--];
}

void pushOperator(char op) {
    if(orTop == MAX-1) {
        printf("Operator Stack Full!\n");
        return;
    }
    operatorStack[++orTop] = op;
    printf("  Pushed operator: %c\n", op);
}
char popOperator() {
    if(orTop == -1) {
        printf("Operator Stack Empty!\n");
        return '\0';
    }
    return operatorStack[orTop--];
}

int precedence(char op) {
    if(op == '^')
        return 3;
    else if(op == '*' || op == '/')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    else
        return 0;
}
int applyOperator(int operand1, int operand2, char operator) {
    switch(operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/':
            if(operand2 == 0) {
                printf("Division by zero error!\n");
                return 0;
            }
            return operand1 / operand2;
        case '^': {
            int result = 1;
            for(int i = 0; i < operand2; i++) {
                result *= operand1;
            }
            return result;
        }
        default:
            return 0;
    }
}

void evaluateTop() {
    int operand2 = popOperand();
    int operand1 = popOperand();
    char operator = popOperator();

    int result = applyOperator(operand1, operand2, operator);

    printf("  Evaluated: %d %c %d = %d\n", operand1, operator, operand2, result);

    pushOperand(result);
}

int evaluateInfix(char infix[]) {
    int i = 0;

    printf("\n=== Evaluating Infix Expression ===\n");
    printf("Expression: %s\n\n", infix);
    while(infix[i] != '\0') {
        char ch = infix[i];
        printf("Reading: '%c'\n", ch);
        if(ch == ' ') {
            i++;
            continue;
        }
        if(isdigit(ch)) {
            int num = 0;
            while(isdigit(infix[i])) {
                num = num * 10 + (infix[i] - '0');
                i++;
            }
            pushOperand(num);
            continue;
        }

        else if(ch == '(') {
            pushOperator(ch);
        }

        else if(ch == ')') {
            while(orTop != -1 && operatorStack[orTop] != '(') {
                evaluateTop();
            }
            if(orTop != -1) {
                orTop--;
                printf("  Removed '('\n");
            }
        }

        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while(orTop != -1 &&
                  operatorStack[orTop] != '(' &&
                  precedence(operatorStack[orTop]) >= precedence(ch)) {
                evaluateTop();
            }
            pushOperator(ch);
        }

        i++;
    }
    printf("\nEvaluating remaining operators:\n");
    while(orTop != -1) {
        evaluateTop();
    }
    return popOperand();
}
int main() {
    char infix[MAX];
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0';
    int result = evaluateInfix(infix);
    printf("Final Result: %d\n", result);
    return 0;
}
