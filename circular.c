#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5 
int queue[MAX_SIZE];
int front = -1, rear = -1;
int isFull() {
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        return 1;
    }
    return 0;
}
int isEmpty() {
    if (front == -1)
        return 1;
    else
        return 0;
}
void enqueue(int element) {
    if (isFull()) {
        printf("\nQueue is full!! \n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = element;
    printf("\nInserted -> %d\n", element);
}
int dequeue() {
    int element;
    if (isEmpty()) {
        printf("\nQueue is empty, cannot dequeue!!\n");
        return -1; 
    }
    element = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    printf("\nDeleted %d\n", element);
    return element;
}
int findElement(int element) {
    if (isEmpty()) {
        printf("\nQueue is empty, cannot find element.\n");
        return -1;
    }
    int i = front;
    int position = 0;
    while (i != rear) {
        if (queue[i] == element) {
            printf("\nElement %d found at position %d (index %d).\n", element, position + 1, i);
            return i; 
        }
        i = (i + 1) % MAX_SIZE;
        position++;
    }
    if (queue[rear] == element) {
        printf("\nElement %d found at position %d (index %d).\n", element, position + 1, rear);
        return rear;
    }
    printf("\nElement %d not found in the queue.\n", element);
    return -1; 
}
void display() {
    int i;
    if (isEmpty()) {
        printf("\nEmpty Queue\n");
        return;
    }
    printf("\nItems -> ");
    for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", queue[i]);
    }
    printf("%d ", queue[i]);
    printf("\n");
}
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    display();
    enqueue(6); 
    display();
    findElement(3);
    findElement(10); 
    return 0;
}
