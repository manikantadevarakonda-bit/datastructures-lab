#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10 
int stack[MAX_SIZE]; 
int top = -1;        
int isFull() {
    return top == MAX_SIZE - 1;
}
int isEmpty() {
    return top == -1;
}
void push(int item) {
    if (isFull()) {
        printf("Stack Overflow! Cannot add more elements.\n");
    } else {
        top++;
        stack[top] = item;
        printf("Pushed element: %d\n", item);
    }
}
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot remove elements from an empty stack.\n");
        return -1; 
    } else {
        int poppedItem = stack[top];
        top--;
        return poppedItem;
    }
}
int peek() {
    if (isEmpty()) {
        printf("Stack is empty! No top element.\n");
        return -1; 
    } else {
        return stack[top];
    }
}

// Function to display all elements in the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Main function to test the stack operations
int main() {
    push(10);
    push(20);
    push(30);
    display();

    printf("Top element is: %d\n", peek());

    int popped = pop();
    if (popped != -1) {
        printf("Popped element: %d\n", popped);
    }
    display();

    push(40);
    display();

    return 0;
}
