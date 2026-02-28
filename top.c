#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int value) {
    if (rear == MAX - 1) {
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}
void display() {
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
void reverseQueue() {
    int stack[MAX];
    int top = -1;
    for (int i = front; i <= rear; i++) {
        stack[++top] = queue[i];
    }
    for (int i = front; i <= rear; i++) {
        queue[i] = stack[top--];
    }
}
int main() {
    int capacity, value;
    scanf("%d", &capacity);
    for (int i = 0; i < capacity; i++) {
        scanf("%d", &value);
        enqueue(value);
    }
    printf("Original queue: ");
    display();
    reverseQueue();
    printf("Reversed queue: ");
    display();
    return 0;
}