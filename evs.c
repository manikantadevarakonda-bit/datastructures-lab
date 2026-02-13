#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;
void initialize(Stack* s) {
    s->top = -1;
}
int isEmpty(Stack* s) {
    return s->top == -1;
}
int isFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}
void push(Stack* s, char item) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = item;
}
char pop(Stack* s) {
    if (isEmpty(s)) {
        return -1; 
    }
    return s->items[s->top--];
}
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return 0;
}
void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initialize(&s);
    int i, j;
    i = j = 0;
    char nextChar;
    while ((nextChar = infix[i++]) != '\0') {
        if (isalnum(nextChar)) {
            postfix[j++] = nextChar; 
        } else if (nextChar == '(') {
            push(&s, nextChar); 
        } else if (nextChar == ')') {
            while (!isEmpty(&s) && s.items[s.top] != '(') {
                postfix[j++] = pop(&s);
            }
            if (!isEmpty(&s) && s.items[s.top] == '(') {
                pop(&s); 
            } else {
                printf("Error: Mismatched parentheses (extra closing parenthesis)\n");
                postfix[0] = '\0'; 
                return;
            }
        } else if (precedence(nextChar) > 0) {
            while (!isEmpty(&s) && precedence(s.items[s.top]) >= precedence(nextChar)) {
                postfix[j++] = pop(&s);
            }
            push(&s, nextChar); 
        } else {
            printf("Error: Invalid character '%c' in expression\n", nextChar);
            postfix[0] = '\0';
            return;
        }
    }
    while (!isEmpty(&s)) {
        if (s.items[s.top] == '(' || s.items[s.top] == ')') {
            printf("Error: Mismatched parentheses (missing closing parenthesis)\n");
            postfix[0] = '\0'; 
            return;
        }
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0'; 
}
int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0'; 
    infixToPostfix(infix, postfix);
    if (strlen(postfix) > 0) {
        printf("Postfix expression: %s\n", postfix);
    }
    return 0;
}
