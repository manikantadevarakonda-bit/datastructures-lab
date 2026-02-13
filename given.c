#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_SIZE 100
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (!stack) return NULL;
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    if (!stack->array) {
        free(stack);
        return NULL;
    }
    return stack;
}
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}
char pop(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0'; 
    return stack->array[stack->top--];
}
char peek(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top];
}
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
void infixToPostfix(char* exp) {
    int i, j;
    int len = strlen(exp);
    struct Stack* stack = createStack(len);
    if (!stack) 
        return;
    printf("Infix expression: %s\n", exp);
    printf("Postfix expression: ");
    for (i = 0, j = 0; i < len; i++) {
        if (isalnum(exp[i])) {
            printf("%c", exp[i]);
        }
        else if (exp[i] == '(') {
            push(stack, exp[i]);
        }
        else if (exp[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                printf("%c", pop(stack));
            }
            if (!isEmpty(stack) && peek(stack) == '(') {
                pop(stack); 
            }
        }
        else {
            while (!isEmpty(stack) && precedence(exp[i]) <= precedence(peek(stack))) {
                printf("%c", pop(stack));
            }
            push(stack, exp[i]);
        }
    }
    while (!isEmpty(stack)) {
        printf("%c", pop(stack));
    }
    printf("\n");
    free(stack->array);
    free(stack);
}
int main() {
    char exp[] = "a+b*(c-d)/e";
    infixToPostfix(exp);
    char exp2[] = "(a+b)*c-d/e";
    infixToPostfix(exp2);
    return 0;
}
