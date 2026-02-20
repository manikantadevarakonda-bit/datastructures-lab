#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5 
int queue[MAX_SIZE];
int front = -1, rear = -1;
int isEmpty() {
    return front == -1;
}
int isFull() {
    return rear == MAX_SIZE - 1;
}
void enqueue(int element) {
    if (isFull()) {
        printf("Queue Overflow: Cannot insert element.\\n");
    } else {
        if (isEmpty()) {
            front = 0; 
        }
        rear++;
        queue[rear] = element;
        printf("Enqueued %d successfully.\\n", element);
    }
}
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow: Cannot delete element.\\n");
    } else {
        printf("Dequeued element: %d\\n", queue[front]);
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}
void findElement(int element) {
    if (isEmpty()) {
        printf("Queue is Empty, cannot find element.\\n");
        return;
    }
    int found = 0;
    for (int i = front; i <= rear; i++) {
        if (queue[i] == element) {
            printf("Element %d found at position %d (index %d).\\n", element, i - front + 1, i);
            found = 1;
            break; 
        }
    }
    if (!found) {
        printf("Element %d not found in the queue.\\n", element);
    }
}
void display() {
    if (isEmpty()) {
        printf("Queue is Empty.\\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\\n");
    }
}
int main() {
    int choice, data;
    while (1) {
        printf("\n---- Linear Queue Operations Using Array ----\n");
        printf("1. Enqueue\n2. Dequeue\n3. Find Element\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Enter the element to find: ");
                scanf("%d", &data);
                findElement(data);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\\n");
        }
    }
    return 0;
}
