#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_SIZE 100
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;
void initialize(Stack* s) {
    s->top = -1;
}
void push(Stack* s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = value;
}
int pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1; 
    }
    return s->items[s->top--];
}
int operate(char operator, int op2, int op1) {
    switch (operator) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': 
            if (op2 == 0) {
                printf("Division by zero error\n");
                exit(EXIT_FAILURE);
            }
            return op1 / op2;
        default: return 0;
    }
}
int evaluatePostfix(char* expression) {
    Stack s;
    initialize(&s);
    int i, operand1, operand2, result;
    for (i = 0; i < strlen(expression); i++) {
        if (isdigit(expression[i])) {
            push(&s, expression[i] - '0'); 
  } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            operand2 = pop(&s);
            operand1 = pop(&s);
            result = operate(expression[i], operand2, operand1);
            push(&s, result);
        }
    }
    return pop(&s);
}
int main() {
    char expression[] = "231*+9-"; 
    int result = evaluatePostfix(expression);
    printf("Postfix expression: %s\n", expression);
    printf("Result: %d\n", result); 
    char expression2[] = "12+3*";
    int result2 = evaluatePostfix(expression2);
    printf("Postfix expression: %s\n", expression2);
    printf("Result: %d\n", result2); 
    return 0;
}
